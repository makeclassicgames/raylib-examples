//Include Lib
#include <raylib.h>

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    //Current Frame Counter
    int frameCounter=0;
    int currentFrame=0;
    int currentAnim=4;
    //Load the Image to RAM
    Image image = LoadImage("../resources/sha.png");

    InitWindow(screenWidth,screenHeight,"Raylib Sprite");

    //Load the Image RAM to VRAM
    Texture2D shatexture = LoadTextureFromImage(image);

    //Frame Rectantle
    Rectangle frameRec = {0,(shatexture.height/5)*4,shatexture.width/3,shatexture.height/5};
    //Position
    Vector2 position = {72,160};
   
    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){

        //Calculate Frame Change
        //If key Rigth Pressed
        if(IsKeyDown(KEY_RIGHT)){
          //Change Animation
          currentAnim=1;
          position.x++;
        }else{
            if(IsKeyDown(KEY_LEFT)){
              currentAnim=3;
             //Change Animation
              position.x--;
          }else{
              if(IsKeyDown(KEY_DOWN)){
                //Change Animation
                currentAnim=2;
                position.y++;
              }else{
                if(IsKeyDown(KEY_UP)){
                  //Change animation
                  currentAnim=0;
                  position.y--;
                }else{
                  //Change animation
                  currentAnim=4;
                }
              }
          }
        }
        //Add Frame Counter
        frameCounter++;
        //Each 6 frames, change sprite frame
        if(frameCounter%6==0){
          currentFrame++;
          if(currentFrame>2){
            currentFrame=0;
          }
        }
        //calculate new frame Rectangle using current frame and current anim
        frameRec.x=currentFrame*(shatexture.width/3);
        frameRec.y=currentAnim*(shatexture.height/5);

        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //Draw Sprite using rectangle
        DrawTextureRec(shatexture,frameRec,position,WHITE);

        //Finish Drawing Mode
        EndDrawing();
    }
    UnloadImage(image);
    UnloadTexture(shatexture);
    //Close Window
    CloseWindow();
    return 0;
}