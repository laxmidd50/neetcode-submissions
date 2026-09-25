struct Node {
    int val;
    Node * next;
};

class MinStack {
public:
    MinStack() {
        m_top = nullptr;
        m_min = nullptr;
    }
    
    void push(int val) {
        Node * node = new Node(val, m_top);
        m_top = node;
        if (m_min == nullptr || val < m_min->val)
        {
            Node * minNode = new Node(val, m_min);
            m_min = minNode;
        }
        else
        {
            Node * minNode = new Node(m_min->val, m_min);
            m_min = minNode;
        }
    }
    
    void pop() {
        if (m_top == nullptr)
            return;
        Node * prev = m_top;
        m_top = m_top->next;
        delete(prev);

        if (m_min == nullptr)
            return;
        prev = m_min;
        m_min = m_min->next;
        delete(prev);
    }
    
    int top() {
        if (m_top == nullptr)
            return 0;
        return m_top->val;
    }
    
    int getMin() {
        if (m_min == nullptr)
            return 0;
        return m_min->val;
    }
private:
    Node * m_top;
    Node * m_min;
};
