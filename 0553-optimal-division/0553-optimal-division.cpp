class Solution {
public:
    
    /*
 
Initialize a string str
If the size of the given num is equal to 1 then add the only element if num to the string ("num[0]")
If the size of the given num is equal to 2 then no brackets required hence add 1st element ,'/' and 2nd element to the string
("num[0]/num[1]")
Else make it in the form "num[0]/(num[1]/......)"
Return the string
Complexity
Time complexity:
O(n)
    */
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