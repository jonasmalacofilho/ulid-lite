#include <stdio.h>
#include "ulid.h"

int main(void) {
    ulid_ctx ctx;
    ulid_t id;
    char buf[64], *cur = buf;
    int n, size = sizeof(buf);

    ctx = ulid_init(0);
    ulid_new(&ctx, &id);

    n = snprintf(cur, size, "Your ULID is ");
    if (n >= size)
        return 1;
    cur += n;
    size -= n;

    n = ulid_write(&id, cur, size);
    if (n < 0) /* failed, typically buffer is too small */
        return 1;
    cur += n;
    size -= n;

    n = snprintf(cur, size, ".");
    if (n >= size)
        return 1;

    printf("%s\n", buf);
    return 0;
}
