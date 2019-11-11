#include "random.h"

int main() {
    int arr[10];
    int i = 0;
    printf("Generating Random Numbers:\n");
    for (; i < 10; i++) {
        int current = rand_num();
        printf("\trandom %d: %d\n", i, current);
        arr[i] = current;
    }

    int fd = open("rand_nums", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        printf("%s\n", strerror(errno));
        return 0;
    }
    printf("Writing Numbers to File...\n\n");
    if (write(fd, arr, sizeof(int) * 10) < 0) {
        printf("%s\n", strerror(errno));
        return 0;
    }
    close(fd);

    int arr_test[10];
    fd = open("rand_nums", O_RDONLY);
    if (fd < -1) {
        printf("%s\n", strerror(errno));
        return 0;
    }
    printf("Reading Numbers From File...\n\n");
    if (read(fd, arr_test, sizeof(int) * 10) < 0) {
        printf("%s\n", strerror(errno));
        return 0;
    }

    printf("Testing if Reading Worked\n");
    for (i = 0; i < 10; i++) {
        printf("\trandom %d: %d\n", i, arr_test[i]);
    }
    return 0;
}
