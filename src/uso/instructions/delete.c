#include "delete.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void deleteFile(char *nameFile) {
    char src[1000], dest[1000];

    // Concatenare "rm -r " + target
    // Pentru a face intr-un string "rm -r target"
    // system("rm -r target");
    strcpy(src, nameFile);
    strcpy(dest, "rm -r ");

    strcat(dest, src);
    system(dest);
}

void deleteDatabase(char* name, char* target) {
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
        deleteFile(name);
        // Daca gaseste fisierul
    } else {
        // Mergem in directorul respectiv
        chdir(target);
        // Stergem fisierul
        deleteFile(name);
    }
}