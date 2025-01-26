#include "pch.h"
#include "PhysXShape.h"

namespace PhysicsEngineAPI
{
	PhysXShape::PhysXShape(physx::PxShape* _shape)
		: shape{ _shape }
	{}
	PhysXShape::~PhysXShape() { Release(); }
	void PhysXShape::Release() { SAFE_RELEASE(shape); }

	void PhysXShape::SetFlag(Utils::DataStructure::CollisionType flag, bool value)
	{
		switch (flag)
		{
		case Utils::DataStructure::CollisionType::Collision:
			shape->setFlag(physx::PxShapeFlag::eSIMULATION_SHAPE, value);
			break;
		case Utils::DataStructure::CollisionType::Trigger:
			shape->setFlag(physx::PxShapeFlag::eTRIGGER_SHAPE, value);
			break;
		case Utils::DataStructure::CollisionType::Scene_Query:
			shape->setFlag(physx::PxShapeFlag::eSCENE_QUERY_SHAPE, value);
			break;
		default:
			break;
		}
	}

	void PhysXShape::SetLocalTranslate(const Utils::Math::Vector3& position)
	{
		auto transform = shape->getLocalPose();
		transform.p = { position.x, position.y, position.z };
		shape->setLocalPose(transform);
	}
	const Utils::Math::Vector3 PhysXShape::GetLocalTranslate() const
	{
		auto transform = shape->getLocalPose();
		return Utils::Math::Vector3({ transform.p.x, transform.p.y, transform.p.z });
	}
	void PhysXShape::SetLocalRotation(const Utils::Math::Vector4& Rotation)
	{
		auto transform = shape->getLocalPose();
		transform.q = { Rotation.x, Rotation.y, Rotation.z, Rotation.w };
		shape->setLocalPose(transform);
	}
	const Utils::Math::Vector4 PhysXShape::GetLocalRotation() const
	{
		auto transform = shape->getLocalPose();
		return Utils::Math::Vector4({ transform.q.x, transform.q.y, transform.q.z, transform.q.w });
	}
	void PhysXShape::SetLocalTransform(const Utils::Math::Transform& _transform)
	{
		const physx::PxTransform transform
		{
			{ _transform.position.x, _transform.position.y, _transform.position.z }
			, {_transform.rotation.x, _transform.rotation.y, _transform.rotation.z, _transform.rotation.w}
		};
		shape->setLocalPose(transform);
	}
	const Utils::Math::Transform PhysXShape::GetLocalTransform() const
	{
		auto transform = shape->getLocalPose();
		return Utils::Math::Transform({ transform.p.x, transform.p.y, transform.p.z }, { transform.q.x, transform.q.y, transform.q.z, transform.q.w });
	}

	void PhysXShape::SetScale(const Utils::Math::Vector3& position)
	{
		/*
			Dynamic Actor���� ��ȣ�ۿ�:
				Dynamic Actor�� ����� Shape�� ũ�⸦ �����ϸ� �浹 ����� ���ŵǹǷ�,
				���� �Ŀ��� Actor�� �ٽ� "Wake up"���Ѿ� �մϴ�:
		*/
		//TODO: Scale
		// Geometry�� �⺻ ������ �ٽ� �����
		// Triangle/Convex�� ������ ���� ���� 
		
	}

	const Utils::Math::Vector3 PhysXShape::GetScale() const
	{
		return scale;
	}

	void PhysXShape::SetName(const char* name)
	{
		shape->setName(name);
	}

	const char* PhysXShape::GetName() const
	{
		return shape->getName();
	}

	void PhysXShape::SetUserData(ICollision* _userData)
	{
		shape->userData = _userData;
	}

	const ICollision* PhysXShape::GetUserData() const
	{
		return static_cast<ICollision*>(shape->userData);
	}

	void PhysXShape::ClearUserData()
	{
		shape->userData = nullptr;
	}
}
