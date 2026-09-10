class Solution {
public:
    std::map <char, char> parens{{')','('},
                                     {'}','{'},
                                     {']','['}};
    bool isValid(string s) {
        std::stack<char> stk;
        for (const char & c: s)
        {
            if (isOpen(c))
            {
                stk.push(c);
            }
            else if (isClose(c))
            {
                if (stk.empty())
                    return false;
                char top = stk.top();
                stk.pop();
                if (top != parens[c])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }

    bool isOpen(const char c)
    {
        return (c == '(' || c == '{' || c == '[');
    }

    bool isClose(const char c)
    {
        return (c == ')' || c == '}' || c == ']');
    }
};
