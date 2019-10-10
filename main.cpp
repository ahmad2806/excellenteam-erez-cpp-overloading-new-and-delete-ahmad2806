#include <iostream>
#include "overload new and delete/overload_new_and_delete_template.h"
#include "test class/person.h"

int main() {
//    Person p ("abc",1,2);
//    AllocTemplate<Person,4> *p4 = new AllocTemplate<Person,4>(p);

//    std::cout<<p4->get_full_name()<<std::endl;
    int * m = new(int);
    int * m1 = new int;
    *m1 = 6;
    *m = 1;
    std::cout << *m1 << "   " << *m << std::endl;
    std::cout << m1 << "   " << m << std::endl;

    *(void**) m = m1;

    std::cout << *m1 << "   " << *m << std::endl;
    std::cout << m1 << "   " << m << std::endl;
    return 0;

}