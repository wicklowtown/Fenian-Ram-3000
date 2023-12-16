// Using guidance from Lecture 1, I added a basic Raylib structure.
// (From https://chirag4862.hashnode.dev/getting-started-with-raylib-for-game-development-in-c#)

#include "raylib.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(1280, 720, "Fenian Ram 3000");
    SetTargetFPS(60);

    // Using guidance from lecture 3, I added music.
    InitAudioDevice();
    Sound sound = LoadSound("music.wav");
    int volume = 50;
    SetSoundVolume(sound, volume / 100.0f);

    // Using guidance from Lecture 3, I began to load textures, add vectors and more.
    // The first image I added was a test for the playable sprite - the submarine.
    // This was then replaced by my own drawn sprites.

    Texture2D submarine1 = LoadTexture("submarine.png");
    Vector2 scale = {0.5f, 0.5f};

    float rotation = 0.0f;
    Color tint = WHITE;

    Vector2 position = {(screenWidth - (submarine1.width * scale.x)) / 2, (screenHeight - (submarine1.height * scale.y)) / 2};
    const float moveSpeed = 5.0f;

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {
        Vector2 position = GetMousePosition();
        position.x -= submarine1.width * scale.x / 2;
        position.y -= submarine1.height * scale.y / 2;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            tint = YELLOW;
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            tint = WHITE;
        }

        if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_THREE)) {
            switch (GetKeyPressed()) {
                case KEY_ONE:
                    tint = RED;
                    break;
                case KEY_TWO:
                    tint = BLUE;
                    break;
                case KEY_THREE:
                    tint = GREEN;
                    break;
                default:
                    break;
            }
        }

        // Using further guidance from Lecture 3, I added movement inputs to the sprite.
        if (IsKeyDown(KEY_RIGHT)) position.x += moveSpeed;
        if (IsKeyDown(KEY_LEFT)) position.x -= moveSpeed;
        if (IsKeyDown(KEY_UP)) position.y -= moveSpeed;
        if (IsKeyDown(KEY_DOWN)) position.y += moveSpeed;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) rotation -= 10.0f;
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) rotation += 10.0f;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        Vector2 textPosition = {10, screenHeight / 1 - 45};
        int textSize = 45;
        Color textColor = LIME;

        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }

    UnloadTexture(submarine1);
    CloseWindow();
    return 0;
}

