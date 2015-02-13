#ifndef __STATE_H_INCLUDED__
#define __STATE_H_INCLUDED__


class State
{
public:

	virtual ~State() {};
	virtual void load(int stack = 0) = 0;
	virtual int unload() = 0;
	virtual void render() = 0;

private:
};

#endif // __STATE_H_INCLUDED__
