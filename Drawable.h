#pragma once
#include "stdafx.h"
class Drawable
{
public:
	Gdiplus::RectF Image_Rect = Gdiplus::RectF(0, 0, 0, 0);
	Gdiplus::Image*image;
	Drawable(Gdiplus::Image*image,Gdiplus::RectF image_rect);
	Drawable(Gdiplus::Image*image, Gdiplus::PointF pt);
	~Drawable();
};

class Texture
{
protected:
	
public:
	Gdiplus::TextureBrush*brush;
	Gdiplus::RectF rect;
	Texture(Gdiplus::Image*image, Gdiplus::RectF rect);
	Texture(Gdiplus::Image*image, Gdiplus::RectF rect, Gdiplus::WrapMode = Gdiplus::WrapModeTile);
	void FillRect(Gdiplus::RectF,Gdiplus::Graphics&graphics);
	void FillRect(Gdiplus::Graphics&graphics);
};

