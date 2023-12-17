// Using guidance from Lecture 1, I added a basic Raylib structure.
// (From https://chirag4862.hashnode.dev/getting-started-with-raylib-for-game-development-in-c#)
#include "raylib.h"

//Main set-up section
int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Fenian Ram 3000");
    SetTargetFPS(60);

    //Music set-up section
//This was very difficult to set up. I tried removing the feature of pressing
// spacebar to start the sound, as shown in Lecture 3, because I wanted the music to play automatically
// throughout. I found solutions by using ‘LoadMusicStream’ and ‘PlayMusicStream’ features.
// The resource I used to find this solution was:
// https://www.raylib.com/examples/audio/loader.html?name=audio_music_stream
    InitAudioDevice();
    Music music1 = LoadMusicStream("music.wav");
    Music music2 = LoadMusicStream("Underwatersounds.wav");
    PlayMusicStream(music1);
    PlayMusicStream(music2);

    // Submarine Sprite set-up section
    Texture2D submarine1 = LoadTexture("NewSub2.png");
    Vector2 position = {(float)screenWidth / 2 - submarine1.width / 2,
                        (float)screenHeight / 2 - submarine1.height / 2};
    float moveSpeed = 6.0f;

    // Title Screen set-up
    // I wanted the titles to evoke the Irish flag colours.
    // Information on setting up titles was found following along with Lecture 3, as well as using the following:
    // https://www.raylib.com/examples/core/loader.html?name=core_basic_screen_manager
    // https://stackoverflow.com/questions/66566761/how-to-make-a-simple-menu-with-c-and-raylib
    // https://www.youtube.com/watch?v=dd5uUfilpJw

    // I then added back in the custom fonts I download, to be used with each piece of title text.
    // Not all ended up being used. Also, some were limited to letters and not numbers, so couldn't be used for the
    // "3000" in the title screen.
    Font customFont = LoadFont("grasping.ttf");
    Font customFont2 = LoadFont("COMICATE.TTF");
    Font customFont3 = LoadFont("Outwrite.ttf");
    Font customFont4 = LoadFont("CabalBold.ttf");
    Font customFont5 = LoadFont("hardik.ttf");
    Font customFont6 = LoadFont("inflate.ttf");
    Font customFont7 = LoadFont("Freedom.ttf");

    bool FenianTitleScreen1 = true;
    float titleY = -MeasureText("Fenian Ram 3000", 90);
    float enterY = screenHeight;
    bool titleEntered = false;
    bool enterEntered = false;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music1);
        UpdateMusicStream(music2);

        if (FenianTitleScreen1) {
            BeginDrawing();
            ClearBackground(BLACK);
            if (!titleEntered) {
                titleY += GetFrameTime() * 100;
                if (titleY >= screenHeight / 2 - 50) {
                    titleEntered = true;
                    titleY = screenHeight / 2 - 50;
                }
            }
            DrawTextEx(customFont7, "Fenian Ram",
                       (Vector2){screenWidth / 2 -
                                 MeasureTextEx(customFont7,"Fenian Ram ",
                                               80,2).x / 2, titleY},80, 2, LIME);
            if (titleEntered && !enterEntered) {enterY -= GetFrameTime() * 100;
                if (enterY <= screenHeight / 2 + 50) {
                    enterEntered = true;
                    enterY = screenHeight / 2 + 50;
                }
            }

            //With 'customfont7', it wouldn't register numbers, so I copied the "Fenian Ram" title text code
            //above and used it with a different font to read "3000". I accidentally copied this twice,
            //but I like the overlapping look it gives the text, so I played around and adjusted the text,
            //keeping the two texts in.
            DrawTextEx(customFont3, "3000", (Vector2){screenWidth / 1.3 -
                                                      MeasureTextEx(customFont3,
                                                                    "3000",90, 2).x / 2, titleY - 4},
                       110, 2, WHITE);
            DrawTextEx(customFont3, "3000", (Vector2){screenWidth / 1.3 -
                                                      MeasureTextEx(customFont3,
                                                                    "3000", 90, 2).x / 2,
                                                      titleY - 4},115, 2, WHITE);

            if (titleEntered && !enterEntered) {
                enterY -= GetFrameTime() * 100;
                if (enterY <= screenHeight / 2 + 50) {
                    enterEntered = true;
                    enterY = screenHeight / 2 + 50;
                }
            }
            DrawText("Press ENTER to Play", screenWidth / 2 -
                                            MeasureText("Press ENTER to Play", 20) / 2,
                     enterY,20, ORANGE);EndDrawing();
            if (titleEntered && enterEntered && IsKeyPressed(KEY_ENTER)) {
                FenianTitleScreen1 = false;
            }
            continue;
        }

        // Using further guidance from Lecture 3, I added movement inputs to the sprite.
        // Submarine Movement set-up
        if (IsKeyDown(KEY_RIGHT) && position.x + submarine1.width / 2 < screenWidth - 10)
        {
            position.x += moveSpeed;
        }
        if (IsKeyDown(KEY_LEFT) && position.x - submarine1.width / 2 > 10)
        {
            position.x -= moveSpeed;
        }
        if (IsKeyDown(KEY_UP) && position.y - submarine1.height / 2 > 10)
        {
            position.y -= moveSpeed;
        }
        if (IsKeyDown(KEY_DOWN) && position.y + submarine1.height / 2 < screenHeight - 10)
        {
            position.y += moveSpeed;
        }


        //Main game loop set-up

        BeginDrawing();
        ClearBackground(BLUE);

        DrawTextureEx(submarine1, position, 0.0f, 0.5f, WHITE);

        DrawTextEx(customFont4, "LEVEL 1", (Vector2){5, screenHeight - 110},
                   40, 2, PINK);
        DrawTextEx(customFont7, "Dreamy Depths", (Vector2){5, screenHeight - 70},
                   40, 2, RAYWHITE);
        DrawTextEx(customFont7, "Use the arrows to move", (Vector2){5,screenHeight - 30},
                   20, 2, PINK);

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}