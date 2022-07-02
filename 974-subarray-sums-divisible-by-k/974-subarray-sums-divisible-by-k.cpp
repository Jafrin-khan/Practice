class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        
        map<int,int>mp;
		int sum=0,ans=0;
         mp[0] = 1;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
		    int r = (sum%k+k)%k;
			if(mp.find(r)!=mp.end()){
                 ans+=mp[r];
            }
			mp[r]++;
		}
		return ans;
        
    }
};