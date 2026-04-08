 #include <bits/stdc++.h>
using namespace std;

bool canTurnOff(string s, int n, int k, int l)
{
    int count = 0;

    for (int i = 0; i < n;)
    {
        if (s[i] == '1')
        {
            count++;
            i += l;
        }
        else
        {
            i++;
        }
    }

    return count <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n, ans = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}