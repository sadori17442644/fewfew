#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <chrono>
#include <thread>
#include <unordered_map>

using namespace std;

class Coffee {
public:
    virtual double cost() = 0;
    virtual string description() = 0;
    virtual ~Coffee() = default;
};

class SimpleCoffee : public Coffee {
public:
    double cost() override {
        return 100.0;  // базовая цена
    }
    string description() override {
        return "Обычный кофе";
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    virtual ~CoffeeDecorator() { delete coffee; }
};

class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}
    double cost() override {
        return coffee->cost() + 20.0;
    }
    string description() override {
        return coffee->description() + " + молоко";
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* c) : CoffeeDecorator(c) {}
    double cost() override {
        return coffee->cost() + 10.0;
    }
    string description() override {
        return coffee->description() + " + сахар";
    }
};

class Syrup : public CoffeeDecorator {
    string flavor;
public:
    Syrup(Coffee* c, const string& f) : CoffeeDecorator(c), flavor(f) {}
    double cost() override {
        return coffee->cost() + 30.0;
    }
    string description() override {
        return coffee->description() + " + " + flavor + " сироп";
    }
};

class Service {
public:
    virtual void execute() = 0;
    virtual ~Service() = default;
};

class BaseService : public Service {
public:
    void execute() override {
        cout << "Выполнение основной бизнес-логики..." << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
};

class LoggingDecorator : public Service {
    Service* service;
public:
    LoggingDecorator(Service* s) : service(s) {}
    ~LoggingDecorator() { delete service; }
    
    void execute() override {
        auto start = chrono::high_resolution_clock::now();
        cout << "[LOG] Начало выполнения в " << getCurrentTime() << endl;
        
        service->execute();
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "[LOG] Конец выполнения. Длительность: " << duration.count() << " мс" << endl;
    }
    
private:
    string getCurrentTime() {
        auto now = chrono::system_clock::now();
        auto time_t = chrono::system_clock::to_time_t(now);
        return ctime(&time_t);
    }
};
class Service {
public:
    virtual void execute(int userId) = 0;
    virtual ~Service() = default;
};

class UserService : public Service {
public:
    void execute(int userId) override {
        cout << "Выполнение операции для пользователя " << userId << endl;
    }
};

class AuthDecorator : public Service {
    Service* service;
    set<int> adminUsers;
public:
    AuthDecorator(Service* s) : service(s) {
        adminUsers = {1, 5, 10};  // ID администраторов
    }
    ~AuthDecorator() { delete service; }
    
    void execute(int userId) override {
        if (adminUsers.count(userId)) {
            cout << "[AUTH] Доступ разрешён для пользователя " << userId << endl;
            service->execute(userId);
        } else {
            cout << "[AUTH] ДОСТУП ЗАПРЕЩЁН! Пользователь " << userId << " не имеет прав" << endl;
        }
    }
};
class AuditDecorator : public Service {
    Service* service;
public:
    AuditDecorator(Service* s) : service(s) {}
    ~AuditDecorator() { delete service; }
    
    void execute(int userId) override {
        cout << "[AUDIT] Зафиксирован вызов от пользователя " << userId << " в " << time(nullptr) << endl;
        service->execute(userId);
    }
};
class DataSource {
public:
    virtual string getData(int id) = 0;
    virtual ~DataSource() = default;
};
class RealDatabase : public DataSource {
public:
    string getData(int id) override {
        cout << "[DB] Выполняется запрос к базе данных для id=" << id << "..." << endl;
        return "Данные_для_" + to_string(id);
    }
};

class CacheDecorator : public DataSource {
    DataSource* source;
    unordered_map<int, string> cache;
    int hits;
    int misses;
public:
    CacheDecorator(DataSource* s) : source(s), hits(0), misses(0) {}
    ~CacheDecorator() { delete source; }
    
    string getData(int id) override {

        auto it = cache.find(id);
        if (it != cache.end()) {
            hits++;
            cout << "[CACHE] HIT! id=" << id << " (попаданий: " << hits << ")" << endl;
            return it->second;
        }
        
        misses++;
        cout << "[CACHE] MISS! id=" << id << " (промахов: " << misses << ")" << endl;
        string data = source->getData(id);
        cache[id] = data;
        return data;
    }
    
    void printStats() {
        cout << "\n=== Статистика кэша ===" << endl;
        cout << "Попаданий: " << hits << endl;
        cout << "Промахов: " << misses << endl;
        cout << "Всего запросов: " << hits + misses << endl;
        cout << "Эффективность: " << (double)hits / (hits + misses) * 100 << "%" << endl;
    }
};
class Character {
public:
    virtual int getDamage() = 0;
    virtual int getSpeed() = 0;
    virtual int getDefense() = 0;
    virtual string getName() = 0;
    virtual ~Character() = default;
};
class BaseCharacter : public Character {
    string name;
public:
    BaseCharacter(const string& n) : name(n) {}
    int getDamage() override { return 10; }
    int getSpeed() override { return 5; }
    int getDefense() override { return 3; }
    string getName() override { return name; }
};

class CharacterDecorator : public Character {
protected:
    Character* character;
public:
    CharacterDecorator(Character* c) : character(c) {}
    virtual ~CharacterDecorator() { delete character; }
};

class DamageBoost : public CharacterDecorator {
    int bonus;
public:
    DamageBoost(Character* c, int b = 5) : CharacterDecorator(c), bonus(b) {}
    int getDamage() override {
        return character->getDamage() + bonus;
    }
    int getSpeed() override {
        return character->getSpeed();
    }
    int getDefense() override {
        return character->getDefense();
    }
    string getName() override {
        return character->getName() + " [Урон+" + to_string(bonus) + "]";
    }
};

class SpeedBoost : public CharacterDecorator {
    int bonus;
public:
    SpeedBoost(Character* c, int b = 3) : CharacterDecorator(c), bonus(b) {}
    int getDamage() override {
        return character->getDamage();
    }
    int getSpeed() override {
        return character->getSpeed() + bonus;
    }
    int getDefense() override {
        return character->getDefense();
    }
    string getName() override {
        return character->getName() + " [Скорость+" + to_string(bonus) + "]";
    }
};
class DefenseBoost : public CharacterDecorator {
    int bonus;
public:
    DefenseBoost(Character* c, int b = 2) : CharacterDecorator(c), bonus(b) {}
    int getDamage() override {
        return character->getDamage();
    }
    int getSpeed() override {
        return character->getSpeed();
    }
    int getDefense() override {
        return character->getDefense() + bonus;
    }
    string getName() override {
        return character->getName() + " [Защита+" + to_string(bonus) + "]";
    }
};

int main() {
    Coffee* myCoffee = new SimpleCoffee();
    cout << myCoffee->description() << ": " << myCoffee->cost() << " руб." << endl;
    
    myCoffee = new Milk(myCoffee);
    myCoffee = new Sugar(myCoffee);
    myCoffee = new Syrup(myCoffee, "шоколадный");
    
    cout << myCoffee->description() << ": " << myCoffee->cost() << " руб." << endl;
    
    delete myCoffee;
  
      Service* service = new BaseService();
    service = new LoggingDecorator(service);
    service->execute();
    
    delete service;

      Service* service = new UserService();
    service = new AuthDecorator(service);   // Добавляем проверку прав
    service = new AuditDecorator(service);  // Добавляем аудит
    
    cout << "=== Попытка пользователя 1 (админ) ===" << endl;
    service->execute(1);
    
    cout << "\n=== Попытка пользователя 99 (обычный) ===" << endl;
    service->execute(99);
    
    delete service;

      DataSource* data = new RealDatabase();
    data = new CacheDecorator(data);
    CacheDecorator* cache = dynamic_cast<CacheDecorator*>(data);
    
    cout << "=== Первый запрос (должен быть промах) ===" << endl;
    cout << data->getData(42) << endl;
    
    cout << "\n=== Второй запрос того же id (должен быть попадание) ===" << endl;
    cout << data->getData(42) << endl;
    
    cout << "\n=== Запрос другого id (промах) ===" << endl;
    cout << data->getData(100) << endl;
    
    if (cache) cache->printStats();
    
    delete data;

      Character* hero = new BaseCharacter("Герой");
    cout << hero->getName() << " | Урон: " << hero->getDamage() 
         << " | Скорость: " << hero->getSpeed() 
         << " | Защита: " << hero->getDefense() << endl;
    
    hero = new DamageBoost(hero, 10);
    hero = new SpeedBoost(hero, 5);    
    hero = new DefenseBoost(hero, 3);  
    
    cout << hero->getName() << " | Урон: " << hero->getDamage() 
         << " | Скорость: " << hero->getSpeed() 
         << " | Защита: " << hero->getDefense() << endl;
    
    delete hero;

    return 0;
}
