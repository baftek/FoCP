// Copyright 2014 by Siarkowy.
// Released under the terms of GNU GPL v3 license.

#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct Person
{
    char *name;
    unsigned age;
} Person;

#define PEOPLE_NUM 5

Person people[] = {
    { "Zyx",    21 },
    { "Xyz",    23 },
    { "Abc",    21 },
    { "Ghj",    17 },
    { "Abcd",   21 },
};

int comp_persons(const void *A, const void *B)
{
    const Person *pA = (Person *) A;
    const Person *pB = (Person *) B;

    return pA->age == pB->age ?
        strcmp(pA->name, pB->name) : pA->age > pB->age;
}

int main(int argc, char **argv)
{
    int i;

    qsort(people, PEOPLE_NUM, sizeof(Person), comp_persons);

    for (i = 0; i < PEOPLE_NUM; ++i)
        printf("%s %d\n", people[i].name, people[i].age);

    return 0;
}
