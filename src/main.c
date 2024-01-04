#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>

void help_menu(void);

int main(int argc, char *argv[]) {
    char *src_dir = malloc(sizeof(char) * PATH_MAX);

    printf("\n********\tWelcome to sorty\t********\n\n");

    while (true) {
        char x;
        printf("Enter Command: ");
        scanf(" %c", &x);

        // convert to upper case
        if (x >= 'a' && x <= 'z') {
            x -= 32;
        }

        // command loop
        if (x == 'H') {
            help_menu();
        } else if (x == 'X') {
            break;
        } if (x == 'S') {
            if (set_src(src_dir) != 0) {

            };
        }
    }

    printf("Exiting sorty...\n");
    free(src_dir);
    return 0;
}

// print out the help menu
void help_menu(void) {
    printf("\n********\tHelp Menu\t********\n\n");
    printf("S\t-\tEnter source directory\n");
    printf("D\t-\tEnter a destination directory\n");
    printf("K\t-\tSelect destination directory and add keyword\n");
    printf("B\t-\tBegin sortying\n");
    printf("X\t-\tExit\n\n");
}

int set_src(char *src_dir) {
    printf("Enter the full path to the directory you are sorting (leave blank for cwd):\n");
    fgets(src_dir, PATH_MAX, stdin);

    if (src_dir[0] == '\0') {
        getcwd(src_dir, PATH_MAX);
    }

    return 0;
} 

int check_directory_exits(char *path) {
    struct stat s;
    if (stat(path, &s) != 0) {
        return 0;
    } 
    return S_ISDIR(s.st_mode);
}

