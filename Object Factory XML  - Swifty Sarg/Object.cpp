#include "Object.h"

Object::Object() {
	xPosition = 0.0f;
	yPosition = 0.0f;

	xVelocity = 0.0f;
	yVelocity = 0.0f;

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