#include "stdafx.h"
#include "Drawable.h"


Drawable::Drawable(Gdiplus::Image*image, Gdiplus::RectF image_rect)
{
	this->image = image;
	this->Image_Rect = image_rect;
}

Drawable::Drawable(Gdiplus::Image*image, Gdiplus::PointF pt)
{
	this->image = image;
	this->Image_Rect = Gdiplus::RectF(pt.X, pt.Y, image->GetWidth(), image->GetHeight());
}


Drawable::~Drawable()
{
	this->image->~Image();
}
Texture::Texture(Gdiplus::Image*image, Gdiplus::RectF rect)
{
	this->brush = new Gdiplus::TextureBrush(image);
	this->rect = rect;
}
Texture::Texture(Gdiplus::Image*image, Gdiplus::RectF rect,Gdiplus::WrapMode wrapmode)
{
	this->brush = new Gdiplus::TextureBrush(image, wrapmode, rect);
	this->rect = rect;
}
void Texture::FillRect(Gdiplus::RectF rect, Gdiplus::Graphics&graphics)
{
	graphics.FillRectangle(this->brush, rect);
}
void Texture::FillRect(Gdiplus::Graphics&graphics)
{
	graphics.FillRectangle(this->brush, this->rect);
}