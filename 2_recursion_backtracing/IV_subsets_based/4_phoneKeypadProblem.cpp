#include<iostream>
using namespace std;
// u can use vector or 2-D array as both are same.
char keypad[][10] ={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void Print_string(char *arr,char *output ,int i,int j)
{
    if(arr[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    // rec case 
    int digit =arr[i]-'0';
    // to iterate over particular 2-D char element (which is string here) corrosponding to keypad char arr.
    for(int k=0;keypad[digit][k] != '\0';k++)
    {
    output[j]=keypad[digit][k];
    Print_string(arr,output ,i+1,j+1);
    }
    return;
}
int main()
{
char arr[]="23";
    int i=0;
    int j=0;
    char output[10];
    Print_string(arr,output,i,j);
}
/*
AD
AE
AF
BD
BE
BF
CD
CE
CF*/