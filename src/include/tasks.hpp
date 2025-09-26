#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>
#include <string>
#include <ctime>

#include <status.hpp>

class Task{
    private:
    const uint16_t id;
    const std::string creator;
    std::string lastModifier;
    const time_t createdOn;
    time_t modifiedOn;
    
    std::string name;
    std::string description;
    TaskStatus status;

    public:

    uint16_t getNewID();
    std::string getCreator();
    std::string getModifier();
    time_t getCreateDate();
    time_t getModifiedDate();

    std::string getName();
    std::string getDescription();
    TaskStatus getStatus();
};

struct Task_s{
    uint16_t id;
    std::string creator;
    std::string lastModifier;
    time_t createdOn;
    std::string name;
    std::string description;
    TaskStatus status;
};
#endif