/*
Minimum rate at which koko can eat banana is 1 banana/hour (i.e banana per hour)

Maximum rate at which can eat banana is (Maximum bananas in pile)/ hour

Using this as low and high apply binary search and check whether the koko can finish
all the bananas with the specified speed (i.e mid ).

If it can finish then there would be some speed which is less than current speed with which
it can finish the all bananas so make high = mid -1

If it can't finish,that mean speed is not enough so increase speed i.e low = mid+1

Time Complexity --- O(n + nlog(max element in piles))
n for finding the max_element in piles. n is the size of the piles

Space Complexity -- O(1)

class Solution {
public:
    Function to find whether koko can finish the bananas or not
    bool helper(vector<int> &piles,int h,int k)
    {
        int time = 0;
        for(auto &pile : piles)
            time += ceil( double(pile)/k );
        return time <=h;
    }  
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            helper(piles,h,mid) ? high = mid-1 : low = mid+1;
        }
        return low;
    }
};
*/

class Solution {
public:
    
    bool isValidAndReturnK(long long k , long long upperTime , vector<int>& piles){
        
        long long time = 0;
        for(long long i = 0 ; i < piles.size() ; i++){
            time += ceil(double(piles[i])/k);
        }
        
        return time <= upperTime;
    }
    
    int minEatingSpeed(vector<int>& piles, int time) {
       long long maxBanana = -1e9;
        
       // for(int i = 0 ; i < piles.size() ; i++){
       //     maxBanana = max(maxBanana , piles[i]);
       // }
        long long low = 1;
        long long high = *max_element(piles.begin(),piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(isValidAndReturnK(mid , time , piles)) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};