#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int main() {
	unordered_map<string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;
	unordered_map<string, int>::iterator it = ourmap.begin(); // 	unordered_map<string, int>::iterator is data type and 'it' is the name of iterator. 'it' is the name of the pointer
	while (it != ourmap.end()) {
		cout << "Key : " << it->first << " Value: " << it->second << endl;
		it++;
	}
	// find function gives us an iterator so stored by an iterator it2  .. so once it2 pointer points to a value then hum "abc" ke baad walle elements ko bhi print kar sakte
	unordered_map<string, int>::iterator it2 = ourmap.find("abc");
	cout << "Key it2: " << it2->first << " Value it2: " << it2->second << endl;
	while (it2 != ourmap.end()) {
		cout << "Key of it2: " << it2->first << " Value of it2: " << it2->second << endl;
		it2++;
	}
	// erasing one element
	ourmap.erase(it2);
	// erasing consicutively more then 1 element
	//ourmap.erase(it2, it2 + 4); // will erase 4 elements starting from where "it" pointer is pointing and the next three elements .. it2 , it2 + 1, it2 + 2, it2 + 3.
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end()) {
		cout << *it1 << endl;
		it1++;
	}

}

