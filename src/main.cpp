#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "excel/excel.h"
#include "logic/logic.h"
#include "testing/testing.h"
#include "worker/worker.h"

/* Main function
 * ARGUMENTS: none
 * RETURNS:
 *     ( int ) OS return code
 */
int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));

    std::vector <Driver> List_Of_Drivers = { };

    std::ifstream file("bin/excel/5.csv");

    if (!file.is_open())
        std::cout << "ERROR";

    while (file.good())
    {
        std::string line, lines;
        getline(file, line, '\n');
        std::vector<std::string> fields = {};

        std::stringstream ss(line);
        while (getline(ss, lines, ';')) {
            fields.push_back(lines);
        }
        if (lines != "")
            List_Of_Drivers.push_back(Driver(stoi(fields[0]), fields[1], stoi(fields[2]),
                stoi(fields[3]), stoi(fields[4]), stoi(fields[5])));
    }
    file.close();


    for (auto person : List_Of_Drivers)
    {
        std::cout << person << std::endl;
    }
    std::cout << std::endl;


    int Amount_Of_Drivers = List_Of_Drivers.size();
    int Amount_of_Days = 0;
    bool f1;
    std::cout << "Do you want print out schedule for all drivers? (1/0) ";
    std::cin >> f1;
    if (f1)
    {
        std::cout << "How many days do you want to be in schedule? ";
        std::cin >> Amount_of_Days;
    }
    std::vector <int> Drivers = Randomizer_Of_Drivers(Amount_Of_Drivers, List_Of_Drivers);
    for (auto i : Drivers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector <int> Group1, Group2, Group3;
    tie(Group1, Group2, Group3) = Groups_Of_Drivers(Drivers);

    std::map <int, int> m;
    for (int i = 0; i < Group1.size(); i++)
    {
        m[Group1[i]] = 1;
        std::cout << Group1[i] << std::endl;
        for (auto x : Schedule(m[Group1[i]], Amount_of_Days))
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < Group2.size(); i++)
    {
        m[Group2[i]] = 2;
        std::cout << Group2[i] << std::endl;
        for (auto x : Schedule(m[Group2[i]], Amount_of_Days))
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < Group3.size(); i++)
    {
        m[Group3[i]] = 3;
        std::cout << Group3[i] << std::endl;
        for (auto x : Schedule(m[Group3[i]], Amount_of_Days))
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

}