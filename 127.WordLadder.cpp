class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> set;
        queue<string> q;
        string word, temp;
        int level, count;        
        
        for(string t : wordList){
            set.insert(t);
        }
        
        if(set.find(endWord) == set.end()) return 0;
        if(set.find(beginWord) != set.end()) set.erase(beginWord);
        
        q.push(beginWord);
        count = q.size();
        level = 1;
        
        while(!q.empty()){
            
            word = q.front();
            q.pop();
            
            for(int i = 0; i < word.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == word[i]) continue;                    
                    
                    temp = word;
                    temp[i] = c;
                    
                    if(set.find(temp) != set.end()){ 
                        if(temp == endWord) return level + 1;    
                        q.push(temp);
                        set.erase(temp);
                    }
                }
            }
            
            if(--count == 0){
                count = q.size();
                level++;
            }
        }
        
        return 0;
        
    }
};