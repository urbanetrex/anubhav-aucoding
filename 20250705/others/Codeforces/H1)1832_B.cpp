#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define lint long long int

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++)cin>>a[i];

    sort(a.begin(), a.end());

    // calculate prefix sums
    vector<lint> pfx(n+1);
    pfx[0]=0;
    for(int i=1; i<=n; i++)pfx[i]=pfx[i-1]+a[i-1];

    lint maximum=0;
    for (int x = 0; x <= k; ++x) {
        lint left = pfx[n+x-k] - pfx[x+x];
        maximum = max(maximum, left);
    }
    
    cout<<maximum<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}