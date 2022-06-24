class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long > pq;
        long long sm=0;
        for(auto x:target){sm+=x;pq.push(x);}
        while(pq.top()>1){
            long long  top=pq.top();
            pq.pop();
            sm-=top;
            if(sm==0)return 0;
            if(top-sm<1)return 0;
            long long  x=1;int f=0;
            
            while((top-sm*x)>sm){f=1;x=x<<1;}
            if(f==1)x=x>>1;
            if(top-sm*x<1)return 0;
            pq.push(top-sm*x);
            sm+=top-sm*x;
            
            
        }
        return 1;
    }
};