 #include <bits/stdc++.h>
using namespace std;

const int MAX = 10000001;

int primeCount[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < MAX; i++)
    {
        if (primeCount[i] == 0)
        {
            for (int j = i; j < MAX; j += i)
            {
                primeCount[j]++;
            }
        }
    }

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        cout << (1 << primeCount[n]) << "\n";
    }

    return 0;
}