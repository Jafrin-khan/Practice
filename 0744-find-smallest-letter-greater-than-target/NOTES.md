l=0
r=len(letters)
while l<r:
mid=(int)(l+(r-l)/2)
if letters[mid]<=target:
l=mid+1
else:
r=mid
return letters[l%len(letters)]