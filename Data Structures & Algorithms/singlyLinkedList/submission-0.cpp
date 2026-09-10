struct Node {
    int value;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index >= size)
            return -1;
        Node * temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }

    void insertHead(int val) {
        Node *temp = new Node();
        temp->value = val;
        temp->next = head;
        head = temp;

        if (size == 0)
        {
            tail = head;
        }
        size++;
    }
    
    void insertTail(int val) {
        Node *temp = new Node();
        temp->value = val;
        temp->next = nullptr;

        if (size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    bool remove(int index) {
        if (index >= size)
            return false;
        Node *cur = head;
        Node *prev = nullptr;
        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        if (prev != nullptr)
        {
            prev->next = cur->next;
        }
        else
        {
            head = cur->next;
        }
        delete(cur);
        size--;
        if (size == 1)
            tail = head;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node * temp = head;
        while (temp != nullptr)
        {
            values.push_back(temp->value);
            temp = temp->next;
        }
        return values;
    }
private:
    Node *head;
    Node *tail;
    int size;
};
