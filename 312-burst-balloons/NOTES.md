class Solution {
public:
int f(vector<int> &arr, int i, int j) {
if (j - i + 1 <= 2) return 0;
int money = INT_MIN;
for (int k = i + 1; k < j; k++) {
int curMoney = (arr[i] * arr[k] * arr[j]) + f(arr, i, k) + f(arr, k, j);
money = max(money, curMoney);
}
return money;
}
int maxCoins(vector<int>& nums) {
nums.push_back(1);
nums.insert(nums.begin(), 1);
return f(nums, 0, nums.size() - 1);
}
};