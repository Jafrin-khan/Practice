if(nums[start] + nums[end] == toFind){
vector<int> v;
v.push_back(nums[i]);
v.push_back(nums[start]);
v.push_back(nums[end]);
ans.push_back(v);
while(start < end && nums[start] == nums[start+1]){
start++;
}
while(start < end && nums[end] == nums[end-1]){
end--;
}
start++;
end--;
}
else if(nums[start] + nums[end] > toFind){
end--;
}
else{
start++;
}
} }
}
return ans;
}
};