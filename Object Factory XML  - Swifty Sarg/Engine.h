#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <memory>
#include "Object.h"
#include "Library.h"
using namespace std;

class Engine {
public:
	Engine();
	~Engine();
	void loadLevel(string levelPath);
	void update();
	void draw();
	bool run(); //calls update and draw and returns false when game is over. it's used by source.cpp
private:
	std::unique_ptr<Library> objectLibrary;
	std::vector<std::unique_ptr<Object>> objects;
};
#endif