#ifndef GAME_H
#define GAME_H

// Define the GameData struct to store the main game components (player, npc, and mediator)
typedef struct
{

} GameData;

// Initialises the game components (player, npc, mediator)
void InitGame(GameData *data);

// Updates the game state each frame (handles game logic)
void UpdateGame(GameData *data, float deltaTime);

// Draws or renders the current game state (e.g., player, npc, environment)
void DrawGame(const GameData *data);

// Closes the game, performing necessary cleanup and freeing resources
void CloseGame(GameData *data);

// Frees memory associated with GameData and its components (player, npc, mediator)
void DeleteGameData(GameData *data);

#endif // GAME_H