#include <stdio.h>
#include <string.h>

int main(void)
{
    char email[100];
    char domain[100];
    char *at_sign;

    printf("Enter employee email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    at_sign = strchr(email, '@');

    if (at_sign == NULL) {
        printf("Invalid email: no '@' symbol found.\n");
        return 1;
    }

  
    strcpy(domain, at_sign + 1);

    printf("Domain name: %s\n", domain);

    return 0;
}