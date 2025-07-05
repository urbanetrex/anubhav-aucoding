#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define lint long long int

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++)cin>>a[i];

    sort(a.begin(), a.end());

    // calculate prefix sums
    vector<lint> pfx(n);
    pfx[0]=a[0];
    for(int i=1; i<n; i++)pfx[i]=pfx[i-1]+a[i];

    lint min_deleted=LLONG_MAX;
    for (int x = 0; x <= k; ++x) {
        int removed_small = 2 * x;
        int removed_large = k - x;
    
        if (removed_small + removed_large > n) continue;
    
        lint sum_small = (removed_small > 0) ? pfx[removed_small - 1] : 0;
    
        lint sum_large = pfx[n-1-removed_large] - pfx[n-1];



        /*
        for (int i = 0; i < removed_large; ++i)
            sum_large += a[n - 1 - i]; // sum from a[n-1] to a[n-1-removed_large-1]
        */

        lint total_deleted = sum_small + sum_large;
        min_deleted = min(min_deleted, total_deleted);
    }
    
    cout<<pfx[n-1]-min_deleted<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}