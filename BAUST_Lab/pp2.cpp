#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> applicant(n), apartment(m);

    for (int i = 0; i < n; i++) cin >> applicant[i];
    for (int i = 0; i < m; i++) cin >> apartment[i];

    sort(applicant.begin(), applicant.end());
    sort(apartment.begin(), apartment.end());

    int i = 0, j = 0, ans = 0;

    while (i < n && j < m) {
        if (apartment[j] < applicant[i] - k) {
            j++;   // apartment too small
        }
        else if (apartment[j] > applicant[i] + k) {
            i++;   // apartment too large
        }
        else {
            ans++; // matched
            i++;
            j++;
        }
    }

    cout << ans << "\n";
    return 0;
}