#ifndef FILEIO_H
#define FILEIO_H

#include <QString>
#include <QVariant>

class FileIO
{
public:
    static QVariant read(const QString & path);
    static void write(const QString & path, const QVariant & value);

};

#endif // FILEIO_H
