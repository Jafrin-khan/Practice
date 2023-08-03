class Solution {
public:
   void f(int ind, string ans, vector<string>& v, string& s, vector<string>& dict) {
    if (ind == s.size()) {
        v.push_back(ans.substr(1));  // Remove the leading space
        return;
    }

    int n = s.size();

    for (int i = ind; i < n; i++) {
        string word = s.substr(ind, i - ind + 1);
        if (find(dict.begin(), dict.end(), word) != dict.end()) {
            f(i + 1, ans + " " + word, v, s, dict);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& dict) {
    vector<string> v;
    f(0, "", v, s, dict);
    return v;
}
};