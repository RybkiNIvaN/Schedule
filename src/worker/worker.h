#ifndef worker_h
#define worker_h




#include <iostream>
#include <string>


class Driver
{

private:

    int driverID = 0;
    std::string name = "";
    int yearBirthday = 1900;
    int Specification = 22; // график: 1-(2/2) 2-(5/2) 3-(3/2/3/1) 4-перег.день 5-перег.ночь 6-разрыв
    int Routes = 0;
    int Status = 0; // 1-здоров 2-болен 3-отпуск

public:

    Driver();
    Driver(int Driver_ID, std::string FIO, int Birthday_Year, int Specification, int Routes, int Status);
    int getDriverID();
    std::string getName();
    int getBirthdayYear();
    int getSpecification();
    int getRoutes();
    int getStatus();
    void setDriverID(int Driver_ID);
    void setName(std::string FIO);
    void setBirthdayYear(int Birthday_Year);
    void setSpecification(int Specification);
    void Set_Routes(int Routes);
    void Set_Status(int Status);

    friend std::ostream& operator << (std::ostream& out, Driver& dr);
};

#endif