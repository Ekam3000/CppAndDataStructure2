/*Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include<iostream>
using namespace std;
int NoOfStrings(string *output,int n){
if( n==0 ||n==1){
    output[0]="";
    return 1;   
}

    int rem=n%10;
    n=n/10;
	int smallOutputSize = NoOfStrings(output,n);
   int  count;
   if(rem==7 ||rem==9){
       count=4;
   }
   else{
        count=3;
   }
    char c;
     if(rem==9){
        c = 98 + 3*(rem-2);
     }
     else{
         c= 97 +3*(rem-2);
     }
     for(int i=0;i<count-1;i++){
         for(int j=0;j<smallOutputSize;j++){
             output[j +(i+1)*smallOutputSize]=output[j];
         }
     }
     int k=0;
    for(int j=0; j<count;j++){
	for (int i = 0; i < smallOutputSize; i++) {
		output[k]= output[k] +c ;
        k++;
    }
    c++;
    }
     return smallOutputSize*count;

}
int main(){
    int n;
    cin>>n;
    string output[100];
    int count=NoOfStrings(output,n);
    for(int i=0;i<count;i++){
       cout<<output[i]<<endl;
    }

/*
#include<iostream>
using namespace std;
 string getString(int d){
     if(d==2){
         return "abc";
     }
     if(d==3){
         return "def";
     }
     if(d==4){
         return "ghi";
     }
     if(d==5){
         return "jkl";
     }
     if(d==6){
         return "mno";
     }
     if(d==7){
         return "pqrs";
     }
     if(d==8){
         return "tuv";
     }
     if(d==9){
         return "wxyz";
     }
     else
         return " ";
     
 }
 int keypad(int n, string *output){
     if(n==0||n==1){
         output[0]="";
         return 1;
     }
     int lastDigit =n%10;
     int remainingNumber=n/10;
     int smallOutputSize= keypad(n, output);
     string options =getString(lastDigit);
     
   for(int i=0;i<options.length()-1;i++){
       for(int j=0;j<smallOutputSize;j++){
           output[j +(i+1)*smallOutputSize]=output[i];
       }
   }
   int k=0;
    for(int i=0;i<options.length();i++){
       for(int j=0;j<smallOutputSize;j++){
           output[k]=output[k]+options[i];
           k++;
       }
   }
   return smallOutputSize*options.length();
 }
 
int main(){
    int n;
    cin>>n;
    string output[100];
    int count=keypad(n,output);
    for(int i=0;i<count;i++){
       cout<<output[i]<<endl;
    }
}
*/