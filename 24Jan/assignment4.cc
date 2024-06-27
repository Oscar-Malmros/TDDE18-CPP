
#include <string>
#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

class Item
{
public:
    Item(double weight) : weight{weight} {}
    virtual ~Item() = default;

    double get_weight() const
    {
        return weight;
    }

    virtual void print(ostream &os) const = 0;

protected:
    virtual void print_info(ostream &os) const
    {
        os << weight << " kg";
    }
    double weight;
};

class Shovel : public Item
{
public:
    Shovel() : Item{3.0} {}
    

    void print(ostream& os) const override
    {
        os << "a shovel ";
        print_info(os);
    }
};

class Weapon : public Item
{
public:
    Weapon(double damage, double weight) : Item{weight}, damage{damage} {}

    double get_damage() const
    {
        return damage;
    }

protected:
    void print_info(ostream &os) const override
    {
        os << "dealing " << damage << " damage";
        Item::print_info(os);
    }

    double damage;
};

class Sword : public Weapon
{
public:
    Sword(string const &name, double damage, double weight) : Weapon{damage, weight}, name{name} {}

    void print(ostream &os) const override
    {
        os << "A sword named " << name;
        print_info(os);
    }

private:
    string name;
};

class Bow : public Weapon
{
public:
    using Weapon::Weapon;
    void print(ostream &os) const override
    {
        os << "A bow " << name;
        print_info(os);
    }

private:
    string name;
};

int main()
{


    std::vector<Item*> bag {
        new Sword { "Sword of stabbing", 10.0, 2.5 },
        new Sword { "Sword of pricking", 5.0, 0.9 },
        new Bow   { 7.5, 0.6 },
        new Shovel { }
    };

    double total_weight{0.0};
    double greatest_damage{0.0};

    std::cout << "Your bag contains: " << std::endl;
    for (Item *item : bag)
    {
        std::cout << " - ";
        item->print(std::cout);
        std::cout << std::endl;

       Weapon* weapon = dynamic_cast<Weapon*>(item);
        if (weapon != nullptr) // Checks if the dynamic cast succeeded
        {
            if (weapon->get_damage() > greatest_damage)
            {
                greatest_damage = weapon->get_damage();
            }
        }

        total_weight += item->get_weight();
    }
    std::cout << "Total weight: " << total_weight << " kg" << std::endl;
    std::cout << "Best damage: " << greatest_damage << " damage" << std::endl;

    for (Item* i : bag)
    {
        delete i;
    }
}