//Include Lib
#include <raylib.h>
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//Update and Draw Frames
void updateDrawFrame(void);

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Hello Raylib");
    //Add ems main loop (no shouldclosewindow)
    emscripten_set_main_loop(updateDrawFrame,0,1);
    //Close Window
    CloseWindow();
    return 0;
}

void updateDrawFrame(void){
      BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Text
        DrawText("Hello Raylib", 290,200,20,BLACK);
        //Finish Drawing Mode
        EndDrawing();
}