#include "raylib.h"

int main()
{   
    //window dimensions
    int width{800};
    int height{450};
    
    //window creation
    InitWindow(width, height, "Keezy's Window");
    
    //circle information
    int circle_x{200};
int circle_y{200};  
    int circle_radius{25};

    //circle edges 
    int l_circle_x{circle_x- circle_radius};
    int r_circle_x{circle_x+ circle_radius};
    int u_circle_y{circle_y * circle_radius};
    int b_circle_y{circle_y + circle_radius};
    
    //axe information
    int axe_x{400};
    int axe_y{0};
    int axe_length {50};

    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};
    
    
    //axe direction per frame    
    int direction{10};

    //collision variable
    bool collision_with_axe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (r_axe_x >= l_circle_x) && 
                    (l_axe_x <= r_circle_x);
   



    SetTargetFPS(60);
    while(WindowShouldClose()!=true)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        //collision if statement
        if(collision_with_axe)
        {
            DrawText("Game over DICKHEAD", 400, 200, 20, RED);
        }
        else
        {

        
          //Game logic begins

          //update the edges
          l_circle_x = circle_x + circle_radius;
          r_circle_x = circle_x + circle_radius;
          u_circle_y = circle_y - circle_radius;
          b_circle_y = circle_y + circle_radius;

          l_axe_x = axe_x;
          r_axe_x = axe_x + axe_length;
          u_axe_y = axe_y;
          b_axe_y = axe_y + axe_length;
          //update collision_with_axe 
          collision_with_axe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (r_axe_x >= l_circle_x) && 
                    (l_axe_x <= r_circle_x);


            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
             DrawCircle(circle_x,circle_y, circle_radius,BLUE);

          //move the axe
            axe_y += direction;
            if(axe_y > height || axe_y < 0){
                direction = -direction;
            }


            if(IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if(IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

        }
        //Game logic ends
        EndDrawing();
    };
}