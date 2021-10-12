#include "Timer.h"

void Timer::fpsRegulate() {
	//Pause for a length of time such that frame rate is maintained
	if (getTicks() < mpf)
	{
		SDL_Delay((eInt)mpf - getTicks());
	}
}
