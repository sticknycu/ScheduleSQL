#include <stdio.h>

// Because SIG_DFL or SIG_IGN could be NULL instead of nullptr, we need to disable the Clang warning here
#ifdef __clang__
    #pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wunknown-warning-option"
	#pragma clang diagnostic ignored "-Wunknown-pragmas"
	#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif  // __clang__


int main(int argc, char** argv)
{
    printf("Bonjour, Monde!\n");
    return 0;
}
