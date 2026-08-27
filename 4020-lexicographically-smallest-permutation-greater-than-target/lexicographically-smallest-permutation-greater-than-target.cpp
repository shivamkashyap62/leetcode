class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());

        // First try to find the permutation by modifying
        // target from right to left.
        for (int i = target.size() - 1; i >= 0; i--) {

            // Characters before i must be exactly target[0...i-1]
            string prefix = target.substr(0, i);

            // Check whether prefix can be formed from s
            multiset<char> st(s.begin(), s.end());

            bool possible = true;

            for (char c : prefix) {
                auto it = st.find(c);

                if (it == st.end()) {
                    possible = false;
                    break;
                }

                st.erase(it);
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            auto it = st.upper_bound(target[i]);

            if (it != st.end()) {
                char bigger = *it;
                st.erase(it);

                string ans = prefix + bigger;

                // Append remaining characters in sorted order
                for (char c : st)
                    ans += c;

                return ans;
            }
        }

        return "";
    }
};