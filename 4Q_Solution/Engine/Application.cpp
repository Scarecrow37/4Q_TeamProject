#include "pch.h"
#include "Application.h"

Engine::Manager::Time* Engine::Application::_timeManager = nullptr;
Engine::Manager::Window* Engine::Application::_windowManager = nullptr;
Engine::Manager::Input* Engine::Application::_inputManager = nullptr;
Engine::Manager::Graphics* Engine::Application::_graphicsManager = nullptr;

Engine::Application::Application(const HINSTANCE instanceHandle, std::wstring title, const SIZE size) :
	_instanceHandle(instanceHandle),
	_title(std::move(title)),
	_size(size),
	_cameraComponent(nullptr)
{
}

void Engine::Application::Begin()
{
	InitializeManagers();
	DeclareInputActions(_inputManager);
	CreateContents();
	InitializeContents();
}

void Engine::Application::InitializeManagers() const
{
	CreateTimeManager(&_timeManager);
	_timeManager->Initialize();

	CreateWindowManager(&_windowManager);
	_windowManager->Initialize(_instanceHandle, _title.c_str(), _size);

	CreateInputManager(&_inputManager);
	_inputManager->Initialize(_windowManager->GetHandle());

	CreateGraphicsManager(&_graphicsManager);
	_graphicsManager->Initialize(_windowManager->GetHandle(), L"../Shaders/", _size, false, 1);
}

void Engine::Application::DeclareInputActions(Manager::IInput* inputManager)
{

}

void Engine::Application::CreateContents()
{
	// TODO: World / Object / Component Manager Create;
	_cameraComponent = new Component::CameraComponent(L"MainCamera", 1.f, 1000.f, _size, 3.141592f / 4);
}

void Engine::Application::InitializeContents()
{
	// TODO: WOC Manager Initialize;
	_cameraComponent->Initialize(); // TODO: Remove this.
	_cameraComponent->Attach();
	_cameraComponent->Activate(); // TODO: Remove this.
}

void Engine::Application::Run(const int showCommand)
{
	_windowManager->Show(showCommand);
	_windowManager->Update();
	_windowManager->SetCursorDefault();

	MSG message = {};
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, nullptr, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			const float metaTime = _timeManager->GetDeltaMetaTime();
			const float deltaTime = _timeManager->GetDeltaTime();

			_timeManager->Tick();
			_inputManager->Update(metaTime);
			_graphicsManager->Update(deltaTime);

			_drive.Update(deltaTime);
			// TODO: Alarm Timer for Fixed Update

			_cameraComponent->Update(deltaTime); // TODO: Remove this.

			_graphicsManager->Render();
			_inputManager->Reset();
		}
	}
}

void Engine::Application::End()
{
	FinalizeContents();
	DeleteContents();
	FinalizeManagers();
}

void Engine::Application::FinalizeContents()
{
	// TODO: WOC Manager Finalize;

	_cameraComponent->Finalize(); // TODO: Remove this.
}

void Engine::Application::DeleteContents()
{
	// TODO: WOC Manager Delete;

	constexpr Utility::SafeDelete deleter;
	deleter(&_cameraComponent);
}

void Engine::Application::FinalizeManagers() const
{
	constexpr Utility::SafeDelete deleter;

	_graphicsManager->Finalize();
	deleter(&_graphicsManager);
	_inputManager->Finalize();
	deleter(&_inputManager);
	_windowManager->Finalize();
	deleter(&_windowManager);
	_timeManager->Finalize();
	deleter(&_timeManager);
}

Engine::Manager::ITime* Engine::Application::GetTimeManager()
{
	return _timeManager;
}

Engine::Manager::IInput* Engine::Application::GetInputManager()
{
	return _inputManager;
}

Engine::Manager::IGraphics* Engine::Application::GetGraphicsManager()
{
	return _graphicsManager;
}

void Engine::Application::CreateTimeManager(Manager::Time** timeManager)
{
	constexpr Utility::ThrowIfFailed thrower;
	if (timeManager == nullptr) thrower(E_INVALIDARG);
	Manager::Time* manager = new Manager::Time();
	if (manager == nullptr) thrower(E_OUTOFMEMORY);
	*timeManager = manager;
}

void Engine::Application::CreateWindowManager(Manager::Window** windowManager)
{
	constexpr Utility::ThrowIfFailed thrower;
	if (windowManager == nullptr) thrower(E_INVALIDARG);
	Manager::Window* manager = new Manager::Window();
	if (manager == nullptr) thrower(E_OUTOFMEMORY);
	*windowManager = manager;
}

void Engine::Application::CreateInputManager(Manager::Input** inputManager)
{
	constexpr Utility::ThrowIfFailed thrower;
	if (inputManager == nullptr) thrower(E_INVALIDARG);
	Manager::Input* manager = new Manager::Input();
	if (manager == nullptr) thrower(E_OUTOFMEMORY);
	*inputManager = manager;
}

void Engine::Application::CreateGraphicsManager(Manager::Graphics** graphicsManager)
{
	constexpr Utility::ThrowIfFailed thrower;
	if (graphicsManager == nullptr) thrower(E_INVALIDARG);
	Manager::Graphics* manager = new Manager::Graphics();
	if (manager == nullptr) thrower(E_OUTOFMEMORY);
	*graphicsManager = manager;
}