#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "openDIct.h"
#include "openDict.c"

int main(){

    Dictionary d = createOpenDict();
    Queue acl;
    initQueue(&acl);
    Person p1 = {{"Zenno", "Abellana"}, {"SanJ ose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p2 = {{"Mallen", "Jugalbot"}, {"San Isidro", "Dao", "Tagb", "Bohol", 6300}};
    Person p3 = {{"Rem", "Marigomen"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p4 = {{"Jethro", "Engutan"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person update = {{"Rem", "Random"}, {"Lindaville", "Dao", "Tagb", "Bohol", 6300}};
    Name n = {"Rem", "Marigomen"};
    Person p5 = {{"Stella", "Salde"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p6 = {{"kaelle", "Gravador"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p7 = {{"Ethan", "Montera"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p8 = {{"Random", "Montera"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};


    insertOpenDict(&d, &acl, p1);
    insertOpenDict(&d, &acl, p2);
    insertOpenDict(&d, &acl, p3);
    insertOpenDict(&d, &acl, p4);
    insertOpenDict(&d, &acl, p5);
    insertOpenDict(&d, &acl, p6);
    insertOpenDict(&d, &acl, p7);
    visualize(d);
    insertOpenDict(&d, &acl, p8);
    printf("===============\n\n");
    visualize(d);

    // updateOpenDict(&d, n, update);
    // deleteOpenDict(&d, n);
    // updateName(&d, n, update);

    // printf("===============\n\n");
    // visualize(d);
}