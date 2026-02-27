//There is a Value data type that works in a single - threaded environment.
//Make changes so that it works as efficiently as possible in a multi - threaded environment.

//class Value
//{
//private:
//    int m_value{};

//public:
//    Value() {}
//    int getValue() const
//    {
//        return m_value;
//    }
//    void updateValue(int value)
//    {
//        m_value = value;
//    }
//}
//
//

#include <atomic>

class Value
{
private:
    std::atomic<int> m_value{}; // atomic ensures thread safety

public:
    Value() = default;

    // Thread-safe getter
    int getValue() const
    {
        return m_value.load(); // load value atomically
    }

    // Thread-safe setter
    void updateValue(int value)
    {
        m_value.store(value); // store value atomically
    }
};
