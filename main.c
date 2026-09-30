#include "main.h"
 
char **external_cmds;

char prompt[50] = "minishell$";

int main()
{
    system("clear");

    char input_string[100];

    external_cmds = malloc(sizeof(char *) * 200);

    scan_input(prompt, input_string);

    return 0;
}