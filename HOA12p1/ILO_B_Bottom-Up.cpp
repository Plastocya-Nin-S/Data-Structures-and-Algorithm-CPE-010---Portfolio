#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinSteps(int n) {
    if (n <= 1) return 0; // Trivial case for 0 or 1
    
    vector<int> dp(n + 1);
    dp[1] = 0; // Base case
    
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Minimum steps to reach " << n << " is: " << getMinSteps(n) << endl;
    return 0;
}

