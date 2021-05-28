#include "modify.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifdef __linux__
#include <unistd.h>
#endif


void modifyName(char *nameFile, char *newName) {
    char src[1000], dest[1000];

    strcpy(src, strcat(nameFile, strcat(strcpy(src, " "), newName)));

    strcpy(dest, "./modify.sh ");

    //printf("\n%s", strcat(dest, src));
    system(strcat(dest, src));
}

void modifyNameTarget(char *nameFile, char *newName, char *target) {
    char src[1000], dest[1000];

    strcpy(dest, "./modify_directory.sh ");

    strcpy(src, strcat(strcat(nameFile, " "), strcat(strcat(newName, " "),
                                                     target)));

    //printf("\n%s", strcat(dest, src));
    system(strcat(dest, src));
}

void modifyFileAddContent(char *nameFile, char *target, char *destination, char *entry) {
    char src[1000], dest[1000];

    strcpy(dest, "./modify_file_add_content.sh ");

    strcpy(src, strcat(strcat(nameFile, " "), strcat(strcat(target, " "),
                                                     strcat(strcat(destination, " "), entry))));

    //printf("\n%s", strcat(dest, src));
    system(strcat(dest, src));
}

void modifyFileDeleteContent(char *nameFile, char *target, char *destination) {
    char src[1000], dest[1000];

    strcpy(dest, "./modify_file_delete_content.sh ");

    strcpy(src, strcat(strcat(nameFile, " "), strcat(strcat(target, " "),
                                                     destination)));

    //printf("\n%s", strcat(dest, src));
    system(strcat(dest, src));
}