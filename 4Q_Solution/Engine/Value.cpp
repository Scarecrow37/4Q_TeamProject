#include "pch.h"
#include "Value.h"

const Engine::Input::Value Engine::Input::Value::Zero = Engine::Input::Value{};

Engine::Input::Value& Engine::Input::Value::operator+=(const Value& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

bool Engine::Input::Value::operator==(const Value& rhs) const
{
    if (std::fabs(this->scalar - rhs.scalar) >= 1e-5f) {
        return false;
    }
    if (std::fabs(this->x - rhs.x) >= 1e-5f ||
        std::fabs(this->y - rhs.y) >= 1e-5f ||
        std::fabs(this->z - rhs.z) >= 1e-5f) {
        return false;
    }
    return this->_ == rhs._ && this->on == rhs.on;
}

Engine::Input::Value::operator bool() const
{
	return on;
}
