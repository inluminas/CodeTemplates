#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define randseed srand(chrono::steady_clock::now().time_since_epoch().count()); 

ll rand(ll a, ll b){
    return a + rand() % (b - a + 1LL);
}

int rand_int(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    n = rand_int(2, 10);

    cout << n << endl;

    vector<pair<int,int>> edges;

    for (int i = 2; i <= n; i++) {
        int parent = rand_int(1, i - 1);
        edges.push_back({parent, i});
    }

    shuffle(edges.begin(), edges.end(), rng);

    for (auto [u, v] : edges)
        cout << u << " " << v << "\n";

    return 0;
}
