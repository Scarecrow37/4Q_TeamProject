#include "pch.h"
#include "RigidStaticComponent.h"

namespace Engine::Component
{
	RigidStaticComponent::RigidStaticComponent()
		: _rigidComponent{ nullptr }
		, _physicsManager{ nullptr }
	{
	}

	void RigidStaticComponent::Initialize(const Modules& modules)
	{
		Component::Initialize(modules);
		_physicsManager = modules.physicsManager;
	}

	void RigidStaticComponent::Attach()
	{
		Component::Attach();
	}
	void RigidStaticComponent::Update(float deltaTime)
	{
		Component::Update(deltaTime);
	}
	void RigidStaticComponent::FixedUpdate()
	{
		Component::FixedUpdate();
	}
	void RigidStaticComponent::Detach()
	{
		Component::Detach();
	}
	void RigidStaticComponent::Finalize()
	{
		Component::Finalize();
	}
}