#pragma once
#include "Drawable.h"


class Weapon :public Drawable
{
public:
	bool OverridePlayerSprite = false;
	std::string Name = "";
	Weapon(Gdiplus::Image*image, Gdiplus::RectF image_rect, bool OverridePlayerSprite, std::string Name);
	Weapon(Gdiplus::Image*image, Gdiplus::PointF pt, bool OverridePlayerSprite, std::string Name);
	~Weapon();
};

