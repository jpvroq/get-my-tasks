#ifndef GROUP_H
#define GROUP_H

#include <stdint.h>
#include <string>
#include <vector>
#include <entity.hpp>

class Group : public Entity {
    private:
    const std::string name;
    std::string description;
    const int creatorID;
    std::vector<int> users;
    std::vector<int> tasks;

    public:
    Group(int id, std::string name, std::string description, int creatorID)
        : Entity(id), name(name), description(description),
        creatorID(creatorID) {}
    ~Group();
    std::string getName();
    std::string getDescription();
    std::vector<int> getUsers();
    std::vector<int> getTasks();
    void addTask(int taskID);
    void addUser(int userID);
    void removeTask(int taskID);
    void removeUser(int userID);
    bool taskExist(int taskID);
    bool userExist(int userID);
};

#endif