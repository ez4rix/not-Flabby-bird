#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "raylib.h"
#include "raymath.h"

class Player
{
public:

    Vector2 pos;
    Rectangle RecPlayer;

    Vector2 gravity;
    Vector2 velocity;

    Player(float x, float y, float w, float h, Vector2 gravity);

    void Update();

    void CheckColision();
    void Jump();

};


#endif