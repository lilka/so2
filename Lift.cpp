#include <ncurses.h>
#include "Lift.h"

Lift::Lift( int x_init, int y_init,bool occup,int counter) {
   

    windowPosX = x_init;
    windowPosY = y_init;

    posX = windowPosX/2+5;
    posY = windowPosY/2+5;

    isOccupied=occup; 

    xVectora = -1;
    yVectora = 0;

    counter=counter; 
}

void Lift::moveLift() {
   
    posX += xVectora;
    posY += yVectora;

   if( posX >= windowPosX ) {
      
        xVectora *= -1;
        counter++;
        
    }

   if(posX<=0){
        xVectora *= -1;
        counter++;
       
    }

    if( posY >= windowPosY  ) {
        yVectora *= -1;
        counter++;
       
          
       
    }

   if(posY <= 0){
        yVectora *= -1;
        counter++;
        
    }
}

void Lift::drawLift() {
    move(posY,posX);
    printw("( )");
 }

