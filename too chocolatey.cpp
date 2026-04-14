#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;


    while (t--)
     {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

   
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }

      
        
        vector<int> v;
        for (auto it : freq) {
            int value = it.first;
            int count = it.second;

            int times = min(2, count);
            for (int i = 0; i < times; i++) {
                v.push_back(value);
            }
        }

  
        sort(v.begin(), v.end(), greater<int>());

        long long alex = 0, bob = 0;

  
        for (int i = 0; i < v.size(); i++) {
            if (i % 2 == 0)
                alex += v[i];
            else
                bob += v[i];
        }

      
        if (alex > bob)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    
    return 0;
}