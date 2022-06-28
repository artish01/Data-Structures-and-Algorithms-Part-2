#include <iostream>
#include <queue>
using namespace std;

int main()
{
// ELEMENTS ARE IN INCREASING ORDER 
// POP WILL REMOVE THE MINIMUM ELEMENT(TOP ELEMENT)

    priority_queue < int, vector<int>, greater<int>> pq;

    pq.push(2);
    pq.push(55);
    pq.push(3);
    pq.push(12);
    pq.push(23);

    cout << pq.size() << endl;
    cout << pq.top() << endl;

    pq.pop();
    cout << endl;
    cout << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}