#include "pch.h"
#include "Mouse.h"

#include "AxisComponent.h"
#include "ButtonComponent.h"
#include "Value.h"

DSH::Input::Device::Mouse::Mouse() :
	_referenceCount(1), _handle(nullptr), _isCursorLock(false), _screenCenter{}
{
}

DSH::Input::Device::Mouse::~Mouse()
{
	std::ranges::for_each(_axes | std::views::values , [](Component::AxisComponent* axis) { axis->Release(); });
	_axes.clear();
	std::ranges::for_each(_buttons | std::views::values, [](Component::ButtonComponent* button) { button->Release(); });
	_buttons.clear();
}

HRESULT DSH::Input::Device::Mouse::QueryInterface(const IID& riid, void** ppvObject)
{
	if (ppvObject == nullptr) return E_INVALIDARG;
	if (riid != IID_IMouse &&
		riid != IID_IDevice &&
		riid != IID_IUnknown) return E_NOINTERFACE;
	*ppvObject = this;
	return S_OK;
}

ULONG DSH::Input::Device::Mouse::AddRef()
{
	return InterlockedIncrement(&_referenceCount);
}

ULONG DSH::Input::Device::Mouse::Release()
{
	const ULONG newRefCount = InterlockedDecrement(&_referenceCount);
	if (newRefCount == 0) delete this;
	return newRefCount;
}

void DSH::Input::Device::Mouse::Update()
{
	UpdateAxes();
	UpdateButtons();
}

void DSH::Input::Device::Mouse::Reset()
{
	if (_isCursorLock) SetCursorToCenter();
	ResetAxes();
	ResetButtons();
}

void DSH::Input::Device::Mouse::SetHandle(const HWND handle)
{
	_handle = handle;
}

HRESULT DSH::Input::Device::Mouse::GetComponent(const Button button, Component::IButtonComponent** ppComponent)
{
	if (button == Button::Max) return E_INVALIDARG;
	if (ppComponent == nullptr) return E_INVALIDARG;
	Component::ButtonComponent* pButtonComponent = nullptr;
	if (_buttons.contains(button) == false)
	{
		pButtonComponent = new Component::ButtonComponent();
		if (pButtonComponent == nullptr) return E_OUTOFMEMORY;
		_buttons[button] = pButtonComponent;
	}
	else pButtonComponent = _buttons[button];
	pButtonComponent->AddRef();
	*ppComponent = pButtonComponent;
	return S_OK;
}

HRESULT DSH::Input::Device::Mouse::GetComponent(const Axis axis, Component::IAxisComponent** ppComponent)
{
	if (axis == Axis::Max) return E_INVALIDARG;
	if (ppComponent == nullptr) return E_INVALIDARG;
	Component::AxisComponent* pAxisComponent = nullptr;
	if (_axes.contains(axis) == false)
	{
		pAxisComponent = new Component::AxisComponent();
		if (pAxisComponent == nullptr) return E_OUTOFMEMORY;
		pAxisComponent->SetSensitivity(MOUSE_SENSITIVE);
		_axes[axis] = pAxisComponent;
	}
	else pAxisComponent = _axes[axis];
	pAxisComponent->AddRef();
	*ppComponent = pAxisComponent;
	return S_OK;
}

DSH::Input::Value DSH::Input::Device::Mouse::GetPosition() const
{
	Value value{};
	value.x = _axes.at(Axis::X)->GetValue().scalar;
	value.y = _axes.at(Axis::Y)->GetValue().scalar;
	return value;
}

void DSH::Input::Device::Mouse::ShowCursor()
{
	CURSORINFO cursorInfo;
	::GetCursorInfo(&cursorInfo);
	if (cursorInfo.flags == NULL) ::ShowCursor(TRUE);
	
}

void DSH::Input::Device::Mouse::HideCursor()
{
	CURSORINFO cursorInfo;
	::GetCursorInfo(&cursorInfo);
	if (cursorInfo.flags == CURSOR_SHOWING)	::ShowCursor(FALSE);
	
}

void DSH::Input::Device::Mouse::LockCursor()
{
	RECT rect;
	::GetClientRect(_handle, &rect);
	_screenCenter.x = (rect.right - rect.left) / 2;
	_screenCenter.y = (rect.bottom - rect.top) / 2;
	::ClientToScreen(_handle, &_screenCenter);

	_isCursorLock = true;
}

void DSH::Input::Device::Mouse::UnlockCursor()
{
	_isCursorLock = false;
}

void DSH::Input::Device::Mouse::UpdateAxes()
{
	if (_handle == nullptr) return;

	POINT mousePosition;
	GetCursorPos(&mousePosition);
	ScreenToClient(_handle, &mousePosition);

	if (_axes.contains(Axis::X)) _axes[Axis::X]->SetAbsoluteValue(mousePosition.x);
	if (_axes.contains(Axis::Y)) _axes[Axis::Y]->SetAbsoluteValue(mousePosition.y);

	MSG message;
	if (_axes.contains(Axis::Wheel) &&
		PeekMessage(&message, _handle, NULL, NULL, PM_NOREMOVE) && 
		message.message == WM_MOUSEWHEEL)
		_axes[Axis::Wheel]->SetRelativeValue(GET_WHEEL_DELTA_WPARAM(message.wParam));

}

void DSH::Input::Device::Mouse::UpdateButtons()
{
	std::ranges::for_each(_buttons, [](const std::pair<const Button, Component::ButtonComponent*>& buttonPair) { buttonPair.second->SetValue(GetAsyncKeyState(static_cast<unsigned char>(buttonPair.first)) & 0x8000); });
}

void DSH::Input::Device::Mouse::SetCursorToCenter() const
{
	SetCursorPos(_screenCenter.x, _screenCenter.y);
}

void DSH::Input::Device::Mouse::ResetAxes()
{
	std::ranges::for_each(_axes | std::views::values, [](Component::AxisComponent* axis) { axis->Reset(); });
}

void DSH::Input::Device::Mouse::ResetButtons()
{
	std::ranges::for_each(_buttons | std::views::values, [](Component::ButtonComponent* button) { button->Reset(); });
}

