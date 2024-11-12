#ifndef __EMPTYSTATE_H__
#define __EMPTYSTATE_H__

#include "State.h"

class EmptyState : public State
{
public:
	EmptyState();
	~EmptyState();

	void Start();
	void Update(float deltaTime);
};

#endif