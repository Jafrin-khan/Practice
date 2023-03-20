class Solution {
public:
    
    /*
Time Complexity: O( 4*N*M * log( N*M) ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the minimum effort and additional log(N*M) for insertion-deletion operations in a priority queue } 

Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.

Space Complexity: O( N*M ) { Distance matrix containing N*M cells + priority queue in the worst case containing all the nodes ( N*M) }.

Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.
    */
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int ,pair<int,int>>> , greater<pair<int ,pair<int,int>>>> pq; //<diff , i , j > 
        pq.push({0 , {0 , 0}});
        
        vector<vector<int>> diffMatrix(n , vector<int>(m,1e9));
        diffMatrix[0][0] = 0;
        
        int dx[4] = {-1 , 1 , 0 , 0};
        int dy[4] = {0 , 0 , -1 , 1};
        
        while(!pq.empty()){
            
            auto front = pq.top();pq.pop();
            
            int diff = front.first;
            int x = front.second.first;
            int y = front.second.second;
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int newEffort = max(diff , abs(heights[nx][ny] - heights[x][y]));
                    
                    if(newEffort < diffMatrix[nx][ny]){
                        diffMatrix[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        
        return diffMatrix[n-1][m-1];
        
    }
};