#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a.begin(), a.end());

    int count=0, prev=0-k;
    for(int i=0; i<n; i++){
        if(a[i]-prev>=k){
            count++;
            prev=a[i];
        }
    }

    cout<<count<<endl;

    return 0;
}