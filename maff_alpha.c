void maff_alpha() {
	char letter = 'a';
	while (letter <= 'z') {
		if (letter % 2)
			ft_putchar(letter);
		else
			ft_putchar(letter + 'a' - 'A');
	}
	ft_putchar('\n');
}
