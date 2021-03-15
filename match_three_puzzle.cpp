/*  Create a nxn matrix board for candy crush game with k different cell colors

    No 3 or more cells of same color should come together horizontally or diagonally.
    Colors should bre alloted randomly using random()
*/
#include<stdio.h>
#include<stdlib.h>

// n=5;
int board[5][5];
int k=4;

int generate_random(int x, int y)
{
    int z;
    do
    {
        z = rand()%(k)+ 1;
    }while(z==x || z==y);

    return z;
}

void create_board(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int t=0,l=0;
            if(i-2>=0)//check on top of the cell
                if(board[i-1][j] == board[i-2][j])
                    t = board[i-1][j];
            
            if(j-2>=0)//check on left of the cell
                if(board[i][j-1] == board[i][j-2])
                    l = board[i][j-1];

            board[i][j] = generate_random(t,l);
        }
    }
}
int main()
{
    create_board(5);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
    return 0;
}
