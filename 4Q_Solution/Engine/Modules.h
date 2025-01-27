#pragma once

#include "Input.h"
#include "Time.h"
#include "Graphics.h"
#include "Window.h"
#include "Physics.h"
#include "Network.h"

namespace Engine
{
	namespace GEGraphics
	{
		class Manager;
	}
	namespace Physics
	{
		class Manager;
	}
	struct Modules
	{
		GEGraphics::Manager* graphicsManager;
		Physics::Manager* physicsManager;
	};
}