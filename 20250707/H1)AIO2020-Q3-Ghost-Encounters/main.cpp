#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin>>n>>k;

    vector<int> existence (n);

    for(int i = 0; i < n; i++){
        int x, t;
        cin >> x >> t;
        existence[i] = t - x * k; // encounter if you leave existence[i] seconds after sunset.
    }

    sort(existence.begin(), existence.end()); // sort the array for further calculating.

    // once the next section is finished calculating,
    // this variable will store the leaving time after sunset to encounter the most ghosts.
    int max_existence_time = existence[0]; 
    {
        int max_existence = 1;
        int current_existence = 1, prev = existence[0];
        for(int i=1; i<n; i++){
            if (existence[i]==prev){
                current_existence++;
                if (current_existence > max_existence){
                    max_existence++;
                    max_existence_time = existence[i];
                }
            } else {
                current_existence = 1;
                prev = existence[i];
            }
        }
    }

    {
        int count=0;
        for (int i=0; i<n; i++) if (existence[i]==max_existence_time) count++; // count how many ghosts you can encounter
        cout<<count<<'\n';
    }
    
    return 0;
}

// Complexity O(N log N) solution