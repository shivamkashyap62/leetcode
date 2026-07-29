class Solution {
    using i128 = __int128_t;
    const i128 LIM = (i128)1000000 + 1;

    i128 C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        i128 ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM;
        }
        return ans;
    }

    i128 ways(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        i128 ans = 1;
        int left = rem;

        for (int c : cnt) {
            if (c == 0) continue;
            ans *= C(left, c);
            if (ans > LIM) ans = LIM;
            left -= c;
        }
        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s) freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (ways(half) < k) return "";

        string left;
        int len = 0;
        for (int x : half) len += x;

        while ((int)left.size() < len) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                i128 cnt = ways(half);

                if (cnt >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= (long long)cnt;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};