#pragma once
#include "Base.h"

class ToneMapping : public Base
{
public:
	explicit ToneMapping() = default;
	virtual ~ToneMapping() = default;

	// Base��(��) ���� ��ӵ�
	void Free() override;
};

