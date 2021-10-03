void check(int flag)
{
    char SUCCESS_MESSAGE[60] = "\nCorrect spelling :)\nThank you!\nHave a nice day :)";
    char FAIL_MESSAGE[50] = "\nIncorrect spelling :(\nTry again...";
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
