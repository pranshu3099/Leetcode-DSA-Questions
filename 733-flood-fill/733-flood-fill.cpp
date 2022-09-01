class Solution {
public:
    
       void DFS(int row, int col, int color, vector<vector<int>>&image, vector<vector<int>>&ans,int delrow[], int delcol[], int ini ){
           ans[row][col] = color;
           int n = image.size();
           int m = image[0].size();
           for(int i=0;i<4;i++){
               int nrow = row + delrow[i];
               int ncol = col + delcol[i];
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && ans[nrow][ncol]!=color ){
                   DFS(nrow, ncol, color,image, ans, delrow, delcol, ini);
               }
           }
       } 
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    vector<vector<int>>ans = image;
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    int ini = image[sr][sc];
    DFS(sr, sc , color, image,ans,delrow,delcol,ini );
    return ans;
    }
};