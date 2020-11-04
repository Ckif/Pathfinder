#include "pathfinder.h"

bool cf_cmpint(int *s1, int *s2) {
    if (s1[0] == -1 || s2[0] == -1)
        return false;
    for (int i = 0; s1[i] != -1 || s2[i] != -1; i++) {
        if (s1[i] != s2[i])
            return false;
        }
    for (int l = 0; s2[l] != -1; l++)
        s2[l] = -1;
    return true;
}

