vector<string> ans;
void f(int open , int close , string s){
if(open == 0 && close == 0){
ans.push_back(s);
return;
}
if(open){
f(open-1 , close , s + '(');
}
if(close > open){
f(open , close-1 , s + ')');
}
}
vector<string> generateParenthesis(int n) {
f(n , n , "");
return ans;
}