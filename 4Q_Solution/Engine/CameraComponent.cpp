#include "pch.h"
#include "CameraComponent.h"


Engine::Component::CameraComponent::CameraComponent(std::wstring name, const float nearZ, const float farZ, const SIZE size, const float fov) :
	_name(std::move(name)), _nearZ(nearZ), _farZ(farZ),
	_size(size), _fov(fov), _graphicsManager(nullptr), _camera(nullptr)
{
}

void Engine::Component::CameraComponent::Setup(const Modules modules)
{
	// TODO: Setup from file.
	Component::Setup(modules);
	_graphicsManager = modules.graphicsManager;
	_graphicsManager->CreateCamera(&_camera);
}

void Engine::Component::CameraComponent::Initialize()
{
	Component::Initialize();
	_camera->SetPerspective(_nearZ, _farZ, static_cast<float>(_size.cx) / static_cast<float>(_size.cy), _fov);
	_camera->SetPosition(0.f, 50.f, -300.f); // TODO: Get position from object.
}

void Engine::Component::CameraComponent::Attach()
{
	Component::Attach();
	_graphicsManager->RegisterCamera(_name, _camera);
}

void Engine::Component::CameraComponent::Detach()
{
	Component::Detach();
	_graphicsManager->UnregisterCamera(_name);
}

void Engine::Component::CameraComponent::Finalize()
{
	Component::Finalize();
	_camera->Finalize();
}

void Engine::Component::CameraComponent::Activate() const
{
	_graphicsManager->SetActiveCamera(_name);
}
