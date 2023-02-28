class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
   
    string complexNumberMultiply(string s1, string s2) {
          string real1 , img1 , real2 , img2;
          
          int i = 0;
          while(s1[i] != '+'){
              real1 += s1[i++];
          }
          img1 = s1.substr(i+1 , s1.size()-i);
          
          i = 0;
          while(s2[i] != '+'){
              real2 += s2[i++];
          }
          img2 = s2.substr(i+1 , s2.size()-i);
          cout<<img1<<" "<<img2<<" "<<"multiple : "<<stoi(img1)*stoi(img2)<<endl;
          int real , img;
          //img ko bhi normal integer ki tarah int mai convert kr skte h trverse aur i seperate krne ki jhanjhat ni h isme bua i^2 = -1 ni hota wo manually include krna hoga"
          real = stoi(real1)*stoi(real2) - stoi(img1)*stoi(img2);
          img = stoi(real1)*stoi(img2) + stoi(real2)*stoi(img1);
          
          return to_string(real) + "+" +  to_string(img) + "i";
    }
};