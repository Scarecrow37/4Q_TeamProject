#include "pch.h"
#include "PhysicsObjectExample.h"

PhysicsObjectExample::PhysicsObjectExample()
{
}

void PhysicsObjectExample::Prepare(Engine::Content::Factory::Component* componentFactory)
{
	_rigid			= componentFactory->Clone<Engine::Component::Rigid>();
	_rigidStatic	= componentFactory->Clone<Engine::Component::RigidStatic>();
	_rigidDynamic	= componentFactory->Clone<Engine::Component::RigidDynamic>();
	_rigidKinematic = componentFactory->Clone<Engine::Component::RigidKinematic>();
}

void PhysicsObjectExample::DisposeComponents()
{
	_rigid->Dispose();
	_rigidStatic->Dispose();
	_rigidDynamic->Dispose();
	_rigidKinematic->Dispose();
}

void PhysicsObjectExample::PreInitialize(const Engine::Modules& modules)
{
	Object::PreInitialize(modules);

	auto PhysicsManager = Engine::Application::GetPhysicsManager();

	// Rigid, Static, Kinematic�� ���� //&& �κи� �Ű�Ἥ �ٲ��ָ� ��
	// Example Dynamic
	{
		// 1. Description �����
		Engine::Physics::RigidComponentDesc desc;
		desc.rigidType = Engine::Physics::RigidBodyType::Dynamic;						//&&
		desc.shapeDesc.geometryDesc.type = Engine::Physics::GeometryShape::Capsule;
		desc.shapeDesc.geometryDesc.data = { 100.f, 100.f, 100.f };
		desc.shapeDesc.isExclusive = true;
		desc.shapeDesc.materialDesc.data = { 0.5f,0.5f,0.f };
		// 2. Transform �����
		Engine::Transform transform{};
		transform.position = { 0,0,0 };
		// 3. ��ü ����
		PhysicsManager->CreateDynamic(&_rigidDynamic->_rigidbody, desc, transform, 1);	//&&
		// 4. ���� �ֱ�
		// �ӽ÷� GetScene�� ��   ->   World�� MainScene�����ͼ� �ʱ�ȭ
		PhysicsManager->GetScene(0)->AddActor(_rigidDynamic->_rigidbody);

		// Pre5. �߰������� �ٿ�� �ڽ��� ���� ���� ����(���̳��͵� �̰����� ���� ��� ��...)
		PhysicsManager->CreateStaticBoundBoxActor(&_rigidDynamic->_boundBox);
		// 5. ī�޶� ���� �߰� :GetScene(1): ī�޶� ���̶�� ����
		PhysicsManager->GetScene(1)->AddActor(_rigidDynamic->_boundBox);
	}
}

void PhysicsObjectExample::PreUpdate(float deltaTime)
{
	// ��Ʈ ��ũ�� ���� �޵� �� �޵� GetTransform();���� ��ġ ����ȭ
	// Response
	_rigidDynamic->_rigidbody->GetTransform();

	// Collision Check
	// �� �κ��� ���� Transform�� ���� ��� �޾ƿ��� �������� ���� �޶�����
	// Component�� ������Ʈ �κе� �ٲ����
}

void PhysicsObjectExample::PostUpdate(float deltaTime)
{
	// �����̴� ��ü�� ��쿡�� ����
	_rigidDynamic->_boundBox->SetTransform(_rigidDynamic->_rigidbody->GetTransform());
}

void PhysicsObjectExample::PreFixedUpdate()
{

}

void PhysicsObjectExample::PostFixedUpdate()
{
}

void PhysicsObjectExample::SceneQueryExample()
{
	auto PhysicsManager = Engine::Application::GetPhysicsManager();

	// Raycast
	{
		Engine::Physics::AdditionalQueryData raycastInfo;
		/*
			Param	
				AdditionalQueryData	raycastInfo : �ݹ� ���� raycast����
				Vector3	startPosition			: ���� ���� ��ġ
				Vector3	direction				: ����
				float	distance				: �ִ� �Ÿ�
		*/
		PhysicsManager->GetScene(0)->Raycast(raycastInfo, { 0,1000,0 }, { 0,-1,0 }, 5000.f);
	}

	// Overlap
	{
		Engine::Physics::AdditionalQueryData OverlapInfo;
		Engine::Physics::GeometryDesc geometryDesc;
		geometryDesc.type = Engine::Physics::GeometryShape::Frustum;
		Engine::Physics::VerticesMeshDesc verticesMeshDesc;
		Engine::Transform transform;
		/*
			Param
				Engine::Physics::QueryData&					overlapInfo			: �ݹ���� ����������
				const std::string&							name				: ���� �̸�
				const Engine::Physics::GeometryDesc&		geometryDesc		: ���� ��ũ����
				const Engine::Physics::VerticesMeshDesc&	verticesMeshDesc	: ���� ������ ��� �߰� ��ũ����
																				, �⺻������ ��� �׳� �� ������ �־��ָ� ��
				const Engine::Transform&					transform			: ��ġ, ȸ������

			Brief
				: ���� �̹� ������ ������ ������ �̸����� ���� �� �� ����.
				geometryDesc, verticesMeshDesc�� ��� �̸����� ã�� ���� ��� ������ �������� �������.
		*/
		PhysicsManager->AddGeomtry("Frustum", geometryDesc, verticesMeshDesc);
		PhysicsManager->GetScene(0)->Overlap(OverlapInfo, "Frustum", transform);
	}

	// Sweep
	{
		Engine::Physics::AdditionalQueryData OverlapInfo;
		Engine::Physics::GeometryDesc geometryDesc;
		geometryDesc.type = Engine::Physics::GeometryShape::Frustum;
		Engine::Physics::VerticesMeshDesc verticesMeshDesc;
		Engine::Transform transform;
		Engine::Math::Vector3 direction;
		float distance = 1000.f;
		/*
			Param
				Engine::Physics::AdditionalQueryData&		sweepInfo				: �ݹ���� ����������
				const std::string&							name 					: ���� �̸�
				const Engine::Physics::GeometryDesc&		geometryDesc 			: ���� ��ũ����
				const Engine::Physics::VerticesMeshDesc&	verticesMeshDesc 		: ���� ������ ��� �߰� ��ũ����
																					, �⺻������ ��� �׳� �� ������ �־��ָ� ��
				const Engine::Transform&					transform 				: ��ġ, ȸ������
				const Engine::Math::Vector3&				direction				: ����
				float										distance				: �Ÿ�
		
			Brief
				: ���� �̹� ������ ������ ������ �̸����� ���� �� �� ����.
				geometryDesc, verticesMeshDesc�� ��� �̸����� ã�� ���� ��� ������ �������� �������.
		*/
		PhysicsManager->AddGeomtry("Frustum", geometryDesc, verticesMeshDesc);
		PhysicsManager->GetScene(0)->Sweep(OverlapInfo, "Frustum", transform, direction, distance);
	}
	// ���� �߰� �ɼ�
	{
		Engine::Physics::GeometryDesc geometryDesc;
		geometryDesc.type = Engine::Physics::GeometryShape::Frustum;
		Engine::Physics::VerticesMeshDesc verticesMeshDesc;
		/**
		 * @brief	����µ� �����ϸ� true,
					���� �Ǵ� �̹� �ִ� �̸��� �����̸� false
		 */
		PhysicsManager->AddGeomtry("Frustum", geometryDesc, verticesMeshDesc);
	}

}
