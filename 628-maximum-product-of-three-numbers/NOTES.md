using namespace std;
​
int maxProduct(vector<int>& v) {
int n = v.size();
// Sort vector in ascending order
sort(v.begin(), v.end());
int prod1 = v[n-1]*v[n-2]*v[n-3];
int prod2 = v[n-1]*v[0]*v[1];
return max(prod1, prod2);
}
​
int main()
{
vector<int> v{-10, -20, 4, 1, 3, 2};
cout << "Maximum product = " << maxProduct(v) << endl;
}