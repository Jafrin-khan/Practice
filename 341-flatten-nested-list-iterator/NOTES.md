vector<int> output;
int size = 0;
void helper(vector<NestedInteger> &nestedList){
for(int i = 0 ; i < nestedList.size() ; i++){
if(nestedList[i].isInteger()){
output.push_back(nestedList[i].getInteger());
}
else{
helper(nestedList[i].getList());
}
}
}
NestedIterator(vector<NestedInteger> &nestedList) {
helper(nestedList);
}
int next() {
int ans = output.at(size);
size++;
return ans;
}
bool hasNext() {
return size != output.size();
}