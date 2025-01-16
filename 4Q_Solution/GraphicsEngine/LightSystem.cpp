#include "pch.h"
#include "LightSystem.h"
#include "Light.h"

void LightSystem::CreateLight(GE::ILight** ppOutLight)
{
	(*ppOutLight) = new Light;
}

void LightSystem::RegisterLight(GE::ILight* pLight)
{
	auto compare = [pLight](const auto* light)
		{ return static_cast<Light*>(pLight)->GetID() == light->GetID();};

	if (std::ranges::any_of(_lights, compare))
	{
		ASSERT(false, L"�̹� ��ϵ� Light �Դϴ�.");
		return;
	}

	_lights.push_back(static_cast<Light*>(pLight));
}

void LightSystem::UnRegisterLight(GE::ILight* pLight)
{
	std::erase_if(_lights, [pLight](const auto* light)
		{ return static_cast<Light*>(pLight)->GetID() == light->GetID(); });
}

void LightSystem::Release()
{
	delete this;
}