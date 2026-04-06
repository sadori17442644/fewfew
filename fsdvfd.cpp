
using System;
using System.Collections.Generic;

public interface IFeedable
{
    void Feed();
}

public abstract class Animal : IFeedable
{
    public string Name { get; set; }
    public int Age { get; set; }
    public double Weight { get; set; }

    protected Animal(string name, int age, double weight)
    {
        Name = name;
        Age = age;
        Weight = weight;
    }

    public abstract void MakeSound();

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"Имя: {Name}, Возраст: {Age}, Вес: {Weight} кг");
    }

    public static bool operator >(Animal a1, Animal a2) => a1.Age > a2.Age;
    public static bool operator <(Animal a1, Animal a2) => a1.Age < a2.Age;
    public static bool operator >=(Animal a1, Animal a2) => a1.Age >= a2.Age;
    public static bool operator <=(Animal a1, Animal a2) => a1.Age <= a2.Age;
}

public class Mammal : Animal
{
    public bool HasFur { get; set; }

    public Mammal(string name, int age, double weight, bool hasFur)
        : base(name, age, weight)
    {
        HasFur = hasFur;
    }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} рычит!");
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Тип: Млекопитающее, Мех: {(HasFur ? "есть" : "нет")}");
    }

    public void Feed()
    {
        Console.WriteLine($"{Name} получает мясо и овощи");
    }
}

public class Bird : Animal
{
    public double Wingspan { get; set; }

    public Bird(string name, int age, double weight, double wingspan)
        : base(name, age, weight)
    {
        Wingspan = wingspan;
    }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} чирикает!");
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Тип: Птица, Размах крыльев: {Wingspan} м");
    }

    public void Feed()
    {
        Console.WriteLine($"{Name} получает зерно и фрукты");
    }
}

public class Reptile : Animal
{
    public bool IsPoisonous { get; set; }

    public Reptile(string name, int age, double weight, bool isPoisonous)
        : base(name, age, weight)
    {
        IsPoisonous = isPoisonous;
    }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} шипит!");
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Тип: Рептилия, Ядовитая: {(IsPoisonous ? "да" : "нет")}");
    }

    public void Feed()
    {
        Console.WriteLine($"{Name} получает насекомых и мелких животных");
    }
}

public class Zoo
{
    private List<Animal> animals = new List<Animal>();

    public string Name { get; set; }
    public string Location { get; set; }

    public Zoo(string name, string location)
    {
        Name = name;
        Location = location;
    }

    public void AddAnimal(Animal animal)
    {
        animals.Add(animal);
        Console.WriteLine($"В зоопарк добавлено животное: {animal.Name}");
    }

    public void RemoveAnimal(string name)
    {
        var animal = animals.Find(a => a.Name == name);
        if (animal != null)
        {
            animals.Remove(animal);
            Console.WriteLine($"Животное удалено: {name}");
        }
        else
        {
            Console.WriteLine($"Животное не найдено: {name}");
        }
    }

    public void MakeAllSounds()
    {
        Console.WriteLine("\n--- Звуки всех животных ---");
        foreach (var animal in animals)
        {
            animal.MakeSound();
        }
    }

    public void DisplayAllAnimals()
    {
        Console.WriteLine($"\n--- Животные зоопарка '{Name}' ---");
        foreach (var animal in animals)
        {
            animal.DisplayInfo();
            Console.WriteLine();
        }
    }

    public void FeedAllAnimals()
    {
        Console.WriteLine("\n--- Кормление всех животных ---");
        foreach (var animal in animals)
        {
            if (animal is IFeedable feedable)
            {
                feedable.Feed();
            }
        }
    }
}

public class ZooKeeper
{
    public string Name { get; set; }

    public ZooKeeper(string name)
    {
        Name = name;
    }

    public void CareForAnimal(Animal animal)
    {
        Console.WriteLine($"{Name} ухаживает за {animal.Name}");
        animal.MakeSound();
    }

    public void MaintainZoo(Zoo zoo)
    {
        Console.WriteLine($"\n{Name} проводит ежедневный обход зоопарка '{zoo.Name}'");
        zoo.DisplayAllAnimals();
        zoo.FeedAllAnimals();
    }
}

public static class ZooStatistics
{
    public public static int GetTotalAnimalCount(Zoo zoo)
    {
        return zoo.GetType().GetProperty("animals").GetValue(zoo) is List<Animal> animals
            ? animals.Count
            : 0;
    }

    public public static double GetAverageAge(Zoo zoo)
    {
        var animals = zoo.GetType().GetProperty("animals").GetValue(zoo) as List<Animal>;
        if (animals == null || animals.Count == 0) return 0;

        double totalAge = 0;
        foreach (var animal in animals)
        {
            totalAge += animal.Age;
        }
        return totalAge / animals.Count;
    }

    public public static Animal GetOldestAnimal(Zoo zoo)
    {
        var animals = zoo.GetType().GetProperty("animals").GetValue(zoo) as List<Animal>;
        return animals?.Count > 0 ? animals.OrderByDescending(a => a.Age).First() : null;
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("=== СИСТЕМА УПРАВЛЕНИЯ ЗООПАРКОМ ===\n");

        Zoo zoo = new Zoo("Городской зоопарк", "Центр города");

        Mammal lion = new Mammal("Лев", 5, 190, true);
        Mammal elephant = new Mammal("Слон", 10, 4000, false);
        Bird parrot = new Bird("Попугай", 3, 0.5, 0.3);
        Bird eagle = new Bird("Орёл", 7, 6, 2.1);
        Reptile crocodile = new Reptile("Крокодил", 15, 450, true);
        Reptile snake = new Reptile("Змея", 2, 3, true);

        zoo.AddAnimal(lion);
        zoo.AddAnimal(elephant);
        zoo.AddAnimal(parrot);
        zoo.AddAnimal(eagle);
        zoo.AddAnimal(crocodile);
        zoo.AddAnimal(snake);

        ZooKeeper keeper = new ZooKeeper("Иван Петров");

        zoo.DisplayAllAnimals();

        zoo.MakeAllSounds();
