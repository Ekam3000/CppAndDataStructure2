//generate Balanced Brackets using N pairs of Round brackets.
// max opening brackets we can put is N. so open <N
// to put a closing bracket we have condition number of closing brackets <number of open brackets(close<open)

#include<iostream>
using namespace std;
void generate_brackets(int N, char * s,int open,int close,int i)
{
    if(i==2*N)
    {
     s[i]='\0';
     cout<<s<<endl;
     return;
    }
    // can i put an open bracket.
    if(open<N)
    {
        s[i]='(';
        generate_brackets(N,s,open+1,close,i+1);
    }
    if(close<open)
    {
        s[i]=')';
         generate_brackets(N,s,open,close+1,i+1);
    }
return;
}
int main()
{
    int N;
    cin>>N; // number of pairs 
    char array_of_brackets[100];
    int idx=0;// current index
    generate_brackets(N,array_of_brackets,0,0,idx); 
    // 0, 0 the number of opening and closing brackets in ouput array(array_of_brackets) 
    // idx -> the current number of brackets in the output array 
}
/*
3
((()))
(()())
(())()
()(())
()()()*/