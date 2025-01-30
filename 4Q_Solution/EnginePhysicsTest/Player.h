#pragma once

class Player : public Engine::Object
{
public:
	Player();
protected:
	void Addition() override;
	void PreInitialize() override;
	void PostInitialize() override;
	void PostAttach() override;
	void PostUpdate(float deltaTime) override;

	void PostFixedUpdate() override;

	void OnHit(Engine::Physics::ContactEvent info);
private:
	Engine::Component::MovementComponent _movement;
	Engine::Component::CameraComponent _camera;
	//Engine::Component::StaticMesh _staticMesh;
	Engine::Component::SkeletalMesh _skeltalMesh;
	Engine::Component::Animator _animator;
	Engine::Math::Matrix _worldMatrix;
	Engine::Component::TextRenderer _textRenderer;
	Engine::Component::SynchronizeComponent _sync;

	Engine::Component::RigidDynamicComponent _rigid;

	Engine::Component::RigidDynamicComponent _tempOtherRigid;
};

//class RemotePlayer : public Engine::Object
//{
//public:
//	RemotePlayer();
//protected:
//	void Addition() override;
//
//private:
//	Engine::Component::SkeletalMesh _skeltalMesh;
//	Engine::Component::Animator _animator;
//	Engine::Math::Matrix _worldMatrix;
//};