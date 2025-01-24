#pragma once
#include "Component.h"
#include "includes/IMeshRenderer.h"

class Model;
class VertexShader;
class MeshRenderer : public Component, public GE::IMeshRenderer
{
protected:
	explicit MeshRenderer() = default;
	virtual ~MeshRenderer() = default;

public:
	std::shared_ptr<Model>& GetModel() { return _model; }
	MeshType::Type GetType() const { return _type; }
	const unsigned int GetLayer() const { return _layer; }

public:
	virtual void Initialize(const wchar_t* filePath) = 0;
	void SetVertexShader();

public:
	// IMeshRenderer��(��) ���� ��ӵ�
	void Release() override;
	void SetRenderLayer(const unsigned int layer) override;

protected:
	std::shared_ptr<Model>			_model;
	std::shared_ptr<VertexShader>	_vertexShader;
	MeshType::Type					_type{ MeshType::End };
	unsigned int					_layer{ 0 };
};