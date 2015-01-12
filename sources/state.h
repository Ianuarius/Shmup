#ifndef __STATE_H_INCLUDED__
#define __STATE_H_INCLUDED__


class State
{
public:

	enum StateCode
	{
		QUIT,
		INGAME,
		SPLASH,
		PAUSE,
		GAME_OVER
	};

	virtual void load() = 0;
	virtual void render() = 0;
};

#endif // __STATE_H_INCLUDED__
