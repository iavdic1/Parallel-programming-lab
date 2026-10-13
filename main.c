#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int ival = atoi(argv[1]);
    int ipos = -1;

    int *iarray = malloc(10 * sizeof(int));

    if (iarray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        iarray[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        if (ival == iarray[i]) {
            ipos = i;
            break;
        }
    }

    printf("Position: %d\n", ipos);

    free(iarray);
    return 0;
}

