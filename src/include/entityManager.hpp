#ifndef ENTiTYMANAGER_H
#define ENTITYMANAGER_H

#include <group.hpp>
#include <tasks.hpp>
#include <user.hpp>
#include <linkedlist.hpp>

class EntityManager{
    private:
    LinkedList<Task> tasks;
    LinkedList<Group> groups;
    LinkedList<User> users;

    public:
    Task getTask(uint16_t id);
    std::vector<Task> getUserTasks(uint16_t uID);
    Group getGroup(uint8_t id);
    User getUser(uint16_t id);
    std::vector<User> getGroupUsers(uint8_t gid);
    bool delete
};

#endif