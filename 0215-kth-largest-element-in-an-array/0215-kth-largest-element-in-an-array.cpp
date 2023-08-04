class Solution {
public:
    
    //QUICKSELECT
    
    int partition(vector<int>&arr, int l, int r)
{
	int f = arr[r] ;
	int i = l;

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= f) {
			swap(arr[i], arr[j]) ;
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}


int kth_Smallest_Element(vector<int>&arr, int l, int r, int k)
{
	if (k <= r - l + 1 && k > 0) {

		int ind = partition(arr, l, r);


		if (ind - l == k - 1) {
			return arr[ind];
		}
		if (ind - l > k - 1) {
			return kth_Smallest_Element(arr, l, ind - 1, k);
		}


		return kth_Smallest_Element(arr, ind + 1, r, k - ind + l - 1);
	}
	return INT_MAX;
}
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = n-k+1;//is tarike se hum both Kth largest aur Kth smallest nikal skte ek hi tarah k function se;
        return kth_Smallest_Element(nums ,0 ,n-1  , k);
    }
};