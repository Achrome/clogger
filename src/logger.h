/*
 * This file is part of the clogger library.
 * (https://github.com/Achrome/clogger)
 *
 * (c) 2014 Ashwin Mukhija<achromatic.rainbow@gmail.com>
 *
 * Licensed under MIT. See LICENSE.md in the base directory
 */

#ifndef _logger_h
#define _logger_h

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Add colors to the terminal */
#define COLOR_ERROR		"\x1b[31m"
#define COLOR_WARN		"\x1b[33m"
#define COLOR_INFO		"\x1b[36m"
#define COLOR_DEBUG		"\x1b[32m"
#define COLOR_RESET		"\x1b[0m"

/* Set log levels*/
#define LOG_ERROR	COLOR_ERROR "ERROR" COLOR_RESET
#define LOG_WARN	COLOR_WARN  "WARN"  COLOR_RESET
#define LOG_INFO	COLOR_INFO  "INFO"  COLOR_RESET
#define LOG_DEBUG	COLOR_DEBUG "DEBUG" COLOR_RESET

#define BUF_SIZE 512

#ifdef nolog
#define LOG(level, fmt, ...)
#else
#define LOG(level, fmt, ...)																\
 			do {																			\
 				do_log(__FILE__, __FUNCTION__, __LINE__, level, fmt, ##__VA_ARGS__);		\
 			} while(0)
#endif

static inline void
do_log(	const 	char 	*file,
		const 	char 	*func,
		const 	int 	line,
		const 	char 	*level,
			  	char 	*fmt,
		...
	)
{

#ifndef logdebug
	if(strcmp(level, LOG_DEBUG) == 0) {
		return;
	}
#endif

	char 		*msg = (char *) malloc(BUF_SIZE);
	va_list 	args;

	va_start(args, fmt);
	vsnprintf(msg, BUF_SIZE, fmt, args);
	va_end(args);
	fprintf(stderr, "[%s]\t[%s:%s:%d]\t%s\n", level, file, func, line, msg);
	free(msg);
}
#endif
