vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses,0); //check if visited
        vector<vector<int>> g(numCourses,vector<int>()); // graph for each vertice and its children
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> result;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){                
                // 0 to check if it the course node is unvisited
                if(!dfs(g,visited,i,result)){ //depth first search (bool value is used to check for cycles)
                    return {};
                }
            }
        }
        return result;
}
    //0,1,2 are states here
bool dfs(vector<vector<int>> &g, vector<int> &visited, int i, vector<int> &result){        
        visited[i]=1;// currently visiting
        for(auto it:g[i]){    
            if(visited[it]==0){
                if(!dfs(g,visited,it,result)) return false;
            }
            if(visited[it]==1) return false;// check for cycle
        }
        result.push_back(i);        
        visited[i]=2;
        return true;
}