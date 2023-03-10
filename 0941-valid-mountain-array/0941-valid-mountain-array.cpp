class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int i = 0 , j = arr.size()-1;
        
        while(i < arr.size()-1 && arr[i+1] > arr[i]) i++;
        while(j > 0 && arr[j] < arr[j-1]) j--;
        cout<<i<<" "<<j<<endl;
        
        if(i == 0 || j == arr.size()-1) return false;
        return i == j;
    }
};