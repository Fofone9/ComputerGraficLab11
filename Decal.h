#pragma once
#include "GraphicObject.h"
using namespace std;
using namespace glm;
class Decal
{
	ivec2 position;
	GraphicObject graphicObject;
	static shared_ptr<PhongMaterialWithTexture> decalTexture;
	static shared_ptr<Mesh> decalMesh;
public:
	Decal();
	Decal(ivec2);
	static void init();
	void draw();
};