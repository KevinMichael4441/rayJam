#include "raylib.h"
#include "raymath.h"

#include <iostream>




class Power
{
public:

    Power();
    void update();
    void draw();

private:

    enum Type{WATER, ELECTRIC, POISON};

    Type m_type;
    bool isActive();
    Vector2 m_position{-100,-100};
};

Power::Power()
{
}

void Power::update()
{
}

void Enemy::draw()
{
    
}

bool setActive()
{
    if (isActive)
    {
        return false;
    }
    else
    {

    }
}