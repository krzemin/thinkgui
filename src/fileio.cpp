#include "fileio.h"
#include <QFile>
#include <QTextStream>

QVariant FileIO::read(const QString & path) {
    QFile f(path);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return QVariant();
    QByteArray ba = f.readLine();
    f.close();

    QString value;
    QTextStream ts(&value);
    ts << ba;

    return QVariant(value);
}


void FileIO::write(const QString & path, const QVariant & value) {
    QFile f(path);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QTextStream out(&f);
    out << value.toString();
    f.close();
}
