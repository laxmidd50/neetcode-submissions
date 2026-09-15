// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> result;
        for (int i = 0; i < pairs.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i].key < pairs[j].key)
                {
                    Pair temp(pairs[i]);
                    pairs.erase(pairs.begin()+i);
                    pairs.insert(pairs.begin()+j, temp);
                    break;
                }
            }
            result.push_back(pairs);
        }
        return result;
    }
};
