#include <group.hpp>
#include <bits/stdc++.h>

void Group::addTask(int taskID) {
    tasks.push_back(taskID);
}

void Group::addUser(int userID) {
    users.push_back(userID);
}

void Group::removeTask(int taskID) {
    auto it = std::find(tasks.begin(), tasks.end(), taskID);
    tasks.erase(it);
}

void Group::removeUser(int userID) {
    auto it = std::find(users.begin(), users.end(), userID);
    users.erase(it);
}

bool Group::taskExist(int taskID) {
    auto it = std::find(tasks.begin(), tasks.end(), taskID);
    if (it == tasks.end()) return false;
    return true;
}

bool Group::userExist(int userID) {
    auto it = std::find(users.begin(), users.end(), userID);
    if (it == users.end()) return false;
    return true;
}

bool Group::operator==(Group& group) {
    if(name == group.getName()) return true;
    return false;
}