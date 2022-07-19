class Solution {
public:
   
     void findans(set<long int> &ugly,long int num)
    {  // int max value is 2147483647
        if(num>2147483647) return;
        if(ugly.find(num)!=ugly.end()) return; //   memoization
        ugly.insert(num);
        findans(ugly,num*2);
        findans(ugly,num*3);
        findans(ugly,num*5);
        return;
    }
    
    int nthUglyNumber(int n) {
       set<long int> ugly;
        findans(ugly,1);
    
        int i=0;
        for(auto it:ugly)
        {
            i++;
            if(i==n) return it;
        }
        return i;
    }
};