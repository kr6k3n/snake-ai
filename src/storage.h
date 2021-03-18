#include "training.h"
#include "utils.h"

#include <stdio.h>
#include <unistd.h>

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#ifndef STORAGE
#define STORAGE

extern int test_folder();

extern char *create_generation_folder(char *id);

#endif