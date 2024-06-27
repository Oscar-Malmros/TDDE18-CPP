#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
using coordinate = std::pair<int, int>;
using hexagon = std::string;

class Tile
{
public:
    Tile(string name) : name{name}, hexes{} {}

    void create_hexagon(coordinate coord, hexagon hex)
    {
        hexes.emplace(coord, hex);
    }

    void print_hexagon(coordinate const &coord)
    {
        cout << "Hexagon(" << coord.first << ", " << coord.second << "): ["
             << hexes.at(coord).back() << "]" << endl;
    }

    void push(coordinate coord, char ch)
    {
        hexes.at(coord).push_back(ch);
    }

    void print_tile()
    {
        cout << name << ":" << endl;
        for (auto it : hexes)
        {
            print_hexagon(it.first);
        }
    }

private:
    string name;
    map<coordinate, string> hexes;
};

int main()
{
    Tile b1{"b1"};
    b1.create_hexagon(coordinate{0, 0}, hexagon{"HXOX"});
    b1.print_hexagon(coordinate{0, 0});
    b1.push(coordinate{0, 0}, 'O');
    b1.create_hexagon(coordinate{0, 1}, hexagon{"OXXXH"});
    b1.print_tile();
}
