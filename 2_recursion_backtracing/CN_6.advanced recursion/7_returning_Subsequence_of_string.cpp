
#include <iostream>
using namespace std;

int subs(string input, string output[]) {
	if (input.empty()) { //input.empty() represent empty string
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;
	//string output[1000];
	//OR dynamically bhi bna sakte hai
	string* output = new string[1000]; // strings ka array bna diya .
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}
