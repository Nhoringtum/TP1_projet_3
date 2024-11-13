#ifndef __GUN_H__
#define __GUN_H__

#include <vector>

class State;

class Gun
{
public:
	Gun();
	~Gun();

	enum eState
	{
		Idle,
		Shooting,
		Empty,
		Reloading,

		StateCount
	};

	static const int STATE_COUNT = (int)eState::StateCount;

	void Update(float dt);
	bool SetState(eState to);

	int mAmmo;
	int mCapacity;
	std::vector<State*> mStateTab;
	eState mState = eState::Idle;

private:

	int mTransitions[STATE_COUNT][STATE_COUNT] =
	{
//2nd   //Idle, Shooting, Empty, Reloading
		{  0,      1,        0,       1   }, //Idle
		{  1,      0,        1,       0   }, //Shooting
		{  0,      0,        0,       1   }, //Empty
		{  1,      0,        0,       0   }  //Reloading
											//1rst
	};

	
};

#endif