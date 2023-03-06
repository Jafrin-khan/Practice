class Solution {
public:
    /*
    Intuition :

Traverse the array and make the array upto the element covered non decreasing and count each modiufication. And we also try to make the last element as small as poosible so that in next iterations the possibily of the array to be non decreasing increases. So we make the elements equal in each non decreasing sequenece found. If modification gets more than 1 then return false else return true.

Now, if we find an element is less than its previous (nums[i] < nums[i-1]) then what are the possibilities?

Either current element is greater or equal than the previous of previous element (num[i-2] <= nums[i])
In this case if we make any of the previous (nums[i-1]) of current (nums[i]) equal to one another. But to make the end element as small as possible we make the greater (previous) equal to smaller (current) i.e. nums[i-1] = nums[i]

        5
	   / \
	  /    4------                      4 __ 4
     /                                 /
    3-------------     ->             3               Decrease middle element to right one
   /                                 /
  2                                 2
 /                                 /
1                                 1
        5
	   / \
	  /   \                   
     /     \                           
    3-------3-------     ->           3 __ 3 __ 3        Decrease  middle element to right and left one
   /                                 /
  2                                 2
 /                                 /
1                                 1
Or the current element is also lesser than the previous of previous element (nums[i-2] > nums[i]).
In this case the array excluding the current element is non-decreasing. But if we exclude the previous element then the last element is still lesser than its previous. So make the current element (smaller) equal to the previous (greater) i.e. nums[i] = nums[i-1]

        5                                  5 __ 5 
	   / \                                /
	  4---\---------                     4
     /     \                            /
    3       3-------      ->           3                  Increse right element to middle one
   /                                  /
  2                                  2
 /                                  /
1                                  1
In case of the second element (nums[1]) if it is lesser than the first (nums[0]) there is no previous of previous element to compare to so just make both as small as possible so make num[0] = num[1] which is in turn the first condition discussed. So just check if i == 1 in first condition to implement it.

Code with Full Explanation :

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0; //to store the count of modifications                   
        for(int i = 1; i < nums.size(); i++){

            //decreasing sequence found
            if(nums[i] < nums[i-1]){

                //if count after increasing becomes more than 1 then false
                if(++cnt > 1) return false;
                
                //in case of the 2nd element as i[1] < i[0] so make i[0] = i[1]
                //if prev of prev element of curr is less than or equal to it then only the we can make it non decreasing by making the greater equal to lesser (prev = curr).
                if(i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];    
                
                //if prev of prev is greater than curr then we have to make the lesser equal to greater (curr = prev)
                else 
                    nums[i] = nums[i-1];
            }
        }
        
        //this command will only run if the loop is totally traversed and count <= 1 so return true.
        return true;
    } 
};
    */
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;             
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                if(++cnt > 1) return false;
                if(i == 1 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];    
                else nums[i] = nums[i-1];
            }
        }
        return true;
        
    }
};