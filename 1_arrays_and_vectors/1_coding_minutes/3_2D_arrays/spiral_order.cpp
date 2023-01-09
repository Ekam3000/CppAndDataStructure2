#include<iostream>
using namespace std;
// four variables
int main()
{
    int array[][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int startrow=0, startcol=0;
    int endrow=n-1, endcol=n-1;
    // aplly 4 for loops
    startrow (startcol....endcol)
    endcol(startrow+1 .... endrow)
    endrow(endcol -1 .... startcol)//if(startrow==endrow) break;
    startcol (endrow -1 .... startrow+1) // to avoid duplicate printing of elements apply a  condition if(startcol==endcol) break;
    startrow++;
    endcol--;
    endrow--;
    startcol++;
    while loop condition --> sc<=ec && startrow<=endrow
    return 0;
}