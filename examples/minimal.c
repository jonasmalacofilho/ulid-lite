#include <stdio.h>
#include "ulid.h"

int main(void) {
    char str[27];

    ulid_ctx ctx = ulid_init(0);
    ulid_write_new(&ctx, str, sizeof(str));

    printf("%s\n", str);

    return 0;
}
