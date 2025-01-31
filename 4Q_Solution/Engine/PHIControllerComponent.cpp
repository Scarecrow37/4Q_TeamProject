#include "pch.h"
#include "PHIControllerComponent.h"

namespace Engine::PHI
{
	Controller::Controller()
		: controller{ nullptr }
		, collision{ nullptr }
		, controllerCollisionFlag{ 0 }
	{
		collision = new Collision<Controller>{ this };
	}

	void Controller::SetName(const char* Name)
	{
		controller->SetName(Name);
	}
	const char* Controller::GetName() const
	{
		return controller->GetName();
	}
	void Controller::ClearUserData()
	{
		controller->ClearUserData();
	}
	unsigned short Controller::Move(const Engine::Math::Vector3 displacement, float minDistance, float deltaTime)
	{
		return controllerCollisionFlag = controller->Move({ displacement.x, displacement.y,displacement.z }, minDistance, deltaTime);
	}
	void Controller::SetGravity(const Engine::Math::Vector3& gravity)
	{
		controller->SetGravity({ gravity.x,gravity.y,gravity.z });
	}
	const Engine::Math::Vector3& Controller::GetGravity() const
	{
		return controller->GetGravity();
	}
	void Controller::SetPosition(const Engine::Math::Vector3& position)
	{
		controller->SetPosition({position.x, position.y, position.z});
	}
	const Engine::Math::Vector3& Controller::GetPosition() const
	{
		return controller->GetPosition();
	}
	void Controller::SetBottomPosition(const Engine::Math::Vector3& position)
	{
		controller->SetBottomPosition({ position.x, position.y, position.z });
	}
	const Engine::Math::Vector3& Controller::GetBottomPosition() const
	{
		return controller->GetBottomPosition();
	}
	void Controller::SetStepOffset(float offset)
	{
		controller->SetStepOffset(offset);
	}
	float Controller::GetStepOffset() const
	{
		return controller->GetStepOffset();
	}
	void Controller::SetNonWalkSlide(const Engine::Physics::ControllerSlope mode)
	{
		controller->SetNonWalkSlide(static_cast<PhysicsEngineAPI::Utils::DataStructure::ControllerSlope>(mode));
	}
	Engine::Physics::ControllerSlope Controller::GetNonWalkSlide() const
	{
		return static_cast<Engine::Physics::ControllerSlope>(controller->GetNonWalkSlide());
	}
	void Controller::SetContactOffset(float offset)
	{
		controller->SetContactOffset(offset);
	}
	float Controller::GetContactOffset() const
	{
		return controller->GetContactOffset();
	}
	void Controller::SetUpDirection(const Engine::Math::Vector3& direction)
	{
		controller->SetUpDirection({ direction.x, direction.y, direction.z });
	}
	const Engine::Math::Vector3& Controller::GetUpdirection() const
	{
		return controller->GetUpdirection();
	}
	void Controller::SetSlopeLimit(float limit)
	{
		controller->SetSlopeLimit(limit);
	}
	float Controller::GetSlopeLimit() const
	{
		return controller->GetSlopeLimit();
	}
	void Controller::InvalidateCache()
	{
		controller->InvalidateCache();
	}
	void Controller::GetState(Engine::Physics::ControllerState& _state) const
	{
		PhysicsEngineAPI::Utils::DataStructure::ControllerState state{};
		controller->GetState(state);

		_state.position = state.position;
		_state.controllerCollisionFlag = state.controllerCollisionFlag;
		_state.isStandingCCT = state.isStandingCCT;
		_state.isStandingObstacle = state.isStandingObstacle;
		_state.isMovingUp = state.isMovingUp;
	}
	void Controller::SetRadius(float offset)
	{
		controller->SetRadius(offset);
	}
	float Controller::GetRadius() const
	{
		return controller->GetRadius();
	}
	void Controller::SetHeight(float offset)
	{
		controller->SetHeight(offset);
	}
	float Controller::GetHeight() const
	{
		return controller->GetHeight();
	}
	void Controller::SetClimbingMode(const Engine::Physics::CapsuleClimbingMode mode)
	{
		controller->SetClimbingMode(static_cast<PhysicsEngineAPI::Utils::DataStructure::CapsuleClimbingMode>(mode));
	}
	Engine::Physics::CapsuleClimbingMode Controller::GetClimbingMode() const
	{
		return static_cast<Engine::Physics::CapsuleClimbingMode>(controller->GetClimbingMode());
	}



	/***********************************
				Engine
	************************************/
	void Controller::Initialize()
	{
		controller->SetUserData(collision);
	}
	void Controller::Update(float deltaTime) const
	{
	}
	void Controller::Finalize()
	{
		constexpr Utility::SafeRelease releaser;

		releaser(&collision);
		releaser(&controller);
	}
	void Controller::FixedUpdate() const
	{
		collision->FixedUpdate();
	}
}