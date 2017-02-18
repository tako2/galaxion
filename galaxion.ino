//
// Galaxian for Arduboy
//

#include "Arduboy.h"
#include "game.h"

Arduboy mArduboy;
Game mGame;

void setup()
{
  //mArduboy.begin();
  mArduboy.beginNoLogo();
  mArduboy.initRandomSeed();
  mArduboy.setFrameRate(60);

#ifdef CAPTURE_SCREEN
  Serial.begin(115200);
#endif
}

void loop()
{
  if (!(mArduboy.nextFrame())) {
    return;
  }

  mArduboy.clear();
  mGame.check_input();
  mGame.do_state();
  mGame.draw();
  mArduboy.display();
}

