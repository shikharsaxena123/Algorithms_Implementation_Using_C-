#include<bits/stdc++.h>

using namespace std;

int binary_search(int array[], int l, int h, int k)

{
    if(h>=1)
    {
        int mid = l + (h-l)/2; 
        
        if(array[mid] == k)
        {
            return mid;
        }
        if(array[mid] > k)
        {
            return binary_search(array, l, mid-1, k);
        }
        else
        {
            return binary_search(array, mid+1, h, k);
        }
    }

    return -1;
}


int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40};
    int k = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, 0, n - 1, k);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
