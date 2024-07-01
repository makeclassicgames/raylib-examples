//Include Lib
#include <raylib.h>

//Custom Color
#define LOGO_BACKGROUND_COLOR (Color){20,36,49,255}

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Raylib Texture");
    //Load Texture to GPU
    Texture2D texture = LoadTexture("../resources/logo.png");

    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){
        //init drawing mode
        BeginDrawing();
        //Clear Background to Custom Color
        ClearBackground(LOGO_BACKGROUND_COLOR);
        //Draw Texture
        DrawTexture(texture,screenWidth/2-texture.width/2,screenHeight/2-texture.height/2,WHITE);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Unload Texture from GPU
    UnloadTexture(texture);
    //Close Window
    CloseWindow();
    return 0;
}