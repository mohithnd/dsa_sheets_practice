#include <iostream>
using namespace std;

int brute_force(int arr[], int n)
{
    // TC - O(n^3)
    // SC - O(1)
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prod = 1;

            for (int k = i; k <= j; k++)
            {
                prod = prod * arr[k];
            }

            ans = max(ans, prod);
        }
    }

    return ans;
}

int better_approach(int arr[], int n)
{
    // TC - O(n^2)
    // SC - O(1)
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int prod = 1;

        for (int j = i; j < n; j++)
        {
            prod = prod * arr[j];
            ans = max(ans, prod);
        }
    }

    return ans;
}

int optimal_approach_1(int arr[], int n)
{
    // TC - O(n)
    // SC - O(1)
    int ans = INT_MIN;

    int pre = 1;
    int suff = 1;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
        {
            pre = 1;
        }
        if (suff == 0)
        {
            suff = 1;
        }

        pre *= arr[i];
        suff *= arr[n - 1 - i];
        ans = max(ans, max(pre, suff));
    }

    return ans;
}

int optimal_approach_2(int arr[], int n)
{
    // TC - O(n)
    // SC - O(1)
    int ans = arr[0];
    int prod1 = arr[0];
    int prod2 = arr[0];

    for (int i = 1; i < n; i++)
    {
        int temp = max(arr[i], max(arr[i] * prod1, arr[i] * prod2));
        prod2 = min(arr[i], min(arr[i] * prod1, arr[i] * prod2));
        prod1 = temp;

        ans = max(ans, prod1);
    }

    return ans;
}

int main()
{
    int arr[] = {3, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << brute_force(arr, n) << endl;
    cout << better_approach(arr, n) << endl;
    cout << optimal_approach_1(arr, n) << endl;
    cout << optimal_approach_2(arr, n) << endl;
    return 0;
}