class Solution {
public:
    
    static bool cmp(vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        
        sort(courses.begin(),courses.end(),cmp);
        
        priority_queue<int> pq;
        int time = 0;
        
        for(int i = 0 ; i < courses.size() ; i++){
            
            if(time + courses[i][0] <= courses[i][1]){
                
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
            
            else if(!pq.empty() && courses[i][0] <= pq.top()){
                time -= pq.top();
                pq.pop();
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
            
        }
        
        return pq.size();
        
        
        
    }
};