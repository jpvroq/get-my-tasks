#ifndef TASKS_H
#define TASKS_H

#include <stdint.h>
#include <string>
#include <ctime>
#include <chrono>

#include <status.hpp>
#include <entity.hpp>

class Task : public Entity{
    private:
    const int creatorID;
    int lastModifierID;
    const time_t createdOn;
    time_t modifiedOn;
    
    std::string name;
    std::string description;
    TaskStatus status;

    public:
    Task(int id, int creatorID, std::string name,
         std::string description, TaskStatus status) :
         Entity(id), creatorID(creatorID), lastModifierID(creatorID), 
         createdOn(std::time(0)),
         modifiedOn(std::time(0)),
         name(name), description(description), status(status) {}
    ~Task();
    int getCreatorID();
    int getModifierID();
    time_t getCreateDate();
    time_t getModifiedDate();

    std::string getName();
    std::string getDescription();
    TaskStatus getStatus();
    
};

#endif