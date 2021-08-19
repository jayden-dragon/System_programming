#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
        struct stat sb;
	struct stat fb;
	char pwd[256];
	int fd;

	if (argc < 2) {
		printf("arg error\n");
		return -1;
	}
	
	printf("----------- File Info -----------\n");
	getcwd(pwd, 256);
	printf("Current Dir is %s\n", pwd);
	printf("File name is \"%s\"\n\n", argv[1]);

	printf("----------- stat() -----------\n");

        stat(argv[1], &sb);

        printf("Inode = %d\n", (int)sb.st_ino);
        printf("Mode = %o\n", (unsigned int)sb.st_mode);
        printf("UID = %d\n", (int)sb.st_uid);
        printf("GID = %d\n", (int)sb.st_gid);
        printf("Atime = %s\n", ctime(&sb.st_atime));
        printf("Mtime = %s\n", ctime(&sb.st_mtime));
        printf("Ctime = %s\n", ctime(&sb.st_ctime));

	printf("----------- fstat() -----------\n");
	fd = open(argv[1], O_RDONLY);
	fstat(fd, &fb);	

        printf("Inode = %d\n", (int)fb.st_ino);
        printf("Mode = %o\n", (unsigned int)fb.st_mode);
        printf("UID = %d\n", (int)fb.st_uid);
        printf("GID = %d\n", (int)fb.st_gid);
        printf("Atime = %s\n", ctime(&fb.st_atime));
        printf("Mtime = %s\n", ctime(&fb.st_mtime));
        printf("Ctime = %s\n", ctime(&fb.st_ctime));

        return 0;

}