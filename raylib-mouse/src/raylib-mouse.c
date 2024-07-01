//Include Lib
#include <raylib.h>

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    bool clicked=false;

    Vector2 mousePosition;
    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Hello Raylib");
    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mousePosition=GetMousePosition();
            clicked=true;
        }
        
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Text
        DrawText("Click On Screen to draw and drag a Circle",120,40,20,BLACK);
        //When clicked draw a Circle
        if(clicked){
            DrawCircleV(mousePosition,40,MAROON);
            clicked=false;
        }
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}