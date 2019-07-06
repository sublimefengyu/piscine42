#include <unistd.h>

void ft_putchar(char *str) {
	while (*str) {
		write(1, str, 1);
		str ++;
	}
}

int main() {
	ft_putchar("Hello World");
	return 0;
}
