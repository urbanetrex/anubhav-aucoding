#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll count_balls(ll rounds, const vector<int>& A) {
    ll total = 0;
    for (int a : A) {
        total += min((ll)a, rounds);
    }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int B;
    ll N;
    cin >> B >> N;

    vector<int> A(B);
    for (int i = 0; i < B; ++i) {
        cin >> A[i];
    }

    // Binary search for number of full rounds
    ll low = 0, high = 1e9, rounds = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (count_balls(mid, A) < N) {
            rounds = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    ll used = count_balls(rounds, A);
    ll remaining = N - used;

    for (int i = 0; i < B; ++i) {
        if (A[i] > rounds) {
            remaining--;
            if (remaining == 0) {
                cout << (i + 1) << '\n';  // 1-based index
                return 0;
            }
        }
    }

    return 0;
}
