//Include Lib
#include <raylib.h>
#include <stdio.h>

#define BALL_SPEED 1

#define GAMEPAD_N 0

void checkKeyBoardInput(void);

void checkGamepadInput(void);

const int screenWidth = 800;
const int screenHeight = 450;
int gamepadN;

Vector2 circlePosition={screenWidth/2,screenHeight/2};
//Main Function
int main(){
    


    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Raylib Input");
    //Set target FPS
    SetTargetFPS(60);

    //Get current Gamepad Avilable
   for(int i=0;i<4;i++){
     if(IsGamepadAvailable(i)){
        gamepadN=i;
        printf("Gamepad %d: %s", i,GetGamepadName(i));
        break;
     }
   }

    //While windows is open
    while(!WindowShouldClose()){
        
        checkKeyBoardInput();
        checkGamepadInput();
        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Text
        DrawCircleV(circlePosition,40,MAROON);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}

//Check GamePadInput
void checkGamepadInput(void){
    if(!IsGamepadAvailable(gamepadN)) return;
    //Get current Axis movement
    int xAxisMovement = GetGamepadAxisMovement(gamepadN,0);
    int yAxisMovement = GetGamepadAxisMovement(gamepadN,1);

    if(yAxisMovement>0){
       circlePosition.y+=BALL_SPEED;
    }

    if(yAxisMovement<0){
       circlePosition.x-=BALL_SPEED;

    }
    if(xAxisMovement>0){
       circlePosition.x+=BALL_SPEED;

    }

    if(xAxisMovement<0){
        circlePosition.x-=BALL_SPEED;
    }

}

//Check KeyBoard Input
void checkKeyBoardInput(){

    if(IsKeyDown(KEY_DOWN)){
        circlePosition.y+=BALL_SPEED;
    }
    if (IsKeyDown(KEY_UP))
    {
        circlePosition.y-=BALL_SPEED;
    }

    if(IsKeyDown(KEY_LEFT)){
        circlePosition.x-=BALL_SPEED;
    }

    if(IsKeyDown(KEY_RIGHT)){
        circlePosition.x+=BALL_SPEED;
    }
    
}
