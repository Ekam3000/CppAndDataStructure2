#include <iostream>
using namespace std;
#include <queue>

	
int main() {
	priority_queue<int, vector<int>, greater<int> > p; // vector<int> sayinf that we are initialising a veator for cr3ating heap ,greater<int>  saying that when a > b(parent>child) then swap out the two elements.. inbuilt a<b works(parent<child) which we have seen in Inbuilt_Max_priority_queue

	p.push(100);
	p.push(21);
	p.push(7);
	p.push(165);
	p.push(78);
	p.push(4);

	cout << p.size() << endl;
	cout << p.empty() << endl;
	cout << p.top() << endl;

	while(!p.empty()) {
		cout << p.top() << endl;
		p.pop();
	}
}