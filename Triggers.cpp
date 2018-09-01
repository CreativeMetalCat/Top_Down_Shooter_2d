#include "stdafx.h"
#include "Triggers.h"


Trigger_Change_Layer::Trigger_Change_Layer(int LayerToChangeTo, Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) :Trigger(type, enter_dir, image, image_rect, true, collision, DrawAsSprite, FillType, Layer)
{
	this->LayerToChangeTo = LayerToChangeTo;
}
Trigger_Change_Layer::Trigger_Change_Layer(int LayerToChangeTo, Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Trigger(type, enter_dir, image, image_rect, true, DrawAsSprite, FillType, Layer)
{
	this->LayerToChangeTo = LayerToChangeTo;
}
Trigger_Change_Layer::Trigger_Change_Layer(int LayerToChangeTo, Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Trigger(type, enter_dir, image, pt, true, collision, DrawAsSprite, FillType, Layer)
{
	this->LayerToChangeTo = LayerToChangeTo;
}
Trigger_Change_Layer::~Trigger_Change_Layer()
{
	this->image->~Image();
}

Trigger::Trigger(Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Actor(image, image_rect, HasCollision, collision, DrawAsSprite, FillType, Layer)
{
	this->type = type;
	this->enter_dir = enter_dir;
}
Trigger::Trigger(Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Actor(image, image_rect, HasCollision, DrawAsSprite, FillType, Layer)
{
	this->type = type;
	this->enter_dir = enter_dir;
}
Trigger::Trigger(Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Actor(image, pt, HasCollision, collision, DrawAsSprite, FillType, Layer)
{
	this->type = type;
	this->enter_dir = enter_dir;
}



