#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.get();
    char sentence[100];
    char largest_string[100];
    int largest_len =0;
    while(n--)
    {
        cin.getline(sentence,1000);
        if(largest_len<strlen(sentence))
        {
            largest_len=strlen(sentence);
            strcpy(largest_string,sentence);
        }

    }
    cout<<"largest_len "<<largest_len<<"and"<<"largest_string "<<largest_string<<endl;
    return 0;
}