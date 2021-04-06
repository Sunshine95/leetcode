class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos){
        
        if(pos == word.size()-1) return true;
        
        int m = board.size();
        int n = board[0].size();
        
        board[i][j] = '*';
        
        bool r, b, l, t;
        r = b = l = t = false;
        
        if(j < n-1){ if(board[i][j+1] == word[pos+1]){ r = dfs(board, i, j+1, word, pos+1); }}
        if(i < m-1){ if(board[i+1][j] == word[pos+1]){ b = dfs(board, i+1, j, word, pos+1); }}
        if(j > 0){ if(board[i][j-1] == word[pos+1]){ l = dfs(board, i, j-1, word, pos+1); }}
        if(i > 0){ if(board[i-1][j] == word[pos+1]){ t = dfs(board, i-1, j, word, pos+1); }}
        
        board[i][j] = word[pos];
        
        return r || b || l || t;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<string> resultSet{};
        for(int w = 0; w < words.size(); w++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == words[w][0]){
                        if(dfs(board, i, j, words[w], 0)){
                            resultSet.push_back(words[w]);
                            goto nextWord;                           
                        }
                    }
                }
            }
            nextWord:
            ;
        }
        
        return resultSet;        
    }
};