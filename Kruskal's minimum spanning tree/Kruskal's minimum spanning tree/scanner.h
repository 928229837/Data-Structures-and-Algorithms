#ifndef SCANNER_H
#define SCANNER_H
/* VERSION 1.3
*
* scanner.h - public interface to scanner.c, the scanner module
*
*/
extern int readInt(FILE *);
extern int stringPending(FILE *);

extern double readReal(FILE *);

extern char readChar(FILE *);
extern char *readLine(FILE *);
extern char *readWords(FILE *);
extern char *readToken(FILE *);
extern char readRawChar(FILE *);
extern char *readString(FILE *);

#endif