#include <stdio.h>
#include <fcntl.h>

#define GPIO_EXPORT_FILE "/sys/class/gpio/export"

int main(int argc, char** argv) {
	if(argc != 2) {
		printf("Usage: gpio_export pin_number\n");
		return 0;
	}
	int fd;
	
	if((fd = open(GPIO_EXPORT_FILE, O_WRONLY)) < 0) {
		printf("Error opening file for write: %s\n",GPIO_EXPORT_FILE);
		return 1;
	}
	
	if(write(fd, argv[1], sizeof(argv[1])) <= 0) {
		printf("Error writing file: %s\n",GPIO_EXPORT_FILE);
		return 1;
	}

	if(close(fd)<0) {
		printf("Error closing file: %s\n",GPIO_EXPORT_FILE);
		return 1;
	}
	return 0;
}
