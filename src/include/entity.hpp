#ifndef ENTITY_H
#define ENTITY_H

enum EntityType {
    TASK,
    GROUP,
    USER
};

class Entity {
    private:
    const int id;

    public:
    Entity(const int& id) : id(id) {}
    virtual ~Entity() {};
    int getID() const {return id;}
};

#endif