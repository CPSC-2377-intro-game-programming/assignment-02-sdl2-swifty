#include "tinyxml2.h"
#include "Engine.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {
	//define the paths where the xml files can be found
	std::string path = "...";

	std::unique_ptr<Engine> engine{ std::make_unique<Engine>(levelConfig, libraryConfig) };
	while (engine->run()) {}
	engine = nullptr;
	return 0;
}
