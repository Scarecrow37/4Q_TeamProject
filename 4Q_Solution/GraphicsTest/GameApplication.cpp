#include "pch.h"
#include "GameApplication.h"

#include "TestWorld.h"

GameApplication::GameApplication(const HINSTANCE instanceHandle) :
	Application(instanceHandle)
{
}

void GameApplication::DeclareInputActions(Engine::Input::IManager* inputManager)
{
	Engine::Input::IMappingContext* mappingContext = nullptr;
	inputManager->GetMappingContext(L"Default", &mappingContext);

	DeclareMoveAction(inputManager, mappingContext);
	DeclareCameraAction(inputManager, mappingContext);

	inputManager->SetActiveMappingContext(mappingContext);
}

void GameApplication::Register(Engine::Content::IManager* contentManager)
{
	Application::Register(contentManager);
	const auto worldFactory = contentManager->GetWorldFactory();
	worldFactory->Register<TestWorld>();

	const auto objectFactory = contentManager->GetObjectFactory();
	objectFactory->Register<Player>(L"../Resources/Test/Live.fbx", L"../Resources/Font/Gungseo12.sfont");	
	objectFactory->Register<GlobalLight>();
	objectFactory->Register<Terrain>(L"../Resources/Level/Level.fbx");
	objectFactory->Register<SkyBox>(L"../Resources/IBL/skybox.fbx");
}

void GameApplication::PrepareInitialWorld(Engine::Content::Factory::World* worldFactory)
{
	worldFactory->Clone<TestWorld>();
}

void GameApplication::DeclareMoveAction(Engine::Input::IManager* inputManager, Engine::Input::IMappingContext* mappingContext)
{
	Engine::Input::Modifier::INegative* negative = nullptr;
	Engine::Input::Modifier::ISwizzleAxis* swizzleAxis = nullptr;
	inputManager->GetModifier(&negative);
	inputManager->GetModifier(Engine::Input::Modifier::ISwizzleAxis::Type::ZXY, &swizzleAxis);

	Engine::Input::IAction* action = nullptr;
	mappingContext->GetAction(L"Move", &action);

	Engine::Input::Device::IKeyboard* keyboard = nullptr;
	inputManager->GetDevice(&keyboard);

	Engine::Input::Trigger::IDown* leftTrigger = nullptr;
	action->GetTrigger(&leftTrigger);
	Engine::Input::Component::IButtonComponent* left = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::Left, &left);
	leftTrigger->AddModifier(negative);
	leftTrigger->SetComponent(left);

	Engine::Input::Trigger::IDown* rightTrigger = nullptr;
	action->GetTrigger(&rightTrigger);
	Engine::Input::Component::IButtonComponent* right = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::Right, &right);
	rightTrigger->SetComponent(right);

	Engine::Input::Trigger::IDown* upTrigger = nullptr;
	action->GetTrigger(&upTrigger);
	Engine::Input::Component::IButtonComponent* up = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::Up, &up);
	upTrigger->AddModifier(swizzleAxis);
	upTrigger->SetComponent(up);

	Engine::Input::Trigger::IDown* downTrigger = nullptr;
	action->GetTrigger(&downTrigger);
	Engine::Input::Component::IButtonComponent* down = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::Down, &down);
	downTrigger->AddModifier(swizzleAxis);
	downTrigger->AddModifier(negative);
	downTrigger->SetComponent(down);
}

void GameApplication::DeclareCameraAction(Engine::Input::IManager* inputManager, Engine::Input::IMappingContext* mappingContext)
{
	Engine::Input::Modifier::INegative* negative = nullptr;
	Engine::Input::Modifier::ISwizzleAxis* swizzleAxis = nullptr;
	
	Engine::Input::IAction* action = nullptr;
	mappingContext->GetAction(L"Camera", &action);

	/*inputManager->GetModifier(&negative);
	inputManager->GetModifier(Engine::Input::Modifier::ISwizzleAxis::Type::YXZ, &swizzleAxis);


	Engine::Input::Device::IMouse* mouse = nullptr;
	inputManager->GetDevice(&mouse);

	Engine::Input::Component::IAxisComponent* xAxis = nullptr;
	mouse->GetComponent(Engine::Input::Device::IMouse::Axis::X, &xAxis);
	Engine::Input::Component::IAxisComponent* yAxis = nullptr;
	mouse->GetComponent(Engine::Input::Device::IMouse::Axis::Y, &yAxis);

	Engine::Input::Trigger::IDown* xTrigger = nullptr;
	action->GetTrigger(&xTrigger);
	xTrigger->SetComponent(xAxis);

	Engine::Input::Trigger::IDown* yTrigger = nullptr;
	action->GetTrigger(&yTrigger);
	yTrigger->AddModifier(swizzleAxis);
	yTrigger->SetComponent(yAxis);*/


	inputManager->GetModifier(&negative);
	inputManager->GetModifier(Engine::Input::Modifier::ISwizzleAxis::Type::YXZ, &swizzleAxis);

	Engine::Input::Device::IKeyboard* keyboard = nullptr;
	inputManager->GetDevice(&keyboard);

	Engine::Input::Trigger::IDown* leftTrigger = nullptr;
	action->GetTrigger(&leftTrigger);
	Engine::Input::Component::IButtonComponent* left = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::A, &left);
	leftTrigger->AddModifier(negative);
	leftTrigger->AddModifier(swizzleAxis);
	leftTrigger->SetComponent(left);

	Engine::Input::Trigger::IDown* rightTrigger = nullptr;
	action->GetTrigger(&rightTrigger);
	Engine::Input::Component::IButtonComponent* right = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::D, &right);
	rightTrigger->AddModifier(swizzleAxis);
	rightTrigger->SetComponent(right);

	Engine::Input::Trigger::IDown* upTrigger = nullptr;
	action->GetTrigger(&upTrigger);
	Engine::Input::Component::IButtonComponent* up = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::W, &up);
	upTrigger->AddModifier(negative);
	upTrigger->SetComponent(up);

	Engine::Input::Trigger::IDown* downTrigger = nullptr;
	action->GetTrigger(&downTrigger);
	Engine::Input::Component::IButtonComponent* down = nullptr;
	keyboard->GetComponent(Engine::Input::Device::IKeyboard::Key::S, &down);
	//downTrigger->AddModifier(swizzleAxis);
	downTrigger->SetComponent(down);
}