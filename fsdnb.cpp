  
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <cmath>

int main() {

    std::cout << "Задание 1. Вывод элементов:\n";
    std::vector<int> vec1 = {1, 2, 3, 4, 5};

    std::cout << "Через итератор: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Через range-based for: ";
    for (const auto& elem : vec1) {
        std::cout << elem << " ";
    }
    std::cout << "\n\n";

    std::cout << "Задание 2. Поиск элемента:\n";
    int search_num = 3;
    auto found = std::find(vec1.begin(), vec1.end(), search_num);
    if (found != vec1.end()) {
        std::cout << "Число " << search_num << " найдено!\n";
    } else {
        std::cout << "Число " << search_num << " не найдено!\n";
    }
    std::cout << "\n";

    std::cout << "Задание 3. Минимум и максимум:\n";
    auto min_it = std::min_element(vec1.begin(), vec1.end());
    auto max_it = std::max_element(vec1.begin(), vec1.end());
    std::cout << "Минимальный элемент: " << *min_it << "\n";
    std::cout << "Максимальный элемент: " << *max_it << "\n\n";

    std::cout << "Задание 4. Подсчёт значений:\n";
    int count_num = 2;
    int count = std::count(vec1.begin(), vec1.end(), count_num);
    std::cout << "Число " << count_num << " встречается " << count << " раз(а)\n\n";

    std::cout << "Задание 5. Разворот массива:\n";
    std::cout << "До разворота: ";
    for (const auto& elem : vec1) std::cout << elem << " ";
    std::cout << "\n";
    std::reverse(vec1.begin(), vec1.end());
    std::cout << "После разворота: ";
    for (const auto& elem : vec1) std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "Задание 6. Сортировка:\n";
    std::vector<int> vec2 = {5, 2, 8, 1, 9};
    std::sort(vec2.begin(), vec2.end());
    std::cout << "По возрастанию: ";
    for (const auto& elem : vec2) std::cout << elem << " ";
    std::cout << "\n";

    std::sort(vec2.begin(), vec2.end(), [](int a, int b) { return a > b; });
    std::cout << "По убыванию: ";
    for (const auto& elem : vec2) std::cout << elem << " ";
    std::cout << "\n\n";
а
    std::cout << "Задание 7. Удаление элемента:\n";
    std::vector<int> vec3 = {1, 2, 3, 2, 4, 2};
    int remove_num = 2;
    vec3.erase(std::remove(vec3.begin(), vec3.end(), remove_num), vec3.end());
    std::cout << "После удаления всех " << remove_num << ": ";
    for (const auto& elem : vec3) std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "Задание 8. Удаление по условию:\n";
    std::vector<int> vec4 = {5, 15, 3, 20, 8};
    vec4.erase(std::remove_if(vec4.begin(), vec4.end(),
                   [](int x) { return x > 10; }), vec4.end());
    std::cout << "После удаления элементов > 10: ";
    for (const auto& elem : vec4) std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "Задание 9. Уникальные элементы:\n";
    std::vector<int> vec5 = {1, 2, 2, 3, 3, 3, 4};
    std::sort(vec5.begin(), vec5.end());
    auto last = std::unique(vec5.begin(), vec5.end());
    vec5.erase(last, vec5.end());
    std::cout << "Уникальные элементы: ";
    for (const auto& elem : vec5) std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "Задание 10. Квадраты чисел:\n";
    std::vector<int> vec6 = {1, 2, 3, 4, 5};
    std::vector<int> squares(vec6.size());
    std::transform(vec6.begin(), vec6.end(), squares.begin(),
               [](int x) { return x * x; });
    std::cout << "Исходные: ";
    for (const auto& elem : vec6) std::cout << elem << " ";
    std::cout << "\nКвадраты: ";
    for (const auto& elem : squares) std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "Задание 11. Частота элементов:\n";
    std::vector<int> vec7 = {1, 2, 2, 3, 3, 3, 1};
    std::map<int, int> frequency;
    for (const auto& num : vec7) {
        frequency[num]++;
    }
    for (const auto& pair : frequency) {
        std::cout << "Число " << pair.first << " встречается "
                  << pair.second << " раз(а)\n";
    }
    std::cout << "\n";

    std::cout << "Задание 12. Самое частое число:\n";
    int most_frequent = 0;
    int max_count = 0;
    for (const auto& pair : frequency) {
        if (pair.second > max_count) {
            max_count = pair.second;
            most_frequent = pair.first;
        }
    }
    std::cout << "Самое частое число: " << most_frequent
              << " (встречается " << max_count << " раз)\n\n";

    std::cout << "Задание 13. Проверка существования:\n";
    int check_key = 2;
    if (frequency.find(check_key) != frequency.end()) {
        std::cout << "Ключ " << check_key << " существует в map\n";
    } else {
        std::cout << "Ключ " << check_key << " не найден в map\n";
    }
    std::cout << "\n";
