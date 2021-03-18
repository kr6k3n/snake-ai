#include "storage.h"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>


char folder_name[] = "/models";

bool write_neural_network(neural_network *nn, char file_path[]){
    FILE *f_ptr;
        
}

bool write_generation(generation *gen, char id[])
{

}

bool create_generation_folder(char id[])
{
    char base_dir[1024];
    getcwd(base_dir, sizeof(base_dir));
    strcat(base_dir, folder_name);
    struct stat st = {0};
    //ensure models folder exists
    if (stat(base_dir, &st) == -1)
        mkdir(base_dir, 0777);

}
