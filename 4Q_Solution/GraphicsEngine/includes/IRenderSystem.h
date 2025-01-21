﻿#pragma once
#include "IBash.h"

namespace GE
{
	struct RENDERER_DESC
	{
		HWND			hWnd;
		const wchar_t*	shaderRootPath;
		float			width;
		float			height;
		enum class Type { DX11, DX12, DXR };
		Type			type;
		unsigned int	maxLayer;
		bool			isFullScreen;
	};

	struct MESH_RENDERER_DESC
	{
		const wchar_t*	filePath;
		enum class Type { Static, Skeletal };
		Type			type;
	};

	class IMatrix;
	class IMeshRenderer;
	class IAnimator;
	class ITextSystem;
	class IPostProcessSystem;
	class IRenderSystem : public IBase
	{
	protected:
		explicit IRenderSystem() = default;
		virtual ~IRenderSystem() = default;
		IRenderSystem(const IRenderSystem&) = delete;
		IRenderSystem(IRenderSystem&&) = delete;
		IRenderSystem& operator=(const IRenderSystem&) = delete;
		IRenderSystem& operator=(IRenderSystem&&) = delete;

	public:
		virtual void Initialize(const RENDERER_DESC* pDesc) = 0;
		virtual void Render() = 0;

		virtual void GetTextSystem(ITextSystem** ppTextSystem) = 0;
		virtual void GetPostProcessSystem(IPostProcessSystem** ppPostProcessSystem) = 0;
		virtual void CreateMatrix(IMatrix** ppMatrix) = 0;
		virtual void CreateMeshRenderer(IMeshRenderer** ppComponent, const MESH_RENDERER_DESC* pDesc) = 0;		
		virtual void RegisterRenderQueue(const unsigned int layer, IMeshRenderer* pComponent, IMatrix* pMatrix) = 0;
		virtual void UnRegisterRenderQueue(const unsigned int layer, IMeshRenderer* pComponent) = 0;
	};
}