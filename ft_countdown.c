void ft_countdown() {
	char number = '9';

	while(number >= '0') {
		ft_putchar(number);
		number --;
	}
	ft_putchar('\n');
}
