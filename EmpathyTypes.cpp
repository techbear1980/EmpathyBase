
#include "EmpathyTypes.h"


//****************************************************************************************************************
void EmpathyRect::Center(void)
{
	float w = right - left;
	right = w / 2;
	left = -w / 2;

	float h = bottom - top;
	bottom = h / 2;
	top = -h / 2;
}

//****************************************************************************************************************
void EmpathyRect::Scale(float sx, float sy)
{
	left *= sx;
	right *= sx;
	top *= sy;
	bottom *= sy;
}

//****************************************************************************************************************
void EmpathyRect::Translate(float sx, float sy)
{
	left += sx;
	right += sx;
	top += sy;
	bottom += sy;
}

