
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book {
private:
    std::string title;
    std::string author;
public:
    void setTitle(const std::string& newTitle) {
        if (!newTitle.empty()) title = newTitle;
        else std::cout << "Ошибка: название не может быть пустым!\n";
    }
    void setAuthor(const std::string& newAuthor) {
        if (!newAuthor.empty()) author = newAuthor;
        else std::cout << "Ошибка: автор не может быть пустым!\n";
    }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    void displayInfo() const {
        std::cout << "Книга: " << title << ", автор: " << author << "\n";
    }
};

class Counter {
private:
    int value;
public:
    Counter() : value(0) {}
    void increment() { if (value < 100) value++; }
    void decrement() { if (value > 0) value--; }
    void setValue(int newValue) {
        if (newValue >= 0 && newValue <= 100) value = newValue;
        else std::cout << "Ошибка: значение должно быть от 0 до 100!\n";
    }
    int getValue() const { return value; }
};

class Student {
private:
    std::string name;
    std::vector<int> grades;
public:
    Student(const std::string& studentName) : name(studentName) {}
    void addGrade(int grade) {
        if (grade >= 1 && grade <= 5) grades.push_back(grade);
        else std::cout << "Ошибка: оценка должна быть от 1 до 5!\n";
    }
    double getAverageGrade() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (int grade : grades) sum += grade;
        return sum / grades.size();
    }
    void displayInfo() const {
        std::cout << "Студент: " << name << ", средняя оценка: " << getAverageGrade() << "\n";
    }
};

class BankAccount {
private:
    double balance;
public:
    BankAccount() : balance(0.0) {}
    void deposit(double amount) {
        if (amount > 0) balance += amount;
        else std::cout << "Ошибка: сумма для пополнения должна быть положительной!\n";
    }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        } else {
            std::cout << "Ошибка: недостаточно средств или неверная сумма!\n";
            return false;
        }
    }
    double getBalance() const { return balance; }
};

class Product {
private:
    std::string name;
    double price;
public:
    Product(const std::string& productName, double productPrice)
        : name(productName), price(productPrice) {
        if (price < 0) price = 0;
    }
    void setPrice(double newPrice) {
        if (newPrice >= 0) price = newPrice;
        else std::cout << "Ошибка: цена не может быть отрицательной!\n";
    }
    double getPrice() const { return price; }
    void displayInfo() const {
        std::cout << "Продукт: " << name << ", цена: " << price << " руб.\n";
    }
};

class Player {
private:
    int hp;
    int level;
public:
    Player() : hp(100), level(1) {}
    void takeDamage(int damage) {
        hp = std::max(0, hp - damage);
    }
    void heal(int healAmount) {
        hp = std::min(100, hp + healAmount);
    }
    void levelUp() { level++; }
    void showStats() const {
        std::cout << "Игрок: HP=" << hp << ", уровень=" << level << "\n";
    }
};

class Car {
private:
    std::string brand;
    int speed;
public:
    Car(const std::string& carBrand) : brand(carBrand), speed(0) {}
    void accelerate(int increment) {
        speed = std::max(0, speed + increment);
    }
    void brake(int decrement) {
        speed = std::max(0, speed - decrement);
    }
    void displayStatus() const {
        std::cout << "Автомобиль " << brand << ", скорость: " << speed << " км/ч\n";
    }
};
»
class Teacher {
private:
    std::string name;
    std::string subject;
public:
    Teacher(const std::string& teacherName, const std::string& teacherSubject)
        : name(teacherName), subject(teacherSubject) {}
    void setName(const std::string& newName) {
        if (!newName.empty()) name = newName;
        else std::cout << "Ошибка: имя не может быть пустым!\n";
    }
    void setSubject(const std::string& newSubject) { subject = newSubject; }
    void displayInfo() const {
        std::cout << "Учитель: " << name << ", предмет: " << subject << "\n";
    }
};

class Order {
private:
    std::vector<std::string> items;
    double total;
public:
    Order() : total(0.0) {}
    void addItem(const std::string& item, double price) {
        items.push_back(item);
        total += price;
    }
    double calculateTotal() const { return total; }
    void displayOrder() const {
        std::cout << "Заказ:\n";
        for (const auto& item : items) std::cout << "- " << item << "\n";
        std::cout << "Итого: " << total << " руб.\n";
    }
};

class Card {
private:
    std::string cardNumber;
    double balance;
public:
    Card(const std::string& number, double initialBalance)
        : cardNumber(number), balance(initialBalance) {}
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        std::cout << "Ошибка операции!\n";
        return false;
    }
    void showBalance() const {
        std::cout << "Баланс карты " << cardNumber << ": " << balance << " руб.\n";
    }
};

class Shop {
private:
    std::vector<Product> products;
public:
    void addProduct(const Product& product) { products.push_back(product); }
    void removeProduct(const std::string& productName) {
        products.erase(std::remove_if(products.begin(), products.end(),
            [&](const Product& p) { return p.getPrice() == productName; }),
            products.end());
    }
    void displayAllProducts() const {
        std::cout << "Товары в магазине:\n";
        for (const auto& product : products) product.displayInfo();
    }
};

class Employee {
private:
    std::string name;
    double salary;
public:
    Employee(const std::string& employeeName, double employeeSalary)
        : name(employeeName), salary(employeeSalary) {
        if (salary < 0) salary = 0;
    }
