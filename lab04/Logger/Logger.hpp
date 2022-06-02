#ifndef LOGGER_HPP_

#define LOGGER_HPP_

#include <QPlainTextEdit>

class Logger: public QPlainTextEdit {
public:
    Logger(QWidget *parent = nullptr);
    void log(const QString& message);
};

void log(Logger* logger, const QString& message);

#endif