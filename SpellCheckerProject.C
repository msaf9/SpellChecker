/* Project Title: Spell Checker Project
   Author: Sahil Afrid Farookhi
   Programming language: C
   Concepts used: Files, loops, control statements, and variable declaration
   File name: dictionary.txt
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
void check(int);
void message(char[]);
void main()
{
    int i = 0, a, flag = 0;
    char word[20], x[20], c;
    char WELCOME_MESSAGE[40] = "Hello!\nWelcome to Spell Checker\n";
    char INPUT_MESSAGE[20] = "Enter word: ";
    char ERROR_MESSAGE[120] = "\nUnable to process ;(\nError code #707\nYour dictionary file is missing!\nPlease reach out developer :(";
    system("clear");
    FILE *dict;
    message(WELCOME_MESSAGE);
    message(INPUT_MESSAGE);
    gets(word);
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL)
    {
        message(ERROR_MESSAGE);
        exit(0);
        getch();
    }
    else
    {
        i = 0;
        while (((c = getc(dict)) != EOF))
        {
            if ((c == ' ' || c == '\n' || c == '\t') && (flag == 0))
            {
                x[i] = '\0';
                a = strcmpi(word, x);
                if (a == 0)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
                i = 0;
            }
            else
            {
                x[i] = c;
                i++;
            }
        }
    }
    check(flag);
}

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

void message(char prompt[150])
{
    printf("%s", prompt);
}