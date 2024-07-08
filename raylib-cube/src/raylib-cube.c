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
    //Camera
    Camera3D camera ={0};
    //Camera Position
    camera.position=(Vector3){10.0f,10.0f,10.0f};
    //Camera Target
    camera.target=(Vector3){0.0f,0.0f,0.0f};
    camera.up=(Vector3){0.0f,1.0f,0.0f};
    camera.fovy=45.0f;
    //CAmera projection
    camera.projection=CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_PERSPECTIVE;

    //Set target FPS
    SetTargetFPS(60);

    //While windows is open
    while(!WindowShouldClose()){

        //Press 1 Camera Perspective        
        if(IsKeyPressed(KEY_ONE)){
            cameraMode=CAMERA_PERSPECTIVE;
        }
            
        //Press 2 First Person Camera
        if(IsKeyPressed(KEY_TWO)){
              cameraMode=CAMERA_FIRST_PERSON;
        }
        //Press 3 Free Camera
        if(IsKeyPressed(KEY_THREE)){
            cameraMode=CAMERA_FREE;
        }

        //Press 4 Orbital Camera
        if(IsKeyPressed(KEY_FOUR)){
            cameraMode=CAMERA_ORBITAL;
        }
        //Press 5 Third Person Camera
        if(IsKeyPressed(KEY_FIVE)){
            cameraMode= CAMERA_THIRD_PERSON;
        }

        //Press Z to look to the target
        if(IsKeyPressed(KEY_Z)){
            camera.target = (Vector3){0.0f,0.0f,0.0f};
        }
        
        //Update Camera
        UpdateCamera(&camera,cameraMode);

        //init drawing mode
        BeginDrawing();
        //Clear Background
        ClearBackground(RAYWHITE);
        //3D Mode
            BeginMode3D(camera);
                //Draw Cube
                DrawCube(cubePosition,2.0f,2.0f,2.0f,BLUE);
                //Draw Wire CUbes
                DrawCubeWires(cubePosition,2.0f,2.0f,2.0f,DARKBLUE);
            EndMode3D();

        //Draw Text
        DrawText("Press 1-5 to Change Camera Mode, Z to return to origin", 40,60,20,BLACK);
        char cameraModStr[40];
        sprintf(cameraModStr,"Camera Mode: %s",getCameraMode(cameraMode));
        //Show Camera Mode
        DrawText(cameraModStr,40, 90,20,BLACK);
        //Finish Drawing Mode
        EndDrawing();
    }
    //Close Window
    CloseWindow();
    return 0;
}

//Get Current Camera Mode
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