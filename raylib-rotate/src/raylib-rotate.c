//Include Lib
#include <raylib.h>

#define ROTATION_DEG 0.8f

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    Rectangle rect = {screenWidth/2,screenHeight/2,140,140};
    Vector2 origin = {70,70};
    float rotation=0.2f;
    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Raylib Rotate");
    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){
        //If key right is pressed rotation added (clockwise)
        if(IsKeyDown(KEY_RIGHT)){
            rotation+=ROTATION_DEG;
        }
        //If key left is pressed rotation subs (counter-clockwise)
        if(IsKeyDown(KEY_LEFT)){
            rotation-=ROTATION_DEG;
        }
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Text
        DrawText("Press Right or Left to rotate",120,20,30,BLACK);
        //Draw rectangle using center as origin and rotation
        DrawRectanglePro(rect,origin,rotation,MAROON);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}