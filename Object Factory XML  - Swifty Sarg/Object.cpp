#include "Object.h"

Object::Object() {
	x = 0.0f;
	y = 0.0f;

	angle = 0.0f;
	rotationAngle = 0.0f;

	inPlay = false;
	renderer = nullptr;
	texture = nullptr;
}


Object::~Object() {
	renderer = nullptr;
	texture = nullptr;
	inPlay = false;

	x = 0.0f;
	y = 0.0f;
	angle = 0.0f;
	rotationAngle = 0.0f;
}