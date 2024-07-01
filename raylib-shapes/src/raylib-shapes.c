//Include Lib
#include <raylib.h>

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    //Circle dimensions (center)
    Vector2 circle={screenWidth/4,screenHeight/4};
    //Rectangle dimenions (initial vertex and size)
    Vector2 rect = {((screenWidth/4)*3)-40,(screenHeight/4)-40};
    Vector2 rectSize = {190,90};

    //triangle vertex (v1,v2,v3)
    Vector2 v1={screenWidth/2,((screenHeight/4)*3)-40};

    Vector2 v2={(screenWidth/4)*3,((screenHeight/4)*3)+60};

    Vector2 v3={screenWidth/4,((screenHeight/4)*3)+60};

    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Raylib Shapes");
    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Circle
        DrawCircleV(circle,100,MAROON);
        //Draw Rectangle
        DrawRectangleV(rect,rectSize,DARKBLUE);
        //draw Triangle
        DrawTriangle(v1,v3,v2,GREEN);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}