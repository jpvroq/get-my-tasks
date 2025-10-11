#ifndef USER_H
#define USER_H

#include <stdint.h>
#include <string>
#include <ctime>
#include <vector>

#include <entity.hpp>

class User : public Entity {
    private:
    const std::string name;
    const std::string email;
    const time_t joinedOn;
    
    std::vector<int> tasks;

    public:
    User(int id, std::string name, std::string email) :
        Entity(id), name(name), email(email), joinedOn(std::time(0)) {}
    ~User();
    std::string getName();
    time_t getJoinedOn();
    std::vector<int> getTasks();
    bool removeTask(int taskID);
    bool addTask(int taskID);
    bool operator==(const User& b);
    bool operator!=(const User& b);
};

#endif