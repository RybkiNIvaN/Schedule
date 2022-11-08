#include "worker.h"


Driver::Driver() {}

Driver::Driver(int Driver_ID, std::string FIO, int Birthday_Year, int Specification, int Routes, int Status)
{
    this->driverID = Driver_ID;
    this->name = FIO;
    this->yearBirthday = Birthday_Year;
    this->Specification = Specification;
    this->Routes = Routes;
    this->Status = Status;
}
int Driver::getDriverID()
{
    return this->driverID;
}
std::string Driver::getName()
{
    return this->name;
}
int Driver::getBirthdayYear()
{
    return this->yearBirthday;
}
int Driver::getSpecification()
{
    return this->Specification;
}
int Driver::getRoutes()
{
    return this->Routes;
}
int Driver::getStatus()
{
    return this->Status;
}
void Driver::setDriverID(int Driver_ID)
{
    this->driverID = Driver_ID;
}
void Driver::setName(std::string FIO)
{
    this->name = FIO;
}
void Driver::setBirthdayYear(int Birthday_Year)
{
    this->yearBirthday = Birthday_Year;
}
void Driver::setSpecification(int Specification)
{
    this->Specification = Specification;
}
void Driver::Set_Routes(int Routes)
{
    this->Routes = Routes;
}
void Driver::Set_Status(int Status)
{
    this->Status = Status;
}

std::ostream& operator << (std::ostream& out, Driver& dr) {
    out << dr.getDriverID() << "\t" << dr.getName() << "\t\t" << dr.getBirthdayYear() << "\t"
        << dr.getSpecification() << "\t" << dr.getRoutes() << "\t" << dr.getStatus();
    return out;
}
