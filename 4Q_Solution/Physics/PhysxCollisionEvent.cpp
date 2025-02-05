#include "pch.h"
#include "PhysxCollisionEvent.h"
#include "ICollision.h"

using namespace physx;
namespace PhysicsEngineAPI
{
	void PhysxCollisionEvent::onContact(const PxContactPairHeader& pairHeader, const PxContactPair* pairs, PxU32 nbPairs)
	{
		if (pairHeader.flags & PxContactPairHeaderFlag::eREMOVED_ACTOR_0) 
		{
			printf("Actor 0 was removed during the collision.\n");
			return;
		}
		if (pairHeader.flags & PxContactPairHeaderFlag::eREMOVED_ACTOR_1) 
		{
			printf("Actor 1 was removed during the collision.\n");
			return;
		}



		for (PxU32 i = 0; i < nbPairs; i++) {
			const PxContactPair& pair = pairs[i];
			// Shape
			if (pair.events & PxPairFlag::eNOTIFY_TOUCH_FOUND) 
			{
				//OnCollisionEnter();
				//OnHit();
			}

			if (pair.events & PxPairFlag::eNOTIFY_TOUCH_PERSISTS) 
			{
				//OnCollision();
			}

			if (pair.events & PxPairFlag::eNOTIFY_TOUCH_LOST) 
			{
				//OnCollisionExit();
			}
		}

		//TODO: �ϴ� ���˵� �� ������ pos�� normal���� ������ ���߿� �迭�� ���� �� �ֵ��� ���� �ʿ�
		Utils::DataStructure::ContactEvent contactEvent{};
		if(nullptr != pairs[0].contactImpulses)
			contactEvent.impulse = *pairs[0].contactImpulses;
		ICollision* actor1 = static_cast<ICollision*>(pairHeader.actors[0]->userData);
		ICollision* actor2 = static_cast<ICollision*>(pairHeader.actors[1]->userData);

		// TODO: �ϴ� ���࿡ ���������Ͱ� ���� �ֶ�� �浹 �ݺ��� ���ϵ���...
		if (actor1 && actor2)
		{
			contactEvent.myCollision = actor1;
			contactEvent.otherCollision = actor2;
			actor1->OnHit(contactEvent);
			
			contactEvent.myCollision = actor2;
			contactEvent.otherCollision = actor1;
			actor2->OnHit(contactEvent);
		}
	}

	void PhysxCollisionEvent::onTrigger(PxTriggerPair* pairs, PxU32 count)
	{
		for (PxU32 i = 0; i < count; i++) {
			const PxTriggerPair& pair = pairs[i];

			if (pair.status & PxPairFlag::eNOTIFY_TOUCH_FOUND) 
			{
				//TODO: � Shape����� �浹������ üũ�ϸ� ������....		
				//pair.otherShape;
				//pair.triggerShape;

				Utils::DataStructure::TriggerEvent triggerEvent{};
				ICollision* actor1 = static_cast<ICollision*>(pair.triggerActor->userData);
				ICollision* actor2 = static_cast<ICollision*>(pair.otherActor->userData);
				
				//TODO: ����Ƽ�� ���� Event�� ���߿� ó�� �ؾ���...	
				//OnTriggerEnter();
				if (actor1 && actor2)
				{
					triggerEvent.myCollision = actor1;
					triggerEvent.otherCollision = actor2;
					actor1->OnOverlapBegin(triggerEvent);
					triggerEvent.myCollision = actor2;
					triggerEvent.otherCollision = actor1;
					actor2->OnOverlapBegin(triggerEvent);
				}
			}

			if (pair.status & PxPairFlag::eNOTIFY_TOUCH_PERSISTS) 
			{
				//OnTrigger();
			}

			if (pair.status & PxPairFlag::eNOTIFY_TOUCH_LOST) 
			{
				//TODO: � Shape����� �浹������ üũ�ϸ� ������....		
				//pair.otherShape;
				//pair.triggerShape;
				Utils::DataStructure::TriggerEvent triggerEvent{};
				ICollision* actor1 = static_cast<ICollision*>(pair.triggerActor->userData);
				ICollision* actor2 = static_cast<ICollision*>(pair.otherActor->userData);

				//TODO: ����Ƽ�� ���� Event�� ���߿� ó�� �ؾ���...	
				//OnTriggerExit();
				if (actor1 && actor2)
				{
					triggerEvent.myCollision = actor1;
					triggerEvent.otherCollision = actor2;
					actor1->OnOverlapEnd(triggerEvent);
					triggerEvent.myCollision = actor2;
					triggerEvent.otherCollision = actor1;
					actor2->OnOverlapEnd(triggerEvent);
				}
			}
		}
	}

	void PhysxCollisionEvent::onWake(PxActor** actors, PxU32 count)
	{
	}

	void PhysxCollisionEvent::onSleep(PxActor** actors, PxU32 count)
	{
	}

	void PhysxCollisionEvent::onConstraintBreak(PxConstraintInfo* constraints, PxU32 count)
	{
	}

	void PhysxCollisionEvent::onAdvance(const PxRigidBody* const* bodyBuffer, const PxTransform* poseBuffer, const PxU32 count)
	{
	}
}