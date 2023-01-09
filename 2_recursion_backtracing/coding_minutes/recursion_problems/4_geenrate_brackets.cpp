#include<bits/stdc++.h>
using namespace std;
void generateBrackets(string output , int n , int open , int close, int i)
{
    // base case
    if(i==2*n)
    {
        cout<<output<<endl;
        return ;
    }
    // open 
    if(open< n)
    {
        // never do like this line below and send 'output' to generateBrackets
      //  output += '('; 
      // do like this 
        generateBrackets(output +'(', n, open, close, i+1);
    

       // if u want to do like output += '(' way then do like this-->
     /*  output += '('; 
       generateBrackets(output, n, open, close, i+1);
       output.pop_back();
       */
    }
    // closing
    if(close<open)
    {
        //never do like this
        //output += ')';
        generateBrackets(output +')', n,open, close+1, i+1);
       // if u want to do like output += '(' way then do like this-->
       /*  output += ')';
         generateBrackets(output, n,open, close+1, i+1);
          output.pop_back();
          */
    }
}
int main(){
    string output;
    int n;
    cin>>n;
    generateBrackets(output, n,0,0,0);
}