
#include <stdint.h>

#define log(format, ...) LOGGER._log(LOGGER, format __VA_OPT__(,) __VA_ARGS__)

typedef struct logger_s {
	u_int8_t level;
	u_int16_t flags;
	int (*_log)(struct logger_s logger, char * const fmt);
} logger_t;

int	x(char * xx) {
	logger_t my_logger;
	#define LOGGER my_logger

	log("Hello world");
	log("Hello world %s", xx);

	return 0;
}
