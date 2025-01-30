#pragma once


class PhysicsSceneExample 
	: public Engine::World
{
public:
	PhysicsSceneExample() = default;

	void Prepare(Engine::Content::Factory::Object* objectFactory) override;
protected:
	void PreInitialize(const Engine::Modules& moduels) override;
	void PreUpdate(float deltaTime) override;
	void PostUpdate(float deltaTime) override;

private:
	// �Ѵ� Get �����ϸ� ����
	Engine::Physics::IScene* mainScene;
	Engine::Physics::IScene* cameraScene;

	bool _loadComplete = false;
};

