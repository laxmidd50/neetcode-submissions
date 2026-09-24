class Solution {
public:
    string multiply(string num1, string num2) {
        int int1 = toInt(num1);
        int int2 = toInt(num2);
        return toString(int1*int2);
    }

    int toInt(const string & num)
    {
        int x = 0;
        int base = 10;

        for (char c: num)
        {
            x = (x*base) + toInt(c);
        }
        return x;
    }

    int toInt(const char c)
    {
        if (c > '9' || c < '0')
            throw;
        return (c - '0');
    }

    string toString(int x)
    {
        if (x == 0)
            return "0";
        
        string result = "";
        int base = 10;
        while (x > 0)
        {
            int y = x % base;
            x = x/10;
            result = toDigit(y) + result;
        }
        return result;
    }

    char toDigit(int x)
    {
        int base = 10;
        if (x > base-1)
            throw;
        return '0'+x;
    }
};