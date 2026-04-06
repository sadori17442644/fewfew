#include <iostream>
#include <string>
using namespace std;

class Transport {
public:
    virtual void move() = 0;
    virtual ~Transport() = default;
};

class Car : public Transport {
public:
    void move() override {
        cout << "Car is driving on the road." << endl;
    }
};

class Bike : public Transport {
public:
    void move() override {
        cout << "Bike is riding on the path." << endl;
    }
};

class Animal {
public:
    virtual void sound() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

class Cow : public Animal {
public:
    void sound() override {
        cout << "Cow moos: Moo! Moo!" << endl;
    }
};

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() override {
        return side * side;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() override {
        return 0.5 * base * height;
    }
};

class Device {
public:
    virtual void turnOn() = 0;
    virtual ~Device() = default;
};

class Phone : public Device {
public:
    void turnOn() override {
        cout << "Phone is turning on..." << endl;
    }
};

class Laptop : public Device {
public:
    void turnOn() override {
        cout << "Laptop is booting up..." << endl;
    }
};

class Drink {
public:
    virtual void prepare() = 0;
    virtual ~Drink() = default;
};

class Tea : public Drink {
public:
    void prepare() override {
        cout << "Boiling water and steeping tea leaves..." << endl;
    }
};

class Coffee : public Drink {
public:
    void prepare() override {
        cout << "Grinding beans and brewing coffee..." << endl;
    }
};
class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() = default;
};

class Card : public Payment {
public:
    void pay(double amount) override {
        cout << "Paying $" << amount << " using card." << endl;
    }
};

class Cash : public Payment {
public:
    void pay(double amount) override {
        cout << "Paying $" << amount << " with cash." << endl;
    }
};

class Crypto : public Payment {
public:
    void pay(double amount) override {
        cout << "Paying $" << amount << " using cryptocurrency." << endl;
    }
};

class Employee {
public:
    virtual double salary() = 0;
    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    double baseSalary;
public:
    Manager(double salary) : baseSalary(salary) {}
    double salary() override {
        return baseSalary * 1.2;
    }
};

class Developer : public Employee {
private:
    double baseSalary;
public:
    Developer(double salary) : baseSalary(salary) {}
    double salary() override {
        return baseSalary;
    }
};

class File {
public:
    virtual void open() = 0;
    virtual ~File() = default;
};

class TextFile : public File {
public:
    void open() override {
        cout << "Opening text file in editor..." << endl;
    }
};

class ImageFile : public File {
public:
    void open() override {
        cout << "Displaying image in viewer..." << endl;
    }
};

class Message {
public:
    virtual void send() = 0;
    virtual ~Message() = default;
};

class Email : public Message {
public:
    void send() override {
        cout << "Sending email via SMTP..." << endl;
    }
};

class SMS : public Message {
public:
    void send() override {
        cout << "Sending SMS via cellular network..." << endl;
    }
};

class Enemy {
public:
    virtual void attack() = 0;
    virtual ~Enemy() = default;
};

class Zombie : public Enemy {
public:
    void attack() override {
        cout << "Zombie attacks with claws!" << endl;
    }
};

class Alien : public Enemy {
public:
    void attack() override {
        cout << "Alien fires laser beam!" << endl;
    }
};

class Account {
public:
    virtual double calculateInterest() = 0;
    virtual ~Account() = default;
};

class SavingsAccount : public Account {
private:
    double balance;
public:
    SavingsAccount(double b) : balance(b) {}
    double calculateInterest() override {
        return balance * 0.05;
    }
};

class FixedDeposit : public Account {
private:
    double amount;
public:
    FixedDeposit(double a) : amount(a) {}
    double calculateInterest() override {
        return amount * 0.1;
    }
};

class Shape2 {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Shape2() = default;
};

class Rectangle : public Shape2 {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override {
        return width * height;
    }
    double perimeter() override {
        return 2 * (width + height);
    }
};

class Circle : public Shape2 {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14159 * radius * radius;
    }
    double perimeter() override {
        return 2 * 3.14159 * radius;
    }
};

class Media {
public:
    virtual void play() = 0;
    virtual ~Media() = default;
};

class Audio : public Media {
public:
    void play() override {
        cout << "Playing audio file..." << endl;
    }
};

class Video : public Media {
public:
    void play() override {
        cout << "Playing video file..." << endl;
    }
};

class Notification {
public:
    virtual void notify() = 0;
    virtual ~Notification() = default;
};

class Push : public Notification {
public:
    void notify() override {
        cout << "Sending push notification..." << endl;
    }
};

class EmailNotification : public Notification {
public:
    void notify() override {
        cout << "Sending email notification..." << endl;
    }
};

class Robot {
public:
    virtual void work() = 0;
    virtual ~Robot() = default;
};

class CleanerRobot : public Robot {
public:
