#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(vector<int> ans)
{
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> brute_force(vector<int> arr, int n)
{
    // TC - O(n^2)
    // SC - O(1)
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0 || ans[0] != arr[i])
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }

            if (cnt > (n / 3))
            {
                ans.push_back(arr[i]);
            }
        }

        if (ans.size() == 2)
        {
            break;
        }
    }

    return ans;
}

vector<int> better_approach(vector<int> arr, int n)
{
    // TC - O(n * log(n))
    // SC - O(n)
    vector<int> ans;

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;

        if (m[arr[i]] == ((n / 3) + 1))
        {
            ans.push_back(arr[i]);
        }

        if (ans.size() == 2)
        {
            break;
        }
    }

    return ans;
}

vector<int> optimal_approach(vector<int> arr, int n)
{
    // TC - O(2n)
    // SC - O(1)
    vector<int> ans;

    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && arr[i] != ele2)
        {
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != ele1)
        {
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1)
        {
            cnt1++;
        }
        else if (arr[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            cnt1++;
        }
        else if (arr[i] == ele2)
        {
            cnt2++;
        }
    }

    if (cnt1 > (n / 3))
    {
        ans.push_back(ele1);
    }
    if (cnt2 > (n / 3))
    {
        ans.push_back(ele2);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2};
    vector<int> ans;
    ans = brute_force(arr, arr.size());
    print(ans);
    ans = better_approach(arr, arr.size());
    print(ans);
    ans = optimal_approach(arr, arr.size());
    print(ans);
    return 0;
}