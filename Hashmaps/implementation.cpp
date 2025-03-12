#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> mpp;

    // insertion (1)
    pair<string, int> p = make_pair("one", 1);
    mpp.insert(p);

    // (2)
    pair<string, int> p2("two", 2);
    mpp.insert(p2);

    // (3)
    mpp["three"] = 3;

    // accessing
    cout << mpp["three"] << endl;

    //overwriting 
    mpp["three"] = 4;
    cout << mpp["three"] << endl;

    // searching
    cout << mpp.at("two") << endl; 

    // searching an undefined key
    // cout << mpp.at("five") << endl; // shows error
    cout << mpp["five"] << endl; //creates a key with value 0 by default


    // size
    cout << mpp.size() << endl;

    // checking presence of a paritcular key using count()
    cout << mpp.count("two") << endl;   // 1 if present
    cout << mpp.count("six") << endl;   // 0 if absent


    // erase()
    mpp.erase("three");
    cout << mpp.size() << endl;

    // iterator
    for(auto i : mpp) {
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}