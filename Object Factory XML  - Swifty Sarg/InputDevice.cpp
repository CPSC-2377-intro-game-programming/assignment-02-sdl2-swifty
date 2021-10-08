#include "InputDevice.h"
#include "View.h"

View::Vector2d getInputPosition(InputDevice::iPosition::x xVal,
	InputDevice::iPosition::y yVal) {
	return iPosition;
}

bool InputDevice::GetEvent(gameEvent eventG) {
	return (keyStates.find(eventG)->second);
}

//bool InputDevice::GetEvent(gameEvent eventG) {
//	gameEvent GE;
//	if (SDL_PollEvent(event.get())) {
//		switch (event->type) {
//		case SDL_KEYDOWN:
//			GE = Translate();
//			if (keyStates.find(GE)->first == eventG) {
//				keyStates.find(GE)->second = true;
//			}
//			break;
//		case SDL_KEYUP:
//			GE = Translate();
//			if (keyStates.find(GE)->first == eventG) {
//				keyStates.find(GE)->second = true;
//			}
//			break;
//		case SDL_MOUSEBUTTONDOWN:
//			switch (event->button.button) {
//			case SDL_BUTTON_LEFT:
//				if (keyStates.find(GE)->first == eventG) {
//					keyStates.find(GE)->second = true;
//				}
//				break;
//			case SDL_BUTTON_RIGHT:
//				if (keyStates.find(GE)->first == eventG) {
//					keyStates.find(GE)->second = true;
//				}
//				break;
//			}
//		case SDL_MOUSEBUTTONUP:
//			switch (event->button.button) {
//			case SDL_BUTTON_LEFT:
//				if (keyStates.find(GE)->first == eventG) {
//					keyStates.find(GE)->second = true;
//				}
//				break;
//			case SDL_BUTTON_RIGHT:
//				if (keyStates.find(GE)->first == eventG) {
//					keyStates.find(GE)->second = true;
//				}
//				break;
//			}
//			break;
//		case SDL_QUIT:
//			if (keyStates.find(GE)->first == eventG) {
//				keyStates.find(GE)->second = true;
//			}
//			break;
//		default:
//			break;
//		}
//	}
//	return true;
//}

InputDevice::InputDevice() {
	event = std::make_unique<SDL_Event>();
	if (!event) {
		printf("SDL Event could not initialize!");
		exit(1);
	}

	keyStates[gameEvent::NA] = false;
	keyStates[gameEvent::DOWN] = false;
	keyStates[gameEvent::UP] = false;
	keyStates[gameEvent::LEFT] = false;
	keyStates[gameEvent::RIGHT] = false;
	keyStates[gameEvent::SPACE] = false;
	keyStates[gameEvent::QUIT] = false;
	keyStates[gameEvent::SHIFT] = false;
	keyStates[gameEvent::B] = false;
	keyStates[gameEvent::LEFT_CLICK] = false;
	keyStates[gameEvent::RIGHT_CLICK] = false;
	update();
}

void InputDevice::update() {
	gameEvent GE;
	if (SDL_PollEvent(event.get())) {
		switch (event->type) {
		case SDL_KEYDOWN:
			GE = Translate();
			keyStates.find(GE)->second = true;
			break;
		case SDL_KEYUP:
			GE = Translate();
			keyStates.find(GE)->second = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event->button.button) {
			case SDL_BUTTON_LEFT:
				keyStates.find(gameEvent::LEFT_CLICK)->second = true;
				break;
			case SDL_BUTTON_RIGHT:
				keyStates.find(gameEvent::RIGHT_CLICK)->second = true;
				break;
			}
		case SDL_MOUSEBUTTONUP:
			switch (event->button.button) {
			case SDL_BUTTON_LEFT:
				keyStates.find(gameEvent::LEFT_CLICK)->second = false;
				break;
			case SDL_BUTTON_RIGHT:
				keyStates.find(gameEvent::RIGHT_CLICK)->second = false;
				break;
			}
			break;
		case SDL_QUIT:
			keyStates.find(gameEvent::QUIT)->second = true;
			break;
		default:
			break;
		}
	}
}

InputDevice::gameEvent InputDevice::Translate() {
	iPosition iposit;
	switch (event->key.keysym.sym) {
	case SDLK_LEFT:
		iposit.x -= 1;
		return gameEvent::LEFT;
		break;
	case SDLK_RIGHT:
		iposit.x += 1;
		return gameEvent::RIGHT;
		break;
	case SDLK_UP:
		iposit.y += 1;
		return gameEvent::UP;
		break;
	case SDLK_DOWN:
		iposit.y -= 1;
		return gameEvent::DOWN;
		break;
	case SDLK_SPACE:
		int checkbar=0;
		if (checkbar == 0) {
			iposit.y += 2;
			checkbar++;
		}
		else {
			iposit.y -= 2;
			checkbar = 0;
		}
		return gameEvent::SPACE;
		break;
	case SDLK_RSHIFT:
	case SDLK_LSHIFT:
		return gameEvent::SHIFT;
		break;
	case SDLK_b:
		return gameEvent::B;
		break;
	}
	return gameEvent::NA;
}