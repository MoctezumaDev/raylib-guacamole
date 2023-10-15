#include "raylib.h"
#include "raymath.h"

#define PLAYER_HOR_SPD 200.0f

typedef struct Player {
    Vector2 position;
} Player;

//----------------------------------------------------------------------------------
// Module functions declaration
//----------------------------------------------------------------------------------
void UpdatePlayer(Player *player, float delta);

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    Player player = { 0 };
    player.position = (Vector2){ 400, 280 };

    

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        UpdatePlayer(&player, deltaTime);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You can move left and right!", 190, 200, 20, LIGHTGRAY);
            Rectangle playerRect = { player.position.x - 20, player.position.y - 40, 40, 40 };
            DrawRectangleRec(playerRect, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void UpdatePlayer(Player *player, float delta)
{
    if (IsKeyDown(KEY_LEFT)) player->position.x -= PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += PLAYER_HOR_SPD*delta;
}