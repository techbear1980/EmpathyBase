
#include "Empathy.h"
#include "EmpathyTypes.h"

int EmpathyBase::requestedScreenW = 0, EmpathyBase::requestedScreenH = 0;
EmpathyGraphics *EmpathyBase::graphics;
EmpathySound    *EmpathyBase::sound;
EmpathyInput    *EmpathyBase::input;



//***************************************************************************************************************************************************************************
void EmpathyRect::Center(void)
{

}

//***************************************************************************************************************************************************************************
void EmpathyRect::Scale(float sx, float sy)
{
	int cx = (left + right) / 2;
	int cy = (top + bottom) / 2;
	left   = (left   - cx)*sx + cx;
	right  = (right  - cx)*sx + cx;
	top    = (top    - cy)*sy + cy;
	bottom = (bottom - cy)*sy + cy;

}

//***************************************************************************************************************************************************************************
void EmpathyRect::Translate(float sx, float sy)
{
	left += sx;
	right += sx;
	top += sy;
	bottom += sy;
}

//***************************************************************************************************************************************************************************
void EmpathyRect::Modify(int dl, int dt, int dr, int db)
{
	left += dl;
	right += dr;
	top += dt;
	bottom += db;
}


