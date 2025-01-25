#pragma once

namespace Engine::Physics
{
	struct IRigidComponent : Component
	{
		/********************************
					 Component
		*********************************/
		virtual void SetName(const char* Name) = 0;
		virtual const char* GetName() const = 0;

		/********************************
					Rigid Object
		*********************************/
		virtual void	SetTranslate(const Engine::Math::Vector3& position) = 0;
		virtual const	Engine::Math::Vector3 GetTranslate() const = 0;

		virtual void	SetRotation(const Engine::Math::Vector4& Rotation) = 0;
		virtual const	Engine::Math::Vector4 GetRotation() const = 0;

		virtual void	SetTransform(const Transform& transform) = 0;
		virtual const	Transform GetTransform() const = 0;

		/********************************
					   Shape
		*********************************/
		virtual void SetFlag(CollisionType flag, bool value) = 0;

		virtual void SetLocalTranslate(const Engine::Math::Vector3& LocalTranslate) = 0;
		virtual const Engine::Math::Vector3 GetLocalTranslate()const = 0;

		virtual void SetLocalRotation(const Engine::Math::Vector4& LocalRotation) = 0;
		virtual const Engine::Math::Vector4 GetLocalRotation() const = 0;

		virtual void SetLocalTransform(const Engine::Transform& LocalTransform) = 0;
		virtual const Engine::Transform GetLocalTransform() const = 0;

		virtual void SetScale(const Engine::Math::Vector3& Scale) = 0;
		virtual const Engine::Math::Vector3 GetScale() const = 0;

		/********************************
					Geometry
		*********************************/
		virtual GeometryShape SetType(GeometryShape type) = 0;
		virtual void GetType(GeometryShape type) = 0;
	};


	/**
	 * @brief	: Physics�� ��κ��� ����� ���� Component�� Client���� ����� ��κ��� ��Ȱ�� �Ѵ�.
				  Physics Object, Physcis Shape, Physics Geometry, Physics Material�� �� ��� �ִ�.
	 */
	struct RigidComponent : IRigidComponent
	{
		virtual void Initialize() = 0;
		virtual void Update(float deltaTime) const = 0;
		virtual void Finalize() = 0;

		/********************************
					   Rigid
		*********************************/
		virtual bool	AttachShape(Shape* shape) = 0;
		virtual bool	DetachShape(Shape* shape) = 0;


		///********************************
		//			Collision
		//*********************************/
		//virtual void SetUserData(ICollision* UserData) = 0;
		//virtual const ICollision* GetUserData() const = 0;
	};
}
