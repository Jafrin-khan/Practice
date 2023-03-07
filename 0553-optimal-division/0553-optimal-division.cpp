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

if we have something like 1000/100/10/2 without any parantheses then to evaluate the expression we start from beginning so 1000/100 reduces to 10 and expression becomes 10/10/2 which then reduces to 1/2 and finally to 0.5. lets analysis another case
if we have parantheses everywhere like 1000/(100/(10/2)) so to evaluate this expression we start calculating from last (inner paranthese first) so this reduces to 1000/(100/5) then 1000/20 and finally to 50.
so from above two cases what we see is that if go like 1st case numerator start decreasing and so its final value but in second case numerator is as it is and denominator is decreasing that finally giving us a maimum value.
So for us to get largest value of the expression we want to maximize numerator and minimize denominator and thats why we will use 2nd way to keep maximum numerator and 1st way to minimize denomitor so this will look like 1000/(100/10/2) to remove confusion numerator is 1000 and denominator is (100/10/2).

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