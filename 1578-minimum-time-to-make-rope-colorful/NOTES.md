int ans = 0;
int i = 0;
while(i < colors.size()){
int j = i;
int max_idx = i;
int maxTime = neededTime[i];
while(j < colors.size() && colors[i]==colors[j]){
if(neededTime[j] > maxTime){
maxTime = neededTime[j];
max_idx = j;
}
j++;
}
int k = i;
int sum = 0;
for(k = i ; k < j ; k++){
if(k != max_idx){
sum+=neededTime[k];
}
}
ans += sum;
i = j;
}
return ans;