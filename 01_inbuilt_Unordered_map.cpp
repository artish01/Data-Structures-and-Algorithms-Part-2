#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main()
{
    // unordered_map<string,int> our_map;
    unordered_map<int,int> our_map;
    our_map[-1] = 7;
    cout<<our_map.at(-1);
//     our_map["adc"] = 12;
//     our_map["dbc"] = 31;

//     cout<<our_map.at("abc")<<endl;
//     cout<<our_map.at("adc")<<endl;
//   //  cout<<our_map.at("adk")<<endl;  
//     cout<<our_map.at("hhhhj")<<endl;  // throw error but square bracket will not give an error if key is not found


//     // checks size
//     cout<<our_map.size()<<endl;


//     // check presence
//     if(our_map.count("aq")>0)
//     {
//         cout<<"abc is present "<<endl;
//     }

//     // delete element

//     our_map.erase("adk");
//     cout<<our_map.size();

    
// // if we try to find a key which is not avilable then at will throw error
// //but [] will give it default value of 0 and create it 


    




    return 0;
}