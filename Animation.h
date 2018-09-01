#pragma once
#include "stdafx.h"
#include "Actor.h"

void StartSpriteAnim(IN Gdiplus::Image*&image, IN Gdiplus::RectF &image_rect, int delay, bool Looped, OUT bool &active);
void StartImageAnim(Gdiplus::Image*&image, Gdiplus::RectF &image_rect, int delay, bool Looped);

class AnimatedSprite :public Actor
{
	std::thread*anim_thread;
public:

	int FrameDelay = 20;
	bool Looped = false;
	bool AnimationIsActive = false;
	AnimatedSprite(int FrameDelay, bool Looped, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, int Layer);
	AnimatedSprite(int FrameDelay, bool Looped, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, int Layer);
	AnimatedSprite(int FrameDelay, bool Looped, Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, int Layer);
	void StartAnimThread()
	{
		anim_thread = new std::thread(StartSpriteAnim, std::ref(this->image), std::ref(this->Image_Rect), this->FrameDelay, this->Looped, std::ref(this->AnimationIsActive));
		anim_thread->detach();
	}
};

