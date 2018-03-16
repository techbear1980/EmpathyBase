#ifndef EMPATHY_INPUT_H
#define EMPATHY_INPUT_H

#include "EmpathyTypes.h"
/*
			EmpathyInput should let you read:
- current key positions
- current key transitions
- current mouse positions
- current mouse button positions
- current mouse button transitions
- current mouse wheel change
- current joystick existence
- current joystick button positions
- current joystick button transitions
- current joystick analog positions

- current milliseconds
- current seconds
- current minutes

- force mouse position

*/

//**********************************************************************************************************************
struct EmpathyInputPoint // for fingers and mice
{
	void Clear(void) {isDown = isHeldDown = isUp = lastState = false; x = y = 0; };

	bool isDown, isHeldDown, isUp, lastState;
	int x,y;
};

//**********************************************************************************************************************
struct EmpathyInput
{
	EmpathyInput()   {;};
	virtual ~EmpathyInput()   {;};

	virtual bool IsKeyDown(UL keyIndex) = 0;
	virtual bool IsKeyDecending(UL keyIndex, bool inDraw = false) = 0;
	virtual bool IsKeyAscending(UL keyIndex, bool inDraw = false) = 0;
	virtual bool GetKeyFromBuffer(UL &value) = 0;

	virtual bool IsPointerGoingDown(int index) = 0;
	virtual bool IsPointerGoingUp(int index) = 0;
	virtual bool IsPointerHeldDown(int index) = 0;
	virtual int  PointerX(int index) = 0;
	virtual int  PointerY(int index) = 0;
	virtual void ForcePointerTo(int x, int y) = 0;

	virtual int  GetMouseWheelChange(void) = 0;
	virtual void SetMouseWheelChange(int value) = 0;

	virtual bool IsControllerWorking(int deviceIndex) = 0;
	virtual bool IsControllerButtonGoingDown(int deviceIndex, int index) = 0;
	virtual bool IsControllerButtonGoingUp(int deviceIndex, int index) = 0;
	virtual bool IsControllerButtonHeldDown(int deviceIndex, int index) = 0;
	virtual bool IsControllerHatButtonHeldDown(int deviceIndex, int index) = 0;
	virtual float ControllerAxis(int deviceIndex, int index) = 0;

	virtual UL CurrentMilliseconds(void) = 0;
	virtual UL CurrentSeconds(void) = 0;
	virtual UL CurrentMinutes(void) = 0;

	virtual bool GetFileName(std::string &path, std::string &name, bool newFile = false) = 0; // opens a system dialog to choose a file

	virtual bool OpenFile           (std::string path, std::string name, std::string suffix, bool read, bool write, bool binary, bool append) = 0; // tries to open a file
	virtual void CloseFile          (void) = 0; // closes the opened file
	virtual bool FileReadLine       (std::string &readData) = 0;
	virtual bool FileWriteString    (std::string &writeData) = 0;
	virtual bool FileReadData       (char *memPtr, int maxToRead, int &amountRead) = 0;
	virtual bool FileWriteData      (char *memPtr, int amountToWrite) = 0;

	virtual bool OpenFileWithBuffering(std::string path, std::string filenameWithoutSuffix, std::string suffix) = 0;
	virtual bool ReadFileWithBuffering(char *memPtr, int maxToRead, int &amountRead) = 0;

	virtual void ForceCloseApp      (void) = 0;

	virtual UL HookFunctionToTimer(int millsToWait, void(*functToCall)(void)) = 0;
	virtual void StopFunctionTimer(UL timerID) = 0;

	// functions for real-time timers (on Windows, based on SYSTEMTIME)
	virtual UL GetSystemTimer(std::string name) = 0;
	virtual void SetToNow         (UL timerID) = 0;
	virtual void AddMinutes       (UL timerID, long minutes) = 0;
	virtual long MinutesDifference(UL timerID, UL futureTimeID) = 0;
	virtual long SecondsDifference(UL timerID, UL futureTimeID) = 0;

	virtual void CopyStringToClipboard(std::string &s) = 0;

	// kinda assumes that these will be used for storing and retrieving data from the Windows registry
	virtual bool StoreTextData(std::string key, std::string data) = 0;
	virtual bool RetrieveTextData(std::string key, std::string &data) = 0;


	EmpathyInputPoint pointArray[5];

	bool usingTouchScreen;

};


#endif

