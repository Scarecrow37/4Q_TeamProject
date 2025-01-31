#include "pch.h"
#include "Synchronize.h"

Engine::Component::Synchronize::Synchronize() :
	_msgBuffer(std::string(256, '\0'))
{
}

void Engine::Component::Synchronize::Initialize(const Modules& modules)
{
	Component::Initialize(modules);
	Engine::Application::GetNetworkManager()->Register(static_cast<Engine::Network::Terminal*>(this));
}

void Engine::Component::Synchronize::Finalize()
{
    Engine::Application::GetNetworkManager()->Unregister(static_cast<Engine::Network::Terminal*>(this));
}

void Engine::Component::Synchronize::InvokeMessage(const Packet& packet)
{
	if (_callbackMap.find(packet._packetId) == _callbackMap.end()) {
		return;
	}

    switch ((PacketID)packet._packetId) {
    case PacketID::EnterAccept:
    {
        _enterAccept.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
        _callbackMap[packet._packetId]->Invoke(&_enterAccept);
        break;
    }
	case PacketID::Sync:
	{
		_syncPlayer.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
		_callbackMap[packet._packetId]->Invoke(&_syncPlayer);

		break;
	}
	case PacketID::ObjectSync:
	{
		_syncObject.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
		_callbackMap[packet._packetId]->Invoke(&_syncObject);

		break;
	}
	case PacketID::MoveSync:
	{
		_moveSync.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
		_callbackMap[packet._packetId]->Invoke(&_moveSync);
		break;
	}
	case PacketID::StateChange:
	{
		_stateChange.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
		_callbackMap[packet._packetId]->Invoke(&_stateChange);
		break;
	}
	case PacketID::DataRemote:
	{
		_syncPlayer.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
		_callbackMap[packet._packetId]->Invoke(&_syncPlayer);

		break;
	}
	case PacketID::DataObject:
	{
		_syncObject.ParseFromArray(packet._data, packet._packetSize - sizeof(PacketHeader));
		_callbackMap[packet._packetId]->Invoke(&_syncObject);

		break;
	}

    default:
        break;
    }
}

void Engine::Component::Synchronize::RemoveCallback(short packetId)
{
    delete _callbackMap[packetId];
    _callbackMap.erase(packetId);
}
