#ifndef USER_H
#define USER_H

#include <stdint.h>
#include <string>
#include <ctime>
#include <vector>

class User {
    private:
    const int id;
    const std::string name;
    const std::string email;
    const time_t joinedOn;
    
    std::vector<uint16_t> task;

    public:
    int getID();
    std::string getName();
    time_t getJoinedOn();
    std::vector<int> getTasks();
};

#endif