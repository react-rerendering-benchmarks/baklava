#include <vector>
#include "raylib.h"
#include "../headerFiles/camera.h"
#include "../headerFiles/tower.h"
#include "../headerFiles/enemies.h"

int main()
{
    // Initializing the window
    const int fpsCap = 60;
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Baklava");

    // Defining the camera
    Camera camera = { 0 };
    cameraSetUp(
        camera,
        50.0f, // FOV
        Vector3({20.0f, 22.0f, 20.0f}), // Position
        Vector3({0.0f, 0.0f, 0.0f}) // Target
    );
    
    // Initializing the tower stats: attack speed, attack power, defense, health, regen, size and position
    TowerStats towerStats = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, Vector3({3.0f, 9.0f, 3.0f}), Vector3({0.0f, 4.5f, 0.0f}) };
 
    // Initializing enemy system
    std::vector<EnemyStats> enemyList;
    const int enemyLimit = 10, debounceTimer = 0.4*fpsCap;
    enemyList.reserve(enemyLimit);
    int enemyDebounce = 0;
    EnemyWave mainWave;
    mainWave.wave = 1;
    mainWave.enemiesLeft = 10;

    // Setting the fps cap to 60
    SetTargetFPS(fpsCap);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Generates new enemy when under enemy limit and off cooldown
        if (int(enemyList.size()) <= enemyLimit && enemyDebounce == 0)
        {

            enemyList.push_back(generateEnemy(mainWave));

            enemyDebounce = debounceTimer;
        }
        enemyDebounce--;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
            
        DrawGrid(50, 1.0f);

        for (size_t i = 0; i < enemyList.size(); i++)
        {
            drawEnemy(enemyList[i], RED, BROWN);

            enemyList[i].linePos -= 4.0f * GetFrameTime();

            if (enemyList[i].linePos <= 1.8f)
            {
                enemyList.erase(enemyList.begin() + i);
            }
        }

        drawTower(towerStats, BLUE, DARKBLUE);
                   
        EndMode3D();

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}