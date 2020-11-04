#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long res = 0;
    unsigned long dp = 1;

    if (!hex)
        return 0;
    for (int i = 0; hex[i + 1]; i++)
        dp *= 16;
    for (int i = 0; hex[i]; i++) {
        res += dp * (hex[i] 
                            - 48 * (hex[i] >= 48 && hex[i] <= 57)
                            - 55 * (hex[i] >= 65 && hex[i] <= 70)
                            - 87 * (hex[i] >= 97 && hex[i] <= 102)
                            );
        dp /= 16;
    }
    return res;
}
