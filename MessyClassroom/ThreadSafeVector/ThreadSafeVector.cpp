#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>

using namespace std;

// Create a class TSV
// Protect main methods with mutex:
// 

class ThreadSafeVector
{
public:
    void push_back(int n)
    {
        lock_guard<mutex> guard(m_mutex);
        m_vector.push_back(n);
    }
    int getFirstElement()
    {
        lock_guard<mutex> guard(m_mutex);
        return m_vector.front();
    }
    int getLastElement()
    {
        lock_guard<mutex> guard(m_mutex);
        return m_vector.back();
    }
    void push_front(int n)
    {
        lock_guard<mutex> guard(m_mutex);
        m_vector.insert(m_vector.begin(), n);
    }
    int getSize()
    {
        lock_guard<mutex> guard(m_mutex);
        return m_vector.size();
    }
    int getCapacity()
    {
        lock_guard<mutex> guard(m_mutex);
        return m_vector.max_size();
    }
    int at(int n)
    {
        lock_guard<mutex> guard(m_mutex);
        return m_vector.at(n);
    }
private:
    vector<int> m_vector;
    mutex m_mutex;
};

int main()
{
    vector<int> v;
}

