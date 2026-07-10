#include "raylib.h"
#include "raymath.h"



class Player
{
public:

    Player();
    void update();
    void draw();

    Vector2 getPosition();
    void setDestination(Vector2 t_destination);

private:

    void move();
    

    Vector2 m_position{360,360};
    const float m_radius{20};

    Vector2 m_destination{360,360};
};

Player::Player()
{
}

void Player::update()
{
    move();
}

void Player::setDestination(Vector2 t_destination)
{
    m_destination = t_destination;
}

void Player::move()
{
    Vector2 difference =  Vector2Subtract(m_destination, m_position);
    if (Vector2Length(difference) > 5)
    {
        Vector2 velocity = Vector2Normalize(Vector2{m_destination.x - m_position.x, m_destination.y - m_position.y});

        m_position += velocity;
    }  


}

void Player::draw()
{
    DrawCircleV(m_position, m_radius, GREEN);
}



Vector2 Player::getPosition()
{
    return m_position;
}