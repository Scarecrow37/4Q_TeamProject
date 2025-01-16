#include "Session.h"
#include "Socket.h"
#include "Utils/StreamBuffer.h"
#include "PacketDispatcher.h"
#include "Packet.h"

void Session::Initialize(Socket* socket)
{
	// TODO: Initialize �� �� PacketDispatcher �ν��Ͻ��� �����;� �մϴ�
	_packetDispatcherInstance = PacketDispatcher::GetInstance();
	_saveRecvData = new StreamBuffer();

	_socket = socket;
	_recvOl._listen = _socket->GetSocket();

	_packetDispatcherInstance->SessionCreated(_sessionId);

	_recvOl._overlappedType = OlType::Recv;
	_sendOl._overlappedType = OlType::Send;
}

bool Session::SendUpdate()
{
	// TODO: PacketDispatcher���� ����ȭ�� ��Ŷ�� �����ͼ� ���ۿ� ä���� �մϴ�.
	SendQueue* msgs = _packetDispatcherInstance->GetSendMessageContainer(_sessionId);
	if ((*msgs).empty()) {
		bool res = _packetDispatcherInstance->SwapSendPacketContainer(_sessionId);
		if (res == false) {
			return true;
		}
	}

	DWORD byteTrans;
	bool res = GetOverlappedResult((HANDLE)_socket->GetSocket(), &_sendOl, &byteTrans, FALSE);
	if (res == false) {
		int error = WSAGetLastError();
		if (error == ERROR_IO_PENDING || error == ERROR_IO_INCOMPLETE) {
			return true;
		}
	}

	while (!(*msgs).empty()) {
		Packet msg = (*msgs).front();
		(*msgs).pop();
		if (_sendOl._dataSize + msg._packetSize > BufferSize) {
			break;
		}
		memcpy(&_sendOl._buffer[_sendOl._dataSize], PtrCast(char*, &msg), msg._packetSize);
		_sendOl._dataSize += msg._packetSize;
	}

	res = _socket->Send(_sendOl);
	if (res == false) {
		return false;
	}

	return true;
}

bool Session::RecvUpdate()
{
	// TODO: Session�� �ִ� StreamBuffer�� �����͸� �����ϰ�, �ϼ��� ��Ŷ�� dispatcher�� �Ѱ���� �մϴ�.
	printf("Data Received. Recv byte : %d\n", (int)_recvOl.InternalHigh);
	int savelen = _saveRecvData->Write(_recvOl._buffer, (int)_recvOl.InternalHigh);
	printf("Data Saved. Save byte : %d\n", savelen);

	_packetDispatcherInstance->SaveRecvPacket(_saveRecvData, _sessionId);

	if (savelen < _recvOl.InternalHigh) {
		int leftSize = (int)_recvOl.InternalHigh - savelen;
		_saveRecvData->Write(&_recvOl._buffer[savelen], leftSize);
	}

	memset(_recvOl._buffer, 0, BufferSize);

	bool res = _socket->Recv(_recvOl);
	if (res == false) {
		return false;
	}

	return true;
}

Socket* Session::Release()
{
	delete _saveRecvData;

	return _socket;
}

const SessionID Session::GetSessionID() const
{
	return _sessionId;
}
