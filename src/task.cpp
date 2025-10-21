#include <task.hpp>

time_t Task::getCreateDate() {
    return createdOn;
}

int Task::getCreatorID() {
    return creatorID;
}

int Task::getModifierID() {
    return modifierID;
}

time_t Task::getModifiedDate() {
    return modifiedOn;
}

std::string Task::getName() {
    return name;
}

std::string Task::getDescription() {
    return description;
}

TaskStatus Task::getStatus() {
    return status;
}

bool Task::modifyTask(std::string* newName, std::string* newDescription, std::time_t* newDeadline, int modifierID) {
    bool modified = false;
    if (newName != nullptr)
    {
        if(*newName != name) {
            this->name = *newName;
            modified = true;
        }
    }
    if (newDescription != nullptr) {
        if(*newDescription != description) {
            this->description = *newDescription;
            modified = true;
        }
    }
    if (newDeadline != nullptr) {
        if(*newDeadline != deadline) {
            this->deadline = *newDeadline;
            modified = true;
        }
    }
    if (modified == true) {
        this->modifierID = modifierID;
        modifiedOn = std::time(0);
    }
    return modified;
}