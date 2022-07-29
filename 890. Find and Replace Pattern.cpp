class Solution {
public:
    bool isMatching(string& word, string pattern)
    {
        unordered_map<char,char>mp;
        set<char>s;
        for(int i=0;i<size(pattern);i++)
        {
            char wch = word[i];
            char pch = pattern[i];
            
            if(mp[pch])
            {
                // pattern char is already mapped
                if(mp[pch]!=wch)return false;
            }
            else{
                if(s.find(wch)!=s.end())return false;
                // pattern char is new for mapping
                mp[pch]=wch;
                s.insert(wch);
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
         if(pattern.size()==0)return res;
        
        
        for(string word:words)
        {
            if(isMatching(word,pattern))
            {
                res.push_back(word);
            }
        }
        return res;
    }
};