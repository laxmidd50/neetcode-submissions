#include <cstring>

class DynamicArray {
public:

    DynamicArray(int capacity) {
        m_data = std::make_unique<int[]>(capacity);
        m_capacity = capacity;
        m_size = 0;
    }

    int get(int i) {
        return m_data[i];
    }

    void set(int i, int n) {
        m_data[i] = n;
    }

    void pushback(int n) {
        if (m_size == m_capacity)
        {
            resize();
        }
        m_data[m_size++] = n;
    }

    int popback() {
        return m_data[--m_size];
    }

    void resize() {
        std::unique_ptr<int[]> temp_arr = std::make_unique<int[]>(m_capacity*2);
        std::memcpy(temp_arr.get(), m_data.get(), m_capacity*sizeof(int));
        m_capacity = m_capacity*2;
        m_data = std::move(temp_arr);
    }

    int getSize() {
        return m_size;
    }

    int getCapacity() {
        return m_capacity;
    }
private:
    std::unique_ptr<int[]> m_data;
    int m_size;
    int m_capacity;
};
