#pragma once
#include "IElementDeclaration.h"

namespace PhysicsEngineAPI
{
	__INTERFACE__
	class ICreate
	{
	public:
		// Creat Physics System
		virtual bool CreatePhysics(bool isVisualDebuger = true) = 0;
		virtual bool CreateScene(_OUT_ IScene** scene, const Utils::Description::SceneDesc& sceneDescription, const char* name = nullptr) = 0;
		virtual bool CreateObject(_OUT_ IObject** object, const Utils::DataStructure::RigidBodyType& type) = 0;
		// TODO: ���� �Ž��� �޴� �͵� �ϸ� ���� �� ���� ���� 1���� �޽���?
		virtual bool CreateGeometry(_OUT_ IGeometry** geometry, const Utils::Description::GeometryDesc& geometryDesc, const Utils::Description::VerticesMeshDesc verticesMeshDesc = Utils::Description::VerticesMeshDesc()) = 0;
		virtual bool CreateShape(_OUT_ IShape** shape, const IGeometry* geometry, const IMaterial* meterial, bool isExclusive = true) = 0;
		virtual bool CreateMaterial(_OUT_ IMaterial** meterial, const Utils::Description::MaterialDesc& materialDesc) = 0;
	
		// Camera Frustum Scene
		
		/**
		 * @brief					: Scene, where all objects are static and are made for the purpose of curling with the camera.
		 * @param scene				: Out Data
		 * @param sceneDescription	: Gravity is 0, CPUDispatcherCount is valid.
		 * @return 
		 */
		virtual bool CreateCameraScene(_OUT_ IScene** scene, const Utils::Description::SceneDesc& sceneDescription) = 0;


		// TODO: 
		// Particle Scene (GPGPU��� ����)
		// 1. ���� ���� ��ȣ�ۿ��� ���� ��ƼŬ -> ������ ���� ���� ���
		// 2. �Ǽ� ���� ��ȣ�ۿ��� ���� ȿ���� �����Ӹ� �ִ� Particle (���� ȿ���� ���� �⺻���� �����ӵ� ���� ���� ��)
	};
}
