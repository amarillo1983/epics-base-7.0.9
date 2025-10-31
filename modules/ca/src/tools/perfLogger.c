#include <stdio.h>
#include <log4c.h>
#include "perfLogger.h"

static log4c_category_t *perf_cat = NULL;

void perf_logger_init(void)
{
    if (log4c_init() != 0) {
        fprintf(stderr, "⚠️ log4c initialization failed\n");
        return;
    }
    perf_cat = log4c_category_get("epics.perf");
    if (!perf_cat) {
        fprintf(stderr, "⚠️ log4c category 'epics.perf' not found\n");
    }
}

void perf_logger_close(void)
{
    log4c_fini();
}

void perf_log(const char* msg)
{
    if (!perf_cat) return;
    if (log4c_category_is_enabled(perf_cat, LOG4C_PRIORITY_INFO)) {
        log4c_category_log(perf_cat, LOG4C_PRIORITY_INFO, "%s", msg);
    }
}
