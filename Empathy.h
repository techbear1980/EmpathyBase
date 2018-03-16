#ifndef EMPATHY_H
#define EMPATHY_H

#include "EmpathyGraphics.h"
#include "EmpathySound.h"
#include "EmpathyInput.h"


// create and destroy your own platform specific derived versions of the managers in EmpathyBase.
//**********************************************************************************************************************
struct EmpathyBase
{
	static EmpathyGraphics *graphics;
	static EmpathySound    *sound;
	static EmpathyInput    *input;

	static int requestedScreenW, requestedScreenH;  // set these to 0 (= default), then call EmpathyInitialSettings(), so the app can make changes

};

extern void EmpathyInitialSettings(void);
extern void EmpathySetup(void);
extern void EmpathyShutdown(void);
extern void EmpathyTick(void);
extern void EmpathyDraw(void);
extern void EmpathySuspend(void);
extern void EmpathyResume(void);

#define SCW    (EmpathyBase::requestedScreenW)
#define SCH    (EmpathyBase::requestedScreenH)


#endif

