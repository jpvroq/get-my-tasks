# include <entityManager.hpp>

Task* EntityManager::getTask(int id){
    Node<Task>* aux = tasks.head;
    while(aux != nullptr){
        if(aux->data.getID() == id) return &(aux->data);
        aux = aux->next;
    }
    return nullptr;
}

std::vector<Task*> EntityManager::getUserTasks(int userID) {
    std::vector<Task*> vector;
    auto pos = vector.begin();
    Node<Task>* aux = tasks.head;
    while(aux != nullptr) {
        if(aux->data.getCreatorID() == userID) vector.insert(pos, &(aux->data));
        aux = aux->next;
    }
    return vector;
}

Group* EntityManager::getGroup(int groupID) {
    Node<Group>* aux = groups.head;
    while(aux != nullptr) {
        if(aux->data.getID() == groupID) return &(aux->data);
    }
    return nullptr;
}

User* EntityManager::getUser(int userID) {
    Node<User>* aux = users.head;
    while (aux != nullptr) {
        if(aux->data.getID() == userID) return &(aux->data);
    }
    return nullptr;
}

std::vector<User*> EntityManager::getGroupUsers(int groupID) {
    std::vector<User*> groupUsers;
    std::vector<int> userIDS;
    Node<Group>* aux = groups.head;

    while(aux != nullptr) {
        if(aux->data.getID() == groupID) {
            userIDS = aux->data.getUsers();
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