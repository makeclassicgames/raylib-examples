//Include Lib
#include <raylib.h>
#include <stdio.h>

char* getCameraMode(int);

//Main Function
int main(){
    //Window Dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    //Init Window (width, Height, title)
    InitWindow(screenWidth,screenHeight,"Raylib Cube Camera");

    //Cube Position
    Vector3 cubePosition = {0.0f,0.0f,0.0f};

    Camera3D camera ={0};
    camera.position=(Vector3){10.0f,10.0f,10.0f};
    camera.target=(Vector3){0.0f,0.0f,0.0f};
    camera.up=(Vector3){0.0f,1.0f,0.0f};
    camera.fovy=45.0f;
    camera.projection=CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_PERSPECTIVE;

    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){

        
        if(IsKeyPressed(KEY_ONE)){
            cameraMode=CAMERA_PERSPECTIVE;
        }
            
        if(IsKeyPressed(KEY_TWO)){
              cameraMode=CAMERA_FIRST_PERSON;
        }

        if(IsKeyPressed(KEY_THREE)){
            cameraMode=CAMERA_FREE;
        }

        if(IsKeyPressed(KEY_FOUR)){
            cameraMode=CAMERA_ORBITAL;
        }

        if(IsKeyPressed(KEY_FIVE)){
            cameraMode= CAMERA_THIRD_PERSON;
        }

        if(IsKeyPressed(KEY_ZERO)){
            cameraMode= CAMERA_PERSPECTIVE;
        }

        if(IsKeyPressed(KEY_Z)){
            camera.target = (Vector3){0.0f,0.0f,0.0f};
        }
        

        UpdateCamera(&camera,cameraMode);

        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //3D Mode
            BeginMode3D(camera);
                //Draw Cube
                DrawCube(cubePosition,2.0f,2.0f,2.0f,BLUE);
                DrawCubeWires(cubePosition,2.0f,2.0f,2.0f,DARKBLUE);
            EndMode3D();

        //Draw Text
        DrawText("Press 1-5 to Change Camera Mode, Z to return to origin", 40,60,20,BLACK);
        char cameraModStr[40];
        sprintf(cameraModStr,"Camera Mode: %s",getCameraMode(cameraMode));
        DrawText(cameraModStr,40, 90,20,BLACK);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}

char * getCameraMode(int cameraMode){
    switch (cameraMode)
    {
    case CAMERA_FREE:
        return "Free";
    case CAMERA_ORBITAL:
        return "Orbital";
    case CAMERA_FIRST_PERSON:
        return "First Person";
    case CAMERA_PERSPECTIVE:
        return "Perspective";
    case CAMERA_THIRD_PERSON:
        return "Third Person";
    default:
        return "CUSTOM";
        break;
    }
}