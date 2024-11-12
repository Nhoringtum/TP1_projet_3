#ifndef __GUN_H__
#define __GUN_H__
#include <vector>

class Gun
{
public:
	Gun();
	~Gun();

	enum State
	{
		Idle,
		Shooting,
		Empty,
		Reloading,

		StateCount
	};

	static const int STATE_COUNT = (int)State::StateCount;

	void Update(float dt);
	void Shoot();
	void Reload();
	bool SetState(State to);

private:
	State mState = State::Idle;

	int mTransitions[STATE_COUNT][STATE_COUNT] =
	{
//2nd   //Idle, Shooting, Empty, Reloading
		{  0,      1,        0,       1   }, //Idle
		{  1,      0,        1,       0   }, //Shooting
		{  0,      0,        0,       1   }, //Empty
		{  1,      0,        0,       0   }  //Reloading
											//1rst
	};

	int mAmmo;
	int mCapacity;
	float mReloadTime;
	float mShootTime;
	float mReloadProgress;
	float mShootProgress;
	std::vector<State*> mStateTab;
};

#endif