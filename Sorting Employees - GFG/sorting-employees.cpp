//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int salary;
	string name;
};

// } Driver Code Ends
/* struct node{          // node structure
     int salary;
     string name;
 };
*/



class Solution{

	public:
	
	bool static cmp(node& a1 , node& a2){
	    if(a1.salary == a2.salary) return a1.name < a2.name;
	    return a1.salary < a2.salary;
	}
	void sortRecords(node arr[], int n)
	{
	    sort(arr , arr + n , cmp);
	}
	 

};

//{ Driver Code Starts.



int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        node arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i].name>>arr[i].salary;
        

        Solution ob;
        ob.sortRecords(arr, n);
        for(int i=0;i<n;i++)
        	cout<<arr[i].name<<" "<<arr[i].salary<<" ";
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends