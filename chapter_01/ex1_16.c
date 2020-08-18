#include <stdio.h>
#define MAXLINE 1000 // maximum input line

/* function prototype */
int get_line(char line[], int maxline); // renamed to 'get_line' to avoid conflict 'stdio.h' function 'getline'
void copy(char to[], char from[]);

/* print longest input line */
int main() {
	int len;               // current line length
	int max;               // maximum length seen so far
	char line[MAXLINE];    // current input line
	char longest[MAXLINE]; // longest line saved

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) // there was a line
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, returns length */
int get_line(char s[], int limit) {
	int c, i, j;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i > limit - 2)
			continue;
		s[i] = c;
		j = i; // to deal with input lines that exceed MAXLINE
	}

	if (c == '\n') {
		s[j] = c;
		++j;
	}
	s[j] = '\0';
	return i;
}

/* copy: copy 'from' into 'to; assumes to is big enough */
void copy(char to[], char from[]) {
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
