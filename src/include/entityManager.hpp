#ifndef ENTiTYMANAGER_H
#define ENTITYMANAGER_H

#include <group.hpp>
#include <tasks.hpp>
#include <user.hpp>
#include <linkedlist.hpp>
#include <entity.hpp>

class EntityManager{
    private:
    LinkedList<Task> tasks;
    LinkedList<Group> groups;
    LinkedList<User> users;

    public:
    Task* getTask(int id);
    std::vector<Task*> getUserTasks(int uID);
    Group* getGroup(int id);
    User* getUser(int id);
    std::vector<User*> getGroupUsers(int gid);
    bool deleteNode(int type, int id);
    bool addTask(int creatorID, std::string name, std::string description);
    bool addUser(std::string name, std::string email);
    bool addGroup(std::string name, std::string description, int userID);
    bool addUserToGroup(int userID, int groupID);
    bool addTaskToUser(int taskID, int userID);
    bool addTaskToGroup(int taskID, int groupID);
    bool modifyTask(int taskID, std::string name, std::string description, TaskStatus status, int modifierID);
    bool removeUserFromGroup(int userID, int groupID);
    bool removeTaskFromUser(int taskID, int userID);
    bool removeTaskFromGroup(int taskID, int groupID);
    bool removeTask(int taskID);
    bool removeUser(int userID);
    bool removeGroup(int groupID);

};

#endif