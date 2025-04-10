#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

class TDemo {
private:
    inline static size_t threadCount{5};
    std::vector<std::thread> threadHolder_;

public:

    auto run() -> void {
        threadHolder_.reserve(threadCount);
        for (int i = 0; i < threadCount; ++i) {
            threadHolder_.emplace_back(&TDemo::worker, this, i,i*1000);
        }
        for(auto & thread : threadHolder_) {
            thread.join();
        }
        std::cout << "Alle Threads beendet" << std::endl;
    }

    auto worker(int id, size_t duration) -> void {
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        std::cout << "Thread Nr. " << id << " terminated" << std::endl;
    }
};


int main() {
    TDemo t;
    t.run();
    return 0;
}
