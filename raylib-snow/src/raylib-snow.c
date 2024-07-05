//Include Lib
#include <raylib.h>

#define MAX_FLAKES 40


typedef struct{
    Texture2D texture;
    Vector2 position;
    bool visible;
}snow;

snow flakes[MAX_FLAKES];

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 1280;
    const int screenHeight = 720;

    //Init Flakes

   
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Hello Raylib");

    Texture2D background = LoadTexture("../resources/icecap.png");
    Texture2D snowFlake = LoadTexture("../resources/snowflake.png");

     for(int i=0;i<MAX_FLAKES;i++){
        flakes[i]=(snow){snowFlake,(Vector2){GetRandomValue(0,1280),0},false};
    }
    
    
    //Set target FPS
    SetTargetFPS(60);
    //Init()
    //While windows is open
    while(!WindowShouldClose()){

        //update()

        for(int i=0;i<MAX_FLAKES;i++){
            snow flake = flakes[i];
            if(flake.visible){
                flake.position.y+=5;
                flake.position.x-=2;
                if(flake.position.y>screenHeight){
                    flake.position.y=0;
                    flake.position.x=GetRandomValue(0,screenWidth);
                    flake.visible=false;
                }
            }
            flakes[i]=flake;
        }

        //make next flake Visible

        int index = GetRandomValue(0,MAX_FLAKES-1);
        snow flake= flakes[index];

        if(!flake.visible){
            flake.visible=true;
        }

        flakes[index]=flake;

        //Draw()
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Background
        DrawTexture(background,0,0,WHITE);

        for(int i=0;i<MAX_FLAKES;i++){
            if(flakes[i].visible){
                DrawTextureEx(flakes[i].texture,flakes[i].position,0.0f,0.1f,WHITE);
            }
        }
        //Finish Drawing Mode
        EndDrawing();
    }
    UnloadTexture(snowFlake);
    UnloadTexture(background);
    //Close Window
    CloseWindow();
    return 0;
}