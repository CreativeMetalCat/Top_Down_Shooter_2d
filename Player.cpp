#include "stdafx.h"
#include "Player.h"


Player::Player(Gdiplus::Image*image, Gdiplus::RectF image_rect, Gdiplus::RectF collision):Drawable(image,image_rect)
{
	this->collision = collision;
}

Player::Player(Gdiplus::Image*image, Gdiplus::PointF pt, Gdiplus::RectF collision) : Drawable(image, pt)
{
	this->collision = collision;
}

Player::~Player()
{
}
