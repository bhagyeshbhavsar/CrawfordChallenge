#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void itsCircle(char *line);

void itsSquare(char *line);

void itsEllipse(char *line);

void itsRectangle(char *line);

void itsTriangle(char *line);


int main() {
    char *line = malloc(100);
    FILE *file = fopen("sample_input_challenge_001.txt", "r");
    if(file == NULL)
    {
        printf("Cannot Open File!");
        exit(1);
    }


    fgets( line, 100, file);
    while(strcmp("END\n", line) != 0 && strcmp("END", line) != 0)
    {
        //printf("%s", line);
        if(line[0] == '#')
        {
            fgets( line, 100, file);
            continue;
        }

        if(line[0] == 'C')
        {
            itsCircle(line);
        }
        else if(line[0] == 'S')
        {
            itsSquare(line);
        }
        else if(line[0] == 'E')
        {
            itsEllipse(line);
        }
        else if(line[0] == 'R')
        {
            itsRectangle(line);
        }
        else
        {
            itsTriangle(line);
        }
        fgets( line, 100, file);
    }

    return 0;
}

void itsTriangle(char *line) {
    //printf("%s", line);
    char *num = malloc(100);
    int i = 2, k = 0;
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    i++;
    k = 0;
    double side1 = atof(num);
    num = malloc(100);
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    double side2 = atof(num);
    i++;
    k = 0;
    num = malloc(100);
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    double side3 = atof(num);
    free(num);
    double perimeter = side1 + side2 + side3;
    double s = perimeter / 2;
    double area = (s * (s - side1) * (s - side2) * (s - side3));


    printf("Triangle %9.2f   %10.2f\n",perimeter, area);

}

void itsRectangle(char *line) {
    //printf("%s", line);
    char *num = malloc(100);
    int i = 2, k = 0;
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    i++;
    k = 0;
    double side1 = atof(num);
    free(num);
    num = malloc(100);
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    double side2 = atof(num);
    free(num);
    double area = side1 * side2;
    double perimeter = 2 * (side1 + side2);

    printf("Rectangle %8.2f   %10.2f\n",perimeter, area);
}

void itsEllipse(char *line) {
    //printf("%k", line);
    char *num = malloc(100);
    int i = 2, k = 0;
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    i++;
    k = 0;
    double radius1 = atof(num);
    free(num);
    char *num1 = malloc(100);
    while(line[i] != ' ')
    {
        num1[k] = line[i];
        i++;
        k++;
    }
    double radius2 = atof(num1);
    free(num1);
    double area = (22 / 7) * radius1 * radius2;
    double perimeter = (22 / 7) * (3 * (radius1 + radius2) - sqrt((3 * radius1 + radius2) * (radius1 + radius2 * 3)));

    printf("Ellipse\t%10.2f   %10.2f\n",perimeter, area);
}

void itsSquare(char *line) {
    //printf("%k", line);
    char *num = malloc(100);
    int i = 2, k = 0;
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    //printf("%k\n", num);
    double side = atof(num);
    free(num);
    double area = side * side;
    double perimeter = 4 * side;

    printf("Square\t%10.2f   %10.2f\n",perimeter, area);

}

void itsCircle(char *line) {
    char *num = malloc(100);
    int i = 2, k = 0;
    while(line[i] != ' ')
    {
        num[k] = line[i];
        i++;
        k++;
    }
    //printf("%s\n", num);
    double radius = atof(num);
    free(num);
    double area = (22/7) * radius * radius;
    double perimeter = 2 * (22 / 7) * radius;

    printf("Circle\t%10.2f   %10.2f\n",perimeter, area);

}

