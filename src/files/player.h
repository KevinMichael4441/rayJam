#include "raylib.h"



class Player
{
public:

    Player();
    void update();
    void draw();

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
    if (m_destination.x < m_position.x)
    {
        m_position.x -= 1;
    }
    else if (m_destination.x > m_position.x)
    {
        m_position.x += 1;
    }

    if (m_destination.y < m_position.y)
    {
        m_position.y -= 1;
    }
    else if (m_destination.y > m_position.y)
    {
        m_position.y += 1;
    }
}

void Player::draw()
{
    DrawCircleV(m_position, m_radius, GREEN);
}