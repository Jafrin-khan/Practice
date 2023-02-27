class Solution {
public:
    /*
    https://www.youtube.com/watch?v=2hVinjU-5SA
    */
    
    /*
    public static bool checkIfCircularArrayHasCycle(int[] arr)
        {
            if (arr.Length <= 1)
            {
                return false;
            }

            for (int i = 0; i < arr.Length; i++)
            {

                int slow, fast;
                slow = fast = i;
                bool ifForward = arr[i] > 0; //checking what's my direction, >0 means array value is positive

                while (true)
                {
                    slow = getNextPosition(arr, slow, ifForward); //get index of the slow pointer, get the main direction
                    if (slow == -1)
                    {
                        break;
                    }

                    fast = getNextPosition(arr, fast, ifForward);
                    if (fast == -1)
                    {
                        break;
                    }
                    //we are running thorugh fast again because fast pointer needs to move 2 positions at a time
                    fast = getNextPosition(arr, fast, ifForward);
                    if (fast == -1)
                    {
                        break;
                    }

                    if (slow == fast)
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        private static int getNextPosition(int[] arr, int index, bool ifForward)
        {
            bool direction = arr[index] >= 0;

            //check if arr[index] direction is same as ifForward, if it changes then return -1

            if (direction != ifForward)
            {
                return -1;
            }

            //find out our next index
            //[1,1,2,1,2] --> suppose the index is at 4, so arr[4] = 2, so (4+2)%5 = 1,
            //so the next index position will be 1
            //so it'll jump from arr[4] = 2 TO--> arr[1] = 1
            int nextIndex = (index + arr[index]) % arr.Length;

            //if nextIndex becomes zero so the new position will be nextIndex + length
            //ex: [-2, -1, 1, -2, -1] --> when nextIndex becomes zero means the pointer is ar arr[0] = -2,
            //so it will jump backwards by two positions which is 3rd Index = arr[3] == -2
            //in this if condition, we get nextIndex = -2 + 5 = 3
            if (nextIndex < 0)
            {
                nextIndex = nextIndex + arr.Length;
            }

            //ex: [4,1,1,1] --> this checks if cycle has only one element
            //go back to this line - nextIndex= (index + arr[index]) % arr.Length;
            //so if (0 + 4) % 4 = 0, means nextIndex has become the index so return -1 here
            if (nextIndex == index)
            {
                return -1;
            }

            return nextIndex;
        }
        //TIME- O(N2)...SPACE- O(1)...While inside foreach, no ds used to store any data

    }
    
    */
      
    /*
    TC = O(N^2)
    SC = O(1)
    */
    
    int getDirection(vector<int>& nums, int ind , bool ifForward){
        
        int n = nums.size();
        bool direction = nums[ind] >= 0;
        if(ifForward != direction) return -1;
        
        int nextInd = ((ind + nums[ind])%n+n)%n;
        if(nextInd < 0) nextInd += nums.size();
        if(nextInd == ind) return -1;
        
        return nextInd;
    }
   
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1) return false;
        
        for(int i = 0 ; i < n ; i++){
            
            int slow = i;
            int fast = i;
            
            bool ifForward = nums[i] > 0;
            
            while(true){
                slow = getDirection(nums , slow , ifForward);
                if(slow == -1) break;
                
                fast = getDirection(nums , fast , ifForward);
                if(fast == -1) break;
                fast = getDirection(nums , fast , ifForward);
                if(fast == -1) break;
                if(slow == fast) return true;
            }
            
        }
        
        return false;
    }
};