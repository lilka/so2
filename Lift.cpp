#include <ncurses.h>
#include "Lift.h"

Lift::Lift( int x_init, int y_init) {
   

    windowPosX = x_init;
    windowPosY = y_init;

    posX = windowPosX/2;
    posY = windowPosY/2;

    xVectora = 0;
    yVectora = -1;
}

void Lift::moveLift() {
   
    posX += xVectora;
    posY += yVectora;

   if( posX >= windowPosX ) {
      
        xVectora *= -1;
        
    }

   if(posX<=0){
        xVectora *= -1;
       
    }

    if( posY >= windowPosY  ) {
        yVectora *= -1;
       
          
       
    }

   if(posY <= 0){
        yVectora *= -1;
        
    }
}

void Lift::drawLift() {
    move(posY,posX);
    printw("( )");
 }

