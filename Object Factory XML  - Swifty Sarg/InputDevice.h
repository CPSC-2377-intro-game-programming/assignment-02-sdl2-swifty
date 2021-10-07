#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include <vector>
#include <map>
#include <memory>
#include <string>
#include "SDL.h"

using namespace std;

class InputDevice {
public:
	enum class gameEvent {
		NA,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SPACE,
		SHIFT,
		MOUSE_MOVE,
		LEFT_CLICK,
		RIGHT_CLICK,
		DOUBLE_CLICK,
		B,
		QUIT,
		NUM_EVENTS
	};

	bool GetEvent(gameEvent eventG);
	InputDevice();
	~InputDevice();
	void update();
private:
	std::unique_ptr<SDL_Event> event;
	gameEvent Translate();
	std::map<gameEvent, bool> keyStates;
};