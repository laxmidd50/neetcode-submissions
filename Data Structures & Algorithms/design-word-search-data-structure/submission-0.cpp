struct TrieNode {
    unordered_map<char, TrieNode *> charMap;
};

class WordDictionary {
public:
    WordDictionary() {
        m_head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * curNode = m_head;
        for (char c: word)
        {
            auto mapIter = curNode->charMap.find(c);
            if (mapIter != curNode->charMap.end())
            {
                curNode = mapIter->second;
            }
            else
            {

                curNode->charMap[c] = new TrieNode();
                curNode = curNode->charMap[c];
            }
        }
    }
    
    bool search(string word) {
        return searchRecurse(word, m_head);
    }

    bool searchRecurse(string word, TrieNode * curNode) {
        if (word == "")
            return true;
        
        char c = word[0];
        string subStr;
        if (word.size() <= 1)
            subStr = "";
        else
            subStr = word.substr(1, word.size()-1);

        if (c == '.')
        {
            for (auto mapIter = curNode->charMap.begin(); mapIter != curNode->charMap.end(); mapIter++)
            {
                if (searchRecurse(subStr, mapIter->second) == true)
                    return true;
            }
            return false;
        }
        else
        {
            auto mapIter = curNode->charMap.find(c);
            if (mapIter == curNode->charMap.end())
            {
                return false;
            }
            else
            {
                return searchRecurse(subStr, mapIter->second);
            }
        }
    }
private:
    TrieNode * m_head;
};
