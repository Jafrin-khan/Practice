/*
So the idea is to make windows of k+1 (as (k+1-1) - 0 <= k) size in which the elements are sorted.
It can be done with multiset.
Now lets understand with an example.

Lets suppose there is a window of size k+1 and some t (given)

Now as soon as we found a consecutive pair of elements whose difference is <= t,
We return true (as our window is of k+1 already size and we found diff <= t).

Otherwise lets suppose a new element comes into play (say x at index k) and

u = upper_bound(x) in a[0...k], return true if u - x <= t
p = previous of upper bound, return true if x - p <= t

else, remove the (i-k)th element from the window and continue to next element.

return false if no such element was found in the entire process.

a[] = 17 4 1 14 11 7 25 2 15 7
k = 4
t = 2
| 1 4 11 14 17 | 7 25 2 15 7
    3  7  3  3
17 | 1 4 7 11 14 | 25 2 15 7
       3 3  4  3
17 4 | 1 7 11 14 25 | 2 15 7
         6  4  3 11
17 4 1 | 2 7 11 14 25 | 15 7
           5  4  3 11
17 4 1 14 | 2 7 11 15 25 | 7
              5  4  4 10
17 4 1 14 11 | 2 7 7 15 25 |
                 5 0  8 10         0 <= t so return true
struct Solution {

    bool containsNearbyAlmostDuplicate(vector<int> &a, int k, int t) {
        
        int n = a.size();
        k = min(k, n);
        
        multiset<long long> s(a.begin(), a.begin() + k);
        
        auto x = s.begin();
        
        for (int j = 1, i = *x; j < k; ++j) {
            ++x;
            if (*x - i <= t) {
                return 1;
            }
            i = *x;
        }
        
        for (int i = k; i < n; ++i) {
            
            x = s.upper_bound(a[i]);
            
            if (x != s.end() && *x - a[i] <= t) {
                return 1;
            }
            if (x != s.begin()) {
                --x;
                if (a[i] - *x <= t) {
                    return 1;
                }
            }
            
            s.insert(a[i]);
            s.erase(a[i-k]);
        }
        
        return 0;
    }
};
*/

//SLIDING WINDOW IMPLEMENT KRNA NI AARA ISLIE YE SUBMISSION DIYA ABHI
/*
TC = O(N*K)
SC = O(N)
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        
        set<int> st(nums.begin() , nums.end());
        if(t == 0 && st.size() == n) return false;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < i+k+1 ; j++){
                if(j >= n) break;
                if(abs((long long)nums[i] - nums[j]) <= t) return true;
            }
        }
        
        return false;
    }
};