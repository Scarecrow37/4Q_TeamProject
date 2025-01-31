 #pragma once
#include "Player.h"
#include "GlobalLight.h"
#include "Terrain.h"
#include "RemotePlayer.h"

class ConnectMsg::EnterAccept;

class TestWorld : public Engine::World
{
public:
	void EnterAccept(const ConnectMsg::EnterAccept* msg);
	void SyncOtherPlayer(const ConnectMsg::SyncPlayer* msg);
protected:
	void Addition() override;

	void PreInitialize() override;
	void PreUpdate(float deltaTime) override;
	void PostFixedUpdate() override;

private:
	Player _player;
	RemotePlayer _remote;
	GlobalLight _light;
	Terrain _terrain;
	Engine::Physics::IScene* testPhysicsScene;

	int playerSerialNum = 0;
};

#include <PxPhysicsAPI.h>

using namespace physx;

PxPhysics* physics;
PxScene* scene;
PxControllerManager* controllerManager;
PxCapsuleController* capsuleController;

void CreateCharacterController() {
    // ĳ���� ��Ʈ�ѷ� �Ŵ��� ����
    controllerManager = PxCreateControllerManager(*scene);

    // ĸ�� ��Ʈ�ѷ� ����
    PxCapsuleControllerDesc capsuleDesc;
    capsuleDesc.height = 1.75f;
    capsuleDesc.radius = 0.3f;
    capsuleDesc.material = physics->createMaterial(0.5f, 0.5f, 0.1f);
    capsuleDesc.position = PxExtendedVec3(0, 1, 0);
    capsuleDesc.stepOffset = 0.5f;

    // ��Ʈ�ѷ� ����
    capsuleController = static_cast<PxCapsuleController*>(controllerManager->createController(capsuleDesc));
}

void UpdateCharacter(float deltaTime) {
    PxControllerFilters filters;

    // �߷� ����
    PxVec3 displacement(0, -9.8f * deltaTime, 0);

    // �̵� ó��
    capsuleController->move(displacement, 0.01f, deltaTime, filters);
}