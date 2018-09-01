#pragma once
#include "Drawable.h"
#include "Animation.h"
class Player
{
public:
	int WeapomId = 0;
	int Rotation = 0;
	bool DrawImageAsAnim = false;
	AnimatedSprite*image;
	Gdiplus::RectF collision = Gdiplus::RectF(0, 0, 0, 0);
	MoveDirection LastDir = MoveDirection::NONE;
	Player(AnimatedSprite*image, Gdiplus::RectF image_rect, Gdiplus::RectF collision);
	Player( AnimatedSprite*image, Gdiplus::PointF pt, Gdiplus::RectF collision);
	Player(int layer, int AnimationFrameDelay,bool AnimationIsLooped,Gdiplus::Image*image, Gdiplus::RectF image_rect, Gdiplus::RectF collision);
	Player(int layer, int AnimationFrameDelay, bool AnimationIsLooped, Gdiplus::Image*image, Gdiplus::PointF pt, Gdiplus::RectF collision);
	float GetX() { return this->image->Image_Rect.X; }
	float GetY() { return this->image->Image_Rect.Y; }
	void SetX(float x) { this->image->Image_Rect.X = x; }
	void SetY(float y) { this->image->Image_Rect.Y = y; }
	int GetLayer()const { return this->image->Layer; }
	void SetLayer(int layer) { this->image->Layer = layer; }
	~Player();
};
