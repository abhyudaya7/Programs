#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2) {
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;
    return v1 > v2;
}

int main() {
    int n;
    cin >> n;
    int w; cin >> w;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), compare);

    int ans = 0;
    for (int i=0; i<n;i++){
        if (a[i].second <= w){
            ans += a[i].first;
            w -= a[i].second;
        }
        else {
            double vw = (double) a[i].first/ a[i].second;
            ans += vw * w;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}