#include "pch.h"
#include "PHIRigidComponent.h"

namespace Engine::PHI
{
	/********************************
				Rigid Object
	*********************************/

	RigidComponent::RigidComponent()
		: object{ nullptr }
		, shape{ nullptr }
		, geometry{ nullptr }
		, material{ nullptr }
	{
	}

	void RigidComponent::SetTranslate(const Math::Vector3& position)
	{
		object->SetTranslate({ position.x, position.y, position.z });
	}
	const Math::Vector3 RigidComponent::GetTranslate() const
	{
		return Math::Vector3(object->GetTranslate());
	}
	void RigidComponent::SetRotation(const Math::Quaternion& Rotation)
	{
		object->SetRotation({ Rotation.x, Rotation.y, Rotation.z, Rotation.w });
	}
	const Math::Quaternion RigidComponent::GetRotation() const
	{
		return Math::Quaternion(object->GetRotation());
	}
	void RigidComponent::SetTransform(const Transform& transform)
	{
		object->SetTransform({ { transform.position.x, transform.position.y, transform.position.z },
			{ transform.rotation.x, transform.rotation.y, transform.rotation.z, transform.rotation.w} });
	}
	const Transform RigidComponent::GetTransform() const
	{
		auto transform = object->GetTransform();
		return Transform({ transform.position, transform.rotation, {1,1,1} });
	}
	void* RigidComponent::GetPhysicsObject() const
	{
		return object;
	}


	/********************************
				   Shape
	*********************************/
	void RigidComponent::SetFlag(Physics::CollisionType flag, bool value)
	{
		shape->SetFlag(static_cast<PhysicsEngineAPI::Utils::DataStructure::CollisionType>(flag), value);
	}
	void RigidComponent::SetLocalTranslate(const Math::Vector3& LocalTranslate)
	{
		shape->SetLocalTranslate({ LocalTranslate.x, LocalTranslate.y, LocalTranslate.z });
	}
	const Math::Vector3 RigidComponent::GetLocalTranslate() const
	{
		return Math::Vector3(shape->GetLocalTranslate());
	}
	void RigidComponent::SetLocalRotation(const Math::Quaternion& LocalRotation)
	{
		shape->SetLocalRotation({ LocalRotation.x, LocalRotation.y, LocalRotation.z, LocalRotation.w });
	}
	const Math::Quaternion RigidComponent::GetLocalRotation() const
	{
		return Math::Quaternion(shape->GetLocalRotation());
	}
	void RigidComponent::SetLocalTransform(const Transform& LocalTransform)
	{
		shape->SetLocalTransform({ { LocalTransform.position.x, LocalTransform.position.y, LocalTransform.position.z },
			{ LocalTransform.rotation.x, LocalTransform.rotation.y, LocalTransform.rotation.z, LocalTransform.rotation.w} });
	}
	const Transform RigidComponent::GetLocalTransform() const
	{
		auto transform = shape->GetLocalTransform();
		return Transform({ transform.position, transform.rotation, {1,1,1} });
	}
	void RigidComponent::SetScale(const Math::Vector3& Scale)
	{
		shape->SetScale({ Scale.x, Scale.y, Scale.z });
	}
	const Math::Vector3 RigidComponent::GetScale() const
	{
		return Math::Vector3(shape->GetScale());
	}

	void* RigidComponent::GetShape() const
	{
		return shape;
	}

	/********************************
				Geometry
	*********************************/
	void RigidComponent::SetType(Physics::GeometryShape type)
	{
		geometry->SetType(static_cast<PhysicsEngineAPI::Utils::DataStructure::GeometryShape>(type));
	}
	Physics::GeometryShape RigidComponent::GetType()
	{
		return static_cast<Physics::GeometryShape>(geometry->GetType());
	}
	void* RigidComponent::GetGeometry() const
	{
		return geometry;
	}


	/********************************
				Material
	*********************************/
	void* RigidComponent::GetMaterial() const
	{
		return nullptr;
	}

	/********************************
			Engine Life Cycle
	*********************************/
	void RigidComponent::Initialize()
	{
		// TODO
		// TODO
		// TODO
		// TODO
		// TODO
		// TODO
	}
	void RigidComponent::Update(float deltaTime) const
	{
		// TODO
		// TODO
		// TODO
		// TODO
		// TODO
		// TODO
	}
	void RigidComponent::Finalize()
	{
		constexpr Utility::SafeRelease releaser;

		releaser(&object);
		releaser(&shape);
		releaser(&geometry);
		releaser(&material);
	}
}
