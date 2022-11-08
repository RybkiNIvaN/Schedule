#ifndef logic_h
#define logic_h




#include <vector>
#include <tuple>
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
std::vector <int> Schedule(int Date_ID, int Amount_of_Days);

/* Randomizer of drivers
 * ARGUMENTS:
 *     - number of drivers:
 *           int Amount_Of_Drivers;
 *     - list of drivers IDs:
 *           std::vector<Driver> &setOfDrivers;
 * RETURNS:
 *     (std::vector <int>) list of randomized IDs
 */
std::vector <int> Randomizer_Of_Drivers(int Amount_Of_Drivers, std::vector<Driver> setOfDrivers);



/* Drivers groups distribution
 * ARGUMENTS:
 *     - list of drivers IDs:
 *           std::vector <int> Drivers_Numers;
 * RETURNS:
 *     ( tuple <std::vector<int>, std::vector<int>, std::vector <int>> ) Drivers groups
 */
std::tuple <std::vector<int>, std::vector<int>, std::vector <int>> Groups_Of_Drivers(std::vector <int> Drivers_Numers);

#endif