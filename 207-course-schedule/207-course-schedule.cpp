class Solution {
public:
    
       bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool> path, int node)
    {
        visited[node] = true;
        path[node] = true;
        bool t = false;
        for(auto nbr: graph[node])
        {
            if (path[nbr] == true)
                return true;
            
            if (!visited[nbr])
            {
                t = dfs(graph, visited, path, nbr);
                if (t)
                    return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        //construct the graph 
        //Adjacency List 
        vector<vector<int>> graph(numCourses);
        
        for(auto pre: prerequisites)
            graph[pre[1]].push_back(pre[0]);
        
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        //call dfs and check for cycles
        for(int i = 0 ; i < numCourses ; i++)
        {
            if (!visited[i] && dfs(graph, visited, path, i))
                return false;
        }
        
        return true;
    }
};