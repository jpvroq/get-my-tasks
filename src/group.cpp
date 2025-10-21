#include <group.hpp>
#include <bits/stdc++.h>

std::string Group::getName() {
    return name;
}

std::string Group::getDescription() {
    return description;
}

std::vector<int> Group::getTasks() {
    return tasks;
}

std::vector<int> Group::getUsers() {
    return users;
}

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

bool Group::operator!=(Group& group) {
    return !(this == &group);
}