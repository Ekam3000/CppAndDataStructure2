#include<iostream>
#include<stack>
using namespace std;
// the span of the highest stock is considered as 1.
// we have to calculate the previous highest price .. w.r.t current price that will give me the span.
// also if s.top() is smaller then the current value which is ready for going into the stack .. then pop the s.top() element bcoz it is of no use. continuously compare the curr value with s.top() value until u get s.top() value higher then the current value
// if stack becomes empty , then span will become index + curr day.
void stock_span_problem(int *prices, int n, int * span )
{
 stack<int> s;
 s.push(0);
 span[0]=1;
 for(int i=1;i<=(n-1);i++)
 {
    int currentPrice=prices[i];
    while(currentPrice>= prices[s.top()] && !s.empty())
    {
        s.pop();
    }
    // span of i
    if(!s.empty())
    {
    int prev_highest = s.top();
    span[i]=i-prev_highest;
    }
    else
    {
        span[i]=1+i; // i is the number of days.
    }
    s.push(i);
 }
}
int main()
{
    int prices[]={100,80,60,70,60,75,85};
    int n=sizeof(prices)/sizeof(prices[0]);
    int span[n]={0};
    stock_span_problem(prices,n,span);
    for(int i=0;i<n;i++)
    {
        cout<<span[i]<<" ";
    }
    return 0;
}