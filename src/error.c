#include "error.h"

void setError(ErrorContext *ctx, const ErrorCode code, const char *msg) {
	ctx->code = code;
	snprintf(ctx->msg, MSG_SIZE, "%s", msg);
}

const char *getErrorMsg(const ErrorContext *ctx) {
	return ctx->msg;
}

void clearError(ErrorContext *ctx) {
	ctx->code = 0;
	ctx->msg[0] = '\0';
}
