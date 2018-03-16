#ifndef EMPATHY_SOUND_H
#define EMPATHY_SOUND_H

#include "EmpathyTypes.h"

/*
			EmpathySound should let you:
- GetAsset (loading it if necessary)
- UnloadAsset
- start sound (with looping flag)
- stop sound
- change pitch, pan, volume of sound
- start streaming music
- stop streaming music
- change volume of streaming music
*/

//**********************************************************************************************************************
struct EmpathySound
{
	EmpathySound(){;};
	virtual ~EmpathySound(){;};

	// ************* general functions
	virtual UL GetAsset(std::string path, std::string filenameWithoutSuffix) = 0;
	virtual void UnloadAsset(UL assetID) = 0;

	virtual void Start(UL assetID, float volume = 1.0f, float pitch = 1.0f) = 0;
	virtual void StartFrom(UL assetID, UL position) = 0;
	virtual void Stop(UL assetID) = 0;
	virtual void Resume(UL assetID) = 0;

	virtual bool IsSoundPlaying(UL assetID) = 0;
	virtual UL   GetPositionOfPlayingSound(UL assetID) = 0;
	virtual UL   SampleLength(UL assetID) = 0;
	virtual float   GetSample(UL assetID, UL index) = 0;
	virtual void SetSample(UL assetID, UL index, float value) = 0;

};





#endif

