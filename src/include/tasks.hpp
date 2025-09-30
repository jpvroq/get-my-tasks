#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>
#include <string>
#include <ctime>

#include <status.hpp>

class Task{
    private:
    const int id;
    const int creatorID;
    int lastModifierID;
    const time_t createdOn;
    time_t modifiedOn;
    
    std::string name;
    std::string description;
    TaskStatus status;

    public:

    int getID();
    int getCreatorID();
    int getModifierID();
    time_t getCreateDate();
    time_t getModifiedDate();

    std::string getName();
    std::string getDescription();
    TaskStatus getStatus();
};

#endif