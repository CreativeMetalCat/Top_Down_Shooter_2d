#pragma once
#include "stdafx.h"
#include "Actor.h"

enum Trigger_Type
{
	Trigger_Once,
	Trigger_Multi,
	Trigget_One_Side_Once,
	Trigger_One_Side_Multi
};

class Trigger :public Actor
{
public:
	Trigger_Type type = Trigger_Once;
	//if trigger type is set to tigger_one_side
	MoveDirection enter_dir = MoveDirection::NONE;
	//if trigger type is  set to Trigger_Once or Trigger_One_Side_Once
	bool Used = false;
	Trigger(Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Trigger(Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Trigger(Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);

};

class Trigger_Change_Layer :public Trigger
{
public:
	int LayerToChangeTo = 0;
	Trigger_Change_Layer(int LayerToChangeTo, Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Trigger_Change_Layer(int LayerToChangeTo, Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Trigger_Change_Layer(int LayerToChangeTo, Trigger_Type type, MoveDirection enter_dir, Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	~Trigger_Change_Layer();
};

