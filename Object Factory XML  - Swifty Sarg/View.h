#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "InputDevice.h"
#include "Object.h"

class InputDevice;

class View {
public:
	struct Vector2d {
		float x = 0;
		float y = 0;
	};
	std::unique_ptr<InputDevice> inputDevice;

	View();
	bool viewUpdate(Vector2d position, InputDevice* inputDevice);
	
private:

	float positCenter;
};





#endif