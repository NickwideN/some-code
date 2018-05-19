#include<iostream>
#include<deque>
#include<cstring> // strcmp

using namespace std;

template<typename value_type> class Deque 
{
private:
    deque<value_type> deq;
    typedef value_type & reference;
    typedef int size_type;
    void check() 
    {
        if (deq.empty())
        {
            throw DequeEmptyException();
        }
    }
public:
    class DequeEmptyException {};

    void push_front(const value_type& val) 
    {
        this->deq.push_front(val);
    }
    void push_back(const value_type& val) 
    {
        this->deq.push_back(val);
    }
    void pop_front() 
    {
        this->check();
        this->deq.pop_front();
    }
    void pop_back()
    {
        this->check();
        this->deq.pop_back();
    }
    reference front() 
    {
        this->check();
        return this->deq.front();
    }
    reference back() 
    {
        this->check();
        return this->deq.back();
    }
    size_type size() const noexcept
    {
        return deq.size();
    }
    void clear() noexcept
    {
        deq.clear();
    }
};

void execute_command(char command[11], Deque<int> & deq)
{
    if (!strcmp(command, "push_front"))
    {
        int value;
        cin >> value;
        deq.push_front(value);
        cout << "ok\n";
    }
    else if (!strcmp(command, "push_back")) 
    {
        int value;
        cin >> value;
        deq.push_back(value);
        cout << "ok\n";
    }
    else if (!strcmp(command, "pop_front"))
    {
        cout << deq.front() << '\n';
        deq.pop_front();
    }
    else if (!strcmp(command, "pop_back"))
    {
        cout << deq.back() << '\n';
        deq.pop_back();
    }
    else if (!strcmp(command, "back"))
    {
        cout << deq.back() << '\n';
    }
    else if (!strcmp(command, "front"))
    {
        cout << deq.front() << '\n';
    }
    else if (!strcmp(command, "size")) 
    {
        cout << deq.size() << '\n';
    }
    else if (!strcmp(command, "clear"))
    {
        deq.clear();
        cout << "ok\n";
    }
}

int main()
{
    int command_cnt;
    cin >> command_cnt;
    Deque<int> deq;
    for (int i = 0; i < command_cnt; ++i) 
    {
        try
        {
            char command[11];
            cin >> command;
            execute_command(command, deq);
        }
        catch (...) 
        {
            cout << "error\n";
        }
    }
    getchar();
    getchar();
    return 0;
}