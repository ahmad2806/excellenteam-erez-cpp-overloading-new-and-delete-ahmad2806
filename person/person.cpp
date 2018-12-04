//
// Created by ahmad on 04/12/2018.
//

#include "person.h"
#include <iostream>
#include <stdlib.h>
#include "cstring"

unsigned char Person::s_pool[sizeof(Person) * Person::POOL_SIZE];
void *Person::s_free_list = Person::init_memory_pool();

void *Person::init_memory_pool() {
    unsigned char *memory_pool = Person::s_pool;

    for (int i = 0; i < Person::POOL_SIZE - 1; i++) {

        *(void **) memory_pool = memory_pool + sizeof(Person);
        memory_pool = memory_pool + sizeof(Person);
    }
    *(void **) memory_pool = NULL;
    return Person::s_pool;
}

void *Person::operator new(std::size_t) {
    void *free_item = Person::s_free_list;
    if (!free_item) {
        throw std::bad_alloc();
    }
    Person::s_free_list = *(void **) s_free_list;
    return free_item;
}

void Person::operator delete(void *ptr) {
    *(void **) ptr = Person::s_free_list;
    Person::s_free_list = ptr;
}

Person::Person(char name[32], unsigned int id, unsigned int age) : id(id), m_age(age) {
    strcpy(fullname, name);
}