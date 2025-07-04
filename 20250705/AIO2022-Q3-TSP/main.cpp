#include <iostream>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    int l[n], r[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    for(int i=0;i<n;i++){
        cin>>r[i];
    }

    int current = l[0];
    for(int i=1; i<n; i++){
        if (r[i]<current) {
            cout<<"NO\n";
            return 0;
        }
        current = max(current, l[i]);
    }
    cout<<"YES\n";

    return 0;
}