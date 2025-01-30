#pragma once
#include <concepts>

namespace PhysicsEngineAPI
{
	//enum class CollisionObjectType
	//{
	//	Object,
	//	Shape,

	//	End
	//};
	
	//ColliderComponent�� �̰��� ��ӹ޾Ƽ� ���鵵��
	//TODO: Fetch���� Colllision�� �߻��ϰ�
	//		-> �̰��� ���� ���� ��ġ �������� Actor���� �����ΰ� �����Ű�� ���� �ȵȴ�.
	//		-> flag�� Event������� ������ ����ȭ ó���ؼ� �ѹ��� ó�� �ؾ���.
	__INTERFACE__
	EXTERN_C class PHYSICS_API ICollision
	{
	public:
		virtual ~ICollision() = default;

		// Refer. Unity Collosion
		virtual void __CALLBACK__ OnTriggerEnter(Utils::DataStructure::TriggerEvent info)		= 0;
		virtual void __CALLBACK__ OnTrigger(Utils::DataStructure::TriggerEvent info)			= 0;
		virtual void __CALLBACK__ OnTriggerExit(Utils::DataStructure::TriggerEvent info)		= 0;
		virtual void __CALLBACK__ OnCollisionEnter(Utils::DataStructure::ContactEvent info)		= 0;
		virtual void __CALLBACK__ OnCollision(Utils::DataStructure::ContactEvent info)			= 0;
		virtual void __CALLBACK__ OnCollisionExit(Utils::DataStructure::ContactEvent info)		= 0;

		// Refer. Unreal Collosion
		virtual void __CALLBACK__ OnHit(Utils::DataStructure::ContactEvent info)			= 0;
		virtual void __CALLBACK__ OnOverlapBegin(Utils::DataStructure::TriggerEvent info)	= 0;
		virtual void __CALLBACK__ OnOverlapEnd(Utils::DataStructure::TriggerEvent info)		= 0;
	};





















	template <typename T>
	concept HasOnTriggerEnter = requires(T obj, Utils::DataStructure::TriggerEvent info) { { obj.OnTriggerEnter(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnTrigger = requires(T obj, Utils::DataStructure::TriggerEvent info) { { obj.OnTrigger(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnTriggerExit = requires(T obj, Utils::DataStructure::TriggerEvent info) { { obj.OnTriggerExit(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnCollisionEnter = requires(T obj, Utils::DataStructure::ContactEvent info) { { obj.OnCollisionEnter(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnCollision = requires(T obj, Utils::DataStructure::ContactEvent info) { { obj.OnCollision(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnCollisionExit = requires(T obj, Utils::DataStructure::ContactEvent info) { { obj.OnCollisionExit(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnHit = requires(T obj, Utils::DataStructure::ContactEvent info) { { obj.OnHit(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnOverlapBegin = requires(T obj, Utils::DataStructure::TriggerEvent info) { { obj.OnOverlapBegin(info) } -> std::same_as<void>; };
	template <typename T>
	concept HasOnOverlapEnd = requires(T obj, Utils::DataStructure::TriggerEvent info) { { obj.OnOverlapEnd(info) } -> std::same_as<void>; };
	template <typename T>
	concept CollisionType =
		HasOnTriggerEnter<T> || HasOnTrigger<T> || HasOnTriggerExit<T> ||
		HasOnCollisionEnter<T> || HasOnCollision<T> || HasOnCollisionExit<T> ||
		HasOnHit<T> || HasOnOverlapBegin<T> || HasOnOverlapEnd<T>;
}
