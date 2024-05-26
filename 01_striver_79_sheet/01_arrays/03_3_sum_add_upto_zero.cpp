#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> ans)
{
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> brute_force(vector<int> arr, int n)
{
    // TC - O(n^3 * (no. of unique triplets))
    // SC - O(1)
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>> better_approach(vector<int> arr, int n)
{
    // TC - O(n^2 * (no. of unique triplets))
    // SC - O(1)
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;

        for (int j = i + 1; j < n; j++)
        {
            int third = -arr[i] - arr[j];

            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>> optimal_approach(vector<int> arr, int n)
{
    // TC - O(n*log(n)) + O(n^2)
    // SC - O(1)
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i - 1] == arr[i])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans = brute_force(arr, arr.size());
    print(ans);
    ans = better_approach(arr, arr.size());
    print(ans);
    ans = optimal_approach(arr, arr.size());
    print(ans);
    return 0;
}