//
// Created by ahmad on 04/12/2018.
//

#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H


#include <cstddef>


class Person {
    static void *s_free_list;
    static unsigned char s_pool[];
    const static int POOL_SIZE = 5;
public:
    void *operator new(std::size_t count);

    void operator delete(void *ptr);

    Person(char fullname[32], unsigned int id, unsigned int age);

    static void *init_memory_pool();

    char fullname[32];
    unsigned int id;
    unsigned char m_age;
private:
    void *operator new[](size_t);

    void operator delete[](void *);


};

#endif //PERSON_PERSON_H
