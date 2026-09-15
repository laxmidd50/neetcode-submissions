struct Node {
    int key;
    int val;
    Node * left;
    Node * right;
};

class TreeMap {

public:
    TreeMap() {
        m_head = nullptr;
    }

    void insert(int key, int val) {
        if (m_head == nullptr)
        {
            m_head = new Node(key, val, nullptr, nullptr);
            return;
        }

        Node * temp = m_head;

        while (true)
        {
            if (key == temp->key)
            {
                temp->val = val;
                return;
            }
            else if (key > temp->key)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(key, val, nullptr, nullptr);
                    return;
                }
                else
                    temp = temp->right;
            }
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(key, val, nullptr, nullptr);
                    return;
                }
                else
                    temp = temp->left;
            }
        }
    }

    int get(int key) {
        Node * temp = m_head;
        while (temp != nullptr && temp->key != key)
        {
            if (key < temp->key)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (temp == nullptr)
            return -1;
        else
            return temp->val;
    }

    int getMin() {
        if (m_head == nullptr)
            return -1;
        Node * temp = m_head;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->val;
    }

    int getMax() {
        if (m_head == nullptr)
            return -1;
        Node * temp = m_head;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->val;
    }

    void remove(int key) {
        m_head = deleteNode(m_head, key);
    }

    Node* getSuccessor(Node * root)
    {
        root = root->right;
        while (root != nullptr && root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node * root, int key)
    {
        if (root == nullptr)
            return root;
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            if (root->right == nullptr && root->left == nullptr)
            {
                delete(root);
                return nullptr;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node* temp = getSuccessor(root);
                root->key = temp->key;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->key);
                return root;
            }
        }

    }

    std::vector<int> getInorderKeys() {
        return getInorderKeysRecursive(m_head);
    }

    std::vector<int> getInorderKeysRecursive(Node* root)
    {
        std::vector<int> leftVec, rightVec;
        if (root == nullptr)
            return leftVec;
        leftVec = getInorderKeysRecursive(root->left);
        leftVec.push_back(root->key);
        rightVec = getInorderKeysRecursive(root->right);
        leftVec.insert(leftVec.end(), rightVec.begin(), rightVec.end());
        return leftVec;
    }

private:
    Node * m_head;
};
