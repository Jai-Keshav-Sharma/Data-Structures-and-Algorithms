#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);

    cout << "front of the queue is : " << q.front() << endl;

    q.push(30);

    cout << "front of the queue is : " << q.front() << endl;

    cout << "size of queue is: " << q.size() << endl;

    q.pop();

    cout << "size of queue is: " << q.size() << endl;

    q.pop();

    cout << "front of the queue is: " << q.front() << endl;
    q.pop();

    cout << "size of queue is: " << q.size() << endl;

    if (q.empty())
        cout << "queue is empty !" << endl;

    return 0;
}