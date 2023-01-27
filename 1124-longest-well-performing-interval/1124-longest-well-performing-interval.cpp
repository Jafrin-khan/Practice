class Solution {
public:
    
    /*
    to find any consecutive sum or consecution 1s we use map in this fashion.....v.imp trick
    TC = O(N)
    
    */
    int longestWPI(vector<int>& hours) {
        
        int n=hours.size();
        unordered_map<int,int>m;
        int res=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(hours[i] > 8) sum++;
            else sum--;
            if(sum>0)
            {
                res=i+1;
            }
            if(sum<=0)
            {
                if(m.find(sum-1)!=m.end())
                {
                     int l=i-m[sum-1];//interval
                     res=max(res,l);
                }
                if(m.find(sum)==m.end())
                    m[sum]=i;
            }
        }
        return res;
       
    }
};