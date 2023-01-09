#include <string>
using namespace std;
template <typename V>
class MapNode
{
public:
	string key;
	V value;
	MapNode *next;
	MapNode(string key, V value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	}
	~MapNode()
	{
		delete next;
	}
};
template <typename V>
class ourmap
{
	MapNode<V> **buckets;
	int count;
	int numBuckets;
 public:
	ourmap()
	{
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V> *[numBuckets];
		for (int i = 0; i < numBuckets; i++)
		{
			buckets[i] = NULL;
		}
	}
	~ourmap()
	{
		for (int i = 0; i < numBuckets; i++)
		{
			delete buckets[i];
		}
		delete[] buckets;
	}
public:
// getLoadFactor -->
double getLoadFactor()
{
	return (1.0*count)/numBuckets;
}
	int size()
	{
		return count;
	}
	V getValue(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];
		while (head != NULL)
		{
			if (head->key == key)
			{
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}
 private:
	int getBucketIndex(string key)
	{
		int hashCode = 0;
		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--)
		{
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}
		return hashCode % numBuckets;
	}
	void rehash()
	{
		MapNode<V> **temp = buckets;
		buckets = new MapNode<V> *[2 * numBuckets];
		for (int i = 0; i < 2 * numBuckets; i++)
		{
			buckets[i] = NULL;
		}
		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0;
        // har ek linked list ke element ka naya bucketindex nikal kar, naye array ke andar dubara se distribute karna pade ga, tabhi code(searching,deletion etc) sahi se chale gi warna nahi chale gi.
		for (int i = 0; i < oldBucketCount; i++)
		{
			MapNode<V> *head = temp[i];
			while (head != NULL)
			{
				string key = head->key;
				V value = head->value;
				insert(key, value);
				head = head->next;
			}
		}
		for (int i = 0; i < oldBucketCount; i++)
		{
			MapNode<V> *head = temp[i];
			delete head;
		}
		delete[] temp;
	}
 public: 
 void insert(string key, V value)
 {
	int bucketIndex = getBucketIndex(key);
	MapNode<V> *head = buckets[bucketIndex]; // head, a pointer to bucket array element.. so now head will move to next of linked list elements for a particular bucket[bucketIndex]
	while (head != NULL)
	{
		if (head->key == key)
		{
			head->value = value;
			return;
		}
		head = head->next;
	}
	head = buckets[bucketIndex];
	MapNode<V> *node = new MapNode<V>(key, value);
	node->next = head;
	buckets[bucketIndex] = node;
	count++;
	// rehashing by calculating loadfactor
	double loadFactor = (1.0 * count) / numBuckets;
	if (loadFactor > 0.7)
	{
		rehash();
	}
}
V remove(string key)
{
	int bucketIndex = getBucketIndex(key);
	MapNode<V> *head = buckets[bucketIndex];
	MapNode<V> *prev = NULL;
	while (head != NULL)
	{
		if (head->key == key)
		{
			if (prev == NULL)
			{
				buckets[bucketIndex] = head->next; // if the first node of linked list has to be removed .. then buckets should be points to the next node (next to head)
			}
			else
			{
				prev->next = head->next; // prev pointing to node next to head node
			}
			V value = head->value;
			head->next = NULL; // node->next is initialed to NULL , becoz (if we call delete head) then all node next to head will get deleted becoz of recursive function in destructor of MapNode class
			delete head;
			count--;
			return value;
		}
		prev = head;
		head = head->next;
		// 110 and 111 telling that two pointers are moving side by side to next node
	}
	return 0;
}
};
