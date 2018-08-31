#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool OverridePlayerSprite, std::string Name) :Drawable(image, image_rect)
{
	this->Name = Name;
	this->OverridePlayerSprite = OverridePlayerSprite;
}

Weapon::Weapon(Gdiplus::Image*image, Gdiplus::PointF pt, bool OverridePlayerSprite, std::string Name) : Drawable(image, pt)
{
	this->Name = Name;
	this->OverridePlayerSprite = OverridePlayerSprite;
}


Weapon::~Weapon()
{
}


