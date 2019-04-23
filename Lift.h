class Lift {
public:
    //współrzędne połozenia windy
    int posX, posY; 
    //poprzednie współrzędne X oraz Y piłki
   // int prevX, prevY;
    float windowPosX, windowPosY;
    //wspolrzedne wektora przesuniecia
    int xVectora, yVectora;
    int ballInsideIndex;
    bool isOccupied=false; 
    int counter;

    
public:
    Lift( int, int, bool, int);
    ~Lift();
    void moveLift();
    void drawLift();
    int getX();
    int getY();
    void clearCircle();
};
