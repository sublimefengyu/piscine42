#include <unistd.h>

void hello(void) {
	char* str = "Hello World\n";
	write(1, str, 11);
}

int main(void) {
	hello();
	return 0;
}
