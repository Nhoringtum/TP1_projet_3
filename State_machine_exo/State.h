#ifndef __STATE_H__
#define __STATE_H__

class State
{
public:
	State(){};
	~State(){};

	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
};

#endif