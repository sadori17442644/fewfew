
#include <iostream>
#include <string>

class Author {
private:
    std::string name;
public:
    Author(const std::string& authorName) : name(authorName) {}
    std::string GetName() const { return name; }
};

class Book {
private:
    std::string title;
    Author* author;
public:
    Book(const std::string& bookTitle, Author* bookAuthor)
        : title(bookTitle), author(bookAuthor) {}
    void DisplayInfo() const {
        std::cout << "Книга: " << title << ", автор: " << author->GetName() << "\n";
    }
};

void Task1() {
    Author author("Лев Толстой");
    Book book("Война и мир", &author);
    book.DisplayInfo();
}
class Furniture {
private:
    std::string type;
public:
    Furniture(const std::string& furnitureType) : type(furnitureType) {}
    void Describe() const { std::cout << type << " в комнате\n"; }
    friend class Room;
};

class Room {
private:
    std::vector<Furniture> furniture;
public:
    Room() {
        furniture.push_back(Furniture("Диван"));
        furniture.push_back(Furniture("Стол"));
    }
    void ShowFurniture() const {
        for (const auto& item : furniture) item.Describe();
    }
};

void Task2() {
    Room room;
    room.ShowFurniture();
}
class Account {
private:
    std::string username;
public:
    Account(const std::string& user) : username(user) {}
    void Login() const { std::cout << username << " вошёл в систему\n"; }
    friend class User;
};

class User {
private:
    std::string name;
    Account account;
public:
    User(const std::string& userName)
        : name(userName), account(userName + "_acc") {}
    void LogIn() const { account.Login(); }
};

void Task3() {
    User user("Анна");
    user.LogIn();
}
class Teacher {
private:
    std::string name;
public:
    Teacher(const std::string& teacherName) : name(teacherName) {}
    std::string GetName() const { return name; }
};

class School {
private:
    std::vector<Teacher*> teachers;
public:
    void AddTeacher(Teacher* teacher) { teachers.push_back(teacher); }
    void ListTeachers() const {
        std::cout << "Учителя школы:\n";
        for (const auto& teacher : teachers)
            std::cout << "- " << teacher->GetName() << "\n";
    }
};

void Task4() {
    Teacher t1("Мария Ивановна");
    Teacher t2("Пётр Сергеевич");
    School school;
    school.AddTeacher(&t1);
    school.AddTeacher(&t2);
    school.ListTeachers();
}
class Wheel {
private:
    int size;
public:
    Wheel(int wheelSize) : size(wheelSize) {}
    void Rotate() const { std::cout << "Колесо размером " << size << " вращается\n"; }
    friend class Car;
};

class Car {
private:
    std::vector<Wheel> wheels;
public:
    Car() {
        wheels.push_back(Wheel(16));
        wheels.push_back(Wheel(16));
        wheels.push_back(Wheel(16));
        wheels.push_back(Wheel(16));
    }
    void Drive() const {
        std::cout << "Автомобиль едет:\n";
        for (const auto& wheel : wheels) wheel.Rotate();
    }
};

void Task5() {
    Car car;
    car.Drive();
}
class Employee {
private:
    std::string name;
public:
    Employee(const std::string& empName) : name(empName) {}
    std::string GetName() const { return name; }
};

class Company {
private:
    std::vector<Employee*> employees;
public:
    void Hire(Employee* employee) { employees.push_back(employee); }
    void ShowEmployees() const {
        std::cout << "Сотрудники компании:\n";
        for (const auto& emp : employees)
            std::cout << "- " << emp->GetName() << "\n";
    }
};

void Task6() {
    Employee e1("Иван");
    Employee e2("Мария");
    Company company;
    company.Hire(&e1);
    company.Hire(&e2);
    company.ShowEmployees();
}
class Keyboard {
private:
    bool isBacklit;
public:
    Keyboard(bool backlit) : isBacklit(backlit) {}
    void Type() const {
        std::cout << "Клавиатура " << (isBacklit ? "с подсветкой" : "обычная")
                  << " печатает\n";
    }
    friend class Laptop;
};

class Laptop {
private:
    Keyboard keyboard;
public:
    Laptop() : keyboard(true) {}
    void Use() const { keyboard.Type(); }
};

void Task7() {
    Laptop laptop;
    laptop.Use();
}
class Student {
private:
    std::string name;
public:
    Student(const std::string& studentName) : name(studentName) {}
    std::string GetName() const { return name; }
};

class Course {
private:
    std::vector<Student*> students;
public:
    void Enroll(Student* student) { students.push_back(student); }
    void ShowStudents() const {
        std::cout << "Студенты на курсе:\n";
        for (const auto& student : students)
            std::cout << "- " << student->GetName() << "\n";
    }
};

void Task8() {
    Student s1("Алексей");
    Student s2("Ольга");
    Course course;
    course.Enroll(&s1);
    course.Enroll(&s2);
    course.ShowStudents();
}
class Door {
private:
    std::string material;
public:
    Door(const std::string& doorMaterial) : material(doorMaterial) {}
    void Open() const { std::cout << material << " дверь открыта\n"; }
    friend class House;
};

class House {
private:
    std::vector<Door> doors;
public:
    House() {
        doors.push_back(Door("Деревянная"));
        doors.push_back(Door("Металлическая"));
    }
    void Enter() const {
        std::cout << "Входим в дом:\n";
        for (const auto& door : doors) door.Open();
    }
};

void Task9() {
    House house;
    house.Enter();
}
#include <iostream>
#include <string>
#include <vector>

class Track {
private:
    std::string title;
public:
    Track(const std::string& trackTitle) : title(trackTitle) {}
    std::string GetTitle() const { return title; }
    friend class Player;
};

class Player {
private:
    std::vector<Track*> tracks;
public:
    void AddTrack(Track* track) { tracks.push_back(track); }
    void PlayAll() const {
        std::cout << "Воспроизведение плейлиста:\n";
        for (const auto& track : tracks) {
            std::cout << "- Воспроизводится: " << track->GetTitle() << "\n";
        }
    }
};

void Task10() {
    Track t1("Песня 1");
    Track t2("Песня 2");
    Player player;
    player.AddTrack(&t1);
    player.AddTrack(&t2);
    player.PlayAll();
}
class Customer {
private:
    std::string name;
public:
    Customer(const std::string& customerName) : name(customerName) {}
    std::string GetName() const { return name; }
};

class Order {
private:
    int orderId;
    Customer* customer;
public:
    Order(int id, Customer* cust) : orderId(id), customer(cust) {}
    void DisplayOrder() const {
        std::cout << "Заказ №" << orderId << " оформлен клиентом: "
                  << customer->GetName() << "\n";
    }
};

void Task11() {
    Customer customer("Иван Петров");
    Order order(123, &customer);
    order.DisplayOrder();
}
class Battery {
private:
    int capacity;
public:
    Battery(int mAh) : capacity(mAh) {}
    void Discharge() const { std::cout << "Батарея " << capacity
                         << " мАч разряжается\n"; }
    friend class Smartphone;
};

class Smartphone {
private:
    Battery battery; 
public:
    Smartphone(int batteryCapacity) : battery(batteryCapacity) {}
    void UsePhone() const { battery.Discharge(); }
};

void Task12() {
    Smartphone phone(4000);
    phone.UsePhone();
}
class Book {
private:
    std::string title;
public:
    Book(const std::string& bookTitle) : title(bookTitle) {}
    std::string GetTitle() const { return title; }
};

class Library {
private:
    std::vector<Book*> books;
public:
    void AddBook(Book* book) { books.push_back(book); }
    void ListBooks() const {
        std::cout << "Книги в библиотеке:\n";
        for (const auto& book : books)
            std::cout << "- " << book->GetTitle() << "\n";
    }
};

void Task13() {
    Book b1("Война и мир");
    Book b2("Преступление и наказание");
    Library library;
    library.AddBook(&b1);
    library.AddBook(&b2);
    library.ListBooks();
}
class Level {
private:
    int levelNumber;
public:
    Level(int num) : levelNumber(num) {}
    void Load() const { std::cout << "Загружен уровень " << levelNumber << "\n"; }
    friend class Game;
};

class Game {
private:
    std::vector<Level> levels;
public:
    Game() {
        levels.push_back(Level(1));
        levels.push_back(Level(2));
        levels.push_back(Level(3));
    }
    void Start() const {
        std::cout << "Запуск игры:\n";
        for (const auto& level : levels) level.Load();
    }
};

void Task14() {
    Game game;
    game.Start();
}
class Database {
private:
    std::string name;
public:
    Database(const std::string& dbName) : name(dbName) {}
    void Connect() const { std::cout << "База данных " << name
                          << " подключена\n"; }
};

class Server {
private:
    Database* database; 
public:
    Server() : database(nullptr) {}
    void SetDatabase(Database* db) { database = db; }
    void Run() const {
        if (database) database->Connect();
        else std::cout << "Ошибка: база данных не подключена!\n";
    }
};

void Task15() {
    Database db("MainDB");
    Server server;
    server.SetDatabase(&db);
    server.Run();
}
class Car {
private:
    std::string model;
public:
    Car(const std::string& carModel) : model(carModel) {}
    std::string GetModel() const { return model; }
};

class Fleet {
private:
    std::vector<Car*> cars;
public:
    void AddCar(Car* car) { cars.push_back(car); }
    void ShowFleet() const {
        std::cout << "Автопарк:\n";
        for (const auto& car : cars)
            std::cout << "- " << car->GetModel() << "\n";
    }
};

void Task16() {
    Car car1("Toyota");
    Car car2("BMW");
    Fleet fleet;
    fleet.AddCar(&car1);
    fleet.AddCar(&car2);
    fleet.ShowFleet();
}
class Heart {
private:
    int bpm;
public:
    Heart() : bpm(70) {}
    void Beat() const { std::cout << "Сердце бьётся: " << bpm << " ударов/мин\n"; }
    friend class Human;
};

class Human {
private:
    Heart heart;
    std::string name;
public:
    Human(const std::string& humanName) : name(humanName) {}
    void Live() const { heart.Beat(); }
};

void Task17() {
    Human person("Алексей");
    person.Live();
}
class Cart {
private:
    std::vector<std::string> items;
public:
    void AddItem(const std::string& item) { items.push_back(item); }
    void ViewCart() const {
        std::cout << "Корзина:\n";
        for (const auto& item : items) std::cout << "- " << item << "\n";
    }
    friend class User;
};

class User {
private:
    std::string username;
    Cart cart;
public:
    User(const std::string& userName) : username(userName) {}
    void Shop() {
        cart.AddItem("Ноутбук");
        cart.AddItem("Мышь");
        cart.ViewCart();
    }
};

void Task18() {
    User user("Мария");
    user.Shop();
}
