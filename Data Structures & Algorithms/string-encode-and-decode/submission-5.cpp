// 1 Byte length n1, str1[0], str1[1], str1[2], .. str1[n1], n2, str2[0], str2[1], ... str2[n]

class Solution {
public:

    string encode(vector<string>& strs) {
        string enc_str;
        for (const string& str: strs)
        {
            char n = static_cast<char>(str.length());
            std::cout << "n:" << static_cast<int>(n) << " ";
            enc_str += n;
            enc_str += str;
        }
        std::cout << std::endl << "enc_str:" << enc_str << std::endl;
        return enc_str;
    }

    vector<string> decode(string s) {
        vector<string> dec_str;
        int i = 0;
        while (i < s.length())
        {
            int n = static_cast<unsigned char>(s[i++]);
            string temp_str = s.substr(i, n);
            dec_str.push_back(temp_str);
            i += n;
            std::cout << "dec_n:" << n << " dec_string:" << temp_str << std::endl;
        }
        return dec_str;
    }
};
