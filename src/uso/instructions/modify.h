#ifndef SCHEDULESQL_MODIFY_H
#define SCHEDULESQL_MODIFY_H

#include <stdio.h>

void modifyName(char *nameFile, char *newName);

void modifyNameTarget(char *nameFile, char *newName, char *target);

void modifyFileAddContent(char *nameFile, char *target, char *destination, char *entry);

void modifyFileDeleteContent(char *nameFile, char *target, char *destination);

#endif //SCHEDULESQL_MODIFY_H
