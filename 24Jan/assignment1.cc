#include <iostream>
#include <list>

using namespace std;

/* Write your code here */
class Ordinal
{
    public:
    Ordinal() : l{} {}

    Ordinal& successor(){
        return *this;
    }

    // +
    // ++
    // <<
    friend ostream& operator<<(ostream& os, Ordinal const& ordinal);

    private:
    list<int> l;

};


ostream& operator<<(ostream& os, Ordinal const& ordinal){
    return os << "BAJS" << endl;
}

int main()
{
    Ordinal zero{};
    cout << "0: " << zero << endl;
    Ordinal const one{zero.successor()};
    cout << "1: " << one << endl;

    // three starts as 0
    Ordinal three{};

    // increment it to two
    ++(++three);

    // copy the current three, thus getting two and then increment three
    Ordinal two { three++ };
    
    cout << "2: " << zero + two << endl;
    cout << "2: " << two + zero << endl;
    cout << "3: " << static_cast<string>(three) << endl;
    cout << "4: " << two + two << endl;
}