#include <iostream>
using namespace std;

#include <queue>

int main()
{

    // PROVIDE ELEMENT IN DECREASING ORDER
    // MAX ELEMENT IS ON THE TOP;
    // POP FUNCTION REMOVES THE TOP ELEMENT (MAX) AND THEN ARRANGE THE REMANING ARRAY TO
    // AGAIN PUT MAX ELEMENT OF REMANING ARRAY IN THE TOP

    priority_queue<int> pq;

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