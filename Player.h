#pragma once
#include "Drawable.h"
enum MoveDirection
{
	//If object is not suposed to be moved, or haven't been yet
	NONE,
	UP=1,
	DOWN,
	LEFT,
	RIGHT,
};
class Player :public Drawable
{
public:
	int WeapomId = 0;
	int Rotation = 0;
	int Layer = 0;
	bool DrawImageAsAnim = false;
	Gdiplus::RectF collision = Gdiplus::RectF(0, 0, 0, 0);
	MoveDirection LastDir = MoveDirection::NONE;
	Player(Gdiplus::Image*image, Gdiplus::RectF image_rect, Gdiplus::RectF collision);
	Player(Gdiplus::Image*image, Gdiplus::PointF pt, Gdiplus::RectF collision);
	~Player();
};

