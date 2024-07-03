//Include Lib
#include <raylib.h>

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 544;
    const int screenHeight = 320;

    float scrollMountains=0.0f;
    float scrollForeMountains=0.0f;
    float scrollMountainsTree=0.0f;
    float scrollTrees = 0.0f;


    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"RayLib Paralax");
    

    Texture2D bg= LoadTexture("../resources/bg.png");
    Texture2D far = LoadTexture("../resources/far.png");
    Texture2D foreMountains = LoadTexture("../resources/mountains.png");
    Texture2D mountainsTree = LoadTexture("../resources/mountain-trees.png");
    Texture2D trees = LoadTexture("../resources/trees.png");
    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){
        scrollMountains-=0.15f;
        scrollForeMountains-=0.4f;
        scrollMountainsTree-=0.7f;
        scrollTrees -=1.1f;



        if(scrollMountains<= -far.width*2.0f) scrollMountains=0;
        if(scrollForeMountains<=-foreMountains.width*2.0f) scrollForeMountains=0;
        if(scrollMountainsTree<=-mountainsTree.width*2.0f) scrollMountainsTree=0;
        if(scrollTrees <= -trees.width*2.0f) scrollTrees=0;
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Background Layer
        
        DrawTextureEx(bg,(Vector2){0,0},0.0f,2.0f,WHITE);
        //Draw Far Scroll
        DrawTextureEx(far, (Vector2){scrollMountains,20},0.0f,2.0f,WHITE);
        DrawTextureEx(far, (Vector2){far.width*2.0+scrollMountains,20},0.0f,2.0f,WHITE);
        //DrawForeMountains
        DrawTextureEx(foreMountains,(Vector2){scrollForeMountains,20},0.0f,2.0f,WHITE);
        DrawTextureEx(foreMountains,(Vector2){foreMountains.width*2.0f+scrollForeMountains,20},0.0f,2.0f,WHITE);
        //Draw MountainsTree
        DrawTextureEx(mountainsTree,(Vector2){scrollMountainsTree,20},0.0f,2.0f,WHITE);
        DrawTextureEx(mountainsTree,(Vector2){mountainsTree.width*2.0f+scrollMountainsTree,20},0.0f,2.0f,WHITE);
        //DrawTrees
        DrawTextureEx(trees,(Vector2){scrollTrees,20},0.0f,2.0f,WHITE);
        DrawTextureEx(trees,(Vector2){trees.width*2.0f+scrollTrees,20},0.0f,2.0f,WHITE);
        //Finish Drawing Mode
        EndDrawing();
    }

    UnloadTexture(bg);
    UnloadTexture(far);
    UnloadTexture(foreMountains);
    UnloadTexture(mountainsTree);
    UnloadTexture(trees);
    //Close Window
    CloseWindow();
    return 0;
}