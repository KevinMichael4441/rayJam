#include <stdio.h>
#include <raylib.h>

#include "../include/game.h"

/**
 * InitGame : Sets everything up before the madness begins.
 *
 * Creates the player, the NPC, and the two mediators that stop them
 * shouting directly at the FSM. Also fires up the input and AI systems.
 * Oh and as Ireland is so green (from all the rain), a nice lush grass background.
 *
 * @data: The GameData structure that holds the whole operation together
 */

void InitGame(GameData *data)
{
}


/**
 * UpdateGame : Runs one tick of game logic.
 *
 * Handles player input, NPC behaviour, state updates, and collisions.
 * The NPC gets a new "idea" every second, which is generous given its low IQ.
 *
 * @data:      All the game's current state.
 * @deltaTime: Time since the last update.
 */
void UpdateGame(GameData *data, float deltaTime)
{
}

/**
 * DrawGame : Draws all the craic on screen.
 *
 * Renders the player, the NPC, their positions, health bars,
 * and whatever animations they've decided to show off.
 *
 * @data: The game state to render.
 */

void DrawGame(const GameData *data)
{
	
}

/**
 * CloseGame - Shuts everything down gracefully.
 *
 * Runs the cleanup routine so you're not leaving memory lying around
 * like empty pint glasses after closing time (in Dinn Ri again).
 *
 * @data: The game data to be disposed of.
 */

void CloseGame(GameData *data)
{
	// printf("Game Closed!\n");

	// If the game data is not null, delete all objects associated with the game
	if (data != NULL)
	{
		DeleteGameData(data);
	}
}

/**
 * DeleteGameData - Frees every object in the game's data.
 *
 * Deletes player, NPC, mediators, and finally frees the GameData
 * itself. No memory leaks here, thank you very much.
 *
 * @data: The structure to purge (I've watched a few)
 * "The unwritten Purge rule: don't save lives" but do free memory
 */

void DeleteGameData(GameData *data)
{

}