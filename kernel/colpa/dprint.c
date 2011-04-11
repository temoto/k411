// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <colpa/dprint.h>


void dprint(debug_type type, char *str, const char *fmt, ...)
{
	if (DEBUG_MODE == NONE)
		return;

	if (DEBUG_MODE == ALL || type == DEBUG_MODE) {
		va_list args;
		int i;

		va_start(args, fmt);
		i = vsnprintf(str, 0, fmt, args);
		va_end(args);

		va_start(args, fmt);
		i = vsnprintf(str, (size_t)i+1, fmt, args);
		va_end(args);
	}
}

void SetDebugMode(debug_type type)
{
	DEBUG_MODE = type;
}

debug_type GetDebugMode(void)
{
	return DEBUG_MODE;
}
