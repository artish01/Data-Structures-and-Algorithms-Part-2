#include <iostream>
#include <queue>
using namespace std;

//DFS

void print(int **arr, int n, int sv, bool *visited)
{
    cout << sv<<" "<<endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (arr[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(arr, n, i, visited);
        }
    }
}

//BFS

void DFS(int **arr,int n,int sv )
{
    queue<int> pendingvertex;
    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }

    pendingvertex.push(sv);
    visited[sv] = true;

    while(!pendingvertex.empty())
    {
        int currentvertex = pendingvertex.front();
        pendingvertex.pop();

        cout<<currentvertex<<" ";

        for(int i=0; i<n; i++)
        {
            if(i==currentvertex)
            {
                continue;
            }

            if(arr[currentvertex][i]==1 && !visited[i])
            {
                pendingvertex.push(i);
                visited[i] = true;

            }
        }
    }
}



int main()
{

    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }

    print(edges, n,0,visited);
    DFS(edges,n,0);

    return 0;
}