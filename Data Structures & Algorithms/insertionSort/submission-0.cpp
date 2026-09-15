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
        result.push_back(pairs);
        for (int i = 1; i < pairs.size(); i++)
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

    const void printVector(vector<Pair> & pairs, bool first, bool last) {
        if (first)
            cout << "[";
        cout << "[";
        for (Pair x: pairs)
        {
            cout << "(" << x.value << ")";
        }
        cout << "]";
        if (last)
            cout << "]" << std::endl;
        else
            cout << "," << std::endl;
    }
};
