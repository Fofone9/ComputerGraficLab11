#pragma once
#include "data.h"

void simulation();
float getFPS();
void keyboard();
void movePlayer();
void gameObjectsSimulation(float);
void cameraSimulation(float);
void moveEnemy(shared_ptr<GameObject>& entity);
void destroyIfPossible(ivec2 pos, ivec2 displacement, bool Decrease);
void bombSimulation(double currentTime);