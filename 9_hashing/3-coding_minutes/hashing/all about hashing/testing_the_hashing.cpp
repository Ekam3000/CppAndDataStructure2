#include<iostream>
#include"hashing_code.h"
using namespace std;

int main()
{
    Hashtable<int> h;
    h.insert("Mango",100);
    h.insert("Apple",120);
    h.insert("Banana",140);
    h.insert("Orange",200);
   // by default we have set the  default size as 7 
   // if se insert more items then size of hashtable will automatically increase
   h.insert("Kiwi",180);
   h.insert("Papaye",170);
   h.insert("Guava",160);

   h.print();
   string fruit;
   cin>>fruit;
   int *price =h.search(fruit);
   if(price != NULL)
   {
    cout<<"Price of fruit is "<<*price<<endl;
   }
   else{
    cout<<"Fruit is not present";
   }
   // supercool functionality
   h["newFruit"]=200;
   cout<<"New fruit cost : "<<h["newfruit"]<<endl;
   h["newFruit"] +=20;
   cout<<"New fruit updated cost : "<<h["newfruit"]<<endl;
   return 0;

}
