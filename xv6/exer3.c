#include "types.h" 
#include "stat.h" 
#include "user.h"

void inspect_file(char* filepath) {
    struct stat file_stat;

    printf(1,"Inspecting: %s\n", filepath);

    if (stat(filepath, &file_stat) == -1) {
        printf(1,"  Error: file not found\n\n");
        return;
    }

    printf(1,"  Size: %d bytes\n", file_stat.size);
    if (file_stat.type == T_DIR) {
	printf(1,"  Type: Directory\n");
    } else if (file_stat.type == T_FILE) {
        printf(1,"  Type: Regular file\n\n");
    } else if (file_stat.type == T_DEV) {
        printf(1,"  Type: Device\n\n");
    } else {
        printf(1,"  Type: Other\n\n");
    }
}

int main(int argc, char *argv[]) {
    // Create a dummy file for testing purposes
    int fd = open("test.txt", 0x200 | 0x002);
    if (fd >= 0) {
	write(fd, "Hello File System!", 18);
	close(fd);
    }

    inspect_file("test.txt");
    inspect_file("."); // Inspect the current directory
    inspect_file("does_not_exist.bin");

    exit();
}
