#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv) {

	if(argc != 2) {
		printf("Usage: gpio_set_output pin_number\n");
		return 0;
	}

	char* gpio_base_path = "/sys/class/gpio/gpio";
	char* gpio_direction_file = "direction";

	char gpio_direction_file_path[64];
	
	sprintf(gpio_direction_file_path, "%s%s/%s",gpio_base_path, argv[1], gpio_direction_file);

	int fd;
	char* data = "out";
	
	if((fd = open(gpio_direction_file_path, O_RDWR)) < 0) {
		printf("Error opening file for write: %s\n",gpio_direction_file_path);
		return 1;
	}
	
	if(write(fd, data, sizeof(data)) <= 0) {
		printf("Error writing file: %s\n",gpio_direction_file_path);
		return 1;
	}

	if(close(fd)<0) {
		printf("Error closing file: %s\n",gpio_direction_file_path);
		return 1;
	}
	return 0;
}
