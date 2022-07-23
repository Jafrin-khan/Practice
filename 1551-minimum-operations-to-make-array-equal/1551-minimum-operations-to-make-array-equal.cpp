class Solution {
public:
    
    //https://www.youtube.com/watch?v=9aGx9hoIBjI
    int minOperations(int n) {
         //if n is even then return sum of 1st n/2 odd numbers
      if(n%2==0)
      {
          n/=2;
          return n*n;
      }
        //if n is odd then return sum of 1st n/2 even numbers
     n/=2;
        return (n+1)*n;
    }
};