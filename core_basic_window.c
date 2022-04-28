/*
Super Cario Bros
THE BEST SUPER MARIO BOOTLEG EVER MADE
*/

#include "raylib.h"
#include <unistd.h>
#include <stdio.h>

#define BUFLEN 1024

int main()
{
    srand (time(NULL));

    int screenWidth = 320;
    int screenHeight = 240;

    int playerX = 10;
    int playerY = 208;

    int goombaX = 310;
    int goombaDead = 0;
    int goombaDirection = 0;

    int direction = 0; //0 = right, 1 = left
    int score = 0;
    int scene = 2;

    InitWindow(screenWidth, screenHeight, "superCarioBros");

    SetTargetFPS(60);
    Image brickImage = LoadImage("bricks.png");
    Texture2D brickTexture = LoadTextureFromImage(brickImage);

    Image smLeft = LoadImage("sm_left.png");
    Texture2D smLeftTexture = LoadTextureFromImage(smLeft);

    Image smRight = LoadImage("sm_right.png");
    Texture2D smRightTexture = LoadTextureFromImage(smRight);

    Image goomba = LoadImage("goomba.png");
    Texture2D goombaTexture = LoadTextureFromImage(goomba);

    Image qmb = LoadImage("question_mark_block.png");
    Texture2D qmbTexture = LoadTextureFromImage(qmb);


    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(SKYBLUE);
            DrawText(TextFormat("%1i", score), 40, 40, 20, LIGHTGRAY);

            //floor
            DrawTexture(brickTexture, 0, 224, WHITE);
            DrawTexture(brickTexture, 16, 224, WHITE);
            DrawTexture(brickTexture, 32, 224, WHITE);
            DrawTexture(brickTexture, 48, 224, WHITE);
            DrawTexture(brickTexture, 64, 224, WHITE);
            DrawTexture(brickTexture, 72, 224, WHITE);
            DrawTexture(brickTexture, 88, 224, WHITE);
            DrawTexture(brickTexture, 104, 224, WHITE);
            DrawTexture(brickTexture, 120, 224, WHITE);
            DrawTexture(brickTexture, 136, 224, WHITE);
            DrawTexture(brickTexture, 152, 224, WHITE);
            DrawTexture(brickTexture, 168, 224, WHITE);
            DrawTexture(brickTexture, 184, 224, WHITE);
            DrawTexture(brickTexture, 200, 224, WHITE);
            DrawTexture(brickTexture, 216, 224, WHITE);
            DrawTexture(brickTexture, 232, 224, WHITE);
            DrawTexture(brickTexture, 248, 224, WHITE);
            DrawTexture(brickTexture, 264, 224, WHITE);
            DrawTexture(brickTexture, 272, 224, WHITE);
            DrawTexture(brickTexture, 288, 224, WHITE);
            DrawTexture(brickTexture, 304, 224, WHITE);
            DrawTexture(brickTexture, 320, 224, WHITE);
            DrawTexture(brickTexture, 336, 224, WHITE);

            //question mark blocks
            //initial
            DrawTexture(qmbTexture, 32, 144, WHITE);

            //row 1
            DrawTexture(qmbTexture, 72, 144, WHITE);
            DrawTexture(brickTexture, 88, 144, WHITE);
            DrawTexture(qmbTexture, 104, 144, WHITE);
            DrawTexture(brickTexture, 120, 144, WHITE);
            DrawTexture(qmbTexture, 136, 144, WHITE);
            //row 2
            //DrawTexture(qmbTexture, 88, 128, WHITE);
            //DrawTexture(brickTexture, 104, 128, WHITE);
            //DrawTexture(qmbTexture, 120, 128, WHITE);
            //row 3
            DrawTexture(qmbTexture, 104, 96, WHITE);

            //player
            if (IsKeyDown(KEY_LEFT)) {
                direction = 1;
                playerX = playerX - 2;
            } else if (IsKeyDown(KEY_RIGHT)) {
                direction = 0;
                playerX = playerX + 2;
            }

            if (direction == 0) {
                DrawTexture(smRightTexture, playerX, playerY, WHITE);
            } else {
                DrawTexture(smLeftTexture, playerX, playerY, WHITE);
            }

            //goomba
            if (goombaDirection == 0) {
                goombaX--;
            } else {
                goombaX++;
            }
            if (goombaDead == 0) {
                DrawTexture(goombaTexture, goombaX, 208, WHITE);
            }
            if (IsKeyPressed(KEY_X)) {
                if (direction == goombaDirection) {
                    if (direction == 0) {
                        int radius = playerX + 10;
                        if (goombaX < radius) {
                            goombaDead = 1;
                            score++;
                            int seed = rand() % 300 + 1;
                            if (seed % 2 == 1) {
                                goombaX = 10;
                                goombaDirection = 1;
                            } else {
                                goombaX = 310;
                                goombaDirection = 0;
                            }

                            goombaDead = 0;
                        }
                    } else {
                        int radius = playerX - 10;
                        if (goombaX > radius) {
                            goombaDead = 1;
                            score++;
                            int seed = rand() % 300 + 1;
                            if (seed % 2 == 1) {
                                goombaX = 10;
                                goombaDirection = 1;
                            } else {
                                goombaX = 310;
                                goombaDirection = 0;
                            }

                            goombaDead = 0;
                        }
                    }
                }
            }


        EndDrawing();
    }


    CloseWindow();

    return 0;
}

