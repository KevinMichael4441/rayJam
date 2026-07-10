static RenderTexture2D target = { 0 };  // Render texture to render our game
static int frameCounter = 0;
static int MAX_ENEMIES = 100;

#include "player.h"
#include "enemy.h"

#include <vector>
#include <iostream>


class Game
{
public:

    Game();
    void update();
    void draw();

private:

    Player m_player;
    std::vector<Enemy> m_enemies;
};

Game::Game()
{
    m_enemies.reserve(MAX_ENEMIES);
    for (int index = 0; index < MAX_ENEMIES; index++)
    {
        Enemy enemy;
        m_enemies.push_back(enemy);
    }
}


void Game::update()
{
    m_player.update();
    for (Enemy enemy : m_enemies)
    {
        enemy.update(m_player.getPosition());
    }
}

void Game::draw()
{
    // Draw
    //----------------------------------------------------------------------------------
    // Render game screen to a texture, 
    // it could be useful for scaling or further shader postprocessing
    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        

        for (Enemy enemy : m_enemies)
        {
            enemy.draw();
        }
        m_player.draw();
        
    EndTextureMode();
    
    // Render to screen (main framebuffer)
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Draw render texture to screen, scaled if required
        DrawTexturePro(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height }, 
            (Rectangle){ 0, 0, (float)target.texture.width, (float)target.texture.height }, (Vector2){ 0, 0 }, 0.0f, WHITE);

        
        
        // TODO: Draw everything that requires to be drawn at this point, maybe UI?
        // Whatever to draw on top of game screen like UI as mentioned.

    EndDrawing();
    //----------------------------------------------------------------------------------  
}