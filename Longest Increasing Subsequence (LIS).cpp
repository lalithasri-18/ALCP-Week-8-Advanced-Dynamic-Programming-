#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if(n <= 0) {
        cout << "Length of LIS: 0";
        return 0;
    }

    vector<int> a(n), dp(n, 1);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << "Length of LIS: " << ans;
    return 0;
}
