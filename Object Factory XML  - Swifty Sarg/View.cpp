#include "View.h"
#include "Object.h"
#include "InputDevice.h"

View::View() {

}

bool View::viewUpdate(Vector2d position, InputDevice* inputDevice)
{
	position = inputDevice->getInputPosition();
	return true;
}

