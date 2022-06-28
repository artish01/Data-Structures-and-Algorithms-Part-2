#include <iostream>
using namespace std;

void inplace(int pq[], int n)
{
    for (int i = 1; i < n; i++)
    {

        int childIndex = i;

        while (childIndex > 0)  // in order to ensure that if it reachees the top of tree
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

    // remove element we need size czz we have to decrease it every time after removal of element

    int size = n;

    while (size > 1)

    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int leftchildIndex = ((2 * parentIndex) + 1);
        int rightchildIndex = ((2 * parentIndex) + 2);

        while (leftchildIndex < size) // if it is less than size it means it is in the limit
        {
            int minIndex = parentIndex;

            if (pq[leftchildIndex] < pq[minIndex])
            {
                minIndex = leftchildIndex;
            }

            if (pq[rightchildIndex] < pq[minIndex] && rightchildIndex < size)
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

            parentIndex = minIndex;  // min index let us us know to which value we have swapped the element so that we can update our

            leftchildIndex = ((2 * parentIndex) + 1);
            rightchildIndex = ((2 * parentIndex) + 2);
        }
    }
}
int main()
{

    int arr[] = {3,2,55,1,6,7};
    inplace(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}