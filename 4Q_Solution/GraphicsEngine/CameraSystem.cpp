#include "pch.h"
#include "CameraSystem.h"
#include "Camera.h"
#include "includes/ICamera.h"

void CameraSystem::SetCurrentCamera(const wchar_t* name)
{
	if (_cameras.find(name) == _cameras.end())
	{
		ASSERT(false, L"�ش� �±׷� ī�޶� ã�� �� �����ϴ�.");
		return;
	}

	_pCurrentCamera = _cameras[name];
}

void CameraSystem::Release()
{
	delete this;
}

void CameraSystem::CreateCamera(GE::ICamera** ppCamera)
{
	(*ppCamera) = new Camera;
}

void CameraSystem::Update()
{
	if (nullptr == _pCurrentCamera)
	{
		ASSERT(false, L"������ ī�޶� �����ϴ�.");
		return;
	}

	_pCurrentCamera->Update();
}

void CameraSystem::RegisterCamera(const wchar_t* name, GE::ICamera* pCaemra)
{
	if (_cameras.find(name) != _cameras.end())
	{
		ASSERT(false, L"�̹� ��ϵ� ī�޶� �Դϴ�.");
		return;
	}

	_cameras[name] = static_cast<Camera*>(pCaemra);
}

void CameraSystem::UnRegisterCamera(const wchar_t* name)
{
	if (_cameras.find(name) == _cameras.end())
	{
		ASSERT(false, L"��ϵ��� ���� ī�޶� �Դϴ�.");
		return;
	}

	_cameras.erase(name);
}