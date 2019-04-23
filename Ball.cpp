#include <ncurses.h>
#include "Ball.h"
using namespace std; 

Ball::Ball(short direction, int defaultSpeed, int x_init, int y_init, int ballId) {
    this->direction = direction;
    this->speed = defaultSpeed;
    this->defaultSpeed=defaultSpeed;
    this->ballId=ballId;

    windowPosX = x_init;
    windowPosY = y_init;

    posX = windowPosX/2;
    posY = windowPosY/2;
    setRandomDirection();
}

void Ball::recover(){
    this->xVectora=oldXVectora;
    this->yVectora=oldYVector;
}

void Ball::moveBall() {

    posX += xVectora;
    posY += yVectora;
    speed+=5000;
    
    if( posX >= windowPosX ) {
      
        xVectora *= -1;
        speed=defaultSpeed;             
        
    }

    if(posX<=0){
        xVectora *= -1;
        speed=defaultSpeed; 
       
    }

    if( posY >= windowPosY  ) {
        yVectora *= -1;
        speed=defaultSpeed; 
       
          
       
    }

    if(posY <= 0){
        yVectora *= -1;
        speed=defaultSpeed; 
        
    }
}   


void Ball::drawBall() {
    move(posY,posX);
    printw("o");
}

int Ball::getSpeed() {
    return this->speed;
}

void Ball::setRandomDirection() {
    switch (direction) {
       
        case 1:
            xVectora = -2;
            yVectora = -1;
            
            break;
        case 2:
            xVectora = 0;
            yVectora = -1;
            
            break;
        case 3:
          
            xVectora = -1;
            yVectora = -1;
            
            break;
        case 4:
            
            xVectora = 2;
            yVectora = -1;
            
            break;
        case 5:
            
            xVectora = 1;
            yVectora = -1;
            
            break;
        
    }
}
