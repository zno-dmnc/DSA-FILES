#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "closeDIct.h"
#include "closeDict.c"

int main(){

    Dictionary d = createCloseDict();
    Queue acl;
    initQueue(&acl);
    Person p1 = {{"Zenno", "Abellana"}, {"SanJose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p2 = {{"Mallen", "Jugalbot"}, {"San Isidro", "Dao", "Tagb", "Bohol", 6300}};
    Person p3 = {{"Rem", "Marigomen"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p4 = {{"Jethro", "Engutan"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person update = {{"Rem", "Marigomen"}, {"Lindaville", "Dao", "Tagb", "Bohol", 6300}};
    Name n = {"Zenno", "Abellana"};
    Person p5 = {{"Stella", "Salde"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p6 = {{"kaelle", "Gravador"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p7 = {{"Ethan", "Montera"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person p8 = {{"Random", "Montera"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};
    Person update1 = {{"Zed", "Putong"}, {"San Jose", "Cogon", "Tagb", "Bohol", 6300}};



    insertCloseDict(&d, &acl, p1);
    insertCloseDict(&d, &acl, p2);
    insertCloseDict(&d, &acl, p3);
    insertCloseDict(&d, &acl, p4);
    insertCloseDict(&d, &acl, p5);
    insertCloseDict(&d, &acl, p6);
    insertCloseDict(&d, &acl, p7);
    visualize(d);
    insertCloseDict(&d, &acl, p8);
    printf("===============\n\n");
    // visualize(d);

    updateCloseDict(&d, n, update);
    deleteCloseDict(&d, n);
    updateName(&d, &acl, n, update1);

    printf("===============\n\n");
    visualize(d);
}