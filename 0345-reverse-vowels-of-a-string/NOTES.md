int i =0,j= s.size()-1;
unordered_set<char> v({'a','e','i','o','u','A','E','I','O','U'});
while(i<j){
if(v.find(s[i])!=v.end() && v.find(s[j])!=v.end()){
char x = s[i];
s[i]=s[j],s[j]=x;
i++,j--;
}
else if(v.find(s[i])==v.end())i++;
else
j--;
}
​
return s;