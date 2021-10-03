#include "Constants.c"
extern char SUCCESS_MESSAGE[60];
extern char FAIL_MESSAGE[50];
void check(int flag)
{
    if (flag == 1)
    {
        message(SUCCESS_MESSAGE);
        exit(0);
    }
    else
    {
        message(FAIL_MESSAGE);
        exit(0);
    }
    getch();
}
