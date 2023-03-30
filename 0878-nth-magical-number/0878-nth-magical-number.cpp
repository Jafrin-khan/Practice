/*
We are given integers N, A and B. We need to find Nth magical number (a number which divides either A or B or both).

❌ Solution - I (Brute-Force)

To start with brute-force approach, we can simply iterate from min(A,B) till we find a total of B magical numbers.

class Solution {
public:
    const int MOD = 1e9+7;
    int nthMagicalNumber(int N, int A, int B) {
        long i = min(A, B);
        for(; n; i++)
            if(i % A == 0 || i % B == 0) n--;
        return (i-1) % MOD;
    }
};
Time Complexity : O(N*min(A, B))
Space Complexity : O(1)

✔️ Solution - II (Binary-Search)

The above solution times out, so a linear search wont work for the problem's constraints. We can do better by applying binary-search since the search space is monotonically increasing, i.e, the function giving number of magical numbers less than or equal to x is monotonically increasing (more specifically, non-decreasing). So we can apply binary search in the range [L, R] to get a number ans which has N magical numbers less than or equal to it.

How to apply Binary Search for this problem?

Determining Binary Search Condition :

First, let's determine the condition to be used in our binary search - magicNumbersLessEqual(x). For a given number x, the numbers <= x which are divisible by A is given by ⌊x/A⌋. For eg. consider x = 17 & A = 3, so ⌊ x/A ⌋ = 5, and we can verify that it is correct. Similarly, numbers <= x which are divisible by B is given as ⌊x/B⌋.

But we cant directly consider the result of ⌊x/A⌋ + ⌊x/B⌋ as the total numbers less than x which is divisible by A or B. This is because there might be numbers which are divisible by both A & B and we would be counting them twice. So, we need to account for this by subtracting the count of numbers which are divisible by both A and B. And we know that numbers which are divisible by both A & B are LCM & its multiples. So we will subtract the count of numbers <= x which are multiples of LCM(A, B) which will be given by ⌊x/LCM⌋. So the final function becomes - magicNumbersLessEqual(x) = ⌊x/A⌋ + ⌊x/B⌋ - ⌊x/LCM⌋

Range of Binary-Search :

Now, let's calculate the range of our search space. The start point L = min(A,B) since no number lower than that would be divisible by either of them. The end point R = N*min(A,B) because we will surely find N magical numbers since this N*min(A,B) means there will be atleast N numbers divisible by minimum of A or B.

At each iteration, we will calculate mid and determine magicNumbersLessEqual(mid). If it is less than N, we do L = mid + 1 since we are sure any number less than mid wont be our answer. If it is > N, then we do R = mid - 1 since we are sure any number greater than mid wont be our answer. Finally, we return the number giving magical numbers less than or equal to it as N which will be the required Nth magical number.

class Solution {
public:
    const int MOD = 1e9+7;
    int nthMagicalNumber(int N, int A, int B) {
        long LCM = lcm(A, B), L = min(A, B), R = N*L, mid, ans;
        auto magicNumbersLessEqual = [&](long x) { return (x/A) + (x/B) - (x/LCM); };
        while(L <= R) {
            mid = L + (R-L) / 2;
            if(magicNumbersLessEqual(mid) < N) L = mid + 1;   // magical numbers <= mid are less than required, so discard search space to left of mid
            else R = mid - 1, ans = mid;                      // mark mid as the potential answer & search in [L, mid-1]
        }
        return ans % MOD;
    }
};
\U0001f4a1\U0001f4dd Proof: How do we know ans will always be magical number (divide either A or B)?

Every time, we are only checking if magicNumbersLessEqual(mid) < N and running the process till L & R narrow down to each other. But how can we be sure that ans is magical number?

For eg. Consider -

A = 2, B = 3, N = 4
Search space is [L, R] = [min(A, B), N*min(A,B)] = [2, 8]
magical numbers = 2, 3, 4, 6, 8, 9, 10, 12, ...

In 1st iteration mid = (2+8)/2 = 5 & we find magicNumbersLessEqual(5) = 3 < N. So search is updated to [6, 8]

In 2nd iteration, we have mid = (6+8)/2 = 7 & we find magicNumbersLessEqual(7) = 4 = N.
But 7 doesn't exist in magical number list. 

How do we know that the search wont return such number which is not in magical number list of A & B?
Let's say ans that the binary-search returns is not a magical number. Then, we must have some other number ans' smaller than ans which does exist in table and for which magicNumbersLessEqual(ans') == N. (Why ans' < ans? Because if ans isn't magical number but still has magicNumbersLessEqual(ans) == N, then there must be smaller number which is magic number & has magicNumbersLessEqual(x) == k and we need to find that)

But, in the above solution, ans is itself the smallest number for which we found magicNumbersLessEqual(mid) == N and then marked mid as ans. We can surely say that it's smallest since we also ran further search over range [L, mid-1] and we didnt find any magicNumbersLessEqual([L...mid-1]) == N.

From above two observation, we must conclude ans' = ans which is our final answer and it is indeed a magical number.

Time Complexity : O(log(N*min(A, B)))
Space Complexity : O(1)

✔️ Solution - III (Math)

This solution relies on a pattern observation in this problem. Let's see it through examples -

A = 2, B = 3.
LCM = 6
magical numbers = 2, 3, 4, 6,       8, 9, 10, 12,       14, 15, 16, 18,  ...
,
A = 3, B = 5
LCM = 15
magical numbers = 3, 5, 6, 9, 10, 12, 15,       18, 20, 21, 24, 25, 27, 30,       32, 35, 36, 39, 40, 42, 45,  ...
Observe a pattern?

Let L be LCM. The magical numbers occur in groups each having ranges [0, L], [L+1 2*L], [2*L+1, 3*L], ..., [k*L+1, (k+1)*L].
All numbers in these groups are equal in count & unique. Each group has a count C such that C = ⌊L/A⌋ + ⌊L/B⌋ - 1 number of magical numbers. The 1st terms accounts for numbers <= L which are divisible by A, 2nd term denotes number <= L which are divisible by B, and -1 to subtract common number L which is divisible by both A & B.

The group index k where our answer will lie can be determined by k = N-1 / C which gives total number of previous groups to skip and leaves us to only search from [k*L, (k+1)*L].
The groups before k-indexed group will contain k*C magical numbers and thus we need to find N-k*Cth magical number in kth group.
We still cant directly linear-search over kth group since [k*L+1, (k+1)*L] range can be big enough to timeout (in case of large co-prime A & B).
We can generate magical numbers of kth group one by one. The 1st magical number would be k*L + min(A, B). Suppose it is k*L + A, then the next one would be k*L + min(2*A, B) and so on... till we generate required number of magical numbers in kth group
class Solution {
public:
    const int MOD = 1e9+7;
    int nthMagicalNumber(int N, int A, int B) {
        long L = lcm(A, B), C = (L/A) + (L/B) - 1, k = (N-1) / C, ans = 0;
        for(int i = 1, j = 1, magicalNeeded = N - k*C; magicalNeeded; magicalNeeded--) 
            if(A*i < B*j) ans = A * i++;
            else ans = B * j++;

        return (k*L + ans) % MOD;
    }
};
Time Complexity : O(A + B)
Space Complexity : O(1)
*/

//TC = O(log(N*min(A, B)))
//SC = O(1)

class Solution {
public:
    const int MOD = 1e9+7;
    
    auto magicNumbersLessEqual(long x , int A , int B , long LCM) { 
        return (x/A) + (x/B) - (x/LCM); 
    }
    
    int nthMagicalNumber(int N, int A, int B) {
        long LCM = lcm(A, B), low = min(A, B), high = N*low, mid, ans;
        
        while(low <= high) {
            mid = low + (high-low) / 2;
            if(magicNumbersLessEqual(mid , A , B , LCM) < N) low = mid + 1;   // magical numbers <= mid are less than required, so discard search space to left of mid
            else high = mid - 1, ans = mid;                      // mark mid as the potential answer & search in [L, mid-1]
        }
        return ans % MOD;
    }
};