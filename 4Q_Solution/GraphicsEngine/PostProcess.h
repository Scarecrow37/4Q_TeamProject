#pragma once
#include "Base.h"

class PostProcess : public Base
{
public:
	explicit PostProcess() = default;
	virtual ~PostProcess() = default;

public:
	void Render();

private:
	// Base��(��) ���� ��ӵ�
	void Free() override;
};

