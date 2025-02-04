#pragma once

namespace Engine::Physics
{
	struct IRigidKinematicComponent : IRigidDynamicComponent
	{

	};

	struct RigidKinematicComponent : IRigidKinematicComponent
	{
		virtual void Initialize(Engine::Component::Component* Owner) = 0;
		virtual void Update(float deltaTime) const = 0;
		virtual void FixedUpdate() const = 0;
		virtual void Finalize() = 0;

		/********************************
					   Rigid
		*********************************/
		//virtual bool	AttachShape(Shape* shape) = 0;
		//virtual bool	DetachShape(Shape* shape) = 0;


		///********************************
		//			Collision
		//*********************************/
		//virtual void SetUserData(ICollision* UserData) = 0;
		//virtual const ICollision* GetUserData() const = 0;

		/********************************
					Shape
		*********************************/


		/********************************
					Geometry
		*********************************/
		virtual void SetType(GeometryShape type) = 0;


		/********************************
					Material
		*********************************/
	};
}
