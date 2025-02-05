#pragma once

class Terrain : public Engine::Object
{
public:
	explicit Terrain(std::filesystem::path&& meshPath, std::filesystem::path&& physicsPath);

	void Prepare(Engine::Content::Factory::Component* componentFactory) override;

protected:
	void DisposeComponents() override;

	void PreInitialize(const Engine::Modules& modules) override;
	void PostInitialize(const Engine::Modules& modules) override;

private:
	Engine::Component::StaticMesh* _staticMesh;
	std::filesystem::path _meshPath;
	Engine::Math::Matrix _matrix;

	Engine::Component::RigidStatic* _rigidStatc;
	std::filesystem::path _physicsPath;
};

