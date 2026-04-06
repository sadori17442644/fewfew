
#include <iostream>
#include <cstdlib>
#include <chrono>

#define PI 3.14159

#define SUM(a, b) ((a) + (b))

#define MULTIPLY_BAD(a, b) a * b
#define MULTIPLY_GOOD(a, b) ((a) * (b))

#define SQUARE(x) ((x) * (x))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define DEBUG
#ifdef DEBUG
#define DEBUG_LOG(x) std::cout << "[DEBUG] " << x << std::endl
#else
#define DEBUG_LOG(x)
#endif

#ifdef DEBUG
    const char* debug_msg = "Debug mode ON";
#else
    const char* debug_msg = "";
#endif

#ifndef RELEASE
    const char* release_msg = "RELEASE not defined";
#else
    const char* release_msg = "RELEASE defined";
#endif

#define VERSION 1
#if VERSION == 1
    const char* version_msg = "v1";
#else
    const char* version_msg = "other version";
#endif

#ifndef UNIFIED_MACROS_H
#define UNIFIED_MACROS_H
class UnifiedMacrosClass {
public:
    void demonstrateMacros();
};
#endif

#define LOG(x) \
    std::cout << __FILE__ << ":" << __LINE__ << " - " << x << std::endl

#define PRINT(x) std::cout << #x << " = " << (x) << std::endl

#define PASTE(a, b) a ## b
#define MAKE_VAR(name, num) PASTE(name, num)

#define STRINGIFY(x) #x

#define CHECK(x) \
    do { \
        if (!(x)) { \
            std::cerr << "CHECK failed: " << #x \
                      << " at " << __FILE__ \
                      << ":" << __LINE__ << std::endl; \
            exit(1); \
        } \
    } while(0)

#define SAFE_DELETE(ptr) \
    do { \
        delete ptr; \
        ptr = nullptr; \
    } while(0)

#define TIMER_START \
    auto start = std::chrono::high_resolution_clock::now();
#define TIMER_END \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); \
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

#define CHECK_PTR(p) \
    do { \
        if (!p) { \
            std::cerr << "Null pointer check failed at " \
                      << __FILE__ << ":" << __LINE__ << std::endl; \
            exit(1); \
        } \
    } while(0)

#define SIMPLE_ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << #condition \
                      << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
            exit(1); \
        } \
    } while(0)

#ifdef DEBUG
#define DEBUG_LOG_FULL(msg) \
    std::cout << "[DEBUG] " << __FILE__ << ":" << __LINE__ << " - " << msg << std::endl
#else
#define DEBUG_LOG_FULL(msg)
#endif

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ МАКРОСОВ ===\n\n";

    std::cout << "Блок 1 — Базовый уровень:\n";
    std::cout << "1. PI = " << PI << "\n";
    std::cout << "2. SUM(5, 3) = " << SUM(5, 3) << "\n";
    int x = 2 + 3, y = 4 + 5;
    std::cout << "3. MULTIPLY_BAD(x, y) = " << MULTIPLY_BAD(x, y) << " (ошибка приоритетов)\n";
    std::cout << "   MULTIPLY_GOOD(x, y) = " << MULTIPLY_GOOD(x, y) << " (исправлено)\n";
    std::cout << "4. SQUARE(5) = " << SQUARE(5) << "\n";
    std::cout << "5. MIN(10, 7) = " << MIN(10, 7) << "\n\n";

    std::cout << "Блок 2 — Работа с препроцессором:\n";
    DEBUG_LOG("Это сообщение появится только в DEBUG режиме");
    std::cout << "7. " << debug_msg << "\n";
    std::cout << "8. " << release_msg << "\n";
    std::cout << "9. " << version_msg << "\n\n";

    std::cout << "Блок 3 — Продвинутые макросы:\n";
    LOG("Сообщение с указанием файла и строки");
    int myVar = 42;
    PRINT(myVar);
    int MAKE_VAR(var, 1) = 10;
    int MAKE_VAR(var, 2) = 20;
    std::cout << "13. var1 = " << var1 << ", var2 = " << var2 << "\n";
    std::cout << "14. STRINGIFY(Hello World) = " << STRINGIFY(Hello World!) << "\n";
    CHECK(5 > 3); 
    std::cout << "15. CHECK прошёл успешно\n\n";

    std::cout << "Блок 4 — Практические кейсы:\n";
    int* ptr = new int(100);
    CHECK_PTR(ptr);
    std::cout << "18. Указатель проверен\n";
    SIMPLE_ASSERT(2 + 2 == 4);
    std::cout << "19. Assert прошёл успешно\n";
    TIMER_START
    for (int i = 0; i < 1000000; ++i) {
    }
    TIMER_END
    SAFE_DELETE(ptr);
    std::cout << "16. Указатель удалён и установлен в nullptr\n";
    DEBUG_LOG_FULL("Полное debug-сообщение с файлом и строкой");

    std::cout << "\n=== ВСЕ МАКРОСЫ ПРОДЕМОНСТРИРОВАНЫ ===\n";
    return 0;
}
