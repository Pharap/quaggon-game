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

enum class quaggonDirection : uint8_t {Up, Down, Left, Right};

quaggonDirection qDir = quaggonDirection::Down;

bool quaggonMoving = false;

uint8_t quaggonFrame = 0;
//int quaggonState = quaggonIddle;

void WalkingAnim(){

  quaggonMoving = true;
  //if (arduboy.everyXFrames(8)) quaggonFrame ++;

  //up
  if (qDir == quaggonDirection::Up) {
    quaggonFrame = 4;
    if (arduboy.everyXFrames(8)) quaggonFrame ++;
    if (quaggonFrame ==7) quaggonFrame = 4;
   }
  //down
  if (qDir == quaggonDirection::Down){
    quaggonFrame = 0;
    if (arduboy.everyXFrames(8)) quaggonFrame ++;
    if (quaggonFrame ==4) quaggonFrame = 0;
  }
  //left
  if (qDir == quaggonDirection::Left){
    quaggonFrame = 12;
    if (arduboy.everyXFrames(8)) quaggonFrame ++;
    if (quaggonFrame ==15) quaggonFrame = 12;
  }
  //Right
  if (qDir == quaggonDirection::Right){
    quaggonFrame = 8;
    if (arduboy.everyXFrames(8)) quaggonFrame ++;
    if (quaggonFrame ==11) quaggonFrame = 8;
  }
    
}

void quaggonMove(){
  if (arduboy.pressed(UP_BUTTON)){
    WalkingAnim();
    qDir = quaggonDirection::Up;
    
    if (map_y < PLAYER_Y_OFFSET) {
      map_y += 1;
    }
  }

  if (arduboy.pressed(DOWN_BUTTON)){
    WalkingAnim();
    qDir = quaggonDirection::Down;
    
    if (PLAYER_Y_OFFSET + PLAYER_SIZE < map_y + TILE_SIZE * WORLD_HEIGHT) {
      map_y -= 1;
    }
  }

  if (arduboy.pressed(RIGHT_BUTTON)){
    WalkingAnim();
    qDir = quaggonDirection::Right;
    
     if (PLAYER_X_OFFSET + PLAYER_SIZE < map_x + TILE_SIZE * WORLD_WIDTH) {
      map_x -= 1;
    }
  }

  if (arduboy.pressed(LEFT_BUTTON)){
    WalkingAnim();
    qDir = quaggonDirection::Left;
    
     if (map_x < PLAYER_X_OFFSET) {
      map_x += 1;
    }
  }

  //drawing and setting direction
  if (qDir == quaggonDirection::Up||qDir == quaggonDirection::Down||qDir == quaggonDirection::Left||qDir == quaggonDirection::Right){
  Sprites::drawPlusMask(PLAYER_X_OFFSET, PLAYER_Y_OFFSET, waddle, quaggonFrame);
  }
}



/*void quaggonInput(){
  if (arduboy.pressed(UP_BUTTON)){
    qDir = quaggonDirection::Up;
    quaggonMoving = true;
    //quaggonWalking();
    
    map_y += 1;
  }

  if (arduboy.pressed(DOWN_BUTTON)){
    quaggonState = quaggonDown;
    quaggonMoving = true;
    quaggonFrame = 0;
    
    if (quaggonState == quaggonDown){
             Sprites::drawPlusMask(30, 30, waddle, quaggonFrame);
             //0-3
    }
    map_y -= 1;
  }

  if (arduboy.pressed(LEFT_BUTTON)){
    quaggonState = quaggonLeft;
    quaggonMoving = true;
    if (quaggonState == quaggonLeft){
             Sprites::drawPlusMask(30, 30, waddle, quaggonFrame);
             //12-15
    }
    map_x += 1;
  }

  if (arduboy.pressed(RIGHT_BUTTON)) {
    quaggonState = quaggonRight;
    quaggonMoving = true;
    if (quaggonState == quaggonRight){
             Sprites::drawPlusMask(30, 30, waddle, quaggonFrame);
             //8-11
    }
    map_x -= 1;
  }

  if (arduboy.notPressed(UP_BUTTON | DOWN_BUTTON | RIGHT_BUTTON | LEFT_BUTTON)){
    quaggonState = quaggonIddle;
    quaggonMoving = false;
    if (quaggonState == quaggonIddle &&(quaggonMoving == false)){
             Sprites::drawPlusMask(30, 30, waddle, quaggonFrame);
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
