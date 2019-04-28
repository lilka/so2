#include <ncurses.h>
#include "Lift.h"

Lift::Lift( int x_init, int y_init) {
   

    windowPosX = x_init;
    windowPosY = y_init;

    posX = windowPosX/2+5;
    posY = windowPosY/2+5;

    xVectora = -1;
    yVectora = 0;

    counter=0; 
}

void Lift::moveLift() {
   
    posX += xVectora;
    posY += yVectora;

   if( posX >= windowPosX ) {
        xVectora *= -1;
        this->increaseCounter();
    }

   if(posX<=0){
        xVectora *= -1;
        this->increaseCounter();
    }

    if( posY >= windowPosY  ) {
        yVectora *= -1;
        this->increaseCounter();
    }

   if(posY <= 0){
        yVectora *= -1;
        this->increaseCounter();
        
    }
}

void Lift::drawLift() {
    move(posY,posX);
    printw("( )");
 }

 void Lift::releaseBall() {
    this->counter = 0;
    this->ballInsideIndex = -1;
 }

 bool Lift::hasBall() {
     return this->ballInsideIndex > -1;
 }

 void Lift::increaseCounter() {
     if(this->hasBall())
        this->counter++;
 }

 bool Lift::isBallInLift(Ball *ball) {
     return (this->posY == ball->posY) &&
     ((this->posX == ball->posX) ||
      (this->posX-1 == ball->posX) ||
      (this->posX+1 == ball->posX));
 }

