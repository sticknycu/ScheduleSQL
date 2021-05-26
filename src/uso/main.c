#include <stdio.h>
#include <string.h>
#include "instructions/modify.h"
#include "instructions/create.h"
#include "instructions/delete.h"

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
    printf("Argumente: %s %s + %d", argv[1], argv[2], argc);

    if (argc > 1 && strcmp(argv[1], "-c") == 0) {
        if (argc > 3 && strcmp(argv[3], "-t") == 0) {
            if (argc > 4) {
                createDatabase(argv[2], argv[4]);
            } else {
                createFile(argv[2]);
            }
        } else {
            createFile(argv[2]);
        }
    } else if (argc > 1 && strcmp(argv[1], "-d") == 0) {
        if (argc > 3 && strcmp(argv[3], "-t") == 0) {
            if (argc > 4) {
                deleteDatabase(argv[2], argv[4]);
            } else {
                deleteFile(argv[2]);
            }
        } else {
            deleteFile(argv[2]);
        }
    } else if (argc > 1 && strcmp(argv[1], "-m") == 0) {
        if (argc > 3 && strcmp(argv[3], "-t") != 0) {
            modifyName(argv[2], argv[3]);
        } else {
            if (argc > 5 && strcmp(argv[5], "-lc") != 0) {
                modifyNameTarget(argv[2], argv[5], argv[4]);
            } else if (argc > 7 && strcmp(argv[7], "-mc") == 0) {
                modifyFileAddContent(argv[2], argv[4], argv[6], argv[8]);
            } else if (argc > 7 && strcmp(argv[7], "-dc") == 0) {
                modifyFileDeleteContent(argv[2], argv[4], argv[6]);
            }
        }
    }

    puts("");
    return 0;
}
