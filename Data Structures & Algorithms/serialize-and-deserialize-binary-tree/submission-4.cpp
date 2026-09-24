/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial = "[";
        std::queue<std::pair<TreeNode*, int>> node_queue;
        int prevIdx = 0;
        node_queue.push({root, 1});

        while (!node_queue.empty())
        {
            std::pair<TreeNode*, int> nodePair = node_queue.front();
            node_queue.pop();
            std::cerr << "data:" << nodePair.first << ", idx:" << nodePair.second << ", prevIdx:" << prevIdx << std::endl;

            while (++prevIdx < nodePair.second)
                appendString(nullptr, serial);

            appendString(nodePair.first, serial);

            if (nodePair.first != nullptr)
            {
                if (nodePair.first->left != nullptr)
                    node_queue.push({nodePair.first->left, nodePair.second*2});
                if (nodePair.first->right != nullptr)
                    node_queue.push({nodePair.first->right, nodePair.second*2+1});
            }
        }

        while (!(isPowerOf2(++prevIdx)))
        {
            appendString(nullptr, serial);
        }
        serial += "]";
        std::cerr << "Serial:" << serial << std::endl;
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        std::queue<TreeNode*> treeQueue = parseString(data);
        std::queue<TreeNode*> ptrQueue = treeQueue;

        if (treeQueue.empty())
            return root;
        
        root = ptrQueue.front();
        ptrQueue.pop();

        while (!ptrQueue.empty() && !treeQueue.empty())
        {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if (node == nullptr)
            {
                ptrQueue.pop();
                ptrQueue.pop();
            }
            else
            {
                node->left = ptrQueue.front();
                ptrQueue.pop();
                node->right = ptrQueue.front();
                ptrQueue.pop();
            }
        }
        return root;
    }

private:
    void appendString(TreeNode* node, string & serial)
    {
        if (serial.length() > 1)
            serial.append(",");
        
        if (node == nullptr)
            serial.append("null");
        else
            serial.append(std::to_string(node->val));
    }

    std::queue<TreeNode*> parseString(const string & data)
    {
        std::queue<TreeNode*> treeQueue;
        int idx = 0;
        while (idx < data.size())
        {
            if (!std::isalnum(data[idx]))
            {
                ++idx;
                continue;
            }

            int count = 1;
            while (idx+count < data.size() && std::isalnum(data[idx+count]))
                count++;
            std::string str = data.substr(idx, count);
            idx += count;
            if (str == "null")
            {
                treeQueue.push(nullptr);
            }
            else
            {
                treeQueue.push(new TreeNode(stoi(str), nullptr, nullptr));
            }
        }
        return treeQueue;
    }

    bool isPowerOf2(int x)
    {
        while (x > 1)
        {
            if (x % 2 != 0)
                return false;
            x = x / 2;
        }
        return true;
    }
};