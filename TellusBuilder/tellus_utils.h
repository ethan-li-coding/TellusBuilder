#ifndef TELLUS_BUILDER_UTILS_H
#define TELLUS_BUILDER_UTILS_H

#include <QString>
#include <string>

// QString to string
inline QString str2qstr(const std::string& str) {
    return QString::fromLocal8Bit(str.data());
}
// string to QString
inline std::string qstr2str(const QString& qstr) {
    QByteArray cdata = qstr.toLocal8Bit();
    return std::string(cdata);
}


#endif