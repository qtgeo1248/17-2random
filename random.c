#include "random.h"

int ranNum() {
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1) {
        printf("%s\n", strerror(errno));
    }
    int num = 0;
    int *p = &num;
    if (read(fd, p, 4) == -1) {
        printf("%s\n", strerror(errno));
    }
    return num;
}
