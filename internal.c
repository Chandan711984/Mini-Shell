#include "main.h" 

void execute_internal_commands(char *input_string)
{
    // compare and check------------->>>>>>>>>>>
        //1.input_string is exit
            //call exit();

        //2.input_string is pwd
            //call get_wcd(str,100);
            //print the str

        //3.input_string is cd
            //call chdir(&input_string[3]);
        //input_string is echo
            //1. echo $SHELL
            //print => getenv("SHELL");

            //2. echo $?
            // take a variable => int status  = 0;
            //print the lastly completed process exit status using waitpid();

            //3. echo $$
            //print pid of current working process using getpid();


    // if none of this (exit,pwd,cd,echo)
        // print 2nd word after echo , if no 2nd word print a new line
}
