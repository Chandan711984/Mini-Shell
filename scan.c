#include "main.h" 

void scan_input(char *prompt, char *input_string)
{

    // register the signals----------------->>>>>>>>>>>>>>>>>>>>>
        // signal(SIGINT,signal_handler);
        // signal(SIGTSTP,signal_handler);
        // call => void signal_handler(int signum){
            
            //print=> "\n" => new line
            //printf("%s",prompt);
            // fflush(stdout);
       // }

    while (1)
    {
        printf("%s", prompt);
        scanf(" %[^\n]", input_string);

        //Step 1 => check whether input_string PS1 or not
            //if YES => check whether space is present in the string or not
                //if space-present => print msg msg
                //if space is not present ,
                    // =>strcpy(prompt,&input_string[4])

        if (strncmp(input_string, "PS1=", 4) == 0)
        {
            if (strchr(input_string, ' ') != NULL)
            {
                printf("Invalid PS1 command\n");
            }
            else
            {
                strcpy(prompt, &input_string[4]);
            }

            continue;
        }

        //Step 2 => check cmd type is external or internal
            //get_command(input_string)

        char *command = get_command(input_string);
        int ret = check_command_type(command);

        if (ret == BUILTIN)
        {
            execute_internal_commands(input_string);
            //1.exit 2.pwd 3.cd 4.echo
        }

        else if (ret == EXTERNAL)
        {
            // check pipe is present or not
                // if present => call n_pipe();
                // if not present =>call execute_external_cmd()
                    // 1. convert the input_string from 1D arr to 2D arr
                        //2.if(pid == 0)=>execvp(_,_);
                            //else if(pid >0) => wait_pid(pid,&status,WUNTRACED)


            //execute the external cmp using exec
            //implement n pipe
        }
        else
        {
            // print the error message
            printf("%s: command not found\n", command);
        }
    }
}

char *get_command(char *input_string)
{
    //get the first wordl of the input_string and return it

    static char command[100];
    int i = 0;

    while (input_string[i] != '\0' && input_string[i] != ' ')
    {
        command[i] = input_string[i];
        i++;
    }

    command[i] = '\0';

    return command;
}