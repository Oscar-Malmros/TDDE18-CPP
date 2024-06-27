#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


// class Effect{
//     public: 
//     Effect(string const & name, string const & description) :
//         name{name}, description{description}
//         {
//         }
//     string const& name;
//     string const& description;
// };

struct Effect
{
    string name;
    string description;
};


class Card{
    public:
    Card(Effect top, Effect bottom, int initiative) :
        top{top}, bottom{bottom}, initiative{initiative}
        {

        }

    friend ostream& operator<<(ostream& os, Card const& card );
    friend bool operator<(Card const& lhs, Card const& rhs);
    Effect top;
    Effect bottom;
    int initiative;
};

class Hand
{
    public:
    Hand() : vec{} {}

    void draw(Card const & card){
        vec.push_back(card);
    }

    void print(ostream& os){
        for(Card card : vec){
            os << card << "\n" << endl;
        }
    }

    private:
    vector<Card> vec;
};


ostream& operator<<(ostream& os,Card const& card ){
    os << "Top: " << card.top.name
        << "\nInitiative: " << card.initiative
        << "\nBottom: " << card.bottom.name;
    return os;
}

bool operator<(Card const& lhs, Card const& rhs){
    return lhs.initiative < rhs.initiative;
}

int main()
{
    Effect aid{"Aid from the Ether", "Heals an ally for 3 health"};
    Effect ally{"Summon Mystic Ally", "Summon minion and gain 2 xp"};
    Effect icelance{"Ice Lance", "Deals 2 damage"};
    Effect ridethewind{"Ride the Wind", "Move 8 spaces"};

    Card card1{aid, ally, 91};
    Card const card2{icelance, ridethewind, 25};
    cout << "Card1:\n" << card1 << '\n' << endl;

    Hand hand{};
    hand.draw(card1);
    hand.draw(card2);
    hand.print(cout); // could also implement operator<<: cout << hand;



    cout << "card1 is less than card2: " << boolalpha << (card1 < card2) << endl;
    cout << "card2 is less than card1: " << boolalpha << (card2 < card1) << endl;



}
