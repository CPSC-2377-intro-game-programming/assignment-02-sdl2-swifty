#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "tinyxml2.h"
#include <memory>

class Object;

class ObjectFactory {
public:
	virtual std::unique_ptr<Object> create(tinyxml2::XMLElement * objectElement) = 0;

};





#endif