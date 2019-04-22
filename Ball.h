class Ball {
private:
    //współrzędne połozenia kulki
    int posX, posY; 
    //poprzednie współrzędne X oraz Y piłki
   // int prevX, prevY;
    float windowPosX, windowPosY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;
    //kierunek w ktorym bedzie poruszax sie pilka
    short direction;
    int speed;  //prędkość z jaką porusza się piłka
    int defaultSpeed; 

    
public:
    Ball(short vec, int , int, int);
    ~Ball();
    void moveBall();
    void drawBall();
    int getSpeed();
    int getX();
    int getY();
    void clearCircle();
    void setRandomDirection();
};
