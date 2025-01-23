#include "pch.h"
#include "Player.h"

Player::Player() :
	_camera(L"MainCamera", 1.f, 1000.f, { 16,9 }, 3.141592f / 4) // TODO: Remove this.
	//, _staticMesh(L"../Resources/FBX/char.fbx")
	, _skeltalMesh(L"../Resources/Player/Player.X", &_worldMatrix)
	, _animator(&_skeltalMesh)
	, _textRenderer(L"../Resources/Font/�ü�12.sfont")
{
}

void Player::Addition()
{
	Object::Addition();
	AddComponent(&_movement);
	AddComponent(&_camera);
	//AddComponent(&_staticMesh);
	AddComponent(&_skeltalMesh);
	AddComponent(&_animator);
	AddComponent(&_textRenderer);
}

void Player::PreInitialize()
{
	Object::PreInitialize();

	_movement.SetTarget(&_transform);

	const auto inputManager = Engine::Application::GetInputManager();
	Engine::Input::IMappingContext* mappingContext = nullptr;
	inputManager->GetMappingContext(L"Default", &mappingContext);
	Engine::Input::IAction* action = nullptr;
	mappingContext->GetAction(L"Move", &action);
	action->AddListener(Engine::Input::Trigger::Event::Triggered, [this](auto value)
	{
		_movement.SetDirection(value);		
	});
	action->AddListener(Engine::Input::Trigger::Event::Started, [this](auto value) { _animator.ChangeAnimation("Run"); });
	action->AddListener(Engine::Input::Trigger::Event::Completed, [this](auto value)
		{ 
			_animator.ChangeAnimation("Wait"); 
			_movement.SetDirection(Engine::Math::Vector3::Zero);
		});
}

void Player::PostInitialize()
{
	_movement.SetSpeed(100.f);	
	_textRenderer.SetPosition(100, 100.f);
	_textRenderer.SetText(L"������ �ü�ü\nHello World!");
	_textRenderer.SetFontColor(1.f, 0.f, 0.f, 1.f);

	/*_animator.SetUpSplitBone(2);
	_animator.SplitBone(0, "Dummy_root");
	_animator.SplitBone(1, "Bip01-Spine1");
	_animator.ChangeAnimation("Wait");*/
}

void Player::PostAttach()
{
	Object::PostAttach();
	_camera.Activate();	
}

void Player::PostUpdate(float deltaTime)
{	
	_worldMatrix = Engine::Math::Matrix::CreateScale(3.f) * Engine::Math::Matrix::CreateTranslation(_transform.position.x, _transform.position.y, _transform.position.z);

	Engine::Math::Vector3 tempPostion = _transform.position;
	tempPostion.z -= 300.f;
	tempPostion.y += 300.f;
	_camera.SetPosition(tempPostion);
	_camera.SetRotation(Engine::Math::Vector3(45.f, 0.f, 0.f));
}

RemotePlayer::RemotePlayer()
	: _skeltalMesh(L"../Resources/Player/Player.X", &_worldMatrix)
	, _animator(&_skeltalMesh)
{
}

void RemotePlayer::Addition()
{
	Object::Addition();
	AddComponent(&_skeltalMesh);
	AddComponent(&_animator);
}
