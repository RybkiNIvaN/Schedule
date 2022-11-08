#include "logic.h"
#include "../worker/worker.h"


/* Drivers distribution
 * ARGUMENTS:
 *     - alternations of dates variations:
 *           int Date_ID;
 *     - number of days:
 *           int Amount_of_Days;
 * RETURNS:
 *     (std::vector <int>) Driver`s schedule
 */
std::vector <int> Schedule(int Date_ID, int Amount_of_Days)
{

    /* string a = "0 1 ";
     string b = "0 0 ";
     string c = "1 0 ";
     string d = "1 1 ";*/
    std::vector <int> l1 = { 1,1 };
    std::vector <int> l2 = { 0,0 };
    std::vector <int> l3 = { 0,1 };
    std::vector <int> l4 = { 1,0 };
    std::vector <int> rasp;

    rasp.resize(Amount_of_Days);

    for (int i = 0; i < Amount_of_Days; i++)
    {
        if (Date_ID == 1)
        {
            rasp[i] = l1[i % 2];
            if (i % 2 == 1)
            {
                Date_ID = 2;
            }
        }
        else if (Date_ID == 2)
        {
            rasp[i] = l2[i % 2];
            if (i % 2 == 1)
            {
                Date_ID = 1;
            }
        }
        else if (Date_ID == 3)
        {
            rasp[i] = l3[i % 2];
            if (i % 2 == 1)
            {
                Date_ID = 4;
            }
        }
        else
        {
            rasp[i] = l4[i % 2];
            if (i % 2 == 1)
            {
                Date_ID = 3;
            }
        }
    }
    return rasp;
}

/* Randomizer of drivers
 * ARGUMENTS:
 *     - number of drivers:
 *           int Amount_Of_Drivers;
 *     - list of drivers IDs:
 *           std::vector<Driver> &setOfDrivers;
 * RETURNS:
 *     (std::vector <int>) list of randomized IDs
 */
std::vector <int> Randomizer_Of_Drivers(int Amount_Of_Drivers, std::vector<Driver> setOfDrivers) //рандомизация списка водителей
{
    int Rand_x;
    std::vector <int> Drivers_Numers;
    for (int i = 0; i < Amount_Of_Drivers; i++) //задание вектора
    {
        Drivers_Numers.push_back(setOfDrivers[i].getDriverID());
    }
    for (int i = Amount_Of_Drivers - 1; i > 0; --i) //рандомизация вектора
    {
        std::swap(Drivers_Numers[i], Drivers_Numers[rand() % (i + 1)]);
    }
    return Drivers_Numers;
}


/* Drivers groups distribution
 * ARGUMENTS:
 *     - list of drivers IDs:
 *           std::vector <int> Drivers_Numers;
 * RETURNS:
 *     ( tuple <std::vector<int>, std::vector<int>, std::vector <int>> ) Drivers groups
 */
std::tuple <std::vector<int>, std::vector<int>, std::vector <int>> Groups_Of_Drivers(std::vector <int> Drivers_Numers) //распределение водителей по группам
{
    std::vector <int> v1, v2, v3;

    if (Drivers_Numers.size() % 2 == 0)
    {
        v1.resize(Drivers_Numers.size() / 2);
        copy(Drivers_Numers.begin(), Drivers_Numers.begin() + (Drivers_Numers.size() / 2), v1.begin());
        v2.resize(Drivers_Numers.size() / 2);
        copy(Drivers_Numers.begin() + (Drivers_Numers.size() / 2), Drivers_Numers.end(), v2.begin());
    }
    else
    {
        v1.resize(Drivers_Numers.size() / 2);
        copy(Drivers_Numers.begin(), Drivers_Numers.begin() + (Drivers_Numers.size() / 2), v1.begin());
        v2.resize(Drivers_Numers.size() / 2);
        copy(Drivers_Numers.begin() + (Drivers_Numers.size() / 2), Drivers_Numers.end() - 1, v2.begin());
        v3.resize(1);
        v3[0] = Drivers_Numers[Drivers_Numers.size() - 1];
    }
    return make_tuple(v1, v2, v3); //вывод тройки(пары) сгруппированных водителей
}