#include "random.h"

int rand_num() {
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1) {
        printf("%s\n", strerror(errno));
    }
    int num = 0;
    int *p = &num;
    if (read(fd, p, sizeof(int)) == -1) {
        printf("%s\n", strerror(errno));
    }
    close(fd);
    return num;
}
