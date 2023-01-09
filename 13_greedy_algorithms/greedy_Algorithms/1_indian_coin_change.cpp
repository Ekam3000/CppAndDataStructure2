#include <iostream>
#include <algorithm>
using namespace std;
// tht whole idea is about using comparators with binary search.
bool compare(int a, int b)
{
    return a <= b; // a is the given array value and b is the current money avalable (the key value).. current word is used bcoz the value of money is changing..
    // inbuilt me jaise hi condition false hui ..vaise hi vo vali index ki value return ho jaye gi.
}
int main()
{
    // minimum number of coins required to make a change of 168 rupee
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int money = 168;
    int a;
    int n = sizeof(coins) / sizeof(int);
    while (money > 0)
    {
        // in lower_bound function consecutive array values starting from index 0 are compared with given key value.
        // our aim is to find that particular coin which is near to the current money.
        auto lb = lower_bound(coins, coins + n, money, compare); 
        a = lb - coins -1;
        cout << a << " value " << coins[a]<<" ";
        money = money - coins[a];
    }
    // this result will give us 200 without -1 from the a,and 100 if -1 is subtracted from a..which maybe right for this case if money is equal to 168. but if the money is 100 given then we will get 50 ..but ans me 100 show hona chahiye tha ..to hum fass gye.
    // so iss liye humne compare function use kiya alag se.
    // isme kya hoga agr given money 100 hogi then compare function 200 indexed value return kare ga , and after -1 we will get 100 as nearest value to 120.
    // 100 amount ki money par 50 nahi mile ga (a)index ki value se , 100 hi mile ga
}