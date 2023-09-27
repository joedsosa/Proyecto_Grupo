#pragma once
#include <string>
using namespace std;
class Object{
public:
	virtual bool equals(Object& other) {
		return false;
	}
	virtual string toString() {
		return "";
	}
	virtual ~Object() = 0;
};