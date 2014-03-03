#include <stdio.h>
#include <logger.h>

int main()
{
	char *msg = "OMFG! Something %s happened.";
	LOG(LOG_ERROR, msg, "bad");
	LOG(LOG_WARN, msg, "not so bad");
	LOG(LOG_INFO, msg, "meh");
	LOG(LOG_DEBUG, msg, "internal");
	return 0;
}
