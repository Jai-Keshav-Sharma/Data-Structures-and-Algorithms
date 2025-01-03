#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "top: " << s.top() << endl;
    s.pop();
    cout << "Top after popping -> " << endl;
    cout << s.top() << endl;
    cout << "size after popping" << s.size() << endl;
    s.pop();
    s.pop();
    cout << "popped two times.." << endl;
    cout << "is empty ? ";
    cout << s.empty() << endl;
    cout << "size now -";
    cout << s.size() << endl;

    return 0;
}