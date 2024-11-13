#ifndef __STATE_H__
#define __STATE_H__

#include "Gun.h"

class State
{
public:
	State(){};
	~State(){};

	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;

	Gun* gun;
};

#endif