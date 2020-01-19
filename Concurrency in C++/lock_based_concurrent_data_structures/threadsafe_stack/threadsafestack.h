#ifndef THREADSAFESTACK_H
#define THREADSAFESTACK_H

#include <stack>
#include <mutex>
#include <iostream>
#include <stdexcept>
#include <memory>   // std::share_ptr
#include <utility>  // std::move

template<typename T>
class ThreadSafeStack
{
    public:
        ThreadSafeStack()
        {
            std::cout << "Construct\n";
        }
        ~ThreadSafeStack()
        {
            std::cout << "Destruct\n";
        }

        ThreadSafeStack(const ThreadSafeStack& other)
        {
            std::lock_guard<std::mutex> lock(other.m);
            data = other.data;
        }

        ThreadSafeStack& operator=(const ThreadSafeStack&) = delete;

        void push(T new_value)
        {
            std::lock_guard<std::mutex> lock(m);
            data.push(std::move(new_value));
        }

        T top()
        {
            std::lock_guard<std::mutex> lock(m);
            if(data.empty()){
                throw std::runtime_error("stack is empty.\n");
            }
            std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
            return *res.get();
        }

        void pop()
        {
            std::lock_guard<std::mutex> lock(m);
            if(data.empty()){
                throw std::runtime_error("stack is empty.\n");
            }
            data.pop();
            return ;
        }

        void pop(T& value)
        {
            std::lock_guard<std::mutex> lock(m);
            if(data.empty()){
                throw std::runtime_error("stack is empty.\n");
            }
            value = data.top();
            data.pop();
        }

        bool empty() const
        {
            std::lock_guard<std::mutex> lock(m);
            return data.empty();
        }

        int size() const
        {
            std::lock_guard<std::mutex> lock(m);
            return data.size();
        }

    private:
        std::stack<T> data;
        mutable std::mutex m;

};

#endif // THREADSAFESTACK_H
