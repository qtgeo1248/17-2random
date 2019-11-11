#include "random.h"

int main() {
    int arr[10];
    int i = 0;
    printf("Generating Random Numbers:\n");
    for (; i < 10; i++) {
        int current = ranNum();
        printf("\t%d\n", current);
        arr[i] = current;
    }

    return 0;
}
