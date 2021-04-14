#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Because SIG_DFL or SIG_IGN could be NULL instead of nullptr, we need to disable the Clang warning here
#ifdef __clang__
    #pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wunknown-warning-option"
	#pragma clang diagnostic ignored "-Wunknown-pragmas"
	#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif  // __clang__


int main(int argc, char** argv) {
    char src[50], dest[50];

    // program.exe -c BazaDeDate.json // CREATE
    // program.exe -u BazaDeDate.json -i angajati -t nume -m Albert // INSERT
    // program.exe -d BazaDeDate.json // DELETE

    puts("");
    printf("Argumente: %s %s" , argv[1], argv[2]);
    /*if (strcmp(argv[1], "-u") == 0) {
        // baza de date = BazaDeDate.json
        if (strcmp(argv[3], "-i")) {
            // inseram

        }
    }*/
    if (strcmp(argv[1], "-c") == 0) {
        // scriem codul pentru create
        // touch BazaDeDate.sql
        strcpy(src,  argv[2]);
        strcpy(dest, "touch ");
        // Concatenare "touch " + "BazaDeDate.json"
        // Pentru a face intr-un string "touch BazaDeDate.json"
        // system("touch BazaDeDate.json");

        strcat(dest, src);
        system(dest);
    }

    if (strcmp(argv[1], "-d") == 0) {
        puts("");
        remove(argv[2]);
    }
    puts("");
    return 0;
}
