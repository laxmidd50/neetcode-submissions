class Singleton {
private:

    Singleton() {}

public:

    static Singleton *getInstance() {
        static Singleton obj;
        return &obj;
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
