
#pragma once
#include "stdafx.h"
#include "Drawable.h"

class Actor : public Drawable
{
protected:
	//for overload
	virtual void Oveload() { return; }
public:
	Gdiplus::RectF collision = Gdiplus::RectF(0, 0, 0, 0);
	int RotateDegree = 0;
	bool HasCollision = true;
	bool DrawAsSprite = true;
	bool Visible = true;
	int Layer = 0;
	int Scale = 1;
	bool AnimateImage = false;
	Gdiplus::WrapMode FillType = Gdiplus::WrapMode::WrapModeTile;
	Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, int RotateDegree, int Scale, bool AnimateImage);
	Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, int RotateDegree, int Scale, bool AnimateImage);
	Actor(Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, int RotateDegree, int Scale, bool AnimateImage);

	Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, bool AnimateImage);
	Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, bool AnimateImage);
	Actor(Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, bool AnimateImage);

	Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Actor(Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);

};