#pragma once

class Tank
{
private:
	POINT2	position;

public:
	Tank();
	Tank(int x, int y);
	~Tank();

	void update();
	void handleInput(InputState &is);
	void render(WinCanvas &wc);
};