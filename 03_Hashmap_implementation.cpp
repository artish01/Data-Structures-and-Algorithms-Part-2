#include <iostream>
using namespace std;
// #include <Template>
#include <string>

template <typename V>
class mapNode
{
public:
    string key;
    V value;
    mapNode<V> *next;
    mapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapNode()
    {
        delete next;
    }
};

template <typename V>
class our_map
{
    mapNode<V> **buckets; // array of buckets associated with class not to fucntions
    int count;
    int numBuckets;

public:
    our_map()
    {
        count = 0;
        numBuckets = 5;
        buckets = new mapNode<V> *[numBuckets]; // creating  a array where every ith position denotes a LL
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~our_map()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // delete each LL at every  ith position of the array
        }
        delete[] buckets;  //deleting whole array now
    }

    int size()
    {
        return count;
    }

    void rehash()
    {
        
        mapNode<V> **temp = buckets;     // ** is because it stores array of double pointer
        buckets = new mapNode<V>*[2 * numBuckets]; 

        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketcount = numBuckets;
        numBuckets = 2 * numBuckets;
        count = 0;
        for (int i = 0; i < oldBucketcount; i++)
        {
            mapNode<V> *head = buckets[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        // To delete previous old array
        for (int i = 0; i < oldBucketcount; i++)
        {
            mapNode<V> *head = temp[i];
            delete head;
        }
        delete temp;
    }

private:
    int getbucketindex(string key)
    {
        int hashcode = 0;
        int currcofficient = 1;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currcofficient;
            hashcode %= numBuckets;
            currcofficient *= 37;
            currcofficient %= numBuckets;
        }

        return hashcode % numBuckets;
    }

public:
    void insert(string key, V value)
    {
        int bucketindex = getbucketindex(key);
        mapNode<V> *head = buckets[bucketindex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        mapNode<V> *node = new mapNode<V>(key, value);
        node->next = head;
        buckets[bucketindex] = node; // bucket index will point to LL head;
        count++;

        // LOAD FACTOR

        double load_factor = (1.0 * count) / numBuckets;
        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketindex = getbucketindex(key);
        mapNode<V> *head = buckets[bucketindex];
        mapNode<V> *previous = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (previous == NULL)
                {
                    buckets[bucketindex] = head->next;
                }
                else
                {
                    previous->next = head->next;
                }
                V value = head->value;
                head->next = NULL; // bcz delete is a recurssive call and if next is filled with address it will delete whole LL
                delete head;
                return value;
            }
            previous = head;
            head = head->next;
        }
        return 0;
    }

    V getvalue(string key)
    {
        int bucketindex = getbucketindex(key);
        mapNode<V> *head = buckets[bucketindex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
        }
        return 0;
    }
};

int main()
{
    our_map<int> o1;
    o1.insert("abc", 12);
    o1.insert("sds", 2);
    o1.insert("aaa", 122);
   
   
}
