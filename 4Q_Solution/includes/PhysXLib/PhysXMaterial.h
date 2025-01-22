#pragma once

#include "IMaterial.h"
#include "PhysXUtils.h"
#include "PhysXScene.h"

namespace Physics
{
	class PhysXMaterial
		: virtual public IMaterial
	{
	public:
		explicit	PhysXMaterial(physx::PxMaterial* material);
		virtual		~PhysXMaterial();

		const physx::PxMaterial* GetMaterial() const;

		physx::PxMaterial* operator->() { return material; }
	private:
		physx::PxMaterial* material;

		friend class PhysXSystem;

		// IMaterial��(��) ���� ��ӵ�
		void setRestitutionCombineMode() override;
	};
}

