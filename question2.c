#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[10][50];
    char temp[50];
    int count = sizeof(names) / sizeof(names[0]);   
    int i, j;

    printf("Enter the names of %d students:\n", count);
    for (i = 0; i < count; i++) {
        printf("Student %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nStudents in alphabetical order:\n");
    for (i = 0; i < count; i++)
        printf("%2d. %s\n", i + 1, names[i]);

    return 0;
}