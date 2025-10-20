#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
	DIR* dir = opendir("."); // Remember: . is the working directory


	
	struct dirent* current_entry = readdir(dir);
	while (current_entry != NULL) {
		// Call the stat() / lstat() function, passing the
		// entry's name as the argument, to retrieve information about
		// it
		struct stat info = {0};
		stat(current_entry->d_name, &info);

		// TODO Print some information about the entry
		printf("Name: %s\n", current_entry->d_name);
		printf("Size: %ld\n", info.st_size);


		// Read the next entry
		current_entry = readdir(dir);
	}


	closedir(dir);

	mode_t prev_umask = umask(0444);
	mkdir("some_cool_directory", 0744);
	chmod("some_cool_directory", 0744);
	umask(prev_umask);
}
