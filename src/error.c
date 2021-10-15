#include "../includes/philo.h"

void error(int code)
{
    if (code == 1)
    {
        printf("bad valid\n");
        exit(1);
    }
    if (code == 2)
    {
        printf("bad init\n");
        exit(1);
    }
}