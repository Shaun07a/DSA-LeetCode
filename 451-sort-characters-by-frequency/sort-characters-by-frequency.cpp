class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> arr;

        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });

        string ans = "";

        for (auto it : arr) {
            ans += string(it.second, it.first);
        }

        return ans;
    }
};