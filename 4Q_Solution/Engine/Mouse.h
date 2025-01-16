#pragma once

namespace Engine::Input::Device
{
	struct IMouse
	{
		enum class Button : unsigned char
		{
			Left,
			Right,
			Middle,
			X1,
			X2
		};

		IMouse() = default;
		IMouse(const IMouse& other) = default;
		IMouse(IMouse&& other) noexcept = default;
		IMouse& operator=(const IMouse& other) = default;
		IMouse& operator=(IMouse&& other) noexcept = default;
		virtual ~IMouse() = default;

		[[nodiscard]] virtual Math::Point GetPosition() const = 0;
		[[nodiscard]] virtual bool IsButtonDown(Button button) const = 0;
		[[nodiscard]] virtual bool IsButtonUp(Button button) const = 0;
		[[nodiscard]] virtual bool IsButtonPressed(Button button) const = 0;
		[[nodiscard]] virtual bool IsButtonReleased(Button button) const = 0;
	};

	struct Mouse : IMouse
	{
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Reset() = 0;
		virtual void Finalize() = 0;
	};
}
