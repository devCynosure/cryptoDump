#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void main()
{
    int ch, i, j, k1, k2,len;
    char str[100], key1[100], key2[100];
    printf("1.Encipher\n2.Decipher\nEnter your choice:");
    scanf("%d", &ch);
    printf("Enter a string\n");
    scanf("%s",str);
    if (ch == 1)
    {
        i = 0;
        k1 = 0;
        k2 = 0;
        while (i < strlen(str))
        {
            if (i % 2 == 0)
            {
                key1[k1] = str[i];
                k1++;
            }
            else
            {
                key2[k2] = str[i];
                k2++;
            }
            i++;
        }
        key1[k1] = '\0';
        key2[k2] = '\0';
        strcat(key1, key2);
        printf("Cipher text is:%s", key1);
    }
    else if (ch == 2)
    {
        j=0;
        k1=0;
        k2=0;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(i<(len/2))
            {
                key1[k1]=str[i];
                k1++;
            }
            else
            {
                key2[k2]=str[i];
                k2++;
            }
        }
        i=0;
        printf("\nDeciphered text is:");
        while(i<(len/2))
        {
            printf("%c%c",key1[i],key2[i]);
            i++;
        }
    }
}
