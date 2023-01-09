// 10 -> P pratas
//  4 1 2 3 4 -> L number of cooks with their rank 4 cooks with their ranks
//  we have to calculate the minimum time to make 10 pratas
#include <iostream>
using namespace std;
// starting point=0;
// ending_point= 1+2+3+4+5+6+7+8+9+10/2; // 55
bool minimum_time(int *ranks,int mid,int No_Cooks, int P)
{
    int count=0;
    int x=0;
    for(int i=0;i<No_Cooks;i++)
    {
            while(ranks[i]*x*(x+1)<=mid)
            {
                x++;
            }
               
                count +=x;
                x=0;
    }
    if(count>=P)
    {
    return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int P;
    cin >> P;
    int No_Cooks;
    cin >> No_Cooks;
    int ranks[No_Cooks];
    for (int i = 0; i < No_Cooks; i++)
    {
        cin >> ranks[i];
    }
    int s = 0;
    int e = 100; // humne mann kar chal liya actual time will be 100 vaise 55 hai
    int time = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (minimum_time(ranks, mid, No_Cooks, P))
        {
            time = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << "Time" << time << endl;
    return 0;
}


// galt ans
// mera ans sahi nahi aa raha 
/*
10
4
1 2 3 4
*/