map<int,int> mp;
int maxi=INT_MIN;
int maxCount=0;                             //keeps the track of the most repeating character
int start=0,end=0;
while(end<s.length())
{
mp[s[end]]++;                                         //update the frequency of the character
maxCount=max(maxCount,mp[s[end]]);                    //update the most repeating character
if(end-start+1-maxCount>k)                            //if the difference between the length of the subarray and the frequency of the most repeated character is
{                                                      // greater than K, then it means that we have already changed K characters, thus we shrink the window and
mp[s[start]]--;                                    // decrease the frequency of the most repeated character
​
start++;
}
maxi=max(maxi,end-start+1);
end++;
}
return maxi;