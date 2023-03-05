/*
Understanding the problem statement and role of time t
Problem statement is quite simply. We are simply provided with a starting vertex and need to find the probability of reaching a target vertex at t seconds.
Here the role of time t is to see if we can reach that node at t seconds.
Let's say you reach target node but you still have time left and also it is not a leaf node(Will explain later why the leaf node condition also have to be checked), then in the further time frog is gonna jump on to the further levels and not gonna stay at target node. Hence the probability will be zero in this case.
The concept of leaf node also plays an important role here, Since the question clearly states that frog can keep jumping on to to the leaf node, So if we reach target node under t seconds, doesn't matter if time is still remaining frog can keep jumping on that node and will be on it at time = t. Hence we will return the probability.

Algorithm:
We are gonna create more params, One for probability and another for time and visited array.
As soon as we come to a node, we mark it visited as generally done in the dfs. Then we check if we have reached the target node. If we have then we check further conditions as explained above.
If the curr node is a leaf node or time == t then we return the probability else 0 indicating that it;s not possible to be at target node at t seconds.
If curr != target, then we compute the new probability, New probability is very easily calculated as each edge is equiprobable, Hence we simply multiply the old probability with 1/(total edges or paths we can take now)
Code:
typedef vector<vector<int>> vtt;
typedef vector<int> vt;
typedef vector<bool> vb;
class Solution
{
public:
    double frogPositionHelper(vtt &adj, int time, int target, int curr, double probability, vb &visited)
    {

        if (time < 0)
            return 0;

        visited[curr] = true;

        if (curr == target)
        {
            if (curr == 1)
            {
                // If it is a leaf node or time has become 0 then the probability is 1 since we started from there only, else
                // we need to go on further levels and we will not be able to stay on 1, Hence prob will become 0
                if (adj[curr].size() == 0 || time == 0)
                    return 1;
                return 0;
            }
            if (adj[curr].size() == 1 || time == 0)
                return probability;
            return 0;
        }

        int neighbors = curr == 1 ? adj[curr].size() : adj[curr].size() - 1;
        double new_probability = probability * (1.0 / neighbors);
        double ans = 0;
        for (auto vertex : adj[curr])
        {
            if (!visited[vertex])
                ans = max(ans, frogPositionHelper(adj, time - 1, target, vertex, new_probability, visited));
        }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {

        // Forming the adjacency list
        vtt adj(n + 1, vector<int>());
        vb visited(n + 1, false);

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return frogPositionHelper(adj, t, target, 1, 1, visited);
    }
};
*/

class Solution {
public:
    
    double dfs(int curr , vector<vector<int>>& adj , int time , int target , double prob , vector<int>& vis){
        if(time < 0) return 0;
        vis[curr] = true;
        if(curr == target){
            
            //khin aur jaane ki ya to jgh ni ya time islie 1 wrna 0
            if(curr == 1){
                if(time == 0 || adj[curr].size() == 0) return 1;
                return 0;
            }
            
            if(adj[curr].size() == 1 || time == 0) return prob*1;
            return 0;
        } 
            int neighbors = curr == 1 ? adj[curr].size() : adj[curr].size()-1;// -1 islie kyunki pichle wala neighbbour cnt ni hoga
            double newProb = prob*(1.0/neighbors);
            double ans = 0;
            for(auto it : adj[curr]){
                if(!vis[it]){
                    ans = max(ans , dfs(it,adj,time-1,target,newProb,vis));
                }
            }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1 , 0);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return dfs(1 , adj , t , target , 1 , vis);
    }
};