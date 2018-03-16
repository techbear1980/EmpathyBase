#ifndef EMPATHY_GRAPHICS_H
#define EMPATHY_GRAPHICS_H

#include "EmpathyTypes.h"
/*
			EmpathyGraphics should let you:
- GetAsset (loading it if necessary)
- UnloadAsset

- draw text to screen
		rotated, in box, multi-line
- draw bitmap to screen
		rotate, scale, RGBA, sub-rectangle
- draw colored rect to screen
- draw colored arbitrary line to screen

- draw mesh to screen

- toggle system mouse display

*/

//**********************************************************************************************************************
struct EmpathyMaterial
{
	EmpathyMaterial(void) {bitmapID[0] = bitmapID[1] = bitmapID[2] = bitmapID[3] = 0;};

	UL shaderID;

	UL bitmapID[4]; // up to 4 bitmaps can be used

	glm::vec4 color[4]; // up to 4 colors can be used

	glm::vec3 normal[4]; // up to 4 normals can be used

	float value[12]; // up to 12 values can be used
};

//**********************************************************************************************************************
struct Empathy3DMesh
{
	std::string name;
	UL vertListID, indexListID;
	EmpathyMaterial material;
};

//**********************************************************************************************************************
struct Empathy3DObject
{
	std::string name;
	std::vector<Empathy3DMesh> meshList;
};

//**********************************************************************************************************************
struct EmpathyGraphics
{
	EmpathyGraphics() {;};
	virtual ~EmpathyGraphics(){;};

	// ************* general functions
	virtual UL GetAsset(std::string path, std::string filenameWithoutSuffix) = 0;
	virtual void UnloadAsset(UL assetID) = 0;

	virtual void Flush(void) = 0;


	// ************* font functions
	virtual void DrawText(UL fontID, std::string textToDraw, EmpathyRect r, glm::vec4 color, UL flags) = 0;
	virtual void DrawText(UL fontID, std::string textToDraw, int left, int top, int right, int bottom, glm::vec4 color, UL flags) = 0;
	// use this funct to word-wrap a string, copy the lines into stringList, and return a total height.
	virtual int  FitTextString(UL fontID, std::string textToWordWrap, int width) = 0;
	virtual int  GetTextStringWidth(UL fontID, std::string text) = 0;
	virtual int  GetTextStringHeight(UL fontID, std::string text) = 0;


	// ************* bitmap functions
	virtual UL MakeBitmapAsset(int w, int h, std::string name) = 0;

	virtual void SetPixel(UL textureID, int x,int y, float a, float r, float g, float b) = 0;
	virtual void GetPixel(UL textureID, int x,int y, float &a, float &r, float &g, float &b) = 0;
	virtual void GetBitmapSize(UL textureID, int &w, int &h) = 0;

	virtual void Draw2dBitmap(EmpathyMaterial &material, float x, float y, float rot = 0, float scale = 1, glm::vec4 color = glm::vec4(1,1,1,1)) = 0;
	virtual void Draw2dLine(EmpathyMaterial &material, float x1, float y1, float x2, float y2, glm::vec4 color = glm::vec4(1,1,1,1)) = 0;
	virtual void Draw2dQuad(EmpathyMaterial &material, glm::vec4 color = glm::vec4(1,1,1,1)) = 0;

	virtual void SetScreenRect(float left, float top, float right, float bottom) = 0;
	virtual void SetScreenQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) = 0;
	virtual void SetBitmapRect(UL bitmapID, float left, float top, float right, float bottom) = 0;
	virtual void SetBitmapQuad(UL bitmapID, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) = 0;
	virtual void SetBitmapUV  (float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) = 0;

	virtual bool SaveBitmapAssetAsPNGFile(UL textureID, std::string name) = 0;


	// ************* 3d mesh functions
	virtual UL MakeVertexListAsset(UL vertCount, std::string name, int numUVs = 0, bool useColor = true, bool useNormal = true) = 0;

	virtual void SetVertexPosition(UL vertexListID, UL vertexIndex, glm::vec3 pos) = 0;
	virtual void SetVertexNormal(UL vertexListID, UL vertexIndex, glm::vec3 n) = 0;
	virtual void SetVertexUV(UL vertexListID, UL vertexIndex, UL uvIndex, float u, float v) = 0;
	virtual void SetVertexColor(UL vertexListID, UL vertexIndex, glm::vec4 c) = 0;
	virtual void SetVertex(UL vertexListID, UL vertexIndex, glm::vec3 pos, glm::vec3 n, glm::vec4 c, float u, float v) = 0;

	virtual void GetVertexPosition(UL vertexListID, UL vertexIndex, glm::vec3 &pos) = 0;
	virtual void GetVertexNormal(UL vertexListID, UL vertexIndex, glm::vec3 &n) = 0;
	virtual void GetVertexUV(UL vertexListID, UL vertexIndex, UL uvIndex, float &u, float &v) = 0;
	virtual void GetVertexColor(UL vertexListID, UL vertexIndex, glm::vec4 &c) = 0;

	virtual UL MakeIndexListAsset(UL indexCount, std::string name) = 0;
	virtual void SetIndexValue(UL indexListID, UL index, int value) = 0;
	virtual void GetIndexValue(UL indexListID, UL index, int &value) = 0;


	virtual void Draw3DTriList(UL vertexListID, EmpathyMaterial &material, int triangleStartIndex, int triangleDrawCount, glm::mat4x4 objectMat, glm::mat4x4 cameraMat, glm::mat4x4 screenMat) = 0;
	virtual void Draw3DIndexedTriList(UL indexListID, UL vertexListID, EmpathyMaterial &material, int triangleStartIndex, int triangleDrawCount, glm::mat4x4 objectMat, glm::mat4x4 cameraMat, glm::mat4x4 screenMat) = 0;
	virtual void Draw3DLineList(UL vertexListID, EmpathyMaterial &material, int lineStartIndex, int lineDrawCount, glm::mat4x4 objectMat, glm::mat4x4 cameraMat, glm::mat4x4 screenMat) = 0;

	virtual bool Load3DObject(Empathy3DObject &obj, std::string path, std::string filenameWithoutSuffix) = 0;


	// ************* member variables

	std::vector<std::string> stringList; // FitTextString() will cut your string into individual word-wrapped lines, and store them here, until the next FitTextString() is called

};


#endif

