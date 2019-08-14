#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

using namespace std;

class FooBar
{
private:
    int n;
    mutex mtx;
    condition_variable cv1, cv2;
    bool ready = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        unique_lock<mutex> lock(this->mtx);
        for (int i = 0; i < n; i++) {
            cv1.wait(lock, [this]{return !ready;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ready = true;
            cv2.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        unique_lock<mutex> lock(this->mtx);
        for (int i = 0; i < n; i++) {
            cv2.wait(lock, [this]{return ready;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ready = false;
            cv1.notify_one();
        }
    }
};

int main()
{
    mutex mtx;
    unique_lock<mutex> lock(mtx);
    condition_variable cv;
    std::atomic<int> count = 0;

    FooBar fb(10);
    std::thread t1(&FooBar::foo, &fb, [&count]() { std::cout << "foo"; count++; });
    std::thread t2(&FooBar::bar, &fb, [&count]() { std::cout << "bar"; count++; });
    cv.wait(lock, [&count] { return count == 2 * 10; });

    return 0;
}