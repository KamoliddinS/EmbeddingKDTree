#include <iostream>
#include <vector>
#include <unordered_map>
#include "kdtree.hpp"

class Person {
public:
    int id;
    std::vector<float> embedding;

    Person(int id, std::vector<float> embedding) : id(id), embedding(embedding) {}
};

class PersonDatabase {
private:
    std::unordered_map<int, Person> id_map;
    KDTree kdtree;

public:
    void addPerson(const Person& person) {
        id_map[person.id] = person;
        kdtree.insert(person.embedding, person.id);
    }

    int searchPersonIdByEmbedding(const std::vector<float>& embedding) {
        int nearestId = kdtree.findNearest(embedding);
        return nearestId;
    }
};

int main() {

    PersonDatabase personDatabase;

    personDatabase.addPerson(Person(2, {4.0, 5.0, 6.0}));

    return 0;
}
