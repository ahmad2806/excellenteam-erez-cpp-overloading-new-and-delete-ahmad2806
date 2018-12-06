#include <iostream>
#include <stddef.h>
#include "cstring"
#include "person.h"


Person::Person(char name[32], unsigned int id, unsigned int age):m_id(id),m_age(age){
    strcpy(m_full_name,name);
}

Person::Person(Person &other) {
    strcpy(m_full_name,other.fullname);
    m_id = other.id;
    m_age = other.m_age;
}

char *Person::get_full_name() {
    return full_name;
}


