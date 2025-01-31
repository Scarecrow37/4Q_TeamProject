#pragma once

#include "PHICollision.h"

namespace Engine::PHI
{
	class RigidStaticComponent final
		: public Physics::RigidStaticComponent
	{
	public:
		RigidStaticComponent();

		/********************************
					Rigid Object
		*********************************/
		void SetTranslate(const Math::Vector3& position) override;
		const Math::Vector3 GetTranslate() const override;
		void SetRotation(const Math::Quaternion& Rotation) override;
		const Math::Quaternion GetRotation() const override;
		void SetTransform(const Transform& transform) override;
		const Transform GetTransform() const override;


		/********************************
					   Shape
		*********************************/
		void SetFlag(Physics::CollisionType flag, bool value) override;
		void SetLocalTranslate(const Math::Vector3& LocalTranslate) override;
		const Math::Vector3 GetLocalTranslate() const override;
		void SetLocalRotation(const Math::Quaternion& LocalRotation) override;
		const Math::Quaternion GetLocalRotation() const override;
		void SetLocalTransform(const Transform& LocalTransform) override;
		const Transform GetLocalTransform() const override;
		void SetScale(const Math::Vector3& Scale) override;
		const Math::Vector3 GetScale() const override;

		
		/********************************
					Geometry
		*********************************/
		void SetType(Physics::GeometryShape type) override;
		Physics::GeometryShape GetType() override;


		/********************************
					Collision
		*********************************/
		void BindCollision(const Physics::CallBackTrigger& callback, Physics::TriggerType type) override;
		void BindCollision(const Physics::CallBackContact& callback, Physics::ContactType type) override;



		/********************************
				Engine Life Cycle
		*********************************/
		void Initialize() override;
		void Update(float deltaTime) const override;
		void Finalize() override;

	protected:
		PhysicsEngineAPI::IStaticObject* object;
		PhysicsEngineAPI::IShape* shape;
		PhysicsEngineAPI::IGeometry* geometry;
		PhysicsEngineAPI::IMaterial* material;

	private:
		Collision<RigidStaticComponent>* collision;

	private:
		friend class Manager;
		friend class Scene;

	};
}


