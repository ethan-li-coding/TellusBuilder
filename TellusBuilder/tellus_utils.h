#ifndef TELLUS_BUILDER_UTILS_H
#define TELLUS_BUILDER_UTILS_H
#include <QString>
#include <string>

// string to QString and in turn
QString str2qstr(const std::string str) {
    return QString::fromLocal8Bit(str.data());
}
std::string qstr2str(const QString qstr) {
    QByteArray cdata = qstr.toLocal8Bit();
    return std::string(cdata);
}
// string to QString and in turn


#endif