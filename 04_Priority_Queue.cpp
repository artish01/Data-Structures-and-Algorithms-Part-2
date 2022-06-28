#include <iostream>
#include <vector>
using namespace std;

class Priorityqueue
{
public:
    vector<int> pq;

    Priorityqueue()
    {
    }

    bool isempty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isempty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size()-1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            { 
                break;
            }
            childIndex = parentIndex;
        }
    }

    int remove()
    {
        int ans = pq[0];   // remvoing root element by replacing the last element with root 
        pq[0] = pq[pq.size() - 1];

        pq.pop_back();

        int parentIndex = 0;
        int leftchildIndex = ((2 * parentIndex) + 1);
        int rightchildIndex = ((2 * parentIndex) + 2);

        while (leftchildIndex < pq.size())
        {
            int minIndex = parentIndex;

            if (pq[leftchildIndex] < pq[minIndex])
            {
                minIndex = leftchildIndex;
            }

            if (pq[rightchildIndex] < pq[minIndex] && rightchildIndex < pq.size())
            {
                minIndex = rightchildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;

            leftchildIndex = ((2 * parentIndex) + 1);
            rightchildIndex = ((2 * parentIndex) + 2);
        }

        return ans;
    }
};

int main()
{

    Priorityqueue pq;
    pq.insert(2);
    pq.insert(10);
    pq.insert(12);
    pq.insert(30);
    pq.insert(40);
    pq.insert(60);
    pq.insert(20);
   

    // cout << pq.getSize();
    // cout<<pq.getMin();

     while(!pq.isempty())
     {
        cout<<pq.remove()<<" ";
        
     }
    return 0;
}