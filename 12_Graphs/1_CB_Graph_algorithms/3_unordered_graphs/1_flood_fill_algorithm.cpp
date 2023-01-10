#include<bits/stdc++.h>
using namespace std;
int R,C;
void printMat(char input[][50])
{
    for(int i=0; i<R;i++)
    {
        for(int j=0; j<C;j++)
        {
            cout<<input[i][j];
        }
        cout<<endl;
    }
}          
/* W (row decrememnt col same)(i-1,j)
   |
 N____S (row same col increment)(i,j+1)
   |
   E(col same row increment)(i+1,j)
*/
// W,N,E,S
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

// ch is the character to be replaced
// color is the character to be added
void floodFill(char mat[][50], int i, int j, char ch, char color)
{// the dots present inside the input 2D apple are just the combination of connected components  
///base case - matrixx bounds
if(i<0 || j<0 || i>= R ||j>= C)
{
    return ;
}
// figure boundary condition
if(mat[i][j] != ch)
{
   return; 
}
// recursive call
mat[i][j] = color;
printMat(mat);
cout<<endl;

for(int k=0; k<4;k++)
{
    floodFill(mat, i+dx[k], j+dy[k], ch,color);
}
}

int main()
{
    cin>>R>>C;
    char input[15][50];

    for(int i=0; i<R;i++)
    {
        for(int j=0; j<C;j++)
        {
            cin>>input[i][j];
        }
    }
    printMat(input);
    floodFill(input, 8,13,'.','r');
    floodFill(input, 0,0,'.','!');
    printMat(input);
}

// flood fill algorithm -> the application of DFS
// 1. used to colour the various connected components in a graph
//2. it is generally performed on implicit graphs(2D matrices)
//3. starting from the particular cell we call 'DFS' on the neighbouring cells to colour them, neighbours can be '4' (up,down,left,right) or '8' if we include diagonals also 