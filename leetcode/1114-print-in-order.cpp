class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(m_mutex);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++counter;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(m_mutex);
        cv1.wait(lk, [this](){return counter == 2;});

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++counter;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(m_mutex);
        cv2.wait(lk, [this](){return counter == 3;});
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    std::mutex m_mutex;
    int counter = 1;
    std::condition_variable cv1;
    std::condition_variable cv2;

};