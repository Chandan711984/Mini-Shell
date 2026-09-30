#include "main.h" 

int check_command_type(char *command)
{
    //either externalor builtin
    //list of builtin
    char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval",
                        "set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source",
                        "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};

    //run a loop
    //use strcmp and compare command with builtins 2d array
        //if match found => return BUILTIN

    for (int i = 0; builtins[i] != NULL; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
        {
            return BUILTIN;
        }
    }

    //if cmd is not builtin
    extract_external_commands(external_cmds);

    //run a loop
        //use strcmp and compare command  with external_commands  2d pointer
            //if match found => return EXTERNAL

    for (int i = 0; external_cmds[i] != NULL; i++)
    {
        if (strcmp(command, external_cmds[i]) == 0)
        {
            return EXTERNAL;
        }
    }

    //if cmd is not external also ,return NO_COMMAND

    return NO_COMMAND;
}

void extract_external_commands(char **external_cmds)
{
    //step1 => open the externalcmds.txt
    FILE *fp = fopen("external_cmd.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    //step2 => read one by one cmd till the new line
        //STEP2.1 =>allocate the memory dynamically
        //STEP2.2 => store the cmd into the 2d pointer
        //STEP2.3 => repeat the step2 till reaching EOF

    char command[100];
    int i = 0;

    while (fgets(command, sizeof(command), fp) != NULL)
    {
        command[strcspn(command, "\r\n")] = '\0';

        external_cmds[i] = malloc(strlen(command) + 1);

        strcpy(external_cmds[i], command);

        i++;
    }

    external_cmds[i] = NULL;

    fclose(fp);
}