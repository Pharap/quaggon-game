#pragma once

#include "globals.h"
#include "map.h"
#define WalkingSpeed 5

#define PLAYER_SIZE      16
#define PLAYER_X_OFFSET    WIDTH / 2 - PLAYER_SIZE / 2
#define PLAYER_Y_OFFSET    HEIGHT / 2 - PLAYER_SIZE / 2

/*#define quaggonIddle 0
#define quaggonUp 1
#define quaggonDown 2
#define quaggonLeft 3
#define quaggonRight 4*/

enum class QuaggonDirection : uint8_t {Up, Down, Left, Right};

QuaggonDirection quaggonDirection = QuaggonDirection::Down;

constexpr uint8_t quaggonFirstStep = 0;
constexpr uint8_t quaggonLastStep = 15;

uint8_t quaggonStep = 0;
//int quaggonState = quaggonIddle;

void resetQuaggonAnimation()
{
    quaggonStep = quaggonFirstStep;
}

void animateQuaggonWalk()
{
    if(quaggonStep < quaggonLastStep)
        ++quaggonStep;
    else
        quaggonStep = quaggonFirstStep;
}

void quaggonMove()
{
  bool moved = false;
  QuaggonDirection previousDirection = quaggonDirection;

  if (arduboy.pressed(UP_BUTTON))
  {
    quaggonDirection = QuaggonDirection::Up;
    
    if (map_y < PLAYER_Y_OFFSET)
    {
      map_y += 1;
    }
    
    moved = true;
  }

  if (arduboy.pressed(DOWN_BUTTON))
  {
    quaggonDirection = QuaggonDirection::Down;
    
    if (PLAYER_Y_OFFSET + PLAYER_SIZE < map_y + TILE_SIZE * WORLD_HEIGHT)
    {
      map_y -= 1;
    }
    
    moved = true;
  }

  if (arduboy.pressed(RIGHT_BUTTON))
  {
    quaggonDirection = QuaggonDirection::Right;
    
    if (PLAYER_X_OFFSET + PLAYER_SIZE < map_x + TILE_SIZE * WORLD_WIDTH)
    {
      map_x -= 1;
    }
    
    moved = true;
  }

  if (arduboy.pressed(LEFT_BUTTON))
  {
    quaggonDirection = QuaggonDirection::Left;
    
    if (map_x < PLAYER_X_OFFSET)
    {
      map_x += 1;
    }
    
    moved = true;
  }
  
  if(moved)
  {
    if(quaggonDirection != previousDirection)
    {
      resetQuaggonAnimation();
    }
    else
    {
      animateQuaggonWalk();
    }
  }
}

void drawQuaggon()
{
  uint8_t baseFrame = 0;

  if (quaggonDirection == QuaggonDirection::Up)
  {
    baseFrame = 4;
  }

  if (quaggonDirection == QuaggonDirection::Down)
  {
    baseFrame = 0;
  }
  
  if (quaggonDirection == QuaggonDirection::Left)
  {
    baseFrame = 12;
  }

  if (quaggonDirection == QuaggonDirection::Right)
  {
    baseFrame = 8;
  }

  Sprites::drawPlusMask(PLAYER_X_OFFSET, PLAYER_Y_OFFSET, waddle, baseFrame + (quaggonStep / 4));
}


/*void quaggonInput(){
  if (arduboy.pressed(UP_BUTTON)){
    quaggonDirection = QuaggonDirection::Up;
    quaggonMoving = true;
    //quaggonWalking();
    
    map_y += 1;
  }

  if (arduboy.pressed(DOWN_BUTTON)){
    quaggonState = quaggonDown;
    quaggonMoving = true;
    quaggonStep = 0;
    
    if (quaggonState == quaggonDown){
             Sprites::drawPlusMask(30, 30, waddle, quaggonStep);
             //0-3
    }
    map_y -= 1;
  }

  if (arduboy.pressed(LEFT_BUTTON)){
    quaggonState = quaggonLeft;
    quaggonMoving = true;
    if (quaggonState == quaggonLeft){
             Sprites::drawPlusMask(30, 30, waddle, quaggonStep);
             //12-15
    }
    map_x += 1;
  }

  if (arduboy.pressed(RIGHT_BUTTON)) {
    quaggonState = quaggonRight;
    quaggonMoving = true;
    if (quaggonState == quaggonRight){
             Sprites::drawPlusMask(30, 30, waddle, quaggonStep);
             //8-11
    }
    map_x -= 1;
  }

  if (arduboy.notPressed(UP_BUTTON | DOWN_BUTTON | RIGHT_BUTTON | LEFT_BUTTON)){
    quaggonState = quaggonIddle;
    quaggonMoving = false;
    if (quaggonState == quaggonIddle &&(quaggonMoving == false)){
             Sprites::drawPlusMask(30, 30, waddle, quaggonStep);
             //0
    }
  }
}

/*void P_State(){
  switch (quaggonState){

    case quaggonDown:
    //Sprites::drawOverwrite(30, 30, waddle, 0);
    break;
    
    case quaggonUp:
    //Sprites::drawOverwrite(30, 30, waddle, 4);
    break;

    case quaggonRight:
    //Sprites::drawOverwrite(30, 30, waddle, 8);
    break;

    case quaggonLeft:
    //Sprites::drawOverwrite(30, 30, waddle, 12);
    break;
   

    case quaggonIddle:
    //Sprites::drawOverwrite(0, 0, waddle, 0);
    break;
  }
}*/
