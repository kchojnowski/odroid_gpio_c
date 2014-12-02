#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv) {

	if(argc != 3) {
		printf("Usage: gpio_set_value pin_number value{0,1}\n");
		return 0;
	}

	char* gpio_base_path = "/sys/class/gpio/gpio";
	char* gpio_value_file = "value";

	char gpio_value_file_path[64];
	
	sprintf(gpio_value_file_path, "%s%s/%s",gpio_base_path, argv[1], gpio_value_file);

	int fd;
	
	if((fd = open(gpio_value_file_path, O_RDWR)) < 0) {
		printf("Error opening file for write: %s\n",gpio_value_file_path);
		return 1;
	}
	
	if(write(fd, argv[2], sizeof(argv[2])) <= 0) {
		printf("Error writing file: %s\n",gpio_value_file_path);
		return 1;
	}

	if(close(fd)<0) {
		printf("Error closing file: %s\n",gpio_value_file_path);
		return 1;
	}
	return 0;
}
