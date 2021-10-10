#include "Minotaur.h"

Minotaur::Minotaur()
{
	renderer = NULL;
	texture = NULL;

	xPosition = 0.f;
	yPosition = 0.0f;
	angle = 0.0f;

	rotationAngle = 0.0f;
	xVelocity = 0.0f;
	yVelocity = 0.0f;

	stepLagCount = 0;
	stepCount = 0;
	spriteID = 0;
	command = "";
}

Minotaur::~Minotaur()
{
	renderer = NULL;
	texture->free(); //will fix once emily makes texture :D
}

bool Minotaur::Initialize(SDL_Renderer* renderer, std::string path)
{
	this->renderer = renderer;
	texture = new Texture();
	texture->load(renderer, path);

	for (int i = 0; i < NUM_SPRITES; i++) {
		int row = i / SPRITE_SHEET_NCOLS;
		int col = i % SPRITE_SHEET_NCOLS;

		clipArray[i].x = col * SPRITE_WIDTH;
		clipArray[i].y = row * SPRITE_HEIGHT;
		clipArray[i].w = SPRITE_WIDTH;
		clipArray[i].h = SPRITE_HEIGHT;
	}

	font = TTF_OpenFont("./Assets/Fonts/impact.ttf", 48);
	if (font == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error:%s\n", TTF_GetError());
	}
	return(true);
}

void Minotaur::HandleEvent(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym)
		{
		case SDLK_LEFT:
			rotationAngle = -360.0f / 100.f;
			command = "left";
			break;
		case SDLK_RIGHT:
			rotationAngle = 360.0f / 100.f;
			command = "right";
			break;
		case SDLK_UP:
			xVelocity = 1.0f;
			yVelocity = 1.0f;
			command = "up";
			break;
		case SDLK_DOWN:
			xVelocity = 0.0f;
			yVelocity = 0.0f;
			command = "down";
			break;
		}
	}
}

void Minotaur::Update()
{
	xPosition += xVelocity;
	yPosition += yVelocity;
	angle += commandAngle;

	commandAngle = 0.0f;

	//Update the Animation Every ANIM_LAG frames (cheat to avoid more comlicated
	//timing issues while demonstrating animation)
	stepLagCount++;
	stepLagCount %= ANIM_LAG;
	if (stepLagCount == 0)
	{
		stepCount++;
		stepCount %= ANIM_SIZE;
		spriteID = ANIMATION[stepCount];
	}
}

void Minotaur::Draw()
{
	texture->renderEx(renderer, (int)xPosition, (int)yPosition, angle, &clipArray[spriteID]);

	if (command != "")
	{
		//Render Command to Text
		SDL_Color textColor = { 255, 255, 51 };
		SDL_Texture* textSheetTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, command.c_str(), textColor));

		//Set rendering space and render to screen
		int width = 0, height = 0;
		SDL_QueryTexture(textSheetTexture, NULL, NULL, &width, &height);
		SDL_Rect renderQuad = { (Uint32)xPosition, (Uint32)yPosition - 80, width, height };

		//Render to screen
		SDL_RenderCopy(renderer, textSheetTexture, NULL, &renderQuad);

		//Reset command
		command = "";
	}
}
