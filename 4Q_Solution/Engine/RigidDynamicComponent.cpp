#include "pch.h"
#include "RigidDynamicComponent.h"

namespace Engine::Component
{
	RigidDynamicComponent::RigidDynamicComponent()
		: _rigidComponent{ nullptr }
	{
	}
	void RigidDynamicComponent::Setup(Modules modules)
	{
		Component::Setup(modules);
	}
	void RigidDynamicComponent::Initialize()
	{
		Component::Initialize();
		static_cast<Physics::RigidDynamicComponent*>(_rigidComponent)->Initialize();
	}
	void RigidDynamicComponent::Attach()
	{
		Component::Attach();
	}
	void RigidDynamicComponent::Update(float deltaTime)
	{
		Component::Update(deltaTime);
		//TODO:: Component�� ��� ���� ���� �ӽ÷�
		static_cast<Engine::Physics::RigidDynamicComponent*>(_rigidComponent)->Update(deltaTime);
		// -> Owner's Transform Update
	}
	void RigidDynamicComponent::FixedUpdate()
	{
		Component::FixedUpdate();
	}
	void RigidDynamicComponent::Detach()
	{
		Component::Detach();
	}
	void RigidDynamicComponent::Finalize()
	{
		Component::Finalize();
	}
}