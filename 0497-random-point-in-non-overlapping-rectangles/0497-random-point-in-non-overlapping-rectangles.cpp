/*
https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/discuss/154795/C%2B%2B-concise-solution-using-binary-search-(pick-with-a-weight)
*/

/*
why upper_bound? example weights: 1 2 3: accumulate sums are 1 3 6 , they correspond to point sets: [0] [1,2] [3,4,5]
If we randomly pick a point id 3. iI falls into the last segment, with accumulated sum array's index 2, with sum 6, previous seg ment has accumulated 3. If we use lower_bound, we will find 2nd array (3==3). not the last one (6>3)
*/

class Solution {
public:
    vector<int> v;
    vector<vector<int>> rectangles;
    
    int area(vector<int>& r){
        //[x1 , y1 , x2 , y2]
        return (r[2] - r[0] + 1)*(r[3] - r[1] + 1);// +1 bcoz we have to include boundary as well
    }
    
    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        for(auto r : rectangles){
            v.push_back(area(r) + (v.empty()? 0 : v.back()));//prefix sum types similar to what we did in leetcode 528
        }}
    
    vector<int> pick() {
        int random = rand()%v.back();//taaki area k andar hmaara random number generate ho
        int ind = upper_bound(v.begin() , v.end() , random) - v.begin();//number line wala concept leetcode 528
        
        //now pick a random rectangle from ractangles
        auto r = rectangles[ind];
        
        return {rand()%(r[2] - r[0] + 1) + r[0] , rand()%(r[3] - r[1] + 1) + r[1]};
    }
};

