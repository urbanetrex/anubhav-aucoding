#include <iostream>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];

    int base=0;
    for (int i=0; i<n-1; i++) {
        base+=abs(a[i]-a[i+1]);
    }

    int max_change = 0;

    //middle ones
    for(int i=1; i<n-1; i++) {
        if ((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i+1] && a[i]<a[i-1])) {
            int diff=min(abs(a[i]-a[i-1]), abs(a[i]-a[i+1]));
            max_change = max(max_change, diff*2);
        }
    }
    //leftmost
    max_change = max(abs(a[0]-a[1]), max_change);
    //rightmost
    max_change = max(abs(a[n-2]-a[n-1]), max_change);

    cout<<base-max_change<<'\n';

    return 0;
}