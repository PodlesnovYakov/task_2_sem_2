#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
double izvlech(char *str)
{
    int i = 0;
    int j = 0;
    char q[5];
    while(i < strlen(str))
    {
        if(str[i] == '(')
        {
            while(str[i+1] != ')')
            {
                q[j] = str[i+1];
                i++;
                j++;
            }
            break;
        }
        else
        {
            i++;
        }
    }
    q[4] = '\0';
    double r = atoi(q);
    return r;
}
void Simple_Merging_Sort (char *name)
{
    int k, i, j, kol;
    FILE *f, *f1, *f2;
    char *estr;
    char *estr1;
    double a1,a2;
    char str[256];
    char str1[256];
    kol = 0;
    if ( (f = fopen(name,"r")) == NULL )
        printf("\nИсходный файл не может быть прочитан.");
    else
    {
        while (1)
        {
            estr = fgets(str,sizeof(str),f);
            if(estr == NULL)
            {
                break;
            }
            else
            {
                kol++;

            }

        }
        fclose(f);
    }
    k = 1;
    while ( k < kol )
    {
        f = fopen(name,"r");
        f1 = fopen("S1.txt","w");
        f2 = fopen("S2.txt","w");
        estr = fgets(str,sizeof(str),f);
        while(estr)
        {
            for ( i = 0; i < k && estr; i++ )
            {
                fprintf(f1,"%s",str);
                estr = fgets(str,sizeof(str),f);
            }
            for ( j = 0; j < k && estr; j++ )
            {
                fprintf(f2,"%s",str);
                estr = fgets(str,sizeof(str),f);
            }
        }
        fclose(f2);
        fclose(f1);
        fclose(f);

        f = fopen(name,"w");
        f1 = fopen("S1.txt","r");
        f2 = fopen("S2.txt","r");

        estr = fgets(str,sizeof(str),f1);
        a1 = izvlech(str);
        estr1 = fgets(str1,sizeof(str),f2);
        a2 = izvlech(str1);

        while(estr && estr1)
        {
            i = 0;
            j = 0;
            while (i < k && j < k && estr && estr1)
            {
                if (a1 < a2)
                {
                    fprintf(f,"%s",str);
                    estr = fgets(str,sizeof(str),f1);
                    a1 = izvlech(str);
                    i++;
                }
                else
                {
                    fprintf(f,"%s",str1);
                    estr1 = fgets(str1,sizeof(str1),f2);
                    a2 = izvlech(str1);
                    j++;
                }
            }
            while (i < k && estr)
            {
                fprintf(f,"%s",str);
                estr = fgets(str,sizeof(str),f1);
                a1 = izvlech(str);
                i++;
            }
            while (j < k && estr1)
            {
                fprintf(f,"%s",str1);
                estr1 = fgets(str1,sizeof(str1),f2);
                a2 = izvlech(str1);
                j++;
            }
        }
        while(estr)
        {
            fprintf(f,"%s",str);
            estr = fgets(str,sizeof(str),f1);
            a1 = izvlech(str);
        }
        while(estr1)
        {
            fprintf(f,"%s",str1);
            estr1 = fgets(str1,sizeof(str1),f2);
            a2 = izvlech(str1);
        }
        fclose(f2);
        fclose(f1);
        fclose(f);
        k *= 2;
    }
    remove("S1.txt");
    remove("S2.txt");
}

int main()
{
    setlocale(LC_ALL, "Rus");
    char name[] = "my.txt";
    Simple_Merging_Sort (name);
    return 0;
}
