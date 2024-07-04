// Include Lib
#include <raylib.h>

#define PARALLAX_SCALE 3.0f

// Main Function
int main()
{
    // Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 480;

    float scrollMountains = 0.0f;
    float scrollForeMountains = 0.0f;
    float scrollMountainsTree = 0.0f;
    float scrollTrees = 0.0f;

    // Init Window (width, Height, title)
    InitWindow(screenWidth, screenHeight, "RayLib Parallax");

    Texture2D bg = LoadTexture("../resources/bg.png");
    Texture2D far = LoadTexture("../resources/far.png");
    Texture2D foreMountains = LoadTexture("../resources/mountains.png");
    Texture2D mountainsTree = LoadTexture("../resources/mountain-trees.png");
    Texture2D trees = LoadTexture("../resources/trees.png");
    // Set target FPS
    SetTargetFPS(60);

    // While windows is open
    while (!WindowShouldClose())
    {
        scrollMountains -= 0.15f;
        scrollForeMountains -= 0.4f;
        scrollMountainsTree -= 0.7f;
        scrollTrees -= 1.1f;

        if (scrollMountains <= -far.width * PARALLAX_SCALE)
            scrollMountains = 0;
        if (scrollForeMountains <= -foreMountains.width * PARALLAX_SCALE)
            scrollForeMountains = 0;
        if (scrollMountainsTree <= -mountainsTree.width * PARALLAX_SCALE)
            scrollMountainsTree = 0;
        if (scrollTrees <= -trees.width * PARALLAX_SCALE)
            scrollTrees = 0;
        // init drawing mode
        BeginDrawing();
        // Clear Background
        ClearBackground(RAYWHITE);
        // Draw Background Layer

        DrawTextureEx(bg, (Vector2){0, 0}, 0.0f, PARALLAX_SCALE, WHITE);
        // Draw Far Scroll
        DrawTextureEx(far, (Vector2){scrollMountains, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        DrawTextureEx(far, (Vector2){far.width * PARALLAX_SCALE + scrollMountains, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        // DrawForeMountains
        DrawTextureEx(foreMountains, (Vector2){scrollForeMountains, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        DrawTextureEx(foreMountains, (Vector2){foreMountains.width * PARALLAX_SCALE + scrollForeMountains, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        // Draw MountainsTree
        DrawTextureEx(mountainsTree, (Vector2){scrollMountainsTree, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        DrawTextureEx(mountainsTree, (Vector2){mountainsTree.width * PARALLAX_SCALE + scrollMountainsTree, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        // DrawTrees
        DrawTextureEx(trees, (Vector2){scrollTrees, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        DrawTextureEx(trees, (Vector2){trees.width * PARALLAX_SCALE + scrollTrees, 20}, 0.0f, PARALLAX_SCALE, WHITE);
        // Finish Drawing Mode
        EndDrawing();
    }

    UnloadTexture(bg);
    UnloadTexture(far);
    UnloadTexture(foreMountains);
    UnloadTexture(mountainsTree);
    UnloadTexture(trees);
    // Close Window
    CloseWindow();
    return 0;
}