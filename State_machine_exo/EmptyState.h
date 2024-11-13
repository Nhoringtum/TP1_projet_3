#ifndef __EMPTYSTATE_H__
#define __EMPTYSTATE_H__

#include "pch.h"

class EmptyState : public State
{
public:
	EmptyState();
	~EmptyState();

	void Start();
	void Update(float deltaTime);
};

#endif