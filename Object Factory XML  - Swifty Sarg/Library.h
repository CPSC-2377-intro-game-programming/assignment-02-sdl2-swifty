#ifndef LIBRARY_H
#define LIBRARY_H
#include <map>
#include <string>
#include "ObjectFactory.h"

using namespace std;

class Library {
public:
	Library();
	~Library();
	getArtAsset(string keyName);
	addArtAsset();
private:
	std::map<string, unique_ptr<ObjectFactory>> library;
	std::map<string, std::shared_ptr<Texture>> artLibrary;
};
#endif