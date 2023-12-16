// Using guidance from Lecture 1, I added a basic Raylib structure.
// (From https://chirag4862.hashnode.dev/getting-started-with-raylib-for-game-development-in-c#)

#include "raylib.h"

//Main set-up section

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Fenian Ram 3000");

    SetTargetFPS(60);

//Music set-up section
//This was very difficult to set up. I tried removing the feature of pressing spacebar to start the sound,
// as shown in Lecture 3, because I wanted the music files to play automatically throughout.
// I found solutions by using the ‘LoadMusicStream’ and ‘PlayMusicStream’ features.
// The resource I used to find this solution was:
// https://www.raylib.com/examples/audio/loader.html?name=audio_music_stream

    InitAudioDevice();
    Music music1 = LoadMusicStream("music.wav");
    Music music2 = LoadMusicStream("Underwatersounds.wav");

    PlayMusicStream(music1);
    PlayMusicStream(music2);

    // Submarine Sprite set-up section
    // I increased the moveSpeed as shown in the lecture from 5.0f to 7.0f.
    Texture2D submarine1 = LoadTexture("submarine.png");
    Vector2 position = {(float) screenWidth / 2 - submarine1.width / 2,
                        (float) screenHeight / 2 - submarine1.height / 2};
    Vector2 scale = {0.5f, 0.5f};
    float moveSpeed = 7.0f;

    // Using further guidance from Lecture 3, I added movement inputs to the sprite.

    // Submarine Movement
    if (IsKeyDown(KEY_RIGHT)) position.x += moveSpeed;
    if (IsKeyDown(KEY_LEFT)) position.x -= moveSpeed;
    if (IsKeyDown(KEY_UP)) position.y -= moveSpeed;
    if (IsKeyDown(KEY_DOWN)) position.y += moveSpeed;

    UpdateMusicStream(music1);
    UpdateMusicStream(music2);

    BeginDrawing();
    ClearBackground(BLUE);
    DrawTextureEx(submarine1, position, 0.0f, 0.5f, BLACK);
    // Here goes all the Game Logic
    EndDrawing();

    UnloadTexture(submarine1);
    CloseWindow();
    return 0;
}