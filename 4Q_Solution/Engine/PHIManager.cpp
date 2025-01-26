#include "pch.h"
#include "PHIManager.h"


namespace Engine::PHI
{
	HRESULT BoolToHRESULT(bool isSuccess)
	{
		return isSuccess ? S_OK : S_FALSE;
	}

	Manager::Manager()
		: system{ nullptr }
	{}

	void Manager::Initialize(Physics::PhysicsType physicsType)
	{
		constexpr Utility::ThrowIfFailed thrower;

		thrower(BoolToHRESULT(PhysicsEngineAPI::CreateSystem(&system, static_cast<PhysicsEngineAPI::IPhysicsSystem::PhysicsType>(physicsType))));
		thrower(BoolToHRESULT(system->CreatePhysics()));


		//TODO: go to Load? ���������� ���°� ���� ��� �ε������� ã�ƾ� �ҵ�?
		//PhysicsEngineAPI::Utils::Description::SceneDesc sceneDesc;
		//sceneDesc.gravity = { 0.f, 9.8f, 0.f };
		//thrower(BoolToHRESULT(system->CreateScene(&scene, sceneDesc)));

	}

	void Manager::WorldInitialize()
	{

	}

	void Manager::Update(float deltaTime) const
	{

	}

	void Manager::Finalize()
	{
		constexpr Utility::SafeRelease releaser;

		//releaser(&scene);
		releaser(&system);
	}
}

