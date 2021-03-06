﻿// game_engine_base.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "game_engine_base.h"

#include <WindowRenderingNew.h>
#include <WindowRenderingNew.cpp>
#include <iostream>
#include <fstream>
#include <string>

#include "Player.h"
#include "Drawable.h"
#include "Weapon.h"
#include "Actor.h"
#include "Animation.h"
#include "Triggers.h"

#define MAX_LOADSTRING 100

#pragma message("All systems Online")

enum TextureFillType
{
	WrapModeTile = Gdiplus::WrapMode::WrapModeTile,        // 0
	WrapModeTileFlipX = Gdiplus::WrapMode::WrapModeTileFlipX,   // 1
	WrapModeTileFlipY = Gdiplus::WrapMode::WrapModeTileFlipY,   // 2
	WrapModeTileFlipXY = Gdiplus::WrapMode::WrapModeTileFlipXY,  // 3
	WrapModeClamp = Gdiplus::WrapMode::WrapModeClamp,       // 4

	Sprite = 5, //5 Just displays image

};


class Func_View_Layer:public Actor
{
public:
	int TargetLayer = 0;
	Func_View_Layer(int TargetLayer,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Func_View_Layer(int TargetLayer,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	Func_View_Layer(int TargetLayer,Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
};
Func_View_Layer::Func_View_Layer(int TargetLayer,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) :Actor(image, image_rect, HasCollision,collision, DrawAsSprite, FillType, Layer)
{
	this->TargetLayer = TargetLayer;
}
Func_View_Layer::Func_View_Layer(int TargetLayer,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Actor(image, image_rect, HasCollision, DrawAsSprite, FillType, Layer)
{
	this->TargetLayer = TargetLayer;
}
Func_View_Layer::Func_View_Layer(int TargetLayer,Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer) : Actor(image, pt, HasCollision,collision, DrawAsSprite, FillType, Layer)
{
	this->TargetLayer = TargetLayer;
}


bool CheckPlayerCollision(Player*&player, std::vector<Actor*>*&world_actors,OUT Actor*&caller)
{
	if (world_actors->empty()) { return false; }
	for (UINT i = 0; i < world_actors->size(); i++)
	{
		if (player->GetLayer()== world_actors->at(i)->Layer)
		{
			if (world_actors->at(i)->HasCollision == true)
			{
				if (player->collision.IntersectsWith(world_actors->at(i)->collision))
				{
					if (dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i)))
					{
						Trigger_Change_Layer*t = dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i));
						if (t->type == Trigger_Type::Trigger_Once)
						{
							player->SetLayer(t->LayerToChangeTo);
							dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i))->Used = true;
						}
						if (t->type == Trigger_Type::Trigget_One_Side_Once)
						{
							if (t->enter_dir == player->LastDir)
							{
								player->SetLayer(t->LayerToChangeTo);
								dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i))->Used = true;
							}
						}
						if (t->type == Trigger_Type::Trigger_One_Side_Multi) 
						{
							if (t->enter_dir == player->LastDir)
							{
								player->SetLayer(t->LayerToChangeTo);
							}
						}
						/*t->~Trigger_Change_Layer();*/
						caller = world_actors->at(i);
						return true;
					}
					
					else
					{
						while (player->collision.IntersectsWith(world_actors->at(i)->collision))
						{
							if (player->LastDir == MoveDirection::DOWN)
							{
								player->SetY(player->GetY()-1);
								player->collision.Y -= 1;
							}
							else if (player->LastDir == MoveDirection::UP)
							{
								player->SetY(player->GetY() + 1);
								player->collision.Y += 1;
							}
							else if (player->LastDir == MoveDirection::LEFT)
							{
								player->SetY(player->GetX() + 1);
								player->collision.X += 1;
							}
							else if (player->LastDir == MoveDirection::RIGHT)
							{
								player->SetY(player->GetX() - 1);
								player->collision.X -= 1;
							}
						}
						caller = world_actors->at(i);
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool CheckPlayerCollision(Player*&player, std::vector<Actor*>*&world_actors)
{
	if (world_actors->empty()) { return false; }
	for (UINT i = 0; i < world_actors->size(); i++)
	{
		if (player->GetLayer() == world_actors->at(i)->Layer)
		{
			if (world_actors->at(i)->HasCollision == true)
			{
				if (player->collision.IntersectsWith(world_actors->at(i)->collision))
				{
					if (dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i)))
					{
						Trigger_Change_Layer*t = dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i));
						if (t->type == Trigger_Type::Trigger_Once)
						{
							player->SetLayer(t->LayerToChangeTo);
							dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i))->Used = true;
						}
						if (t->type == Trigger_Type::Trigget_One_Side_Once)
						{
							if (t->enter_dir == player->LastDir)
							{
								player->SetLayer(t->LayerToChangeTo);
								dynamic_cast<Trigger_Change_Layer*>(world_actors->at(i))->Used = true;
							}
						}
						if (t->type == Trigger_Type::Trigger_One_Side_Multi)
						{
							if (t->enter_dir == player->LastDir)
							{
								player->SetLayer(t->LayerToChangeTo);
							}
						}
						else
						{
							//do
						}
						/*t->~Trigger_Change_Layer();*/
						return true;
					}
					else
					{
						while (player->collision.IntersectsWith(world_actors->at(i)->collision))
						{
							if (player->LastDir == MoveDirection::DOWN)
							{
								player->SetY(player->GetY() - 1);
								player->collision.Y -= 1;
							}
							else if (player->LastDir == MoveDirection::UP)
							{
								player->SetY(player->GetY() + 1);
								player->collision.Y += 1;
							}
							else if (player->LastDir == MoveDirection::LEFT)
							{
								player->SetY(player->GetX() + 1);
								player->collision.X += 1;
							}
							else if (player->LastDir == MoveDirection::RIGHT)
							{
								player->SetY(player->GetX() - 1);
								player->collision.X -= 1;
							}
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

////base class for ptojectile data only
//class Projectile abstract :public Actor
//{
//public:
//
//};
class GunShot :public Actor
{
public:
	bool IsActive = false;
	int Speed = 0;
	GunShot(int Speed,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	GunShot(int Speed,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	GunShot(int Speed,Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer);
	static void CountPhysics(GunShot*&e, int delay, Gdiplus::PointF dest);
	static std::thread*CreatePhysicThread(GunShot*&e, Gdiplus::PointF dest)
	{
		std::thread*res = new std::thread(GunShot::CountPhysics, std::ref(e), e->Speed, dest);
		return res;
	}
};

GunShot::GunShot(int Speed,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer):Actor(image, image_rect, HasCollision, collision, DrawAsSprite, FillType, Layer)
{
	this->Speed = Speed;
}
GunShot::GunShot(int Speed,Gdiplus::Image*image, Gdiplus::RectF image_rect, bool HasCollision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer):Actor(image, image_rect, HasCollision, DrawAsSprite, FillType, Layer)
{
	this->Speed = Speed;
}
GunShot::GunShot(int Speed,Gdiplus::Image*image, Gdiplus::PointF pt, bool HasCollision, Gdiplus::RectF collision, bool DrawAsSprite, Gdiplus::WrapMode FillType, int Layer):Actor(image, pt, HasCollision, collision, DrawAsSprite, FillType, Layer)
{
	this->Speed = Speed;
}

void GunShot::CountPhysics(GunShot *& e, int delay, Gdiplus::PointF dest)
{
	if (dest.X < 0 || dest.Y < 0) { return; }
	else
	{
		int sx = e->Image_Rect.X;
		int sy = e->Image_Rect.Y;
		e->IsActive = true;
		float multiply = dest.Y / dest.X;
		while (dest.Y != e->Image_Rect.Y || dest.X != e->Image_Rect.X)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			e->Image_Rect.X += 1;
			e->Image_Rect.Y = e->Image_Rect.X*multiply;
		}
		/*e->Image_Rect.X = sx;
		e->Image_Rect.Y = sy;*/
		e->IsActive = false;
		return;
	}
}






// Global Variables:
HINSTANCE hInst;                               
WindowRendering*window;

Player*player;

std::vector<Actor*>*world_actors = new std::vector<Actor*>();
GunShot*g;
Gdiplus::Point mousecoord(0, 0);
int ScreenHeight = 1000;
int ScreenWidth = 1000;

Gdiplus::RectF PlayerViewArea(0, 0, 0, 0);
int PlayerViewRadius = 600;
int PlayerSpeed = 2;

Gdiplus::Image*anim;



//void LoadMap(std::string filename)
//{
//	using namespace std;
//	ifstream file;
//	string line;
//	file.open(filename.c_str());
//
//	while (!file.eof())
//	{
//		if (line == "entity")
//		{
//		
//		}
//		if (line == "actor")
//		{
//			
//		}
//	}
//	file.close();
//}



void paint(PaintArgs e)
{
	using namespace Gdiplus;
	Gdiplus::Graphics graphics(e.hdc);

	graphics.Clear(Color::White);
	std::vector<Func_View_Layer*>*view_areas = new std::vector<Func_View_Layer*>();
	for (UINT i = 0; i < world_actors->size(); i++)
	{
		if (dynamic_cast<Func_View_Layer*>(world_actors->at(i)) && world_actors->at(i)->Layer == player->GetLayer())
		{
			view_areas->push_back(dynamic_cast<Func_View_Layer*>(world_actors->at(i)));
		}
		if (PlayerViewArea.Contains(world_actors->at(i)->Image_Rect) || PlayerViewArea.IntersectsWith(world_actors->at(i)->Image_Rect))
		{
			if (world_actors->at(i)->Layer == player->GetLayer())
			{
				if (!dynamic_cast<Func_View_Layer*>(world_actors->at(i)))
				{
					if (world_actors->at(i)->Visible == true)
					{
						if (world_actors->at(i)->DrawAsSprite != true)
						{
							if (((world_actors->at(i)->Image_Rect.X + world_actors->at(i)->Image_Rect.Width) < player->GetX() - PlayerViewRadius) && (world_actors->at(i)->Image_Rect.Y + world_actors->at(i)->Image_Rect.Height) < player->GetY()- PlayerViewRadius)
							{

							}
							else if (((world_actors->at(i)->Image_Rect.X + world_actors->at(i)->Image_Rect.Width) > player->GetX() + PlayerViewRadius) && (world_actors->at(i)->Image_Rect.Y + world_actors->at(i)->Image_Rect.Height) > player->GetY() + PlayerViewRadius)
							{

							}
							else
							{

								/*RectF draw_rect(world_actors->at(i)->Image_Rect.X, world_actors->at(i)->Image_Rect.Y, world_actors->at(i)->Image_Rect.Width, world_actors->at(i)->Image_Rect.Height);

								if ((world_actors->at(i)->Image_Rect.X > player->Image_Rect.X) && world_actors->at(i)->Image_Rect.X < (player->Image_Rect.X + PlayerViewRadius))
								{
									if ((world_actors->at(i)->Image_Rect.X + world_actors->at(i)->Image_Rect.Width)>(player->Image_Rect.X+PlayerViewRadius))
									{
										draw_rect.Width = PlayerViewRadius;
									}
								}
								if ((world_actors->at(i)->Image_Rect.Height + world_actors->at(i)->Image_Rect.Y) > (player->Image_Rect.Y + PlayerViewRadius))
								{
									draw_rect.Height = player->Image_Rect.Y + PlayerViewRadius;
								}

								if ((world_actors->at(i)->Image_Rect.Width + world_actors->at(i)->Image_Rect.X) > (player->Image_Rect.X + PlayerViewRadius))
								{
									draw_rect.Width = player->Image_Rect.X + PlayerViewRadius;
								}
								if (world_actors->at(i)->Image_Rect.X < (player->Image_Rect.X - PlayerViewRadius))
								{

									if ((world_actors->at(i)->Image_Rect.X + world_actors->at(i)->Image_Rect.Width) > player->Image_Rect.X - PlayerViewRadius)
									{
										draw_rect.X++;
										draw_rect.Width--;
									}
								}
								if (world_actors->at(i)->Image_Rect.Y < (player->Image_Rect.Y - PlayerViewRadius))
								{
									if ((world_actors->at(i)->Image_Rect.Y + world_actors->at(i)->Image_Rect.Height) > player->Image_Rect.Y - PlayerViewRadius)
									{
										draw_rect.Y++;
										draw_rect.Height--;
									}
								}*/
								TextureBrush* brush = new TextureBrush(world_actors->at(i)->image, world_actors->at(i)->FillType);
								if (world_actors->at(i)->RotateDegree != 0) { brush->RotateTransform(world_actors->at(i)->RotateDegree); }
								if (world_actors->at(i)->Scale != 1) { brush->ScaleTransform(world_actors->at(i)->Scale, world_actors->at(i)->Scale); }
								graphics.FillRectangle(brush, world_actors->at(i)->Image_Rect);
								delete brush;

							}
						}
						else
						{
							if (dynamic_cast<AnimatedSprite*>(world_actors->at(i)))
							{
								if (dynamic_cast<AnimatedSprite*>(world_actors->at(i))->AnimationIsActive == false)
								{
									dynamic_cast<AnimatedSprite*>(world_actors->at(i))->StartAnimThread();
								}
							}
							graphics.DrawImage(world_actors->at(i)->image, world_actors->at(i)->Image_Rect);
						}
					}
				}
			}
			else
			{
				if (!world_actors->empty())
				{
					for (UINT u = 0; u < view_areas->size(); u++)
					{
						if (view_areas->at(u)->collision.Contains(world_actors->at(i)->Image_Rect) && !dynamic_cast<Func_View_Layer*>(world_actors->at(i)))
						{
							if (world_actors->at(i)->Visible = true)
							{
								if (world_actors->at(i)->DrawAsSprite != true)
								{
									graphics.FillRectangle(new TextureBrush(world_actors->at(i)->image, world_actors->at(i)->FillType), world_actors->at(i)->Image_Rect);
								}
								else
								{
									graphics.DrawImage(world_actors->at(i)->image, world_actors->at(i)->Image_Rect);
								}
							}
						}
					}
				}
			}
		}
	}

	if (player->image->AnimationIsActive == false)
	{
		player->image->StartAnimThread();
	}

	graphics.DrawImage(player->image->image, player->image->Image_Rect);

	graphics.DrawImage(g->image, g->Image_Rect);

	view_areas->~vector();
	graphics.~Graphics();
}

void onkeydown(KeyDownArgs e)
{
	if (e.Key == KeyCodes::eKeyCodes::KEY_DOWN)
	{
		int sy = player->image->Image_Rect.Y;
		player->image->Image_Rect.Y += PlayerSpeed/2;
		player->collision.Y += PlayerSpeed/2;
		player->LastDir = MoveDirection::DOWN;

		CheckPlayerCollision(player, world_actors);
		if (player->image->Image_Rect.Y != sy)
		{
			for (UINT i = 0; i < world_actors->size(); i++)
			{
				world_actors->at(i)->Image_Rect.Y -= PlayerSpeed / 2;
				world_actors->at(i)->collision.Y -= PlayerSpeed / 2;
			}
		}
		
	}
	if (e.Key == KeyCodes::eKeyCodes::KEY_RIGHT)
	{
		int sx = player->image->Image_Rect.X;
		player->image->Image_Rect.X += PlayerSpeed/2;
		player->collision.X += PlayerSpeed/2;
		player->LastDir = MoveDirection::RIGHT;
		CheckPlayerCollision(player, world_actors);
		if (player->image->Image_Rect.X != sx)
		{
			for (UINT i = 0; i < world_actors->size(); i++)
			{
				world_actors->at(i)->Image_Rect.X -= PlayerSpeed / 2;
				world_actors->at(i)->collision.X -= PlayerSpeed / 2;
			}
		}
		
	}
	if (e.Key == KeyCodes::eKeyCodes::KEY_UP)
	{
		int sy = player->image->Image_Rect.Y;
		player->image->Image_Rect.Y -= PlayerSpeed/2;
		player->collision.Y -= PlayerSpeed/2;
		if (player->image->Image_Rect.Y < 0) { player->image->Image_Rect.Y = 0; }
		player->LastDir = MoveDirection::UP;
		CheckPlayerCollision(player, world_actors);
		if (player->image->Image_Rect.Y != sy)
		{
			for (UINT i = 0; i < world_actors->size(); i++)
			{
				world_actors->at(i)->Image_Rect.Y += PlayerSpeed / 2;
				world_actors->at(i)->collision.Y += PlayerSpeed / 2;
			}
		}
		

	}
	if (e.Key == KeyCodes::eKeyCodes::KEY_LEFT)
	{
		int sx = player->image->Image_Rect.X;
		player->image->Image_Rect.X -= PlayerSpeed/2;
		player->collision.X -= PlayerSpeed/2;
		if (player->image->Image_Rect.X < 0) { player->image->Image_Rect.X = 0; }
		player->LastDir = MoveDirection::LEFT;
		CheckPlayerCollision(player, world_actors);
		if (player->image->Image_Rect.X != sx)
		{
			for (UINT i = 0; i < world_actors->size(); i++)
			{
				world_actors->at(i)->Image_Rect.X += PlayerSpeed / 2;
				world_actors->at(i)->collision.X += PlayerSpeed / 2;
			}
		}
		
	}

	PlayerViewArea.X = player->image->Image_Rect.X - PlayerViewRadius;
	PlayerViewArea.Y = player->image->Image_Rect.Y - PlayerViewRadius;

}

void onclick(MouseClickArgs e)
{
	mousecoord.X = e.x;
	mousecoord.Y = e.y;
	if (g->IsActive == false)
	{
		g->Image_Rect.X = player->GetX();
		g->Image_Rect.Y = player->GetY();
		GunShot::CreatePhysicThread(g, Gdiplus::PointF(e.x, e.y))->detach();
	}
}

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	using namespace Gdiplus;

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	anim = new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\image.gif");

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	PlayerViewArea.Height = PlayerViewRadius*2;
	PlayerViewArea.Width = PlayerViewRadius*2;
	
	/*world_actors->push_back(new Actor(new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\Dust2_layout.png"), Gdiplus::RectF(0, 0, 700, 1000), false, true, WrapMode::WrapModeTile, 0));*/
	////world_actors->push_back(new Actor(new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\floor_checkboard_texture.png"), Gdiplus::RectF(300, 0, 200, 200), false, false, WrapMode::WrapModeTile, 1,0,5));
	//world_actors->push_back(new Actor(new Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\floor_checkboard_texture.png"), Rect(100, 100, 500, 500), true, false, WrapMode::WrapModeTile));
	player = new Player(0,20,true,new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\player_idle.gif"), Gdiplus::RectF(0, 0, 60, 60), Gdiplus::RectF(0,0,50,50));
	player->DrawImageAsAnim = true;
	/*world_actors->push_back(new Trigger_Change_Layer(1, Trigger_Type::Trigget_One_Side_Once, MoveDirection::RIGHT, new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\ground_texture.png"), Gdiplus::RectF(100, 0, 60, 60), true, true, WrapMode::WrapModeTile, 0));*/
	


	/*world_actors->push_back(new Func_View_Layer(1, new Gdiplus::Image(L""), Gdiplus::RectF(50, 300, 100, 100), true, true, WrapMode::WrapModeTile, 0));
	world_actors->push_back(new Actor(new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\floor_checkboard_texture.png"), Gdiplus::RectF(200, 200, 500, 500), false, false, WrapMode::WrapModeTile, 1));
	world_actors->push_back(new Actor(new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\floor_checkboard_texture.png"), Gdiplus::RectF(50, 300, 60, 60), true, true, WrapMode::WrapModeTile, 0));
	world_actors->push_back(new Actor(new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\floor_checkboard_texture.png"), Gdiplus::RectF(50, 100, 60, 60), true, true, WrapMode::WrapModeTile, 0));*/
	/*t = new std::thread(PlayImageAnim, std::ref(anim), 20,true);
	t->detach();*/
	world_actors->push_back(new AnimatedSprite(20,true,new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\image.gif"), Gdiplus::RectF(50, 100, 60, 60), true, 0));
	g = new GunShot(1, new Gdiplus::Image(L"C:\\Users\\catgu\\source\\repos\\game_engine_base\\Debug\\assets\\models\\gunshot.bmp"), Gdiplus::RectF(0, 0, 10, 10), true, true, WrapMode::WrapModeTile, 0);
    // TODO: Place code here.
	
	using namespace Gdiplus;

	EventListener*l = new EventListener();
	l->OnPaint = paint;
	l->OnKeyDown = onkeydown;
	l->OnMouseClick = onclick;
	window = new WindowRendering(hInstance, 0, L"0", 0, WS_OVERLAPPEDWINDOW, 0, 0, 1000, 1000, MAKEINTRESOURCE(IDC_MYICON), LoadCursor(hInstance, IDC_ARROW), l);
	if (window->Show())
	{
		HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEENGINEBASE));

		MSG msg;

		// Main message loop:
		while (GetMessage(&msg, nullptr, 0, 0))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		GdiplusShutdown(gdiplusToken);
		return (int)msg.wParam;
	}
	else
	{
		//Handle Window Errors
		
		GdiplusShutdown(gdiplusToken);
		return 0;
	}

   
}




// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
