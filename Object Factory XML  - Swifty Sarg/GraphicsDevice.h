#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H
#include "SDL.h"
#include "SDL_image.h"
#include "Definitions.h"
#include "Vector2D.h"

class GraphicsDevice {

public:
	GraphicsDevice(ResourceManager* devices, Uint32 width, Uint32 height, bool fullScreen = true) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height)
	~GraphicsDevice();
	void Begin();
	void Present();
	SDL_Renderer* getRenderer();

};

#endif