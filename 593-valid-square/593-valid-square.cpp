class Solution {
public:
      int dis2(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0])* (p1[0] - p2[0]) + (p1[1] - p2[1])* (p1[1] - p2[1]);
    }
public:

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> ss;

        ss[dis2(p1, p2)]++;
        ss[dis2(p1, p3)]++;
        ss[dis2(p1, p4)]++;
        ss[dis2(p3, p2)]++;
        ss[dis2(p4, p2)]++;
        ss[dis2(p3, p4)]++;

        return ss.size() == 2 && (ss.begin()-> second == 4);
    }
};