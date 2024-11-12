#ifndef __IDLESTATE_H__
#define __IDLESTATE_H__

#include "State.h"

class IdleState : State
{
	IdleState();
	~IdleState();

	void Start();
	void Update(float deltaTime);
};

#endif