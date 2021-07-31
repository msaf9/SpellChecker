/* Project Title: Spell Checker Project
   Author: Mohammad Sahil Afrid Farookhi
   University ID: 150030590
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
    char hello[40] = "Hello!\nWelcome to Spell Checker\n";
    char input[20] = "Enter word: ";
    char error[120] = "\nUnable to process ;(\nError code #707\nYour dictionary file is missing!\nPlease reach out developer :(";
    system("clear");
    FILE *dict;
    message(hello);
    message(input);
    gets(word);
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL)
    {
        message(error);
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
    char success[60] = "\nCorrect spelling :)\nThank you!\nHave a nice day :)";
    char fail[50] = "\nIncorrect spelling :(\nTry again!";
    if (flag == 1)
    {
        message(success);
        exit(0);
    }
    else
    {
        message(fail);
        exit(0);
    }
    getch();
}

void message(char prompt[150])
{
    printf("%s", prompt);
}