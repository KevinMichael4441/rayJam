#include "raylib.h"
#include "raymath.h"



class Player
{
public:

    Player();
    void update();
    void draw();

    Vector2 getPosition();

private:

    void move();
    void handleInput();

    Vector2 m_position{360,360};
    const float m_radius{20};

    Vector2 m_destination{360,360};
};

Player::Player()
{
}

void Player::update()
{
    handleInput();
    move();
}

void Player::handleInput()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        m_destination = GetMousePosition();
    }
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