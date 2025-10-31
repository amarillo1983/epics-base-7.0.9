#ifndef PERFLOGGER_H
#define PERFLOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Inicializa logger (llamar al inicio del IOC) */
void perf_logger_init(void);

/* Cierra logger (llamar al shutdown del IOC) */
void perf_logger_close(void);

/* Log de mensaje simple */
void perf_log(const char* msg);

#ifdef __cplusplus
}
#endif

#endif /* PERFLOGGER_H */
