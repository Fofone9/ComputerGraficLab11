#pragma once
#include "GL/glew.h"
#include "Mesh.h"
#include "Material.h"
#include "PhongMaterialWithTexture.h"
#include "PhongMaterial.h"
#include <memory>
#include <Windows.h>
using namespace glm;
using namespace std;
// ����� ��� ������������� ������ ������������ �������
class GraphicObject
{
public:
	// �����������
	GraphicObject();
	GraphicObject(vec3 pos, vec3 color, float angle);
	GraphicObject(vec3 pos, vec3 color, float angle, shared_ptr<Material> mat);
	// ��������� � ��������� ������� �������
	void setPosition(vec3 position);
	vec3 getPosition();
	// ��������� � ��������� ���� �������� � ��������
	// ������� �������������� � �������������� ���������
	// ������ ��� Oy �� ������� �������
	void setAngle(float grad);
	float getAngle();
	// ��������� �������� ����� �������
	void set�olor(vec3 color);
	vec3 getColor();
	// ��������� ������������� ���������
	void setMaterial(shared_ptr<Material> material);
	// ��������� ������������� ����
	void setMesh(shared_ptr<Mesh> mesh);
	// ������� ������
	void draw();
private:
	// ������� ������� � ���������� ������� ���������
	vec3 position;
	// ���� �������� � �������������� ��������� (� ��������)
	float angle;
	// ���� ������
	vec3 color;
	// ������� ������ - ���� �� ��������� ������ ���
	mat4 modelMatrix;
	// ������������ ��������
	shared_ptr<Material> material;
	// ������������ ���
	shared_ptr<Mesh> mesh;
private:
	// ������ ������� modelMatrix �� ������ position � angle
	void recalculateModelMatrix();
};