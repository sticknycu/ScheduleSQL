#ifndef SCHEDULESQL_MODIFY_H
#define SCHEDULESQL_MODIFY_H

#include <stdio.h>

void modifyName(char *nameFile, char *newName);

void modifyNameTarget(char *nameFile, char *newName, char *target);

void modifyDatabase(char *nameFile, char *target, char *destination, char *newName);

void modifyFile(char *nameFile, char *target, char *destination, char *entry);

#endif //SCHEDULESQL_MODIFY_H
