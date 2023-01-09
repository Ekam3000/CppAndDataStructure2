#include <string>
using namespace std;
// for creating close hashing a linked list class is formed
template <typename V>
class MapNode {
	public:
		string key;
		V value;
		MapNode* next;
		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}
		~MapNode() {
			delete next;
		}
};
template <typename V>
class ourmap {
	MapNode<V>** buckets; //MapNode<V>* is a pointer of MapNode class and (MapNode<V>** buckets) is an pointer storing the address of the pointer to MapNode
	int count;
	int numBuckets;
	public:
	ourmap() {
		count = 0;
		numBuckets = 5; // number of array elements
		buckets = new MapNode<V>*[numBuckets]; // now buckets is allocated a dynamic memory ..so it becomes an array useful for storing the addresses of the head node of the every linked lists linked to each array element
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL; // innitialising the array elements with the NULL addresses otherwise the garbage address are the their in every array element
		}
	}
	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i]; // deleting the individual linked list
		}
		delete [] buckets; // deleting the array as well
	}
	int size() {
		return count;
	}
	V getValue(string key) {
	}
	private:
	int getBucketIndex(string key) { // for generating hashcode 
		int hashCode = 0;
		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37; // 37 a prime number
			currentCoeff = currentCoeff % numBuckets; 
			// example "abc" a string 
			//hashcode = c*p^2 + b*p^1 + a*p^0  , p is a prime number 37
		}
		return hashCode % numBuckets; // a pure example of compression function
		// line 60 , 62, and 65 indicating that we are keeping things small , so that they dont go away out of the range of arraysize i.e numBuckets
	}
	public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex( key); // for generating hashcode 
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) { // if suppose "abc" ke corrosponding value 50 hai and ab hum usi "abc" ke corrosponding value 5 karna chahte hai ..then value update ho jaye gi
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex]; // head ko fir se buckets[bucketIndex] se index se initialise kar diya 
		MapNode<V>* node = new MapNode<V>(key, value); // a new node is created , before head node whose next is head
		node->next = head;
		buckets[bucketIndex] = node; //  buckets[bucketIndex] pointing to new node formed
		count++;  // counting the number of entries in the whole map
	}
};