char*	ft_strrev(char *str) {
	/* h指向s的头部 */
    char* h = s;    
    char* t = s;
    char ch;
 
    /* t指向s的尾部 */
    while(*t){
		t++;
	};

    /* 当h和t未重合时，交换它们所指向的字符 */
    while(h < t)
    {
        ch = *h;
        *h++ = *t;    /* h向尾部移动 */
        *t-- = ch;    /* t向头部移动 */
    }
 
    return s;
}

int	ft_strlen(char *str) {
	/* h指向s的头部 */
    char* h = s;    
    char* t = s;
    char ch;
 
    /* t指向s的尾部 */
    while(*t){
		t++;
	};

	return t - h + 1;
}
