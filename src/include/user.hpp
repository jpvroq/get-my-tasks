#ifndef USER_H
#define USER_H

#include <stdint.h>
#include <string>
#include <ctime>
#include <vector>

#include <entity.hpp>

class User : public Entity {
    private:
    std::string name;
    std::string email;
    const time_t joinedOn;
    time_t modifiedOn;
    
    std::vector<int> tasks;

    public:
    User(int id, std::string name, std::string email) :
        Entity(id), name(name), email(email), joinedOn(std::time(0)), modifiedOn(std::time(0)) {}
    ~User();
    int getID();
    std::string getName();
    std::string getEmail();
    time_t getJoinedOn();
    std::vector<int> getTasks();
    bool modify(std::string* newName, std::string* newEmail);
    bool removeTask(int taskID);
    bool addTask(int taskID);
    bool operator==(const User& b);
    bool operator!=(const User& b);
};

#endif