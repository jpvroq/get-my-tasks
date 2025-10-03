#include <task.hpp>

bool Task::modifyTask(std::string* newName, std::string* newDescription, std::time_t* newDeadline, int modifierID) {
    bool modified = false;
    if (newName != nullptr)
    {
        this->name = *newName;
        modified = true;
    }
    if (newDescription != nullptr) {
        this->description = *newDescription;
        modified = true;
    }
    if (newDeadline != nullptr) {
        this->deadline = newDeadline;
        modified = true;
    }
    if (modified == true) {
        this->modifierID = modifierID;
        return true;
    }
    return false;
}