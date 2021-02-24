#include "mystring.h"

char* strchr(const char* s, int c) {
    while (*s != (char) c) {
        if (!*s++) {
            return 0;
        }
    }
    return (char*) s;
}
void *memcpy(void *dest, void *src, size_t n) {
	char *csrc = (char*) src;
	char *cdest = (char*) dest;
 	for (int i = 0; i < (int) n; i++) {
		cdest[i] = csrc[i];
	}
}
size_t strlen(const char *s) {
	const char *ptr = s;
	while (*ptr	return (size_t) (ptr - s);
}
char* strcpy(char* dest, char* source) {
	if (dest == 0) return 0;
	char *p = dest;
	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return p;
}
//returns the number of characters in the initial segment of str which consists only of characters from chars
size_t strspn(char *str, char *chars) {
    size_t i = 0;
    while (str[i] && strchr(chars, str[i]))
        i++;
    return i;
}
//ok
char* strcat(char *dest, const char *src) {
    size_t i, j;
    for (i = 0; dest[i] != '\0'; i++); //ищет конец первой строки
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}
char* strtok(char* s, const char* delim) {
    static char* buf = 0;
    if (s) buf = s;
    if ((buf == 0) || (*buf == 0)) return 0;
    char* c = buf;
    while (strchr(delim, *c)) ++c;
    if (*c == 0) return 0;
    char* res = c;
    while (*c && (strchr(delim, *c) == 0)) ++c;
    if (*c == 0){
        buf = c;
        return res;
    }
    *c = 0;
    buf = c + 1;
    return res;
}
