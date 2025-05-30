// libmysyslog.h
#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H

// Уровни логирования
typedef enum {
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_CRITICAL,
    LOG_UNKNOWN
} LogLevel;

// Форматы вывода
typedef enum {
    LOG_FORMAT_TEXT = 0,
    LOG_FORMAT_JSON
} LogFormat;

/**
 * @brief Записывает сообщение в системный журнал
 * 
 * @param message Сообщение для записи
 * @param level Уровень важности сообщения
 * @param driver Идентификатор драйвера/модуля
 * @param format Формат вывода (текст/JSON)
 * @param path Путь к файлу журнала
 * @return int 0 при успехе, -1 при ошибке
 */
int mysyslog(const char* message, LogLevel level, int driver, LogFormat format, const char* path);

#endif // LIBMYSYSLOG_H
