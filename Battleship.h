#include <iostream>
#include<time.h>
#include <string>
using namespace std;

class vehicle
{
public:
    int coordX;
    int coordY;
    int coordX_prev;
    int coordY_prev;
    int coord_ascii;
    int m_size;
    int m_player;
    string m_name;
private:
    void drawShip();
    boat();
    void locateXY(int x, int y);
    void generateVehicle();
    virtual void sound();
    int getX(int x);
    int gety(int y);
    int getsize();
    string getname();
    int getposition(int loc1, int loc2);
    void setCordinateX(int x);
    void setCoordinateY(int y);
    void setplayer(int player);
    void setlocaton(int loc1,int loc 2, int value);
    int counter;

    

};

class tank: public vehicle
{
public:
    tank();
    void sound();
};

class boat: public vehicle
{
public:
    boat();
    void sound();
};

class cruiser: public boat
{
public:
    cruiser()
    void sound();
};

class submarine: public boat
{
public:
    submarine()
    void sound();
};
class destroyer: public boat
{
public:
    destroyer()
    void sound ();

};