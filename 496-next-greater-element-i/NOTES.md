stack <int> stk;
map <int, int> mp;
reverse(nums2.begin(), nums2.end());
for(int i = 0; i < nums2.size(); i++)
{
while(!stk.empty() && stk.top() <= nums2[i]) stk.pop();
if(!stk.empty())
{
mp[nums2[i]] = stk.top();
}
else
{
mp[nums2[i]] = -1;
}
stk.push(nums2[i]);
}
vector <int> arr;
for(int i = 0; i < nums1.size(); i++)
{
arr.push_back(mp[nums1[i]]);
}
return arr;