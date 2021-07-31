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
void main()
{
    int i = 0, a, flag = 0;
    char word[20], x[20], c;
    system("clear");
    FILE *dict;
    printf("HELLO\nWELCOME TO SPELL CHECKER");
    printf("\nEnter word:");
    gets(word);
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL)
    {
        printf("\nUnable to process ;(\nError code #707\nYour dictionary file is missing!\nPlease reach out developer :(");
        getch();
        exit(0);
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
    if (flag == 1)
    {
        printf("\nCORRECT SPELLING :)\nTHANK YOU\nHAVE A NICE DAY :)");
        exit(0);
    }
    else
    {
        printf("\nINCORRECT SPELLING :(\nTRY AGIAN......!");
        exit(0);
    }
    getch();
}