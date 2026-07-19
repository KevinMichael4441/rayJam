#include "raylib.h"
#include "raymath.h"


float static constexpr m_gravity{9.8};


class Ball
{
public:

    Ball();
    void init(float t_radius);
    void update(float t_dt);
    void draw();


private:

    Vector2 m_position;
    float m_radius;

    bool m_isSelected;

};

Ball::Ball()
{
}

void Ball::init(float t_radius)
{
    m_radius = t_radius;
    m_isSelected = false;

}

void Ball::update(float t_dt)
{
    if (m_isSelected)
    {

    }
    else
    {
        m_position.y += (m_gravity *  t_dt);
    }
}

void Ball::draw()
{
    DrawCircleV(m_position, m_radius, GREEN);
}
