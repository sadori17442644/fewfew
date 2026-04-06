#include <iostream>
#include <string>
#include <cmath>

class Number {
private:
    int value;
public:
    Number(int val) : value(val) {}
    friend void printValue(const Number& num);
};

void printValue(const Number& num) {
    std::cout << "Значение: " << num.value << "\n";
}

class Value {
private:
    int data;
public:
    Value(int d) : data(d) {}
    int getData() const { return data; }
    friend Value addValues(const Value& v1, const Value& v2);
};

Value addValues(const Value& v1, const Value& v2) {
    return Value(v1.data + v2.data);
}

class Data {
private:
    int value;
public:
    Data(int val) : value(val) {}
    int getValue() const { return value; }
    friend Data maxData(const Data& d1, const Data& d2);
};

Data maxData(const Data& d1, const Data& d2) {
    return (d1.value > d2.value) ? d1 : d2;
}

class Point {
private:
    int x, y;
public:
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    friend bool areEqual(const Point& p1, const Point& p2);
};

bool areEqual(const Point& p1, const Point& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

class Multiplier {
private:
    int value;
public:
    Multiplier(int val) : value(val) {}
    int getValue() const { return value; }
    friend Multiplier multiply(const Multiplier& m1, const Multiplier& m2);
};

Multiplier multiply(const Multiplier& m1, const Multiplier& m2) {
    return Multiplier(m1.value * m2.value);
}

class NumberDiff {
private:
    int value;
public:
    NumberDiff(int val) : value(val) {}
    int getValue() const { return value; }
    friend NumberDiff subtract(const NumberDiff& n1, const NumberDiff& n2);
};

NumberDiff subtract(const NumberDiff& n1, const NumberDiff& n2) {
    return NumberDiff(n1.value - n2.value);
}

class Container {
private:
    int data;
public:
    Container(int val) : data(val) {}
    void display() const { std::cout << "Данные: " << data << "\n"; }
    friend void swapContainers(Container& c1, Container& c2);
};

void swapContainers(Container& c1, Container& c2) {
    int temp = c1.data;
    c1.data = c2.data;
    c2.data = temp;
}

class ValueMin {
private:
    int value;
public:
    ValueMin(int val) : value(val) {}
    int getValue() const { return value; }
    friend ValueMin minOfThree(const ValueMin& v1, const ValueMin& v2, const ValueMin& v3);
};

ValueMin minOfThree(const ValueMin& v1, const ValueMin& v2, const ValueMin& v3) {
    int min_val = v1.value;
    if (v2.value < min_val) min_val = v2.value;
    if (v3.value < min_val) min_val = v3.value;
    return ValueMin(min_val);
}

class Employee {
private:
    std::string name;
    double salary;
public:
    Employee(const std::string& n, double s) : name(n), salary(s) {}
    std::string getName() const { return name; }
    double getSalary() const { return salary; }
    friend Employee higherSalary(const Employee& e1, const Employee& e2);
};

Employee higherSalary(const Employee& e1, const Employee& e2) {
    return (e1.salary > e2.salary) ? e1 : e2;
}
class PointDist {
private:
    int x, y;
public:
    PointDist(int x_val, int y_val) : x(x_val), y(y_val) {}
    friend int distance(const PointDist& p1, const PointDist& p2);
};

int distance(const PointDist& p1, const PointDist& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

class Box {
private:
    int size;
public:
    Box(int s) : size(s) {}
    int getSize() const { return size; }
    friend Box operator+(const Box& b1, const Box& b2);
};

Box operator+(const Box& b1, const Box& b2) {
    return Box(b1.size + b2.size);
}

class User {
private:
    std::string username;
    int id;
public:
    User(const std::string& name, int user_id) : username(name), id(user_id) {}
    friend bool operator==(const User& u1, const User& u2);
};

bool operator==(const User& u1, const User& u2) {
    return (u1.username == u2.username && u1.id == u2.id);
}

class Product {
private:
    std::string name;
    double price;
public:
    Product(const std::string& p_name, double p_price) : name(p_name), price(p_price) {}
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
};

std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << "Товар: " << p.name << ", цена: " << p.price << " руб.\n";
    return os;
}

class Student {
private:
    std::string name;
    int grade;
public:
    Student() : name(""), grade(0) {}
    void display() const {
        std::cout << "Студент: " << name << ", оценка: " << grade << "\n";
    }
    friend std::istream& operator>>(std::istream& is, Student& s);
};

std::istream& operator>>(std::istream& is, Student& s) {
    std::cout << "Введите имя студента: ";
    is >> s.name;
    std::cout << "Введите оценку: ";
    is >> s.grade;
    return is;
}

class Score {
private:
    int points;
public:
    Score(int p) : points(p) {}
    int getPoints() const { return points; }
    friend Score maxOfThree(const Score& s1, const Score& s2, const Score& s3);
};

Score maxOfThree(const Score& s1, const Score& s2, const Score& s3) {
    Score max_score = s1;
    if (s2.points > max_score.points) max_score = s2;
    if (s3.points > max_score.points) max_score = s3;
    return max_score;
}
