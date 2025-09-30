#ifndef GROUP_H
#define GROUP_H

#include <stdint.h>
#include <string>
#include <vector>

class Group{
    private:
    const int id;
    const std::string name;
    std::string description;
    std::vector<int> users;
    std::vector<int> tasks;

    public:
    int getID();
    std::string getName();
    std::string getDescription();
    std::vector<int> getUsers();
    std::vector<int> getTasks();
};

#endif