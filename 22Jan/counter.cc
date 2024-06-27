#include <string>
#include <iostream>

using namespace std;

class Counter
{
public:
Counter(string const & name, int no) : name{name}, no{no}{}

friend ostream& operator<<(ostream& os, Counter const& counter)
{   
    os << "[" << counter.name << "] = " << counter.no;
    return os;
}
friend Counter& operator++(Counter & counter)
{   
    counter.no = counter.no + 1;
    return counter;
}

friend Counter& operator+(Counter & counter)
{   
    counter.no = counter.no + 1;
    return counter;
}


private:
string name;
int no;

};




int main()
{
    Counter my_counter {"My Counter", 1};
    std::cout << my_counter << std::endl;

    std::cout << ++my_counter << std::endl;
    
    std::cout << my_counter++ << std::endl;

    // my_counter += 3;
    // std::cout << my_counter << std::endl;

    // std::cout << (my_counter + 5) << std::endl;

    // std::cout << (5 + my_counter) << std::endl;
}