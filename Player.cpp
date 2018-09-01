#include "stdafx.h"
#include "Player.h"


Player::Player(AnimatedSprite*image, Gdiplus::RectF image_rect, Gdiplus::RectF collision)
{
	this->collision = collision;
	this->image = image;
}

Player::Player(AnimatedSprite*image, Gdiplus::PointF pt, Gdiplus::RectF collision)
{
	this->image = image;
	this->collision = collision;
}
Player::Player(int layer, int AnimationFrameDelay, bool AnimationIsLooped, Gdiplus::Image*image, Gdiplus::RectF image_rect, Gdiplus::RectF collision)
{
	this->collision = collision;
	this->image = new AnimatedSprite(AnimationFrameDelay, AnimationIsLooped, image, image_rect, true, layer);
}

Player::Player(int layer, int AnimationFrameDelay, bool AnimationIsLooped, Gdiplus::Image*image, Gdiplus::PointF pt, Gdiplus::RectF collision)
{
	this->collision = collision;
	this->image = new AnimatedSprite(AnimationFrameDelay, AnimationIsLooped, image, Gdiplus::RectF(pt.X,pt.Y,image->GetWidth(),image->GetHeight()), true, layer);
}

Player::~Player()
{
}
