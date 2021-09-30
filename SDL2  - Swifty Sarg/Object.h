#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <memory>
using namespace std;

class Object {
public:
	Object();
	~Object();
	virtual unique_ptr<Object> update() = 0; 
	virtual void draw() = 0;
private:
	float x;
	float y;
	float angle;
	bool inPlay = false;
};
#endif