#include "shell.h"



/**
 *hsh -shell loops
 *Description:shell loops
 *@info :parameter and return value
 *@argv:vector
 *Return: 0 (success), 1 error
 */


int hsh(info_t *info, char **argv)
{
        ssize_t a = 0;
        int builtin_retn = 0;

        while (a != -1 && builtin_retn != -2)
        {
                clear_info(info);

                if (interactive(info))
                        _puts("$ ");
                _eputchar(BUF_FLUSH);
                a = get_input(info);

                if (a != -1)
                {
                        set_info(info, argv);
                        builtin_retn = find_builtin(info);

                        if (builtin_retn == -1)
                                find_cmd(info);
                }

                else if (interactive(info))
   _putchar('\n');
                free_info(info, 0);
        }
        write_history(info);
        free_info(info, 1);

        if (!interactive(info) && info->status)
                exit(info->status);

        if (builtin_retn == -2)
        {

                if (info->err_num == -1)
                        exit(info->status);
                exit(info->err_num);
        }
        return (builtin_retn);
}







/**
 *find_builtin - finding built-in commands
 *Description: to find a built-in commands
 *@info: parameter and return info struct
 *Return: 0 (success) 1 (not success) -1  (not found) 2 (exit)
 */


int find_builtin(info_t *info)
{
        int r, built_in_retn = -1;
        builtin_table builtintbl[] = {
   {"exit", _myexit},
                {"env", _myenv},
                {"help", _myhelp},
                {"history", _myhistory},
                {"setenv", _mysetenv},
                {"unsetenv", _myunsetenv},
                {"cd", _mycd},
                {"alias", _myalias},
                {NULL, NULL}
        };

        for (r = 0; builtintbl[r].type; r++)

                if (_strcmp(info->argv[0], builtintbl[r].type) == 0)
                {
                        info->line_count++;
                        built_in_retn = builtintbl[r].func(info);
                        break;
                }
        return (built_in_retn);
}
