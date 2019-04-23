class Lift {
private:
    //współrzędne połozenia windy
    int posX, posY; 
    //poprzednie współrzędne X oraz Y piłki
   // int prevX, prevY;
    float windowPosX, windowPosY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;

    
public:
    Lift( int, int);
    ~Lift();
    void moveLift();
    void drawLift();
    int getX();
    int getY();
    void clearCircle();
};
