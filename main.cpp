#include <raylib.h>
#include <stdio.h>

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Stephen's Window");

    // circle
    int circleX{200}, circleY{200}, circleR{25};
    
    // circle hitbox
    int l_circleX{circleX - circleR};
    int r_circleX{circleX + circleR};
    int u_circleY{circleY - circleR};
    int b_circleY{circleY + circleR};

    // square coordinates
    int rectX{400};
    int rectY{0};
    int rectSize{50};

    // square edges
    int l_rectX{rectX};
    int r_rectX{rectX + rectSize};
    int u_rectY{rectY};
    int b_rectY{rectY + rectSize};

    int direction{10};
    bool collision = (b_rectY >= u_circleY) && (u_rectY <= b_circleY) && (r_rectX >= l_circleX) && (l_rectX <= r_circleX);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            l_circleX = circleX - circleR;
            r_circleX = circleX + circleR;
            u_circleY = circleY - circleR;
            b_circleY = circleY + circleR;
            l_rectX = rectX;
            r_rectX = rectX + rectSize;
            u_rectY = rectY;
            b_rectY = rectY + rectSize;

            collision = (b_rectY >= u_circleY) && (u_rectY <= b_circleY) && (r_rectX >= l_circleX) && (l_rectX <= r_circleX);

            DrawCircle(circleX, circleY, circleR, BLUE);
            DrawRectangle(rectX, rectY, rectSize, rectSize, RED);

            rectY += direction;
            if (rectY > height || rectY < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circleX < width)
            {
                circleX += 10;
            }
            if (IsKeyDown(KEY_A) && circleX > 0)
            {
                circleX -= 10;
            }
        }
        
        EndDrawing();
    }
}
