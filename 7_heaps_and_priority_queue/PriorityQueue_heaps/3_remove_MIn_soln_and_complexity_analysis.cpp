#include <iostream>
using namespace std;
#include <vector>
class PriorityQueue {
	vector<int> pq;

	public :

	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}
	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}
	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}
	void insert(int element) {
		pq.push_back(element);
		int childIndex = pq.size() - 1;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;
			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}
	int removeMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back(); // removing thew last element from the vector
		// down-heapify
		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) { //  as leftChildIndex and rightChildIndex are updated time to time so condition becomes whether leftChildIndex goes out of vector size or not (ofcourse if leftChildIndex > pq.size(), then  rightChildIndex will also be greater then pq.size()  )
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) { // maybe   leftChildIndex is the last index of the  pq.size() so a seperate condition has also to be checked for rightChild
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;
	}

};

int main() {
	PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout << p.getSize() << endl;
	cout << p.getMin() << endl;

	while(!p.isEmpty()) {
		cout << p.removeMin() << " " ;

	}
	cout << endl;
}

