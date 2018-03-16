#ifndef EMPATHY_TYPES_H
#define EMPATHY_TYPES_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>


# define GLM_FORCE_RADIANS  // use radians not angles
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#ifndef UL
#define UL unsigned long
#endif

const UL EMPATHY_TEXTCENTERED     = 0x001;
const UL EMPATHY_TEXTVERTCENTERED = 0x002;
const UL EMPATHY_TEXTRIGHTJUSTIF  = 0x004;

#define AppendInt(s,num)  { std::stringstream ssdjrfneisd; ssdjrfneisd << num; s += ssdjrfneisd.str(); }

#define AppendFilledInt(s,num, minimum)  { std::stringstream ssdjrfneisd; ssdjrfneisd << std::setfill ('0') << std::setw (minimum) << num; s += ssdjrfneisd.str(); }

#define AppendFilledFloat(s,num, leftMin, rightMax)  { std::stringstream ssdjrfneisd; ssdjrfneisd << std::setfill ('0') << std::setw (leftMin) << std::fixed << std::setprecision(rightMax) << num; s += ssdjrfneisd.str(); }

 

struct EmpathyRect
{
	EmpathyRect(void) { left = 0; top = 0; right = 0; bottom = 0; };
	EmpathyRect(int a, int b, int c, int d) { left = a; top = b; right = c; bottom = d; };

	EmpathyRect& EmpathyRect::operator=(const EmpathyRect& rhs) 
	{
		left = rhs.left;
		right = rhs.right;
		top = rhs.top;
		bottom = rhs.bottom;
		return *this;
	};

	bool Contains(int x, int y) {if (x < left || x > right || y < top || y > bottom) return false;  return true; };
	bool Contains(float x, float y) {if (x < left || x > right || y < top || y > bottom) return false;  return true; };

	void Center(void);
	void Scale(float sx, float sy);
	void Translate(float sx, float sy);
	void Modify(int dl, int dt, int dr, int db);

	int left,top,right,bottom;
};


// function for deleting every element in a vector; use only for vectors containing pointers.
template<class T> void purge( std::vector<T> & v ) 
{
    for (std::vector<T>::const_iterator sdfsdfwef = v.begin(); sdfsdfwef != v.end(); ++sdfsdfwef ) 
		 delete *sdfsdfwef;
    v.clear();
}




#endif