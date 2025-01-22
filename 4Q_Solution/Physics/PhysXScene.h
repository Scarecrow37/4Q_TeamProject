#pragma once
#include "IScene.h"
#include "PhysXUtils.h"

namespace Physics
{
	class PhysXScene
		: virtual public IScene
	{
	public:
		PhysXScene();
		virtual ~PhysXScene();

		// Additional to Physics System
		bool AddActor(IObject* object) override;

		// Setting Physics System
		void SetSecneFilter() override;
		void SetScene(physx::PxScene* _scene) { scene = _scene; }

		// Scene Query
		bool Raycast(
			Utils::DataStructure::AdditionalQueryData& raycastInfo,
			const Physics::Utils::Math::Vector3& startPosition, 
			const Physics::Utils::Math::Vector3& direction, 
			float distance) override;
		bool Overlap(
			Utils::DataStructure::QueryData& overlapInfo, 
			const IGeometry* geometry, 
			const Utils::Math::Transform& transform) override;		
		bool Sweep(
			Utils::DataStructure::AdditionalQueryData& sweepInfo, 
			const IGeometry* geometry,
			const Utils::Math::Transform& transform,
			const Utils::Math::Vector3& direction, 
			float distance) override;
		bool QueryFiltering() override;





		physx::PxScene* operator->() { return scene; }

	private:
		physx::PxScene* scene;

	};
}

