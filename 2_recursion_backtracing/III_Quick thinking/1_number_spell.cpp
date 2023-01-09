//2048 -> two zero four eight 

#include<iostream>
using namespace std;
string spell[] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
void number_spell(int n)
{
    if(n==0)
    {
        return;
    }
    number_spell(n/10);
    int a= n%10;
    cout<< spell[a]<<" ";
}
int main()
{
   int n;
   cin>>n;
   number_spell(n);
   return 0;
}
