#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <map>
#include <sstream>
// Add your functions here
using namespace std;

/* Example:

$ ./a.out
I study at LiU
I study at Linköping University
The course FULL_COURSE taught me programming in C++
The course TDDE18 at Department of Computer and Information Science / LinkÃ¶ping University
taught me programming in C++
<ctrl+D>

 */


// I choose return type
map<string, string> define_macros(ifstream & ifS){
    map<string, string> m{}; 
    string line;
    while(getline(ifS, line)){
        istringstream iss {line};
        string name{};
        string definition{};
        getline(iss, name, ':');
        getline(iss, definition);
        m[name] = definition;
    }

    return m;
}


string expand(string const & line, map<string, string> const& macro){ //
    
    istringstream iss {line};
    ostringstream oss {};
    
    string word;
    while (iss >> word)
    {
        auto it = macro.find(word);
        if( it == macro.find(word)){
            if(it == macro.end()){
                oss << word << " ";
            }
            else
            {
                oss << expand(it->second, macro);
            }
        }
    }

    // if(macro.find(line)){
        
    // }
    // while(macro.find(line))
    // {

    // }   
    // macro.find(line);
    // str { macro.find(line)->second}; 
    return str;
}



// You may NOT modify the main function
int main()
{   
    std::ifstream ifs { "macros.txt" };
    auto macros { define_macros(ifs) };
    std::string line;
    while (std::getline(std::cin, line))
    {        
        std::cout << expand(line, macros) << std::endl;
    }
}