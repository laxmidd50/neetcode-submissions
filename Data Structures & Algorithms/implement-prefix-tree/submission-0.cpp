struct TrieNode {
    TrieNode() : isWord(false) {};
    unordered_map<char, TrieNode*> charMap;
    bool isWord;
};

class PrefixTree {
public:
    PrefixTree() {
        m_head = new TrieNode();
    }
    
    void insert(string word) {
        if (word == "")
            return;
        TrieNode * curNode = m_head;
        for (char c: word)
        {
            auto tempNode = curNode->charMap.find(c);
            if (curNode->charMap.find(c) != curNode->charMap.end())
            {
                curNode = tempNode->second;
            }
            else
            {
                curNode->charMap[c] = new TrieNode();
                curNode = curNode->charMap[c];
            }
        }
        curNode->isWord = true;
    }
    
    bool search(string word) {
        if (word == "")
            return false;
        TrieNode * curNode = m_head;
        for (char c: word)
        {
            auto tempNode = curNode->charMap.find(c);
            if (curNode->charMap.find(c) == curNode->charMap.end())
            {
                return false;
            }
            curNode = tempNode->second;
        }
        return curNode->isWord;
    }
    
    bool startsWith(string prefix) {
        if (prefix == "")
            return false;
        TrieNode * curNode = m_head;
        for (char c: prefix)
        {
            auto tempNode = curNode->charMap.find(c);
            if (curNode->charMap.find(c) == curNode->charMap.end())
                return false;
            curNode = tempNode->second;
        }
        return true;
    }
private:
    TrieNode * m_head;

};
