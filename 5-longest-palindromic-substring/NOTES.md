h++;
}
}
//even substring
for(int i = 0 ; i < s.length() ; i++){
l = i-1;
h = i;
while(l >= 0 && h < s.length() && s[l] == s[h]){
if(h-l+1 > end){
start = l;
end = h-l+1;
}
l--;
h++;
}
}
string ans ="";
int length = end+start;
for(int i = start ; i < length ; i++){
ans+=s[i];
}
return ans;
}