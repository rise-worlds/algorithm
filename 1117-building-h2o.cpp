class H2O {
public:
    H2O() {
        m_h = 0;
        m_o = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock<mutex> lock(this->mtx);
        cv1.wait(lock, [this]{ return m_h < m_o * 2 + 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++m_h;
        cv2.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock<mutex> lock(this->mtx);
        cv2.wait(lock, [this]{ return m_o < m_h / 2 + 1; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++m_o;
        cv1.notify_one();
    }
private:
    int m_h, m_o;
    mutex mtx;
    condition_variable cv1, cv2;
};
