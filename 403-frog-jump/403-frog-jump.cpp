class Solution {
public:
   int dp[2001][2001];

	bool canfrog(vector<int> &stones,int idx,int jump){
		if(idx == stones.size()-1)return true; // IF WE'VE REACHED THE LAST STONE
		if(dp[idx][jump]!=-1)
		return dp[idx][jump];
		for(int j=idx+1;j<stones.size();j++){
			bool x = false;
			bool y = false;
			bool z = false;
			int nextjump = stones[j] - stones[idx];
			if(nextjump == jump - 1){
				x = canfrog(stones,j,jump-1);
			}
			if(nextjump == jump){
				y = canfrog(stones,j,jump);
			}
			if(nextjump == jump + 1){
				z = canfrog(stones,j,jump+1);
			}
			if(x || y || z) return dp[idx][jump] = 1; // IF USING ANY OF THE 3 WAYS WE COULD REACH END RETURN TRUE
		}
		return dp[idx][jump] = 0; // ELSE RETURN FALSE
	}

	bool canCross(vector<int>& stones) {
		int n = stones.size();
		if(stones[1] != 1) // IF WE CAN'T REACH THE FIRST STONE THEN ANS. IS ALWAYS FALSE
		return false;
		memset(dp,-1,sizeof(dp));
		return canfrog(stones,1,1);
	}
};