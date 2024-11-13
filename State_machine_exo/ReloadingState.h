#ifndef __RELOADINGSTATE__H__
#define __RELOADINGSTATE__H__

#include "pch.h"

class ReloadingState : public State
{
public:
	ReloadingState();
	~ReloadingState();

	void Start();
	void Update(float deltaTime);

private:
	float mReloadProgress;
	float mReloadTime;
};

#endif
