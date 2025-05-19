#include "Player.h"

Player::Player(float x, float y, float w, float h, Vector2 gravity)
{
    pos = {x, y};
    RecPlayer = {pos.x, pos.y, w, h};
    this -> gravity = gravity;
    velocity = {5, -2};
}

void Player::Update()
{
    CheckColision();
    Jump();

    if(velocity.y < 15) {velocity += gravity;}
    pos += velocity;

    RecPlayer.x = pos.x;
    RecPlayer.y = pos.y;

    // std::cout << "pos = " << pos.x << ";" << pos.y << "     gravity = " << gravity.x << ";" << gravity.y << "     velocity = " << velocity.x << ";" << velocity.y << std::endl;

    DrawRectangleRec(RecPlayer, WHITE);
}

void Player::CheckColision()
{
    if(pos.x > GetScreenWidth() - RecPlayer.width || pos.x < 0) {velocity.x *= -1;} // Check if player has hit the walls
    if(pos.y > GetScreenHeight() - RecPlayer.height || pos.y < 0) {velocity.y *= -1;} // Check if the player has hit celling
}

void Player::Jump()
{
    int key = GetKeyPressed();
    
    std::cout << key << '\n';

    if(key == 32) {velocity.y = -5;}
}