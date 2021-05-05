#include "create.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#define S_IRWXU _S_IRWXU

void createFile(char *nameFile) {
    char src[1000], dest[1000];

    // Concatenare "touch " + "BazaDeDate.json"
    // Pentru a face intr-un string "touch BazaDeDate.json"
    // system("touch BazaDeDate.json");
    strcpy(src, nameFile);
    strcpy(dest, "touch ");

    strcat(dest, src);

    system(dest);
}

void createDatabase(char* name, char* target) {
    // Verificam daca exista directorul respectiv
    char src[1000], dest[1000];

    // Concatenare "find " + target
    // Pentru a face intr-un string "find target"
    // system("find target");
    strcpy(src,  target);
    strcpy(dest, "find -d ");

    strcat(dest, src);

    // Daca nu a gasit directorul
    if (system(dest) == -1) {
        // Creeaza directorul
        mkdir(target, S_IRWXU);
        // Mergem in directorul respectiv
        chdir(target);
        // Cream fisierul
        createFile(name);
    }
}
