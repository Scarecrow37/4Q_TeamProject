#include "pch.h"
#include "RemotePlayer.h"


RemotePlayer::RemotePlayer() :
	//_camera(L"MainCamera", 1.f, 1000.f, { 16,9 }, 3.141592f / 4) // TODO: Remove this.
	_staticMesh(L"../Resources/FBX/char.fbx", &_worldMatrix)
	//_skeltalMesh(L"../Resources/Player/Player.X", &_worldMatrix)
	//, _animator(&_skeltalMesh)
{
}

void RemotePlayer::Addition()
{
	Object::Addition();
	//AddComponent(&_movement);
	//AddComponent(&_camera);
	AddComponent(&_staticMesh);
	//AddComponent(&_skeltalMesh);
	//AddComponent(&_animator);
	AddComponent(&_remoteMove);
}

void RemotePlayer::PreInitialize()
{
	Object::PreInitialize();

	//_movement.SetTarget(&_transform);
	_remoteMove.SetTarget(&_transform);

	const auto inputManager = Engine::Application::GetInputManager();
	Engine::Input::IMappingContext* mappingContext = nullptr;
	inputManager->GetMappingContext(L"Default", &mappingContext);
	Engine::Input::IAction* action = nullptr;
	mappingContext->GetAction(L"Move", &action);
	action->AddListener(Engine::Input::Trigger::Event::Triggered, [this](auto value)
		{
			//_movement.SetDirection(value);
		});
	action->AddListener(Engine::Input::Trigger::Event::Started, [this](auto value) 
		{ 
			//_animator.ChangeAnimation("Run"); 
		});
	action->AddListener(Engine::Input::Trigger::Event::Completed, [this](auto value)
		{
			//_animator.ChangeAnimation("Wait");
			//_movement.SetDirection(Engine::Math::Vector3::Zero);
		});
}

void RemotePlayer::PostInitialize()
{
	//_movement.SetSpeed(100.f);

	/*_animator.SetUpSplitBone(2);
	_animator.SplitBone(0, "Dummy_root");
	_animator.SplitBone(1, "Bip01-Spine1");*/
	//_animator.ChangeAnimation("Wait");

	_worldMatrix = Engine::Math::Matrix::CreateScale(3.f);
}

void RemotePlayer::PostAttach()
{
	Object::PostAttach();
	//_camera.Activate();
}

void RemotePlayer::PostUpdate(float deltaTime)
{
	//_worldMatrix = Engine::Math::Matrix::CreateScale(1.f); *Engine::Math::Matrix::CreateTranslation(_transform.position.x, _transform.position.y, _transform.position.z);

	//Engine::Math::Vector3 tempPostion = _transform.position;
	//tempPostion.z -= 300.f;
	//tempPostion.y += 300.f;
	//_camera.SetPosition(tempPostion);
	//_camera.SetRotation(Engine::Math::Vector3(45.f, 0.f, 0.f));
}

void RemotePlayer::SyncMove(float x, float y, float z, float speed)
{
	Engine::Math::Vector3 nextLocation(x, y, z);
	_remoteMove.SetNextLocation(nextLocation);
	
}
