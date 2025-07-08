#include <iostream>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    vector<int> monks(n);
    for(int i = 0; i < n; i++) cin >> monks[i];
    sort(monks.begin(), monks.end());
    int s; cin>>s;
    vector<int> sjobs(s);
    for(int i = 0; i < s; i++) cin >> sjobs[i];
    sort(sjobs.begin(), sjobs.end());
    int m; cin>>m;
    vector<int> mjobs(m);
    for(int i = 0; i < m; i++) cin >> mjobs[i];
    sort(mjobs.begin(), mjobs.end());

    

    return 0;
}