class Solution {
public:
    
    /*
The tricky part is that we use the self-defined compare function to sort the vector.
We should first make clear what the definition of "less" should be here.
For example, there are two string number a("121") and b("12"), which one is smaller?
The most straight way is to compare the result string a+b("12112") and b+a("12121").
We find that b+a is bigger, so a is smaller. So we can define our own compare function
  */
    
    static bool cmp(string& s1 , string& s2) {return s1+s2 > s2+s1;}
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> v;
        for(int i = 0 ; i < nums.size() ; i++) v.push_back(to_string(nums[i]));
        
        sort(v.begin() , v.end() , cmp);
        
        string ans = "";
        for(auto it : v){
            ans += it;
        }
        
        /*
        for this test case we are running this while loop bbaki main logic to uper wala hi hai
        Input        [0,0]
        Output       "00"
        Expected     "0" 
        */
        
        int cnt = 0;
        int i = 0;
        int pos = -1;
        
        while(i < ans.size()){
            if(ans[i++] == '0')cnt++;

        }
        
        if(cnt == ans.size()) return "0";
       
        return ans;
    }
};