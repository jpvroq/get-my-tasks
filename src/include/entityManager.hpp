#ifndef ENTiTYMANAGER_H
#define ENTITYMANAGER_H

#include <group.hpp>
#include <task.hpp>
#include <user.hpp>
#include <linkedlist.hpp>
#include <entity.hpp>

class EntityManager{
    private:
    LinkedList<Task*> tasks;
    LinkedList<Group*> groups;
    LinkedList<User*> users;

    public:
    Task* getTask(int id);
    std::vector<Task*> getUserTasks(int uID);
    Group* getGroup(int id);
    User* getUser(int id);
    std::vector<User*> getGroupUsers(int gid);
    int getNewEntityID(EntityType type);
    bool deleteNode(int type, int id);
    bool addTask(int creatorID, std::string name, std::string description, std::time_t* deadline);
    bool addUser(std::string name, std::string email);
    bool addGroup(std::string name, std::string description, int userID);
    bool addUserToGroup(int userID, int groupID);
    bool addTaskToUser(int taskID, int userID);
    bool addTaskToGroup(int taskID, int groupID);
    bool modifyTask(int taskID, std::string* name, std::string* description, TaskStatus* status, std::time_t* deadline, int modifierID);
    bool removeUserFromGroup(int userID, int groupID);
    bool removeUserFromGroup(int userID);
    bool removeTaskFromUser(int taskID, int userID);
    bool removeTaskFromGroup(int taskID, int groupID);
    bool removeEntity(EntityType type, int entityID);
    bool entityExist(EntityType type, int entityID);
    bool userExist(User& user);
    bool groupExist(Group& group);
    bool taskExist(Task& task);

};

#endif