//Include Lib
#include <raylib.h>

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Hello Raylib");
    //Set target FPS
    SetTargetFPS(60);
    //Init()
    //While windows is open
    while(!WindowShouldClose()){

        //update()

        //Draw()
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Text
        DrawText("Hello Raylib", 290,200,20,BLACK);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}