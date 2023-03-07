class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string str="";
        if(nums.size()==1) return to_string(nums[0]);
        if(nums.size()==2) return to_string(nums[0])+'/'+to_string(nums[1]);
        for(int i=0;i<nums.size()-1;i++){
            str+= to_string(nums[i])+'/';
            if(i==0) str+='(';

        }
        str+=to_string(nums[nums.size()-1])+')';
        return str;
    }
};