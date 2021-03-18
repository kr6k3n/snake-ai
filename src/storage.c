#include "storage.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

char folder_name[] = "/models";

bool folder_exists(char dir[])
{
	struct stat st = {0};
	return stat(dir, &st) == 0;
}



bool write_neural_network(neural_network *nn, char *file_path){
	FILE *f_ptr;

}


int get_latest_gen_version(char *dir)
{
	int max_version = -1;
	DIR *dp;
	struct dirent *ep;
	dp = opendir(dir);

	if (dp != NULL)
	{
		while (ep = readdir(dp))
			if (is_number(ep->d_name))
				{
					int version = (int) ep->d_name[0];
					max_version = MAX(version, max_version);
				}
		(void)closedir(dp);
	}
	else
		perror("Couldn't open the directory");

	return max_version;
}

bool write_generation(generation *gen, char *id)
{
	//ensure gen folder exists
	char *base_dir = create_generation_folder(id);
	//get version
	int new_version = get_latest_gen_version(base_dir);
	new_version++;

	return true;
}



char *create_generation_folder(char *id)
{
	char *dir = malloc(sizeof(char)* 1024);
	getcwd(dir, sizeof(dir));

	strcat(dir, folder_name);
	//ensure models folder exists
	if (!folder_exists(dir))
		mkdir(dir, 0777);
	//write generation folder
	strcat(dir, id);
	if (!folder_exists(dir))
		mkdir(dir, 0777);
	return dir;
}

generation *restore_generation(char *id, int version)
{

}

int test_folder()
{
	create_generation_folder("/gen2");
}