#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    for(int i = 0; i < q; i++) {
        int d;
        cin>>d;

        auto verdict = lower_bound(b.begin(), b.end(), d);
        //leftmost
        if (verdict == b.begin()){
            cout<<b[0]-1<<'\n';
        }
        // rightmost
        else if (verdict == b.end()){
            cout<<n-b[m-1]<<'\n';
        }
        //
        else {
            int left = *(verdict - 1);
            int right = *verdict;
            cout << (right - left) / 2 << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}