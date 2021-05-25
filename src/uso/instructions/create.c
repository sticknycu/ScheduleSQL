#include "create.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#ifdef __linux__
#include <unistd.h>
#endif

void createFile(char *nameFile) {
    char src[1000], dest[1000];

    strcpy(src, nameFile);
    strcpy(dest, "./create.sh ");
    system(strcat(dest, src));
}

void createDatabase(char* name, char* target) {
    char src[1000], dest[1000];

    strcpy(src, strcat(name, strcat(strcpy(src, " "), target)));

    strcpy(dest, "./create_directory.sh ");

    printf("\n%s", strcat(dest, src));
    //system(strcat(dest, src));
}
