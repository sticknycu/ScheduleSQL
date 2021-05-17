#include <stdio.h>
#include <string.h>
#include "instructions/modify.h"
#include "instructions/create.h"
#include "instructions/delete.h"

#ifdef __linux__
#include "../json-c/json.h"
#else
#include "..\json-c\json.h"
#endif //__linux__

// Because SIG_DFL or SIG_IGN could be NULL instead of nullptr, we need to disable the Clang warning here
#ifdef __clang__
    #pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wunknown-warning-option"
	#pragma clang diagnostic ignored "-Wunknown-pragmas"
	#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif  // __clang__


int main(int argc, char** argv) {
    /*
     * ``-<type of action>
     * <name of database>
     * -<instruction flag>
     * <location database>
     * -<interaction flag>
     * <location 1> <location 2> <location 3>``
     */

    puts("");
    printf("Argumente: %s %s" , argv[1], argv[2]);

    if (strcmp(argv[1], "-c") == 0) {
        if (strcmp(argv[3], "-t") != 0) {
            createFile(argv[2]);
        } else {
            createDatabase(argv[2], argv[4]);
        }
    } else if (strcmp(argv[1], "-d") == 0) {
        if (strcmp(argv[3], "-t") != 0) {
            deleteFile(argv[2]);
        } else {
            deleteDatabase(argv[2], argv[4]);
        }
        // TODO: Check argv[0], argv[7]
    } else if (strcmp(argv[1], "-m") == 0) {
        if (strcmp(argv[3], "-t") != 0)
            modifyFile(argv[2], argv[0], argv[0], argv[8]);
        else
            modifyDatabase(argv[2], argv[4], argv[6], argv[8]);
    }

    /*if (strcmp(argv[1], "-d") == 0) {
        puts("");
        remove(argv[2]);
    }*/
    puts("");
    return 0;
}
