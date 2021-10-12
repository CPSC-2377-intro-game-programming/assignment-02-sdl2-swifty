#include "View.h"
#include "Object.h"
#include "InputDevice.h"

View::View() {
	positCenter.x = 0;
	positCenter.y = 0;
}

bool View::viewUpdate(Vector2d position, InputDevice* inputDevice)
{
	position = inputDevice->getInputPosition(position);
	positCenter = position;
	return true;
}

