#ifndef MYSTRING_H
#define MYSTRING_H

char* strchr(const char* s, int c);
void* memcpy(void *dest, void *src, size_t n);
size_t strlen(const char *s);
char* strcpy(char* dest, char* source);
size_t strspn(char* str, char* chars);
char* strcat(char* dest, const char* src);
char* strtok(char* s, const char* delim);


#endif
