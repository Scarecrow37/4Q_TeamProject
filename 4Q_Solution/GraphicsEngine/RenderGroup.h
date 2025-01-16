#pragma once
#include "Base.h"

namespace GE
{
	class IMatrix;
	class IMeshRenderer;
}

class MeshRenderer;
class RenderGroup : public Base
{
	using RenderData = std::pair<MeshRenderer*, Matrix4x4*>;
public:
	explicit RenderGroup() = default;
	virtual ~RenderGroup() = default;

public:
	const std::list<RenderData>& GetRenderData() { return _datas; }

	void RegisterRenderQueue(GE::IMeshRenderer* pComponent, GE::IMatrix* pMatrix);
	void UnRegisterRenderQueue(GE::IMeshRenderer* pComponent);

private:
	// Base��(��) ���� ��ӵ�
	void Free() override;

private:
	std::list<RenderData> _datas;
};