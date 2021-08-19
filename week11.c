#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int printdir(char *dir, int depth) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	dp = opendir(dir);
	if (dp == NULL) {
		printf("dir open fail\n");
		return -1;
	}

	chdir(dir);

	while(entry = readdir(dp)) {
		stat(entry->d_name, &statbuf); 
		if(S_ISDIR(statbuf.st_mode)) { 
			if(!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name)) {
				continue;
			}
			printf("%*s%s/\n", depth,"", entry->d_name);
			printdir(entry->d_name, depth+4); 
		}
		else {
			printf("%*s%s\n", depth, "", entry->d_name);
		}
	}
	chdir(".."); 
	closedir(dp);
}

int main() {
	printf("Directory scan : /home/2019SP/2018572030/week11\n");
	printdir("/etc", 0);
	printf("done\n");
	return 0;
}