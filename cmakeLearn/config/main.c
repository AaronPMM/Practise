#include <stdio.h>

void main(void)
{

#ifdef H_TEST_CONFIG
    printf("here is  test config\n");
#else
    printf("here is not in test config\n");
#endif
}
