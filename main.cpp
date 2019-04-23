#include <ncurses.h>
#include <string>
#include <unistd.h>
#include "Window.h"
#include "Ball.h"
#include <thread>
#include <vector>
#include <iostream>

using namespace std;

Window *window;
Lift* lift;
vector<Ball*> balls;
bool endFlag = true;
vector<thread> threads;

void moveLift(Lift *lift){
 while((endFlag)){
     lift->moveLift();
     usleep(90000);
 }
}


void moveBall(Ball * ball){

    while(( endFlag
 ) ) {
   /*  if(ball->isInLift==true){
         if(lift->counter%2==0 && lift->counter!=0){
              ball->moveBall(lift->xVectora, lift->yVectora);
              usleep(ball->getSpeed());
              lift->isOccupied=false;
              ball->isInLift=false;
         }
              else{
                     
         ball->speed=1;
      if( ball->posX >= ball->windowPosX ) {
            ball-> xVectora *= -1;
        }
       if(ball->posX<=0){
       ball-> xVectora *= -1;
       }
       if( ball->posY >= ball->windowPosY  ) {
       ball-> yVectora *= -1;
       }
       if(ball->posY <= 0){
       ball-> yVectora *= -1;
       }
       usleep(90000);
              }
    
     }

     if(ball->isInLift==false && lift->isOccupied==true){
          ball->moveBall(lift->xVectora, lift->yVectora);
        usleep(ball->getSpeed());
     }*/
     
 //if(  lift->isOccupied==false) {
  if((lift->posX==ball->posX && lift->posY==ball->posY ) || 
  (lift->posX+1==ball->posX  && lift->posY+1==ball->posY ) || 
  (lift->posX-1==ball->posX  && lift->posY-1==ball->posY ) ||
  (lift->posX-1==ball->posX  && lift->posY==ball->posY   ) ||
  (lift->posX==ball->posX    && lift->posY-1==ball->posY ) ||
  (lift->posX==ball->posX    && lift->posY+1==ball->posY ) ||
   (lift->posX+1==ball->posX  && lift->posY==ball->posY  ) )
  {

        ball->oldXVectora=ball->xVectora;
        ball-> oldYVector=ball->yVectora;
        ball-> posX=lift->posX;
        ball-> posY=lift->posY;
        ball-> xVectora=lift->xVectora;
        ball-> yVectora=lift->yVectora;
        lift->isOccupied=true;
         
         ball->speed=1;

    if( ball->posX >= ball->windowPosX ) {
      
       ball-> xVectora *= -1;
        
     }

   if(ball->posX<=0){
       ball-> xVectora *= -1;
       
    }

    if( ball->posY >= ball->windowPosY  ) {
       ball-> yVectora *= -1;
       
          
       
    }

   if(ball->posY <= 0){
       ball-> yVectora *= -1;
        
    }
     usleep(90000);

 }else{
     ball->moveBall(lift->xVectora, lift->yVectora);
     usleep(ball->getSpeed());
 }
 }
 //e}

}

   


void windowRefresh(){

    while(endFlag
) {
        clear();
           lift->drawLift();
        for (int i = 0; i < balls.size(); i++) {
            balls[i]->drawBall();
        }
        refresh();
        usleep(20000);
    }
    clear();
    endwin();
}

void makeNewLift(){
     float x = window->getWidth();
     float y = window->getHeight();

     lift=new Lift(x,y,false,0);
     moveLift(lift);

     usleep(50000);

}


void makeNewBall(){
    float x = window->getWidth();
    float y = window->getHeight();
    short randDirectionChooser;
    int speed;
    while(endFlag)
    {

        randDirectionChooser = rand() % 5 +1;
        speed = 50000;
        Ball *ball = new Ball(randDirectionChooser,speed, x, y, false);
        balls.push_back(ball);

        threads.push_back(thread(moveBall, balls.back()));

        usleep(5000000);

    }
}

 

void exitProgram(){
    int inputChar;
    while(endFlag){
        inputChar = getch();
        if(inputChar == 'e'){
            endFlag= false;
        }
    }
}

/*void updateMove(Ball* ball, Lift* lift){
     cout<<"Winda x "<<lift->posX<<"y "<<lift->posY<<endl;
     cout<<"pilka x "<<ball->posX<<"y "<<ball->posY<<endl;
     if(lift->posX==ball->posX && lift->posY==ball->posY){
         ball->posX=lift->posX;
         ball->posY=lift->posY;
         ball->speed=0;
         usleep(60000);
        
     }
}*/



int main() {
    srand(time(NULL));
    window = new Window();

    thread generateNewLift(makeNewLift);
    thread generateBallThread(makeNewBall);
    thread windowRefreshThread(windowRefresh);
    
    thread exitProgramThread(exitProgram);
    exitProgramThread.join();
    generateBallThread.join();
    windowRefreshThread.join();
    generateNewLift.join();

    for(int i = 0; i<threads.size(); i++){
        threads[i].join();
    }

    
   
    
    endwin();
    return 0;
}
