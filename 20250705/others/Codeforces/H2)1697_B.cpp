#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // input
    int n, q;
    cin>>n>>q;
    vector<long long int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    sort(a.begin(), a.end()); // sort the array

    // prefix sums
    vector<long long int> pfx(n+1);
    pfx[0]=0;
    for(int i=1; i<=n; i++)pfx[i]=pfx[i-1]+a[i-1];

    // queries
    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        cout<<(pfx[n-x+y]-pfx[n-x])<<'\n';
    }

    return 0;
}