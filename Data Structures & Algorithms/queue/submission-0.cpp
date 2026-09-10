struct Node {
    int value;
    Node * prev;
    Node * next;
};

class Deque {
public:
    Deque() {
        m_head = nullptr;
        m_tail = nullptr;
    }

    bool isEmpty() {
        if (m_head == nullptr)
            return true;
        else
            return false;
    }

    void append(int value) {
        Node * temp = new Node(value, nullptr, nullptr);

        if (isEmpty())
        {
            m_head = temp;
            m_tail = temp;
        }
        else
        {
            temp->prev = m_tail;
            m_tail->next = temp;
            m_tail = temp;
        }
    }

    void appendleft(int value) {
        Node * temp = new Node(value, nullptr, nullptr);
        
        if (isEmpty())
        {
            m_head = temp;
            m_tail = temp;
        }
        else
        {
            temp->next = m_head;
            m_head->prev = temp;
            m_head = temp;
        }
    }

    int pop() {
        if (isEmpty())
            return -1;
        Node * temp = m_tail;
        m_tail = m_tail->prev;

        if (m_tail == nullptr)
        {
            m_head = nullptr;
        }
        else
        {
            m_tail->next = nullptr;
        }
        int val = temp->value;
        delete(temp);
        return val;
    }

    int popleft() {
        if (isEmpty())
            return -1;
        Node *temp = m_head;
        m_head = m_head->next;

        if (m_head == nullptr)
        {
            m_tail = nullptr;
        }
        else
        {
            m_head->prev = nullptr;
        }
        int val = temp->value;
        delete(temp);
        return val;
    }

private:
    Node * m_head;
    Node * m_tail;
};
