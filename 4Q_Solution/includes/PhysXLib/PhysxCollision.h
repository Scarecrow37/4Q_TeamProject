#pragma once

#include "ICollision.h"
#include "PhysXUtils.h"

namespace Physics
{
	class PhysxCollisionEvent
		: virtual public physx::PxSimulationEventCallback
	{
	public:
		// PxSimulationEventCallback��(��) ���� ��ӵ�
		void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs) override;
		void onTrigger(physx::PxTriggerPair* pairs, physx::PxU32 count) override;
		void onWake(physx::PxActor** actors, physx::PxU32 count) override;
		void onSleep(physx::PxActor** actors, physx::PxU32 count) override;
		void onConstraintBreak(physx::PxConstraintInfo* constraints, physx::PxU32 count) override;
		void onAdvance(const physx::PxRigidBody* const* bodyBuffer, const physx::PxTransform* poseBuffer, const physx::PxU32 count) override;
	};
}

