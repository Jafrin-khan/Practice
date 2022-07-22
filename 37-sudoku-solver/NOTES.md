for(int i = 0 ; i < board.size() ; i++){
for(int j = 0 ; j < board[0].size() ; j++){
if(board[i][j] == '.'){
for(char c = '1'; c <= '9' ; c++){
if(isValid(board,i,j,c)){
board[i][j] = c;
if(solve(board) == true){
return true;
}
else{
board[i][j] = '.';
}
}}
return false;}
}
}
return true;
}