#include <stdio.h>
#include <string.h>

int main(void)
{
    char feedback[500];
    char updated[1000];   
    char *found;

    printf("Enter customer feedback: ");
    fgets(feedback, sizeof(feedback), stdin);

  
    feedback[strcspn(feedback, "\n")] = '\0';

  
    printf("\nTotal characters: %zu\n", strlen(feedback));

    if (strstr(feedback, "good") != NULL)
        printf("The word \"good\" was found.\n");
    else
        printf("The word \"good\" was not found.\n");

    found = strstr(feedback, "bad");
    if (found != NULL)
        printf("The word \"bad\" was found.\n");
    else
        printf("The word \"bad\" was not found.\n");

    if (found == NULL) {
        printf("\nNothing to replace. Review stays the same:\n%s\n", feedback);
        return 0;
    }

    strncpy(updated, feedback, found - feedback);
    updated[found - feedback] = '\0';

    strcat(updated, "not good");
    strcat(updated, found + strlen("bad"));

    printf("\nUpdated review: %s\n", updated);

    return 0;
}