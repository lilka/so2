#include <ncurses.h>
#include <string>
#include <unistd.h>
#include "Window.h"
#include "Ball.h"
#include <thread>
#include <vector>
#include "Lift.h"

using namespace std;

Window *window;
Lift* lift;
vector<Ball*> balls;
bool endFlag = true;
vector<thread> threads;

void moveLift(Lift *lift){
 while((endFlag)){
     lift->moveLift();
     usleep(60000);
 }
}


void moveBall(Ball * ball){
    while(( endFlag
 ) ) {
        ball->moveBall();
        usleep(ball->getSpeed());
    }
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

     lift=new Lift(x,y);
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
        Ball *ball = new Ball(randDirectionChooser,speed, x, y);
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