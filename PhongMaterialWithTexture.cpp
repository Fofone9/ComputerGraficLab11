#include "PhongMaterialWithTexture.h"

PhongMaterialWithTexture::PhongMaterialWithTexture() :Material() {};
PhongMaterialWithTexture::PhongMaterialWithTexture(string sourcePath) :Material(sourcePath) {}
PhongMaterialWithTexture::PhongMaterialWithTexture(string materialSourcePath, shared_ptr<Texture> sharedTex) :Material(), texture(sharedTex) {};
PhongMaterialWithTexture::PhongMaterialWithTexture(string textureSourcePath, int) :Material()
{
	this->texture = make_unique<Texture>();
	this->texture->load(textureSourcePath);
};
PhongMaterialWithTexture::PhongMaterialWithTexture(string materialSourcePath, string textureSourcePath) :Material(materialSourcePath)
{
	this->texture = make_unique<Texture>();
	this->texture->load(textureSourcePath);
}

void PhongMaterialWithTexture::setTexture(shared_ptr<Texture> tex)
{
	this->texture = tex;
}
void PhongMaterialWithTexture::apply()
{
	if (this->texture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		this->texture->apply();
	}
	glMaterialfv(GL_FRONT, GL_DIFFUSE, value_ptr(this->material[0]));
	glMaterialfv(GL_FRONT, GL_AMBIENT, value_ptr(this->material[1]));
	glMaterialfv(GL_FRONT, GL_SPECULAR, value_ptr(this->material[2]));
	glMaterialfv(GL_FRONT, GL_EMISSION, value_ptr(this->material[3]));
	glMaterialf(GL_FRONT, GL_SHININESS, this->shininess);
}