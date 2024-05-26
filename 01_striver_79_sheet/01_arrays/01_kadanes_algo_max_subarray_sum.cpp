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
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            ans = max(ans, sum);
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
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            ans = max(ans, sum);
        }
    }

    return ans;
}

int optimal_approach(int arr[], int n)
{
    // TC - O(n)
    // SC - O(1)
    int ans = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        ans = max(ans, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return ans;
}

int follow_up_question(int arr[], int n)
{
    // TC - O(n)
    // SC - O(1)
    int ans = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > ans)
        {
            ans = sum;

            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;

            start = i + 1;
        }
    }

    cout << "Subarray Is: {";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "}" << endl;

    return ans;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << brute_force(arr, n) << endl;
    cout << better_approach(arr, n) << endl;
    cout << optimal_approach(arr, n) << endl;
    cout << follow_up_question(arr, n) << endl;
    return 0;
}