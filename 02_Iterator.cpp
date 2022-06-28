#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> kv;
    kv["abc"] = 121;
    kv["adx"] = 543;
    kv["swq"] = 65;
    kv["mmm"] = 3;
    kv["xyz"] = 1121;

    // iterator for unordered map;
    // unordered_map<string, int>::iterator it0 = kv.begin();

    unordered_map<string, int>::iterator it = kv.begin();

    while (it != kv.end())
    {
        cout << "Key " << (*it).first << " value " << it->second << endl;  // because it is a pointer
        it++;  
    }
    // cout<<endl;
    // unordered_map<string, int>::iterator it2 = kv.find("mmm");
    // kv.erase(it2);
    // while (it0 != kv.end())
    // {
    //     cout << "Key " << it0->first << " value " << it0->second << endl;
    //     it0++;
    // }





    // vector iterator

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    // iterator for vectors
    // vector<int> :: iterator it = v1.begin();
    // while(it!=v1.end())
    // {
    //     cout<<*it<<endl;
    //     it++;
    // }

    return 0;
}