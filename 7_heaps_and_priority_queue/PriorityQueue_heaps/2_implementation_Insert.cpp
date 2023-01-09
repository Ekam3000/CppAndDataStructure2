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

		while(childIndex > 0) { // comparison can be done max upto root node ... so childindex > 0 is the condition for thr root index
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

};
   /*
      10
	/    \
   20    100
  /  \  /
 40  50 150  
 ---> inserting zero
      10
	/    \
   20    100
  /  \  /  \
 40  50 150 0 
 */