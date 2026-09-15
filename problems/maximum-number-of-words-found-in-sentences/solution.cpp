class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = 0;
        
        for(string s : sentences){
            int word=1;

            for(char c : s){
                if(c == ' '){
                    word++;
                }
            }
            mx = max(mx, word);
        }
        return mx;
    }
};