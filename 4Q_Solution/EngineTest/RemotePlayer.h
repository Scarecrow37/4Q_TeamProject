#pragma once
#include "RemoteMoveComponent.h"

class RemotePlayer : public Engine::Object
{
public:
	RemotePlayer();
protected:
	void Addition() override;
	void PreInitialize() override;
	void PostInitialize() override;
	void PostAttach() override;
	void PostUpdate(float deltaTime) override;

	void SyncMove(float x, float y, float z, float speed);

private:
	//Engine::Component::MovementComponent _movement;
	//Engine::Component::CameraComponent _camera;
	Engine::Component::StaticMesh _staticMesh;
	//Engine::Component::SkeletalMesh _skeltalMesh;
	//Engine::Component::Animator _animator;
	Engine::Math::Matrix _worldMatrix;

	RemoteMoveComponent _remoteMove;
};

