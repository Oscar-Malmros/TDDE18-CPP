#include <vector>
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
/*

Expected output:

1970-01-01
Thursday 1/1/1970
2000-12-24
Christmas Eve 12/24/2000
2020-02-19
Thursday 2/19/2020

*/

class Date
{
public:
    Date(int year, int month, int date) : year{year}, month{month}, date{date} {}
    virtual ~Date() = default;
    virtual string to_string() const = 0;

protected:
    int year;
    int month;
    int date;
};

class YMD_Date : public Date
{
    public:
    using Date::Date;
    ostringstream oss;
    string to_string() const override{
        ostringstream oss;
        
        oss << year << "-"
        << setfill('0') << setw(2) << month
        << "-" << date;
        return oss.str();
        }
};

class MDY_Date : public Date
{
    public:
    MDY_Date(string const & weekday, int year, int month, int date) :
        Date{year, month, date}, weekday{weekday} {

        }
    
    // Thursday 2/19/2020
    string to_string() const override{
        ostringstream oss;
        
        oss << weekday << " "
        << month << "/"
        << date << "/"
        << year;
        return oss.str();
    }
    private:
    string weekday;


};





int main()
{
    std::vector<Date *> dates = {
        new YMD_Date{1970, 1, 1},
        new MDY_Date{"Thursday", 1970, 1, 1},
        new YMD_Date{2020, 2, 19},
        new MDY_Date{"Thursday", 2020, 2, 19}
    };

    for (Date* date : dates)
    {
        std::cout << date->to_string() << std::endl;
    }
}