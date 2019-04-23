#include <mutex> 
#include "Lift.h"
#include <iostream> 
using namespace std; 

class Ball {
public:
    //współrzędne połozenia kulki
    int posX, posY; 
    //poprzednie współrzędne X oraz Y piłki
   // int prevX, prevY;
    float windowPosX, windowPosY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;
    int oldXVectora, oldYVector; 
    //kierunek w ktorym bedzie poruszax sie pilka
    short direction;
    int speed;  //prędkość z jaką porusza się piłka
    int defaultSpeed; 
    bool isInLift; 
    int ballId; 
    

    
public:
    Ball(short vec, int , int, int, bool, int);
    ~Ball();
    void moveBall(int, int);
    void drawBall();
    int getSpeed();
    int getX();
    int getY();
    void clearCircle();
    void setRandomDirection();
};
