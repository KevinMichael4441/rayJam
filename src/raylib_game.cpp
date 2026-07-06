/*******************************************************************************************
*
*   raylib gamejam template
*
*   Code licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022-2026 Ramon Santamaria (@raysan5)
*
********************************************************************************************/


#include "raylib.h"
#include "include/game.h"
#include "include/constants.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>      // Emscripten library
#endif

#include <stdio.h>                          // Required for: printf()
#include <stdlib.h>                         // Required for: 
#include <string.h>                         // Required for:
#include <iostream>

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
// Simple log system to avoid printf() calls if required
// NOTE: Avoiding those calls, also avoids const strings memory usage
#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
    #define LOG(...) printf(__VA_ARGS__)
#else
    #define LOG(...)
#endif

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum { 
    SCREEN_LOGO = 0, 
    SCREEN_TITLE, 
    SCREEN_GAMEPLAY, 
    SCREEN_ENDING
} GameScreen;

// TODO: Define your custom data types here

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 720;
static const int screenHeight = 720;

// Function Prototypes
// Game Loop Function
void GameLoop(GameData *data);

/**
 * main - Entry point of the whole shebang.
 *
 * Sets up the Raylib window, fires up the game systems, and kicks off
 * the main loop. When the player finally closes the window, everything
 * gets cleaned up properly ..... none of this "sure it's grand" memory 
 * leaking is no problem I've loads after shelling out for another 64 GB of DDR5.
 */

int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);         // Disable raylib trace log messages
#endif


	srand(time(NULL));

	// Init raylib window
	InitWindow(screenWidth, screenHeight, "Aliens v Mech by Kevin Michael c00313609");

    // TODO: Load resources / Initialize variables at this point
    // Create GameData Pointer
	GameData *data = (GameData *)(malloc(sizeof(GameData)));

	// Initialise Game
	InitGame(data);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(GameLoop(data), 60, 1);
#else
	// Set Target FPS
	SetTargetFPS(TARGET_FPS);

	// Raylib while loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// Call GameLoop
		GameLoop(data);
	}
#endif
    
    // TODO: Unload all loaded resources at this point-------------------------------------------------------------------------------------
	// Free resources
	CloseGame(data);

	// Close Raylib Window
	CloseWindow();

	return 0;
}

/**
 * GameLoop - One full cycle of updating and drawing.
 *
 * Updates the game world first (because drawing before thinking rarely ends well),
 * then starts the Raylib drawing phase and renders the whole scene.
 *
 * @data: Pointer to the shared GameData struct.
 */

void GameLoop(GameData *data)
{
	// Update Game Data
	// Should be outside BeginDrawing(); and EndDrawing();
	float deltaTime = GetFrameTime(); // Get delta time frame time expressed in seconds

	UpdateGame(data, deltaTime);

	// Raylib function Draw
	BeginDrawing();

	// Clear the screen with a grren background
	ClearBackground(DARKGREEN);

	// Draw the Game Objects
	DrawGame(data);

	// Raylib End drawing to Frame Buffer
	EndDrawing();
}