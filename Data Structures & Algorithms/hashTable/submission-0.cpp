struct Pair {
    int key;
    int value;
};

class HashTable {
public:
    HashTable(int capacity) {
        m_keys = 0;
        m_table.resize(capacity);
    }

    void insert(int key, int value) {
        int bucket = hashFunction(key);
        for (auto x = m_table[bucket].begin(); x != m_table[bucket].end(); x++)
        {
            if (x->key == key)
            {
                x->value = value;
                return;
            }
        }
        m_table[bucket].push_back(Pair(key, value));
        ++m_keys;

        if (loadFactor() >= 0.5)
            resize();
    }

    int get(int key) {
        int bucket = hashFunction(key);
        for (const Pair & x : m_table[bucket])
        {
            if (x.key == key)
            {
                return x.value;
            }
        }
        return -1;
    }

    bool remove(int key) {
        int bucket = hashFunction(key);
        for (auto x = m_table[bucket].begin(); x != m_table[bucket].end(); x++)
        {
            if (x->key == key)
            {
                m_table[bucket].erase(x);
                --m_keys;
                return true;
            }
        }
        return false;
    }

    int getSize() const {
        return m_keys;
    }

    int getCapacity() const {
        return m_table.size();
    }

    void resize() {
        vector<list<Pair>> new_table;
        new_table.resize(m_table.size()*2);
        for (auto vec_it = m_table.begin(); vec_it != m_table.end(); vec_it++)
        {
            for (auto list_it = vec_it->begin(); list_it != vec_it->end(); list_it++)
            {
                int bucket = hashFunction(list_it->key);
                new_table[bucket].push_back(Pair(list_it->key, list_it->value));
            }
        }
        m_table = new_table;
    }

    int hashFunction(int key)
    {
        return key % m_table.size();
    }

    double loadFactor()
    {
        return static_cast<double>(m_keys) / static_cast<double>(m_table.size());
    }

private:
    int m_keys;
    vector<list<Pair>> m_table;
};
