#include<iostream>
#include<stack>

using namespace std;
int main()
{
    stack<string> s;

    s.push("love");
    s.push("babbar");
    s.push("Kumar");

    cout << "Top Element--> " << s.top() << endl;

    s.pop();
    cout << "Top Element--> " << s.top() << endl;

    cout << "Size Of Stack--> " << s.size() << endl;

    cout << "Empty Or not--> " << s.empty() << endl;


}