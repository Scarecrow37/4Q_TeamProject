#pragma once
#include "Base.h"
#include "includes/IPostProcessSystem.h"

class Filter;
class PostProcessSystem : public Base, public GE::IPostProcessSystem
{
public:
	explicit PostProcessSystem() = default;
	virtual ~PostProcessSystem() = default;

public:
	// IPostProcessSystem��(��) ���� ��ӵ�
	void AddFilter(const unsigned int layer, GE::IFilter* pFilter) override;
	void CreateBloom(GE::IBloom** ppBloom) override;

public:
	std::vector<Filter*>& GetFilters(const unsigned layer) const { return _filters[layer]; }

public:
	void Initialize(const unsigned int layer);

private:
	// Base��(��) ���� ��ӵ�
	void Free() override;

private:
	std::vector<Filter*>* _filters{ nullptr };
};

