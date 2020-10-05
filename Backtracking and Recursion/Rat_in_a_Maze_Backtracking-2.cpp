#include <bits/stdc++.h>

using namespace std;

#define loop for(int i=0;i<N;i++)for(int j=0;j<N;j++)

#define N 4

bool isPossible(int x,int y,int maze[][N])
{
    return x>=0 && y>=0 && x<N && y<N && maze[x][y]==1;
}

void print(int maze[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<"  "<<setw(2)<<maze[i][j]<<"  ";
        cout<<"\n";
    }
}

bool solveUtil(int x, int y,int maze[][N],int sol[][N])
{
    // goal
    if ( x == N - 1 && y == N - 1 && maze[x][y] == 1) 
    { 
        sol[x][y] = 1; 
        return true; 
    } 
  
    // Check if maze[x][y] is valid 
    if (isPossible( x, y, maze) == true) 
    { 
        // mark
        sol[x][y] = 1; 
  
        //move forward
        if (solveUtil(x + 1, y, maze, sol) == true) 
            return true; 
  
        //move right
        if (solveUtil(x, y+1, maze, sol) == true) 
            return true; 
  
        //Backtrack
        sol[x][y] = 0; 
        return false; 
    } 
  
    return false; 
}

bool solve(int maze[][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 

    if (solveUtil(0, 0, maze, sol) == false) 
    { 
        printf("Solution doesn't exist"); 
        return false; 
    } 
    print(sol);
    return true;
}

int main()
{
    int maze[N][N] = 
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solve(maze);
    return 0;
}