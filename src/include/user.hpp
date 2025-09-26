#ifndef USER_H
#define USER_H

#include <stdint.h>
#include <string>
#include <ctime>
#include <vector>

class User {
    private:
    const uint16_t id;
    const std::string name;
    const time_t joinedOn;
    
    std::vector<uint16_t> task;

    public:
    uint16_t getID();
    std::string getName();
    time_t getJoinedOn();
    std::vector<uint16_t> getTasks();
};

struct User_s{
    uint16_t id;
    std::string name;
    time_t joinedOn;
    std::vector<uint16_t> task;
};

#endif