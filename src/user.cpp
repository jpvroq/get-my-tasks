#include <user.hpp>

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