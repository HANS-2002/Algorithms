//Courtesy: https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/?ref=leftbar-rightbar
#include <bits/stdc++.h>

using namespace std;

#define loop for(int i=0;i<N;i++)for(int j=0;j<N;j++)

#define N 30
/*For N=25 it completes in measureable time.
  But for N=30 it takes lot of time(102.474s (XD)).*/

void print(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            cout<<"  "<<setw(2)<<board[i][j]<<"  ";
        cout<<"\n"; 
    } 
} 

bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  
    //Check this row on left side
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    //Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    //Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 

bool solveUtil(int board[N][N], int col) 
{ 
    //base case: If all queens are placed then return true
    if (col >= N) 
        return true; 
  
    //Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) { 
        //Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) { 
            //Place this queen in board[i][col]
            board[i][col] = 1; 
  
            /* recur to place rest of the queens */
            if (solveUtil(board, col + 1)) 
                return true; 
  
            /* If placing queen in board[i][col] doesn't lead to a solution, then 
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK 
        } 
    } 
  
    // If the queen cannot be placed in any row in this colum col then return false 
    return false; 
} 
  
/* This function solves the N Queen problem using 
   Backtracking. It mainly uses solveNQUtil() to  
   solve the problem. It returns false if queens 
   cannot be placed, otherwise, return true and 
   prints placement of queens in the form of 1s. 
   Please note that there may be more than one 
   solutions, this function prints one  of the 
   feasible solutions.*/
bool solve() 
{ 
    int board[N][N];
    loop board[i][j]=0;
  
    if (solveUtil(board, 0) == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    print(board); 
    return true; 
} 
  
int main() 
{ 
    solve(); 
    return 0; 
} 