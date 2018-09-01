#include "stdafx.h"
#include "Animation.h"


AnimatedSprite::AnimatedSprite(int FrameDelay, bool Looped, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, int Layer) :Actor(image, image_rect, HasCollision, true, Gdiplus::WrapMode::WrapModeTile, Layer)
{
	this->FrameDelay = FrameDelay;
	this->Looped = Looped;
}
AnimatedSprite::AnimatedSprite(int FrameDelay, bool Looped, Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, int Layer) : Actor(image, image_rect, HasCollision, true, Gdiplus::WrapMode::WrapModeTile, Layer)
{
	this->FrameDelay = FrameDelay;
	this->Looped = Looped;
}
AnimatedSprite::AnimatedSprite(int FrameDelay, bool Looped, Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, int Layer) : Actor(image, pt, HasCollision, collision, true, Gdiplus::WrapMode::WrapModeTile, Layer)
{
	this->FrameDelay = FrameDelay;
	this->Looped = Looped;
}

void StartSpriteAnim(IN Gdiplus::Image*&image, IN Gdiplus::RectF &image_rect, int delay, bool Looped, OUT bool &active)
{
	active = true;
	do {
		UINT dcount = 0;
		GUID *dimensionsIDs;
		dcount = image->GetFrameDimensionsCount();
		dimensionsIDs = new GUID[dcount];
		image->GetFrameDimensionsList(dimensionsIDs, dcount);
		UINT frame_count = image->GetFrameCount(&dimensionsIDs[0]);
		int y = 0;
		GUID pageGUID = Gdiplus::FrameDimensionTime;

		for (UINT i = 0; i <= frame_count; i++)
		{

			image->SelectActiveFrame(&pageGUID, i);
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		}
		image->SelectActiveFrame(&pageGUID, 0);
		delete[]dimensionsIDs;
	} while (Looped == true);
	active = false;
}
void StartImageAnim(Gdiplus::Image*&image, Gdiplus::RectF &image_rect, int delay, bool Looped)
{
	do {
		UINT dcount = 0;
		GUID *dimensionsIDs;
		dcount = image->GetFrameDimensionsCount();
		dimensionsIDs = new GUID[dcount];
		image->GetFrameDimensionsList(dimensionsIDs, dcount);
		UINT frame_count = image->GetFrameCount(&dimensionsIDs[0]);
		int y = 0;
		GUID pageGUID = Gdiplus::FrameDimensionTime;

		for (UINT i = 0; i <= frame_count; i++)
		{

			image->SelectActiveFrame(&pageGUID, i);
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		}
		image->SelectActiveFrame(&pageGUID, 0);
		delete[]dimensionsIDs;
	} while (Looped == true);
}
