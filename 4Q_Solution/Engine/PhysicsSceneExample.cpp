#include "pch.h"
#include "PhysicsSceneExample.h"

void PhysicsSceneExample::Prepare(Engine::Content::Factory::Object* objectFactory)
{
}

void PhysicsSceneExample::PreInitialize(const Engine::Modules& moduels)
{
	// ���� �� ����� - �߷°� ���� �ʿ�
	Engine::Physics::SceneDesc mainSceneDesc{ {0.f,-9.8f,0.f},0 };
	Engine::Application::GetPhysicsManager()->CreateScene(&mainScene, mainSceneDesc);
	Engine::Application::GetPhysicsManager()->AttachUpdateSecne(mainScene);

	// ī�޶� �� ����� - �߷°�X
	Engine::Physics::SceneDesc cameraSceneDesc{ {0.f,0.f,0.f},0 };
	Engine::Application::GetPhysicsManager()->CreateCameraScene(&cameraScene, cameraSceneDesc);
}

void PhysicsSceneExample::PreUpdate(float deltaTime)
{

}

void PhysicsSceneExample::PostUpdate(float deltaTime)
{
	// �Ƹ� Application���� �߰������� �ܲ��� ���� �ؾ� �ҵ� �ܲ������δ� �� ��ġ�� ����
	// ������Ʈ���� �������� ������ ������Ʈ
	// ī�޶� �� ������Ʈ(ó���� �׷��ְ� �������� Ȯ���� �ϱ� ������ ���� Attach�� ������ �ʰ� �Ѵ�.)
	Engine::Application::GetPhysicsManager()->UpdateSecne(cameraScene, deltaTime);

	// �Ƹ� Application���� �߰������� �ܲ��� ���� �ؾ� �ҵ� �ܲ������δ� �� ��ġ�� ����
	// ī�޶� ��
	Engine::Application::GetPhysicsManager()->FetchSecne(cameraScene, true);


	Engine::Physics::AdditionalQueryData OverlapInfo;
	Engine::Physics::GeometryDesc geometryDesc;
	geometryDesc.type = Engine::Physics::GeometryShape::Frustum;
	//	Frustum data�� ī�޶� ������
	//	data.x : fovY
	//	data.y : aspect
	//	data.z : nearPlane
	//	data.w : farPlane
	geometryDesc.data;
	Engine::Physics::VerticesMeshDesc verticesMeshDesc;
	Engine::Transform transform; // GetCameraTransform �ؼ� �־������
	cameraScene->Overlap(OverlapInfo, "Camera", geometryDesc, verticesMeshDesc, transform);

	// ī�޶� �ø� �� ������Ʈ���� ������
	// ������ Component::Rigid->_boundBox�� �������� �ϴ� Get,Get�ؼ� Object�� �����ʹ� ���� ���� �� ��
	OverlapInfo.UserDatas;
}
