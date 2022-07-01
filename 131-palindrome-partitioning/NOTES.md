bool isPalindrome(string s , int start ,int end){
while(start < end){
if(s[start++] != s[end--]){
return false;
}
}
return true;
}
void f(int ind ,string s ,vector<string> helper,vector<vector<string>> &ans){
if(ind == s.size()){
ans.push_back(helper);
return;
}
for(int i = ind ; i < s.size() ; i++){
if(isPalindrome(s,ind,i)){
helper.push_back(s.substr(ind,i - ind+1));
f(i+1,s,helper,ans);
helper.pop_back();
}
}
}
vector<vector<string>> partition(string s) {
vector<vector<string>> ans;
vector<string> helper;
f(0 , s , helper , ans);
return ans;
}