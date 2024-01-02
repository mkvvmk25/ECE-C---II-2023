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
    int fs;
    cin >> fs;

    for(int i= 0; i <= n-fs; i++)
    {
        int max = arr[i];// arr[0] 
        for(int j = i+1; j <= i+(fs-1); j++ )
        {
            if(max < arr[j])
            {
                max = arr[j];
            }
        }

        // print the max 
        cout << max << " ";

    }
}