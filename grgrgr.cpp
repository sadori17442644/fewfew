#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void partialSum(const std::vector<int>& arr, size_t start, size_t end, long long& result) {
    result = 0;
    for (size_t i = start; i < end; ++i) {
        result += arr[i];
    }
}

int main() {
    const size_t N = 8000000;
    std::vector<int> arr(N);

    for (size_t i = 0; i < N; ++i) {
        arr[i] = i;
    }

    auto t1 = std::chrono::high_resolution_clock::now();

    long long sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    double timeSingle = std::chrono::duration<double>(t2 - t1).count();

    std::cout << "Single-thread sum = " << sum << "\n";
    std::cout << "Time = " << timeSingle << " sec\n";

    t1 = std::chrono::high_resolution_clock::now();

    long long sum1 = 0, sum2 = 0;
    std::thread t1Thread(partialSum, std::ref(arr), 0, N / 2, std::ref(sum1));
    std::thread t2Thread(partialSum, std::ref(arr), N / 2, N, std::ref(sum2));

    t1Thread.join();
    t2Thread.join();

    long long twoThreadSum = sum1 + sum2;

    t2 = std::chrono::high_resolution_clock::now();
    double timeTwo = std::chrono::duration<double>(t2 - t1).count();

    std::cout << "Two-thread sum = " << twoThreadSum << "\n";
    std::cout << "Time = " << timeTwo << " sec\n";

    std::cout << "\nОтветы на вопросы:\n";
    std::cout << "1. Ускорение было, но не в 2 раза.\n";
    std::cout << "2. Из-за накладных расходов на создание потоков и синхронизации.\n";
    std::cout << "3. Модель MIMD (Multiple Instruction, Multiple Data).\n";

    return 0;
}
