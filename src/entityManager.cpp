# include <entityManager.hpp>
#include <iostream>

Task* EntityManager::getTask(int id){
    Node<Task*>* aux = tasks.head;
    while(aux != nullptr){
        if(aux->data->getID() == id) return aux->data;
        aux = aux->next;
    }
    return nullptr;
}

std::vector<Task*> EntityManager::getUserTasks(int userID) {
    std::vector<Task*> vector;
    auto pos = vector.begin();
    Node<Task*>* aux = tasks.head;
    while(aux != nullptr) {
        if(aux->data->getCreatorID() == userID) vector.insert(pos, aux->data);
        aux = aux->next;
    }
    return vector;
}

Group* EntityManager::getGroup(int groupID) {
    Node<Group*>* aux = groups.head;
    while(aux != nullptr) {
        if(aux->data->getID() == groupID) return aux->data;
    }
    return nullptr;
}

User* EntityManager::getUser(int userID) {
    Node<User*>* aux = users.head;
    while (aux != nullptr) {
        if(aux->data->getID() == userID) return aux->data;
    }
    return nullptr;
}

std::vector<User*> EntityManager::getGroupUsers(int groupID) {
    std::vector<User*> groupUsers;
    std::vector<int> userIDS;
    Node<Group*>* aux = groups.head;

    while(aux != nullptr) {
        if(aux->data->getID() == groupID) {
            userIDS = aux->data->getUsers();
            break;
        }
    }
    User* userptr = nullptr;
    auto pos = groupUsers.begin();
    for(const int& i: userIDS) {
        userptr = this->getUser(i);
        if(userptr != nullptr) groupUsers.insert(pos, userptr);
    }
    return groupUsers;
}

int EntityManager::getNewEntityID(EntityType type) {
    int maxID = -1;
    switch(type) {
        case EntityType::GROUP:
            for(Node<Group*>* n = groups.head; n; n = n->next) {
                if(maxID < n->data->getID()) maxID = n->data->getID();
            }
            break;
        case EntityType::TASK:
        for(Node<Task*>* n = tasks.head; n; n = n->next) {
                if(maxID < n->data->getID()) maxID = n->data->getID();
            }
            break;
        case EntityType::USER:
        for(Node<User*>* n = users.head; n; n = n->next) {
                if(maxID < n->data->getID()) maxID = n->data->getID();
            }
            break;
        default:
            std::cout << "Invalid type!! Check code, dumbass." << std::endl;
            return -1;
    }
    return maxID + 1;
}

bool EntityManager::addTask(int creatorID, std::string name, std::string description, std::time_t* deadline) {
    int id = getNewEntityID(EntityType::TASK);
    return tasks.push(new Task(id, creatorID, name, description, TaskStatus::TODO, deadline));
}

bool EntityManager::addGroup(std::string name, std::string description, int creatorID) {
    int id = getNewEntityID(EntityType::GROUP);
    return groups.push(new Group(id, name, description, creatorID));
}

bool EntityManager::addUser(std::string name, std::string email) {
    int id = getNewEntityID(EntityType::USER);
    return users.push(new User(id, name, email));
}

bool EntityManager::entityExist(EntityType type, int entityID) {
    switch(type) {
        case EntityType::GROUP:
            for(Node<Group*>* n = groups.head; n; n = n->next) {
                if(entityID == n->data->getID()) return true;
            }
            break;
        case EntityType::TASK:
            for(Node<User*>* n = users.head; n; n = n->next) {
                if(entityID == n->data->getID()) return true;
            }
            break;
        case EntityType::USER:
            for(Node<Task*>* n = tasks.head; n; n = n->next) {
                if(entityID == n->data->getID()) return true;
            }
            break;
        default:
            std::cout << "Entity does not exist. Check your code." << std::endl;
    }
    return false;
}

bool EntityManager::addTaskToGroup(int taskID, int groupID) {
    if(entityExist(EntityType::GROUP, groupID)) {
        if(!entityExist(EntityType::TASK, taskID)) {
            getGroup(groupID)->addTask(taskID);
            return true;
        }
    }
    return false;
}

bool EntityManager::modifyTask(int taskID, std::string* name, std::string* description, TaskStatus* status, std::time_t* deadline, int modifierID) {
        return this->getTask(taskID)->modifyTask(name, description, deadline, modifierID);
}

bool EntityManager::removeUserFromGroup(int userID, int groupID) {
    if(this->getGroup(groupID)->userExist(userID)) {
        this->getGroup(groupID)->removeUser(userID);
    }
}

bool EntityManager::removeTaskFromUser(int taskID, int userID) {
    User* usr = this->getUser(userID);
    if (usr != nullptr) {
        return usr->removeTask(taskID);
    }
    return false;
}

bool EntityManager::addTaskToUser(int userID, int taskID) {
    User* usr = this->getUser(userID);
    if (usr != nullptr) {
        return usr->addTask(taskID);
    }
    return false;
}

bool EntityManager::removeTaskFromGroup(int groupID, int taskID) {
    Group* grp = this->getGroup(groupID);
    if (grp != nullptr) {
        if (!grp->taskExist(taskID)) {
            grp->addTask(taskID);
            return true;
        }
    }
    return false;
}

bool EntityManager::addUserToGroup(int userID, int groupID) {
    Group* grp = this->getGroup(groupID);
    if (grp != nullptr) {
        
    }
}