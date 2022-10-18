#include "lab3.hpp"
#include "lab3.cpp"
#include <thread>
#include <random>
#include <iomanip>
using namespace Lab3;

class Profiler final {
public:
    Profiler() {
        mBegin = std::chrono::steady_clock::now();
    }

    Profiler(const Profiler&) = delete;

    ~Profiler() {
        auto end = std::chrono::steady_clock::now();
        std::cout << "Elapsed in: " <<
                  std::chrono::duration_cast<std::chrono::seconds>(end - mBegin).count() << " sec or " <<
                  std::chrono::duration_cast<std::chrono::milliseconds>(end - mBegin).count() << "ms or " <<
                  std::chrono::duration_cast<std::chrono::microseconds>(end - mBegin).count() << "microsec\n";
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> mBegin;
};

template<class T>
void Print(Storage<T>& storage) {
    for (auto begin = storage.Begin(); begin != storage.End(); ++begin) {
        std::cout << std::fixed << std::setprecision(2) << *begin << " ";
    }
    std::cout << std::endl;
}

void RandomActions(uint32_t count) {
    srand(time(NULL));
    std::random_device device;
    std::mt19937 gen{device()};
    std::uniform_real_distribution<float> range(0.f, 1.f);
    float result =  .0f;

    Storage<float> storage;
    Profiler profile;
    for (uint32_t i = 0; i < count; ++i) {
        result = range(gen);
        if(result < 0.25) {
            std::cout << "Push: " << result << std::endl;
            storage.Push(result);
        }
        else if (result < 0.5) {
            auto index = (storage.GetSize() - 1);
            std::cout << "Pop: " << storage.GetSize() << " size, " << storage.GetCapacity() << " cap " << index << " id\n";
            storage.Pop(index);
        }
        else if (result <  0.75) {
            std::cout << "Print\n";
            Print(storage);
        }
    }
}

void ActionBegin(uint32_t count) {
    std::cout << "Action count: " << count << std::endl;
    RandomActions(count);
    system("pause");
}

int main() {
    while (true) {
        ActionBegin(100);
        ActionBegin(1000);
        ActionBegin(10000);
        system("cls");
    }
    return 0;
}
