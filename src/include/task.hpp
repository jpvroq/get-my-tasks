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
    int modifierID;
    const time_t createdOn;
    time_t modifiedOn;
    time_t deadline;
    
    std::string name;
    std::string description;
    TaskStatus status;

    public:
    Task(int id, int creatorID, std::string name,
         std::string description, TaskStatus status, std::time_t deadline) :
         Entity(id), creatorID(creatorID), modifierID(creatorID), 
         createdOn(std::time(0)),
         modifiedOn(std::time(0)),
         name(name), description(description), status(status), deadline(deadline) {}
    ~Task();
    int getCreatorID();
    int getModifierID();
    time_t getCreateDate();
    time_t getModifiedDate();

    std::string getName();
    std::string getDescription();
    TaskStatus getStatus();
    bool modifyTask(std::string* name, std::string* description, std::time_t* deadline, int modifierID);
    
};

#endif