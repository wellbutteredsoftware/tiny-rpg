#include <stdlib.h>
#include <stdio.h>

#define that(x) do {                                                                 \
        if (!(x)) {                                                                  \
            fprintf(stderr, "Assertion failure in %s/%d. Condition '%s' not met.\n", \
            __FILE__, __LINE__, #x);                                                 \
            abort();                                                                 \
        }                                                                            \
    } while (0)
