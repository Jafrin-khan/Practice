​
int f(vector<int>& coins, int amount,int ind){
if(ind == 0){
if(amount%coins[ind] == 0){
return amount/coins[ind];
}
else{
return 1e9;
}
}
int notTaken = f(coins,amount,ind-1);
int taken = INT_MAX;
if(coins[ind] <= amount){
taken = 1 + f(coins,amount - coins[ind] , ind);
}
return min(taken,notTaken);
}
int coinChange(vector<int>& coins, int amount) {
int n = coins.size();
int ans = f( coins, amount,n-1);
if(ans == 1e9){
return -1;
}
return ans;
}