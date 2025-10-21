#include <user.hpp>

std::string User::getName() {
    return name;
}

time_t User::getJoinedOn() {
    return joinedOn;
}

bool User::modify(std::string* newName, std::string* newEmail) {
    bool modified = false;
    if(newName != nullptr) {
        if(*newName != name){
            name = *newName;
            modified = true;
        }
    }
    if(newEmail != nullptr) {
        if(*newEmail != email) {
            email = *newEmail;
            modified = true;
        }
    }
    if(modified) {
        modifiedOn = std::time(0);
    }
    return modified;
}

bool User::addTask(int taskID) {
    for (int assignedTaskID : tasks) {
        if (assignedTaskID == taskID) return false;
    }
    tasks.push_back(taskID);
    return true;
}

bool User::removeTask(int taskID) {
    for (auto pos = tasks.begin(); pos < tasks.end(); pos++){
        if (*pos == taskID) {
            tasks.erase(pos);
            return true;
        }
    }
    return false;
}

bool User::operator==(const User& b) {
    if(name == b.name && email == b.email) return true;
    return false;
}

bool User::operator!=(const User& b) {
    return !(this == &b);
}