#pragma once

#include "ISceneQuery.h"
#include "IPhysicsSystem.h"

namespace PhysicsEngineAPI
{
	class IObject;
}

namespace PhysicsEngineAPI
{
	__INTERFACE__
	EXTERN_C class PHYSICS_API IScene
		: public ISceneQuery
		, public IBase
	{
	public:
		virtual ~IScene() = default;

		// Additional to Physics System
		virtual bool AddActor(IObject* object) = 0;

		// Setting Physics System
		// TODO: 
		virtual void SetSceneFilter() = 0;
		virtual void SetGravity(const Utils::Math::Vector3& gravity) = 0;
		virtual Utils::Math::Vector3 GetGravity() const = 0;

		unsigned int GetSceneNumber();

	private:
		unsigned int sceneNumber{0};

		friend class IPhysicsSystem;
	};
}
