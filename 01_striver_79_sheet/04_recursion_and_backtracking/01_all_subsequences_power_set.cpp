#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string &str, int i, string s, vector<string> &ans)
{
    if (i >= str.length())
    {
        ans.push_back(s);
        return;
    }
    solve(str, i + 1, s, ans);
    s.push_back(str[i]);
    solve(str, i + 1, s, ans);
}

void using_recursion()
{
    // TC - O(2^N)
    // SC - O(N)
    string str = "abc";
    vector<string> ans;
    solve(str, 0, "", ans);
    sort(ans.begin(), ans.end());
    for (string s : ans)
    {
        cout << s << " ";
    }
}

int main()
{
    using_recursion();
    return 0;
}