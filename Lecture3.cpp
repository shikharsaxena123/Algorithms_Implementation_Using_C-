#include<iostream>
using namespace std;

int main()
{
    // int a;
    // cin >> a;
    // cout << "The value of n is : " << n << endl;

    // if a is positive
    // if(a>0)
    // {
    //     cout << "A is positive" << endl;
    // }

    // else
    // {
    //     cout << "A is Negative" << endl;
    // }

//    int a , b;
//    cin >> a >> b;
//    cout << "Value of a and b is: " << a << " " << b << endl;
    // cout << "Enter the value of a: " << endl;
    // cin >> a;
    // cout << "Enter the value of b: " << endl;
    // cin >> b; 

    // if(a>b)
    // {
    //     cout << "A is Greater" << endl;
    // }

    // else if(b>a)
    // {
    //     cout << "B is Greater" << endl;
    // }

    // else
    // {
    //     cout << "Both a & b are equal" << endl;
    // }

    // if(a>0)
    // {
    //     cout << "A is positive" << endl;
    // }

    // else if(a<0)
    // {
    //     cout << "A is negative" << endl; 
    // }

    // else
    // {
    //     cout << "A is equal to Zero" << endl;
    // }

    char ch;
    cin >> ch;

    if(ch >= 97 && ch <= 122)
    {
        cout << "This is Lowercase" << endl;
    }

    else if(ch >= 65 && ch <= 90)
    {
        cout << "This is Uppercase" << endl;
    }

    else if(ch >= 48 && ch<= 57)
    {
        cout << "This is Numeric" << endl;
    }

    else
    {
        return 0;
    }


}