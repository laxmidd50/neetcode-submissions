class Singleton {
private:

    Singleton() {}

public:

    static Singleton *getInstance() {
        static Singleton * obj = nullptr;
        if (obj == nullptr)
        {
            obj = new Singleton();
        }
        return obj;
    }

    string getValue() {
        return m_str;
    }

    void setValue(string &value) {
        m_str = value;
    }

private:
    string m_str;
};
