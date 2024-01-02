#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i ++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;


    int i;
    int j; 
    i = 0;
    j = k-1;

    while( i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    
}


/*
if(n % 2 == 0)
    {
        n = n;
    }
    else 
    {
        n = n - 1;
    }

    for(int i = 0; i < n; i = i + 2)
    {
        if(arr[i] > arr[i+1])
        {
            // 5 4 3 2
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    for(int i = 0; i < d; i++)
    {
        cout << arr[i] <<" ";
    }
*/