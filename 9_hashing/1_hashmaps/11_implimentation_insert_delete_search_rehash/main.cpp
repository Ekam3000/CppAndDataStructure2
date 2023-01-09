#include <iostream>
#include "ourmap.h"
using namespace std;
int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i; // character '0' to character '9'
        string key = "abc";
        key = key + c;          // abc0, abc1,abc2,abc3,abc4,abc4...
        int value = i + 1;      // value 1, 2 ,3 4, 5, 6,....
        map.insert(key, value); // inersion
        cout << map.getLoadFactor() << endl;
    }
    map.remove("abc2");
    map.remove("abc7");
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i; // character '0' to character '9'
        string key = "abc";
        key = key + c;
        cout << key << ":" << map.getValue(key) << endl;
    }
    cout << map.size() << endl;
}