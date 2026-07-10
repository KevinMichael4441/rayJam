#include "raylib.h"
#include "raymath.h"

#include <iostream>


class Enemy
{
public:

    Enemy();
    void update(Vector2 t_playerPos);
    void draw();

private:

    void move(Vector2 t_playerPos);

    Vector2 m_position{float(rand() % 700 + 20), float(rand() % 700 + 20)};
    static constexpr float m_radius{20};

    int m_velocity;
    int m_health;
};

Enemy::Enemy()
{
    // int quadrant = rand() % 4;
    // switch (quadrant)
    // {
    // case 0:
    //     m_position.x = rand() % 100 - 120;
    //     m_position.y = rand() % 100 - 120;
    //     break;
    // case 1:
    //     m_position.x = rand() % 100 - 120;
    //     m_position.y = rand() % 100 + 740;
    //     break;
    // case 2:
    //     m_position.x = rand() % 100 + 740;
    //     m_position.y = rand() % 100 - 120;
    //     break;
    // case 3:
    //     m_position.y = rand() % 100 + 740;
    //     m_position.y = rand() % 100 + 740;
    //     break;
    // }

    m_velocity = 10;
    
}

void Enemy::update(Vector2 t_playerPos)
{
    move(t_playerPos);
}

void Enemy::move(Vector2 t_playerPos)
{
    Vector2 difference =  Vector2Subtract(t_playerPos, m_position);
    if (Vector2Length(difference) > 5)
    {
        Vector2 heading = Vector2Normalize(Vector2{t_playerPos.x - m_position.x, t_playerPos.y - m_position.y});

        m_position += heading;
    }


}

void Enemy::draw()
{
    DrawCircleV(m_position, m_radius, RED);
}