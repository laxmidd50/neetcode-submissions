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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        return recurseMerge(pairs);
    }

    vector<Pair> recurseMerge(const vector<Pair> & pairs) {
        vector<Pair> merged;
        merged.reserve(pairs.size());
        if (pairs.size() <= 1) {
            merged = pairs;
        }
        else {
            int half = pairs.size() / 2;
            vector<Pair> left(pairs.begin(), pairs.begin()+half);
            vector<Pair> right(pairs.begin()+half, pairs.end());
            left = recurseMerge(left);
            right = recurseMerge(right);
            int l = 0;
            int j = 0;
            for (int i = 0; i < pairs.size(); i++)
            {
                if (l >= left.size())
                {
                    merged.push_back(right[j++]);
                }
                else if (j >= right.size())
                {
                    merged.push_back(left[l++]);
                }
                else if (left[l].key <= right[j].key)
                {
                    merged.push_back(left[l++]);
                }
                else
                {
                    merged.push_back(right[j++]);
                }
            }
        }
        return merged;
    }

    void printVec(const vector<Pair> & vec)
    {
        std::cerr << "[";
        for (Pair x: vec)
        {
            std::cerr << "(" << x.key << ", \"" << x.value << "\")";
        }
        std:: cerr << "]" << std::endl;
    }
};
