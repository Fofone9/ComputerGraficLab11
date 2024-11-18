#include "Decal.h"

Decal::Decal(ivec2 decalPos)
{
	this->position = decalPos;
	this->graphicObject.setMaterial(Decal::decalTexture);
	this->graphicObject.setMesh(Decal::decalMesh);
	this->graphicObject.setPosition({ this->position.x,-0.5,this->position.y });
}
Decal::Decal()
{
	this->graphicObject = GraphicObject();
	this->position = { 0,0 };
	this->graphicObject.setPosition({ this->position.x,-0.5,this->position.y });
}
shared_ptr<Mesh> Decal::decalMesh = nullptr;
shared_ptr<PhongMaterialWithTexture> Decal::decalTexture = nullptr;

void Decal::init()
{

	Decal::decalMesh = make_unique<Mesh>();
	Decal::decalMesh->load(R"(data/meshes/Decal.obj)");
	Decal::decalTexture = make_unique<PhongMaterialWithTexture>(R"(data/textures/decal.png)",0);
}
void Decal::draw()
{
	glEnable(GL_BLEND);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendEquation(GL_FUNC_ADD);
	glPolygonOffset(-1, -3);
	this->graphicObject.draw();
	glDisable(GL_BLEND);
	glDisable(GL_POLYGON_OFFSET_FILL);

}