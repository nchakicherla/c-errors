#ifndef NC_ERROR_H
#define NC_ERROR_H

#include <stdio.h>

#define MSG_SIZE 256

typedef enum {
	ERR_SUCCESS = 0,
	ERR_ARG_INVALID,
	ERR_OUT_OF_MEMORY,
	ERR_FILE_NOT_FOUND,
	ERR_OTHER,
} ErrorCode;

typedef struct s_ErrorContext {
	ErrorCode code;
	char msg[MSG_SIZE];
} ErrorContext;

void setError(ErrorContext *ctx, const ErrorCode code, const char *msg);
const char *getErrorMsg(const ErrorContext *ctx);
void clearError(ErrorContext *ctx);

#endif // NC_ERROR_H
