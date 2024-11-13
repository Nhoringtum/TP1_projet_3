#ifndef __IDLESTATE_H__
#define __IDLESTATE_H__

#include "pch.h"

class IdleState : public State
{
public:
	IdleState();
	~IdleState();

	void Start();
	void Update(float deltaTime);
};

#endif