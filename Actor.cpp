#include "stdafx.h"
#include "Actor.h"
Actor::Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, int RotateDegree, int Scale, bool AnimateImage) : Drawable(image, image_rect)
{
	this->HasCollision = HasCollision;
	this->collision = collision;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;
	this->Scale = Scale;
	this->RotateDegree = RotateDegree;
	this->AnimateImage = AnimateImage;
}
Actor::Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, int RotateDegree, int Scale, bool AnimateImage) : Drawable(image, image_rect)
{
	this->HasCollision = HasCollision;
	this->collision = image_rect;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;
	this->Scale = Scale;
	this->RotateDegree = RotateDegree;
	this->AnimateImage = AnimateImage;
}
Actor::Actor(Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, int RotateDegree, int Scale, bool AnimateImage) : Drawable(image, pt)
{
	this->HasCollision = HasCollision;
	this->collision = collision;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;
	this->Scale = Scale;
	this->RotateDegree = RotateDegree;
	this->AnimateImage = AnimateImage;
}

Actor::Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, bool AnimateImage) : Drawable(image, image_rect)
{
	this->HasCollision = HasCollision;
	this->collision = collision;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;
	this->AnimateImage = AnimateImage;

}
Actor::Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, bool AnimateImage) : Drawable(image, image_rect)
{
	this->HasCollision = HasCollision;
	this->collision = image_rect;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;
	this->AnimateImage = AnimateImage;

}
Actor::Actor(Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer, bool AnimateImage) : Drawable(image, pt)
{
	this->HasCollision = HasCollision;
	this->collision = collision;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;
	this->AnimateImage = AnimateImage;
}

Actor::Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Drawable(image, image_rect)
{
	this->HasCollision = HasCollision;
	this->collision = collision;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;


}
Actor::Actor(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Drawable(image, image_rect)
{
	this->HasCollision = HasCollision;
	this->collision = image_rect;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;


}
Actor::Actor(Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Drawable(image, pt)
{
	this->HasCollision = HasCollision;
	this->collision = collision;
	this->FillType = FillType;
	this->DrawAsSprite = DrawAsSprite;
	this->Layer = Layer;

}
