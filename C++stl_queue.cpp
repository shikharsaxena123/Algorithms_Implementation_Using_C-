#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<string> q;
    
    q.push("Love");
    q.push("Babbar");
    q.push("Kumar");

    cout << "Size Before Pop: " << q.size() << endl;
    
    cout << "First Element " << q.front() << endl;
    q.pop();
    
    cout << "First Element " << q.front() << endl;

    cout << "Size After Pop: " << q.size() << endl;
}