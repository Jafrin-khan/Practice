//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends

/*
TC = O(N*N)
SC = O(N)
*/

void helper(stack<int>& st , int num){
    
   
    if(st.empty() || (!st.empty() && st.top() < num)) {
        st.push(num);
        return;
    }
    
    int x = st.top();
    st.pop();
    helper(st , num);
    st.push(x);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty()) return;
   
   int x = s.top();s.pop();
   sort();
   helper(s,x);
   
}