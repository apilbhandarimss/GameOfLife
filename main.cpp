#include<iostream>
#include<cstdlib>
#include"raylib.h"
#define rows 200
#define col 300
#define cell_size 5
int grid[rows][col];
int countNeig(int r, int c)
{
    int count =0;
    for(int dr = -1;dr<=1;dr++)
    {
        for(int dc=-1;dc<=1;dc++)
        {
            if(dr==0 && dc==0)
            continue;
            int nr=(r+dr+rows)%rows;
            int nc = (c + dc + col) % col;
            count += grid[nr][nc];
        }
    }
    return count;
}
void nextSim()
{
    int next[rows][col];
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<col;c++)
        {
            int negi=countNeig(r,c);
            if(grid[r][c]==1)
            {
                next[r][c]=(negi==2||negi==3) ? 1: 0;
            }
            else next[r][c]=(negi==3)?1:0;
        }

    }
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < col; c++)
            grid[r][c] = next[r][c];

}
void randomize()
    {
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<col;c++)
            {
                grid[r][c]=rand()%2;

            }

        }
    }
void drawGrid()
{
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<col;c++)
        {
            Color color = grid[r][c] ? GREEN : BLACK;
            DrawRectangle(c*cell_size,r*cell_size,cell_size-1,cell_size-1,color);   
        
        }
    }
}



int main()
{

    InitWindow(col*cell_size,rows*cell_size,"Game_OF_Life");
    SetTargetFPS(160);
    randomize();
    int framecount = 0;
    int speed=5;
      while(!WindowShouldClose())
      {
        framecount++;
        if(framecount>=speed)
        {
            nextSim();
            framecount=0;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        drawGrid();
        EndDrawing();

      }
    CloseWindow();

    }
