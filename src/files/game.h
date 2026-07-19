static RenderTexture2D target = { 0 };  // Render texture to render our game
static int frameCounter = 0;

static int constexpr MAX_BALLS = 10;

#include <vector>
#include <iostream>

#include "ball.h"


class Game
{
public:

    Game();
    void init(int t_ActiveBalls);
    void update();
    void draw();

private:


    void handleInput();

    std::vector<Ball> m_leftBalls;
    std::vector<Ball> m_rightBalls;


};

Game::Game()
{
    m_leftBalls.reserve(MAX_BALLS);
    m_rightBalls.reserve(MAX_BALLS);

    for (int index = 0; index < MAX_BALLS; index++)
    {
        Ball leftBall;
        m_leftBalls.push_back(leftBall);

        Ball rightBall;
        m_rightBalls.push_back(rightBall);
    }
}

void Game::init(int t_ActiveBalls)
{

    
    int maxRadius = 100;

    for (int index = 0; index < MAX_BALLS; index++)
    {

        int currentLeftRadius = (rand() % maxRadius) + 1; 
        while (currentLeftRadius > 80)
        // capping max radius to 80
        {
            currentLeftRadius = 80; 
        }


        int currentRightRadius = (rand() % maxRadius) + 1; 
        if (currentRightRadius > 80)
        // capping max radius to 80
        {
            currentRightRadius = 80; 
        }



        m_leftBalls[index].init(currentLeftRadius);
        m_rightBalls[index].init(currentRightRadius);
    }
}

void Game::handleInput()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        //
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        // 
    }
}


void Game::update()
{
    float deltaTime = GetFrameTime(); // Get delta time frame time expressed in seconds
	
    handleInput();


    for (int index = 0; index < MAX_BALLS; index++)
    {
        m_leftBalls[index].update(deltaTime);
        m_rightBalls[index].update(deltaTime);
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
        
        
        for (int index = 0; index < MAX_BALLS; index++)
        {
            m_leftBalls[index].draw();
            m_rightBalls[index].draw();
        }
        
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