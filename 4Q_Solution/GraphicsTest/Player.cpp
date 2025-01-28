#include "pch.h"
#include "Player.h"

Player::Player() :
	_camera(L"MainCamera", 1.f, 1000.f, { 16,9 }, 3.141592f / 4) // TODO: Remove this.
	//, _staticMesh(L"../Resources/FBX/char.fbx", &_worldMatrix)
	, _skeltalMesh(L"../Resources/Test/Character_ray2.fbx", &_worldMatrix)
	//, _skeltalMesh(L"../Resources/Player/Player.X", &_worldMatrix)
	, _animator(&_skeltalMesh)
	, _textRenderer(L"../Resources/Font/�ü�12.sfont")
	, _camRotation(0.f, 0.f, 0.f)
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

	Engine::Input::IAction* moveAction = nullptr;
	mappingContext->GetAction(L"Move", &moveAction);

	moveAction->AddListener(Engine::Input::Trigger::Event::Started, [this](auto value)
		{ 
			_animator.ChangeAnimation("rig|walking"); 
			_movement.SetDirection(value);
		});
	moveAction->AddListener(Engine::Input::Trigger::Event::Completed, [this](auto value)
	{ 
		_animator.ChangeAnimation("rig|Breathing"); 
		_movement.SetDirection(Engine::Math::Vector3::Zero);
	});

	Engine::Input::IAction* cameraAction = nullptr;
	mappingContext->GetAction(L"Camera", &cameraAction);
	cameraAction->AddListener(Engine::Input::Trigger::Event::Triggered, [this](Engine::Math::Vector3 value)
	{			
		//_camera.Rotate(value);
		_camRotation += value;
	});
}

void Player::PostInitialize()
{
	_movement.SetSpeed(100.f);
	_textRenderer.SetPosition(100, 100.f);
	_textRenderer.SetText(L"������ �ü�ü\nHello World!");
	_textRenderer.SetFontColor(1.f, 0.f, 0.f, 1.f);
	
	//_skeltalMesh.SetRenderLayer(0);
	/*_animator.SetUpSplitBone(2);
	_animator.SplitBone(0, "Dummy_root");
	_animator.SplitBone(1, "Bip01-Spine1");
	_animator.ChangeAnimation("Wait");*/
	
	_animator.ChangeAnimation("rig|Breathing");	

	_skeltalMesh.SetRenderLayer(1);
}

void Player::PostAttach()
{
	Object::PostAttach();
	_camera.Activate();	
}

void Player::PostUpdate(float deltaTime)
{	
	_worldMatrix = Engine::Math::Matrix::CreateScale(0.5f) * /*Engine::Math::Matrix::CreateRotationX(0.785f) * */Engine::Math::Matrix::CreateTranslation(_transform.position.x + 20, _transform.position.y + 20.f, _transform.position.z);

	Engine::Math::Vector3 tempPostion = _transform.position;
	tempPostion.z -= 150.f;
	tempPostion.y += 50.f;
	_camera.SetPosition(tempPostion);
	//_camera.SetRotation(_camRotation);

	// SetCursorPos(960, 540);
}

void Player::PostFixedUpdate()
{

}

TestPlayer::TestPlayer()
	: _staticMesh(L"../Resources/FBX/char.fbx", &_worldMatrix)
{
}

void TestPlayer::Addition()
{
	Object::Addition();
	AddComponent(&_staticMesh);
}

void TestPlayer::PostInitialize()
{
	_staticMesh.SetRenderLayer(0);
}

void TestPlayer::PostUpdate(float deltaTime)
{
	_worldMatrix = Engine::Math::Matrix::CreateScale(0.5f);
	_staticMesh.SetRenderLayer(1);
}
