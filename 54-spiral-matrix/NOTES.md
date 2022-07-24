class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
int row_start = 0;
int row_end = matrix.size()-1;
int col_start = 0;
int col_end = matrix[0].size()-1;
vector<int> ans;
while(row_start <= row_end && col_start <= col_end){
for(int i = col_start ; i <= col_end ; i++){
ans.push_back(matrix[row_start][i]);
}
for(int i = row_start+1 ; i <= row_end ; i++){
ans.push_back(matrix[i][col_end]);
}
for(int i = col_end-1 ; i >= col_start ; i--){
if(row_start == row_end){
break;
}
ans.push_back(matrix[row_end][i]);
}
for(int i = row_end-1 ; i>row_start ; i--){
if(col_start == col_end){
break;
}
ans.push_back(matrix[i][col_start]);
}
col_start++;
col_end--;
row_start++;
row_end--;
}
return ans;
}
};