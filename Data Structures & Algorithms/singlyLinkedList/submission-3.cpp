struct Node {
    int val;
    Node * next;
};

class LinkedList {
public:
    LinkedList() {
        m_head = nullptr;
    }

    int get(int index) {
        Node * curNode = m_head;
        for (int i = 0; i < index && curNode != nullptr; i++)
        {
            curNode = curNode->next;
        }
        if (curNode == nullptr)
            return -1;
        return curNode->val;
    }

    void insertHead(int val) {
        Node * newNode = new Node(val, m_head);
        m_head = newNode;
    }
    
    void insertTail(int val) {
        Node * newNode = new Node(val, nullptr);
        Node * curNode = m_head;

        if (curNode == nullptr)
        {
            newNode->next = m_head;
            m_head = newNode;
            return;
        }
        
        while (curNode->next != nullptr)
        {
            curNode = curNode->next;
        }
        curNode->next = newNode;        
    }

    bool remove(int index) {
        Node * curNode = m_head;
        Node * prevNode = nullptr;
        for (int i = 0; i < index && curNode != nullptr; i++)
        {
            prevNode = curNode;
            curNode = curNode->next;
        }
        if (curNode == nullptr)
            return false;
        if (prevNode != nullptr)
        {
            prevNode->next = curNode->next;
        }
        else
        {
            m_head = curNode->next;
        }
        delete(curNode);
        return true;
    }

    vector<int> getValues() {
        Node * curNode = m_head;
        vector<int> vals;

        while (curNode != nullptr)
        {
            vals.push_back(curNode->val);
            curNode = curNode->next;
        }
        return vals;
    }
private:
    Node * m_head;
};
