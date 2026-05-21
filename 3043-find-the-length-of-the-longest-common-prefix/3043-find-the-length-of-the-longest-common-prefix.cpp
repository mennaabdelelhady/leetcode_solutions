class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        // Store all prefixes of arr1 numbers
        for (int num : arr1) {
            string s = to_string(num);

            for (int i = 1; i <= s.size(); i++) {
                prefixes.insert(s.substr(0, i));
            }
        }

        int ans = 0;

        // Check prefixes of arr2 numbers
        for (int num : arr2) {
            string s = to_string(num);

            for (int i = 1; i <= s.size(); i++) {
                string pref = s.substr(0, i);

                if (prefixes.count(pref)) {
                    ans = max(ans, i);
                }
            }
        }

        return ans;
    }
};