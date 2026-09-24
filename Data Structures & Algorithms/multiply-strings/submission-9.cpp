class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        if (isLeftBigger(num1, num2))
            multiply(num1, num2, result);
        else
            multiply(num2, num1, result);
        return result;
    }
private:
    int m_base = 10;

    void multiply(string & num1, string & num2, string & result)
    {
        if (num1 == "0" || num2 == "0")
        {
            result = "0";
            return;
        }
        for (int i = num2.size()-1; i >= 0; i--)
        {
            int x = toInt(num2[i]);
            int carry = 0;
            string res1 = "";
            for (int j = num1.size()-1; j >= 0 || carry > 0; j--)
            {
                int y = getDigitInt(num1, j);
                y = (y * x) + carry;
                carry = y / m_base;
                y = y % m_base;
                res1 = toDigit(y) + res1;
                //cout << "i: " << i << " j:" << j << " y:" << y << " carry:" << carry << " res1:" << res1 << std::endl;
            }
            result = add(res1, result);
            //cout << "result:" << result << std::endl;
            num1 = num1 + "0";
        }
    }

    string add(const string & num1, const string & num2)
    {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string result;
        //std::cout << "num1:" << num1 << " num2:" << num2 << std::endl;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = getDigitInt(num1, i--);
            int y = getDigitInt(num2, j--);
            int z = y + x + carry;
            carry = z / m_base;
            z = z % m_base;
            result = toDigit(z) + result;
            //cout << "x:" << x << " y:" << y << " z:" << z << " carry:" << carry << std::endl;
        }
        return result;
    }

    bool isLeftBigger(const string & left, const string & right)
    {
        if (left.size() > right.size())
            return true;
        else if (right.size() > left.size())
            return false;
        else
        {
            for (int i = 0; i < left.size(); i++)
            {
                char l = left[i];
                char r = right[i];
                if (l > r)
                    return true;
                else if (r > l)
                    return false;
            }
            return false;
        }
    }

    int getDigitInt(const string & str, int index)
    {
        if (str.size() == 0 || index < 0 || index >= str.size())
            return 0;

        return toInt(str[index]);
    }

    int toInt(const char c)
    {
        return (c - '0');
    }

    char toDigit(int x)
    {
        if (x > m_base-1)
            throw;
        return '0'+x;
    }
};