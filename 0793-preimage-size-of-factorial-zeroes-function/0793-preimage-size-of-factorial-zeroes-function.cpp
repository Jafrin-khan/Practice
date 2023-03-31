/*
The problem is a transformed Factorial Zeroes Function. So let's see how to get number of zeros in the factorial.

Basically, when any 10 based numbers come with tailing 0s, there are factors 5 and 2 in it. Obviously, in the factorial, we have much more 2 factors than 5. Let's see an example below:

10! = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 = 3628800 = 2^8 * 5^2 * xxx
So the number of tailing zeros is directly decided by the how many 5 factors are there. To get the number of 5 more easily, we can convert the 10 based number to a 5 based number, or quinary number. 10 based 10 equals to 5 based 20, 10(10) = 20(5). And the number of 5 equals to 20(5) % 10(5) = 2. If the number is even larger, for example 1234(5)!, them the number of 5s will be:

1234(5) % 10(5) + 1234(5)  % 100(5) +1234(5)  % 1000(5) = 123(5) + 12(5) + 1(5) = 141(5)
Such thing can be easily implemented by using a loop.

int zeros(int x) {
  int result = 0;
  while(x > 0) {
    x /= 5;
    result += x;
  }
  return result;
}
Back to this question, we are given the number of zeros K and asked for how many different numbers to get K tailing zeros. It looks really funny/tricky, since there can only two answers, 5 or 0.

If we could figure out any number X whose factorial has K tailing 0s, then [ X, X + 1, X + 2, X + 3, X + 4] (assume X is the smallest one) will be the anwers. X + 5 will bring in another number with factor 5 for sure, and the tailing zeros will be more than K.
If we could NOT figure out a number with K tailing 0s, then you can do nothing but return 0.
To figure out if K is a feasible number, we can binary search and see if any number matches. Below is the implemention and we need the zeros function decleared above.

int preimageSizeFZF(int K) {
  int lower = K, upper = K * 5;
  while(lower <= upper) {
    int mid = (lower + upper) / 2, nZeros = zeros(mid);
    if (nZeros > K) {
      upper = mid - 1;
    } else if (nZeros < K) {
      lower = mid + 1;
    } else {
      return 5;
     }
  }
  return 0;
}
The above code may not be accepted, since K * 5 can be more than INT_MAX, but I know you guys can figure out how to make it pass. lol
*/

class Solution {
public:
       long long f(long long num){
            long long cnt = 0;
            while(num){
                cnt += (num/5);
                num/=5;
            }
            return cnt;
        }
    
        int findNum(long long n)
        {
            if(n == 0) n = 1;
            long long ans = 0;
            
            long long low = 1;
            long long high = n*5;
            
            while(low <= high){
                long long mid = low + (high-low)/2;
                long long check = f(mid);
                
                if(check >= n){
                    if(check == n ) return 5;
                    high = mid-1;
                }
                
                else  low = mid+1;
            }
        
           return 0;
        }
    int preimageSizeFZF(int k) {
        return findNum(k);
    }
};