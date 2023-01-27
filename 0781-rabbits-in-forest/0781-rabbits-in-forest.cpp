class Solution {
public:
    /*
    TC = O(NlogN) + O(N)
    Sc = O(1)
    */
    int numRabbits(vector<int>& answers) {
        
        int n = answers.size();
        sort(answers.begin() , answers.end());
        int i = 0;
        int cnt = 0;
        
        while(i < n){
            int curr = answers[i];
            int j = i+1;
            while(j < n && curr &&  answers[i] == answers[j]){
                j++;
                curr--;
            }
            cnt += curr;
            i = j;
        }
        cnt+=answers.size();
        return cnt;
    }
};