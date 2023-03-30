/*
Pancake Sorting
The main logic behind this problem is that we have to find the index of max number in the array then we will reverse the array from starting to the max index and will use a end pointer which will point at last index.
for example :-> [5,4,2,1,6,3]
the max element here is 6 and its index is 3 so we will reverse the array from start to max element index the resulting array will be [6,1,2,4,5,3].
In next step well will reverse the array from start to the end pointer the resulting array will be [3,5,4,2,1,6]. the last element is 6 and which is the max element of all.
now we will shift the end pointer to 1 and repeat until our end pointer reach to position 1.

class Solution {
public:

//  the function find is use to find the max index till the end pointer.
int find(vector<int>& arr, int len)
{
    int maxi = 0;
    int ans = 0;
    for(int i=0;i<len;i++)
    {
        if(maxi < arr[i])
        {
            maxi = arr[i];
            ans = i;
        }
    }
    return ans;
}

// this function is use to reverse the array from start to max_index position.
// in next step to reverse the whole array till end pointer.
void flip(vector<int>& arr, int x)
{
   reverse(arr.begin(),arr.begin()+x);
}


vector<int> pancakeSort(vector<int>& arr) {
    
    int n = arr.size();
    int i;
	// the end pointer.
    int end = n;
    vector<int>ans;
	we will iterate till the end pointer comes at start position.
    while(end != 1)
    {
	   // will find the max index.
        int idx = find(arr,end);
		// then reverse from start to amx index.
        flip(arr,idx + 1);
		// then start to  the end pointer.
        flip(arr,end);
		// push the number of flips used in step 1 and step 2.
        ans.push_back(idx + 1);
        ans.push_back(end);
		// decrease the end pointer everytime and you will have the last element greatest of all in every iteration.
		//finally when end pointer will be at 1then you array will be sorted.
        end--;
    }
   return ans; 
}
};
*/

class Solution {
public:
    
    int find(vector<int>& arr , int n){
        int ind = 0;
        int maxElem = arr[0];
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > maxElem){
                maxElem = arr[i];
                ind = i;
            }
        }
        
        return ind;
    }
    
    void flip(vector<int>& arr , int k){
        reverse(arr.begin() , arr.begin() + k);//rememebr srr.begin() + k
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        while(n != 1){
            int maxInd = find(arr , n);
            flip(arr , maxInd+1);//kyunki zero-based indexing hai
            flip(arr , n);
            
            ans.push_back(maxInd+1);//kyunki zero-based indexing hai
            ans.push_back(n);
            n--;
        }
        
        return ans;
        
    }
};