#pragma once

#include "IUserData.h"

namespace PhysicsEngineAPI
{
	class IDynamicObject;
}

namespace PhysicsEngineAPI
{
	__INTERFACE__
	EXTERN_C class PHYSICS_API IController
		: public IUserData
		, public IBase
	{
	public:
		// virtual IDynamicObject* GetActor() const = 0;
		virtual void CollisionUpdate() = 0;

		/***********************************
				Capsule Controller
		************************************/
		// return value : Short = Utils::DataStructure::ControllerCollisionFlag's Combination
		virtual unsigned short Move(
			const Utils::Math::Vector3 displacement,
			float minDistance,
			float deltaTime
			// controllerFilter,
			// obstacleContext...
		) = 0;

		virtual void SetGravity(const Utils::Math::Vector3& gravity) = 0;
		virtual Utils::Math::Vector3 GetGravity() const = 0;

		virtual void SetPosition(const Utils::Math::Vector3& position) = 0;
		virtual Utils::Math::Vector3 GetPosition() const = 0;

		virtual void SetBottomPosition(const Utils::Math::Vector3& position) = 0;
		virtual Utils::Math::Vector3 GetBottomPosition() const = 0;

		virtual void SetStepOffset(float offset) = 0;
		virtual float GetStepOffset() const = 0;

		virtual void SetNonWalkSlide(const Utils::DataStructure::ControllerSlope mode) = 0;
		virtual Utils::DataStructure::ControllerSlope GetNonWalkSlide() const = 0;

		virtual void SetContactOffset(float offset) = 0;
		virtual float GetContactOffset() const = 0;

		virtual void SetUpDirection(const Utils::Math::Vector3& direction) = 0;
		virtual Utils::Math::Vector3 GetUpdirection() const = 0;

		virtual void SetSlopeLimit(float limit) = 0;
		virtual float GetSlopeLimit() const = 0;

		virtual void InvalidateCache() = 0;

		virtual void GetState(Utils::DataStructure::ControllerState& state) const = 0;

		/***********************************
				Capsule Controller
		************************************/
		virtual void SetRadius(float offset) = 0;
		virtual float GetRadius() const = 0;

		virtual void SetHeight(float offset) = 0;
		virtual float GetHeight() const = 0;

		virtual void SetClimbingMode(const Utils::DataStructure::CapsuleClimbingMode mode) = 0;
		virtual Utils::DataStructure::CapsuleClimbingMode GetClimbingMode() const = 0;
	};
}
