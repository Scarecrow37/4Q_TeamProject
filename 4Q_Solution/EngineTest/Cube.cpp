#include "pch.h"
#include "Cube.h"

Cube::Cube(std::filesystem::path&& meshPath) :
	_meshPath(std::forward<std::filesystem::path>(meshPath)),
	_staticMesh(nullptr),
	_sync(nullptr)
{
}

void Cube::Prepare(Engine::Content::Factory::Component* componentFactory)
{
	_staticMesh = componentFactory->Clone<Engine::Component::StaticMesh>(this);
	_sync = componentFactory->Clone<Engine::Component::Synchronize>(this);
}



void Cube::DisposeComponents()
{
	_staticMesh->Dispose();
	_sync->Dispose();
}

void Cube::PreInitialize(const Engine::Modules& modules)
{
	Object::PreInitialize(modules);

	_staticMesh->SetFilePath(_meshPath);
	_staticMesh->SetMatrix(&_worldMatrix);

	_sync->AddCallback((short)PacketID::DataObject, &Cube::SyncLocation, this);
}

void Cube::PostInitialize(const Engine::Modules& modules)
{
}

void Cube::PostAttach()
{
}

void Cube::PostUpdate(float deltaTime)
{
	Object::PostUpdate(deltaTime);

	_worldMatrix = Engine::Math::Matrix::CreateScale(0.1f) * Engine::Math::Matrix::CreateTranslation(_transform.position.x, _transform.position.y, _transform.position.z);
	//assert(_transform.position != Engine::Math::Vector3::Zero);
}

void Cube::PostFixedUpdate()
{
}

void Cube::SyncLocation(const ConnectMsg::SyncObject* msg)
{
	const auto& position = msg->position();
	const auto& rotation = msg->rotation();
	const auto& scale = msg->scale();
	float x = *(position.begin());
	float y = *(position.begin() + 1);
	float z = *(position.begin() + 2);
	_transform.position = Engine::Math::Vector3(x, y, z);
	printf("Object Location Sync Complete Num : %d. Position : %f, %f, %f\n", _sync->GetSerialNumber(), x, y, z);
}

void Cube::SetSerialNumber(int num)
{
	_sync->SetSerialNumber(num);
}
