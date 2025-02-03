#pragma once

namespace Engine::Physics
{
	// Client Interface
	struct IManager
		: public ICreate
		, public IUpdate
		, public IFactory
	{
		IManager() = default;
		IManager(const IManager& other) = default;
		IManager(IManager&& other) noexcept = default;
		IManager& operator=(const IManager& other) = default;
		IManager& operator=(IManager&& other) noexcept = default;
		virtual ~IManager() = default;

		virtual void AttachUpdateScene(IScene* scene) = 0;
		virtual void DetachUpdateScene(IScene* scene) = 0;
		virtual IScene* GetScene(unsigned int sceneNumber) = 0;


		/********************************
					GeometryMap
		*********************************/

		/**
		 * @brief	����µ� �����ϸ� true,
					���� �Ǵ� �̹� �ִ� �̸��� �����̸� false
		 */
		virtual bool AddGeomtry(
			const std::string& name,
			const Engine::Physics::GeometryDesc& _geometryDesc,
			const Engine::Physics::VerticesMeshDesc& _verticesMeshDesc
		) = 0;
		virtual bool LoadTriangleMesh(
			const Engine::Physics::GeometryDesc& geometryDesc,
			const char* name,
			const char* filePath
		) = 0;
		virtual void CreateTriangleStatic(
			IRigidStaticComponent** destObject,
			const char* geomtryName,
			const MaterialDesc& materialDesc,
			const Engine::Transform& transform,
			const Engine::Transform& shapeOffset = Engine::Transform(),
			bool isExclusive = true
		) = 0;
	};

	// Engine Interface
	struct Manager : IManager
	{
		virtual void Initialize(PhysicsType physicsType = PhysicsType::Physx, bool visualDebug = true, float length = 1.f, float speed = 10.f) = 0;
		virtual void WorldInitialize() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void FetchScene(bool block = true) = 0;
		virtual void Finalize() = 0;

		virtual void* GetSystem() const = 0;
	};
}
