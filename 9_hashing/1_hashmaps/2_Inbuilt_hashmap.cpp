#include <iostream>
//#include<map> // impliment the map using BST . almost every inbuilt function will take log(n) time. elements to be inserted in sorted order . so its a ordered map
#include <unordered_map> // using HashTable. time complexity here is O(n). elements can be inserted in unordered manner
#include <string>
using namespace std;

int main() {
	unordered_map<string,int> ourmap; //unordered_map is an template .. so its ur choice of adjuating key and value. ourmap is an object
	// insert
	pair<string, int> p("abc", 1); // class pair.. using constructor of pair class we initialise values
	ourmap.insert(p); // internally insert of unordered_map stores the value and  key in a pair
	ourmap["def"] = 2; // other way of inserting , just like array element initialization
	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl; // at function of unordered_map
	//cout << ourmap.at("ghi") << endl; -->// will give key not found
	cout << "size : " << ourmap.size() << endl; // size function of unordered_map
	cout << ourmap["ghi"] << endl; // if the value does not exist at given key then this will give a default value .. but at function accurate result batae ga(if only the value is their at given key then output will be shown otherwise will say 'key not found')
	cout << "size : " << ourmap.size() << endl;
	// check Presense
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl; // count function will tell us ek key kitne baar aati hai .. will check the presence of the key.. now "ghi" is present bcoz we tried to access "ghi" at line number 18.. so will print "ghi is present"
	}
	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}
}
