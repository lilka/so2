#include "Ball.h"

class Lift {
public:
    //współrzędne połozenia windy
    int posX, posY; 
    //poprzednie współrzędne X oraz Y piłki
   // int prevX, prevY;
    float windowPosX, windowPosY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;
    int ballInsideIndex=-1;
    int counter;

    
public:
    Lift( int, int);
    ~Lift();
    void moveLift();
    void drawLift();
    int getX();
    int getY();
    void clearCircle();
    void releaseBall();
    bool hasBall();
    bool isBallInLift(Ball*);
private:
    void increaseCounter();
};
