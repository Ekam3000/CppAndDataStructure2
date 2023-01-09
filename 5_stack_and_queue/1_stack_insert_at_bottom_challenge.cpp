#include<iostream>
#include<stack>
using namespace std;
/*void insertAtBottom(stack<int> &s,int key)
{
    
    stack<int> s1;
    while(s.size()>=1)
    {
       s1.push(s.top());
       s.pop();
    }
    s.push(key);
    while(s1.size()>=1)
    {
       s.push(s1.top());
       s1.pop();
    }
    while(!s.empty())
    {
       cout<<s.pop()<<endl;
    }
}
*/
//using recursion
void insertAtBottom(stack<int> &s,int key)
{
    if(s.empty()) 
    {
      s.push(key);
      return;
    }
    // rec case
    int temp = s.top();
    s.pop();
    insertAtBottom(s,key);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int k;
    cin>>k;
    insertAtBottom(s,k);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}