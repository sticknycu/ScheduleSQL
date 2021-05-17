#include "modify.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void modifyFile(char* nameFile, char* target, char* destination, char* newName) {
    char src[1000], dest[1000];

    // Concatenare "mv " + "source " + "destination"
    // Pentru a face intr-un string "mv source destination"
    // system("mv ScheduleSQL.json target.json");
    char c[1000];
    strcpy(c,"mv ");
    strcat(c, target); //
    strcat(c,"/");
    strcat(c, nameFile);
    strcat(c, " ");
    strcat(c, destination);
    strcat(c, newName);

    system(dest);
}

void modifyDatabase(char* name, char* target, char* destination, char* newName) {
    char src[1000], dest[1000];
    strcpy(src, target);
    strcpy(dest, "find -d ");

    strcat(dest, src);

    // Daca nu gaseste fisierul
    if(system(dest) == -1) {
#ifdef __linux__
        mkdir(target, S_IRWXU);
#else
        mkdir(target);
#endif
        chdir(target);
        modifyFile(name, target, destination, newName);
        // Daca gaseste fisierul
    } else {
        // Mergem in directorul respectiv
        chdir(target);
        // Stergem fisierul
        modifyFile(name, target, destination, newName);
    }
}