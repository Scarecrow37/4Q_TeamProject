#pragma once

namespace Engine::Physics
{
	struct Component
	{
		Component() = default;
		Component(const Component& other) = default;
		Component(Component&& other) noexcept = default;
		Component& operator=(const Component& other) = default;
		Component& operator=(Component&& other) noexcept = default;
		virtual ~Component() = default;
	};
}

