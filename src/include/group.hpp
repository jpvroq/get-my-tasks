#ifndef GROUP_H
#define GROUP_H

#include <stdint.h>
#include <string>
#include <vector>

class Group{
    private:
    const uint8_t id;
    const std::string name;
    std::string description;
    std::vector<uint16_t> users;
    std::vector<uint16_t> tasks;

    public:
    uint8_t getID();
    std::string getName();
    std::string getDescription();
    std::vector<uint16_t> getUsers();
    std::vector<uint16_t> getTasks();
};

struct Group_s{
    uint8_t id;
    std::string name;
    std::string description;
    std::vector<uint16_t> users;
    std::vector<uint16_t> tasks;
};

#endif