#include <stdio.h>
#include <stdlib.h>

#define that(x) do {                                                       \
    if (!(x)) {                                                            \
        fprintf(stderr, "Assert fail in %s/%d. Condition '%s' not met.\n", \
        __FILE__, __LINE__, #x);                                           \
        abort();                                                           \
    }                                                                      \
} while (0)
