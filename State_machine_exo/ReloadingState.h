#ifndef __RELOADINGSTATE__H__
#define __RELOADINGSTATE__H__

#include "State.h"

class ReloadingState : State
{
	ReloadingState();
	~ReloadingState();

	void Start();
	void Update();
};

#endif
