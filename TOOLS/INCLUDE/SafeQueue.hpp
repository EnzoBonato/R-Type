/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
#define SAFEQUEUE_HPP_

// INCLUDE

#include <queue>
#include <mutex>
#include <condition_variable>

// DEFINE

// CLASS DEFINITION

template <typename T>
class SafeQueue {

    public:

        SafeQueue() = default;
        ~SafeQueue() = default;

        // FUNCTION

        bool empty() noexcept
        {
            std::unique_lock<std::mutex> lock(_mutex);
            bool err;

            err = this->_queue.empty();
            lock.unlock();
            return (err);
        }

        size_t size() noexcept
        {
            std::unique_lock<std::mutex> lock(_mutex);
            size_t size;

            size = this->_queue.size();
            lock.unlock();
            return (size);
        }

        void push(const T &value)
        {
            std::unique_lock<std::mutex> lock(_mutex);

            this->_queue.push(value);
            lock.unlock();
            cond.notify_one();
        }

        T pop()
        {
            std::unique_lock<std::mutex> lock(_mutex);

            while (_queue.empty())
                 cond.wait(lock);
            auto item =_queue.front();
            _queue.pop();
            return item;
        }

    protected:
    private:

        std::mutex _mutex;
        std::queue<T> _queue;
        std::condition_variable cond;
};

#endif /* !SAFEQUEUE_HPP_ */
