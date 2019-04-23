#include <mutex> 
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
    int ballId; 
    

    
public:
    Ball(short vec, int , int, int, int);
    ~Ball();
    void moveBall();
    void drawBall();
    int getSpeed();
    int getX();
    int getY();
    void clearCircle();
    void setRandomDirection();
    void recover();
};
