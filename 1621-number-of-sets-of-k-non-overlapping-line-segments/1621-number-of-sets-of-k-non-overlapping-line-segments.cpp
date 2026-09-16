class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        long long ans = 1;

        // C(N, R)
        for (int i = 1; i <= R; i++) {
            ans = ans * (N - i + 1) % MOD;

            // Divide by i using modular inverse
            ans = ans * modPow(i, MOD - 2) % MOD;
        }

        return ans;
    }
};