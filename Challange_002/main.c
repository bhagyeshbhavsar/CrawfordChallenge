#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

int getUnicodeValue(int a);

int getCharacterId(int UnicodeValue);

int main() {


    // Unicode Value for 0x30.
    int a = '\x30';
    int ans = getUnicodeValue(a);
    if(ans != 0)
    {
        printf("Character ID: 0x30, Unicode: 0x%.4x\n", ans);
    }
    else
    {
        printf("Character ID: 0x30 does not exist\n", ans);
    }

    // unicode value for 0x40
    int b = '\x40';
    ans = getUnicodeValue(b);
    if(ans != 0)
    {
        printf("Character ID: 0x40, Unicode: 0x%.4x\n", ans);
    }
    else
    {
        printf("Character ID: 0x40 does not exist\n", ans);
    }

    // unicode value for 0x40
    int c = '\x50';
    ans = getUnicodeValue(c);
    if(ans != 0)
    {
        printf("Character ID: 0x50, Unicode: 0x%.4x\n", ans);
    }
    else
    {
        printf("Character ID: 0x50 does not exist\n", ans);
    }


    return 0;
}

int getUnicodeValue(int a) {
    char *line = malloc(100);
    FILE *file = fopen("sample_input_challenge_002.txt", "r");
    if(file == NULL)
    {
        printf("Cannot Open File!");
        exit(1);
    }

    while (!feof(file))
    {
        fgets( line, 100, file);
        char ua[6], x[11];
        memcpy(x, line, 4);
        sprintf(ua, "0x%X", a);
        //printf("%s\n", x);
        if(strcmp(ua, x) == 0)
        {
            //printf("%s == %s\n", ua, x);
            char unicode[2];
            int i = 5, k = 0;
            while(line[i] != ' ')
            {
                unicode[k] = line[i];
                i++;
                k++;
            }
            //printf("%s\n", unicode);
            int q = (int)strtol(unicode, NULL, 16);;
            //printf("%d",q);
            return q;
        }
    }
    return 0;
}


int getCharacterId(int UnicodeValue) {
    char *line = malloc(100);
    FILE *file = fopen("sample_input_challenge_002.txt", "r");
    if (file == NULL) {
        printf("Cannot Open File!");
        exit(1);
    }

    while (!feof(file)) {
        fgets(line, 100, file);
        char ua[6], x[13];
        int i = 5, k = 0;
        while (line[i] != ' ') {
            x[k] = line[i];
            i++;
            k++;
        }
        sprintf(ua, "0x%.4X", UnicodeValue);
        //printf("%s\n", x);
        if (strcmp(ua, x) == 0) {
            //printf("%s == %s\n", ua, x);
            char unicode[6];
            memcpy(unicode, line, 4);
            //printf("%s\n", unicode);
            int q = (int) strtol(unicode, NULL, 16);;
            //printf("%d",q);
            return q;
        }
    }
}