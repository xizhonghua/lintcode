class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        words.insert(word);
        ws[word.length()].insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.find(".")==string::npos)
            return words.count(word);
        
        auto ss = ws[word.length()];
        for(const auto& w : ss) {
            if(match(word, w)) return true;
        }
        
        return false;
    }
    
    bool match(const string& p, const string& w) {
        for(int i=0;i<p.length();++i) {
            if(p[i] == '.') continue;
            if(p[i] != w[i]) return false;
        }
        return true;
    }
private:
    unordered_set<string> words;
    unordered_map<int, unordered_set<string>> ws;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
