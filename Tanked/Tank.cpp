#include "ui/WinCanvas.h"
#include "Tank.h"

Tank::Tank()
{
	position = POINT2(0, 0);
}
Tank::Tank(int x, int y)
{
	position = POINT2(x, y);
}

Tank::~Tank()
{

}

void Tank::update()
{

}

void Tank::render(WinCanvas &wc)
{
	wc.DrawPoly(Triangle(position+POINT2(0, 0), 
						position + POINT2(60, 30), 
						position + POINT2(30, 60)),
		LRGB(0, 0, 0), 1);

}

void Tank::handleInput(InputState &is)
{
	if (is.isActive('D'))
	{
		position = position + POINT2(0.1, 0);
	}
	if (is.isActive('A'))
	{
		position = position - POINT2(0.1, 0);
	}
}
