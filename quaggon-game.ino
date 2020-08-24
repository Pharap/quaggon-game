#include "globals.h"
#include "enemy.h"
#include "objects.h"
#include "player.h"

void G_Tittle() {
  arduboy.setCursor(0, 0);
  //arduboy.print("Tittle");
  Sprites::drawOverwrite(0, 0, Tittle_screen, 0);

  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = Game;
  }
}

void G_Game() {
  arduboy.setCursor(0, 0);
  //arduboy.print("Game");
  
  drawWorld();
  quaggonMove();
  drawQuaggon();
//  quaggonInput();

  if (arduboy.justPressed(B_BUTTON)) {
    gamestate = Over;
  }
}

void G_Over() {
  arduboy.setCursor(0, 0);
  arduboy.print("Over");

  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = Score;
  }
}

void H_Score() {
  arduboy.setCursor(0, 0);
  arduboy.print("Score");

  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = Tittle;
  }
}

void gameloop() {
  switch (gamestate) {

    case Tittle:
      G_Tittle();
      break;

    case Game:
      G_Game();
      break;

    case Over:
      G_Over();
      break;

    case Score:
      H_Score();
      break;

  }
}




void setup(){
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.display();
  arduboy.initRandomSeed();
  arduboy.clear();
}

void loop(){
  if(!(arduboy.nextFrame())) {
    return;
  }

  arduboy.pollButtons();
  arduboy.clear();

  gameloop();
  
  arduboy.display();
}
