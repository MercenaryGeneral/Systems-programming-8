// libmysyslog.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "libmysyslog.h"

static const char* get_level_string(LogLevel level) {
    static const char* level_strings[] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "CRITICAL"
    };
    
    if (level >= LOG_DEBUG && level <= LOG_CRITICAL) {
        return level_strings[level];
    }
    return "UNKNOWN";
}

static void remove_newline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int mysyslog(const char* message, LogLevel level, int driver, LogFormat format, const char* path) {
    if (message == NULL || path == NULL) {
        return -1;
    }

    FILE* log_file = fopen(path, "a");
    if (log_file == NULL) {
        return -1;
    }

    // Получаем текущее время
    time_t now;
    time(&now);
    char* timestamp = ctime(&now);
    remove_newline(timestamp);

    const char* level_str = get_level_string(level);

    // Записываем в выбранном формате
    if (format == LOG_FORMAT_TEXT) {
        fprintf(log_file, "%s %s %d %s\n", timestamp, level_str, driver, message);
    } else {
        fprintf(log_file, 
                "{\"timestamp\":\"%s\",\"log_level\":\"%s\",\"driver\":%d,\"message\":\"%s\"}\n",
                timestamp, level_str, driver, message);
    }

    fclose(log_file);
    return 0;
}
