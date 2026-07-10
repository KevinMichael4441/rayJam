static RenderTexture2D target = { 0 };  // Render texture to render our game
static int frameCounter = 0;


#include "player.h"

class Game
{
public:

    Game();
    void update();
    void draw();

private:

    Player m_player;
};

Game::Game()
{

}

void Game::update()
{
    m_player.update();
}

void Game::draw()
{
    // Draw
    //----------------------------------------------------------------------------------
    // Render game screen to a texture, 
    // it could be useful for scaling or further shader postprocessing
    BeginTextureMode(target);
        ClearBackground(RAYWHITE);
        

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