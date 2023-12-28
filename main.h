#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_pint(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_chara(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_strg(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_inter(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsig(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upp(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_h(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_point(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flg(const char *format, int *i);
int get_with(const char *format, int *i, va_list list);
int get_prec(const char *format, int *i, va_list list);
int get_siaz(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_chara(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_namb(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_namb(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_point(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsg(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_print(char);
int append_hexa_cod(char, char[], int);
int is_dig(char);

long int convert_size_namb(long int num, int size);
long int convert_size_unsg(unsigned long int num, int size);

#endif
