#include <stdio.h>
#include <stdlib.h>

static const int coinsDenom[] = {50, 10, 5, 2, 1, -1};

unsigned int simple_hashfunc(char *string)
{
        unsigned int simple_hashfunc = 0;

        for (int i = 0; string[i] != '\0'; i++)
                simple_hashfunc += string[i];

        return simple_hashfunc;
}

void putCoins(int summa)
{
        if (summa <= 0)
                return;
        for (int i = 0; coinsDenom[i] != -1; i++) {
                if (summa - coinsDenom[i] >= 0) {
                        printf("%u ", coinsDenom[i]);
                        putCoins(summa - coinsDenom[i]);
                        break;
                }
        }
}

int main()
{
        char *strings[] = {"AAAAAAAA", "Hello, world!", "1122", "0342", "", NULL};
        for (int i = 0; strings[i] != NULL; i++)
                printf("Sinple hash-sum of '%s': %u\n",
                       strings[i], simple_hashfunc(strings[i]));

        int summation[] = {98, 20, -1, 123, 1010};
        for (int i = 0; i < 5; i++) {
                printf("\n%d: ", summation[i]);
                putCoins(summation[i]);
        }

        return 0;
}
