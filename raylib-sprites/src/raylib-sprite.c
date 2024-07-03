//Include Lib
#include <raylib.h>

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    int frameCounter=0;
    int currentFrame=0;
    int currentAnim=4;

    Image image = LoadImage("../resources/sha.png");

    InitWindow(screenWidth,screenHeight,"Raylib Sprite");

    Texture2D shatexture = LoadTextureFromImage(image);

    Rectangle frameRec = {0,(shatexture.height/5)*4,shatexture.width/3,shatexture.height/5};
    Vector2 position = {72,160};
   
    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){

        //Calculate Frame Change

        if(IsKeyDown(KEY_RIGHT)){
          currentAnim=1;
          position.x++;
        }else{
            if(IsKeyDown(KEY_LEFT)){
              currentAnim=3;
              position.x--;
          }else{
              if(IsKeyDown(KEY_DOWN)){
                currentAnim=2;
                position.y++;
              }else{
                if(IsKeyDown(KEY_UP)){
                  currentAnim=0;
                  position.y--;
                }else{
                  currentAnim=4;
                }
              }
          }
        }

        frameCounter++;

        if(frameCounter%6==0){
          currentFrame++;
          if(currentFrame>2){
            currentFrame=0;
          }
        }

        frameRec.x=currentFrame*(shatexture.width/3);
        frameRec.y=currentAnim*(shatexture.height/5);

        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);

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