class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (grid[i][j] == '1' && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j] = true;
                    ans++;

                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= n || nc >= m || nr < 0 || nc < 0) continue;
                            else if (grid[nr][nc] == '1' && !vis[nr][nc]){
                                q.push({nr, nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
