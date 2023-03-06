**Recursion**
​
class Solution {
private:
int f(int i,int j1,int j2,int row,int col,vector<vector<int>>&grid)
{
if(j1<0 ||j1>=col || j2<0 || j2>=col)   return -1e8;
if(i==row-1)   {
if(j1==j2)  return grid[i][j1];
else    return grid[i][j1] + grid[i][j2];
}
int maxi = -1e8;
for(int dj1=-1; dj1<=+1; dj1++)
{
for(int dj2=-1; dj2<=+1; dj2++)
{
int value = 0;
if(j1==j2)  value = grid[i][j1];
else value = grid[i][j1] + grid[i][j2];
value+= f(i+1,j1+dj1,j2+dj2,row,col,grid);
maxi = max(maxi,value);
}
}
return maxi;
}
public: