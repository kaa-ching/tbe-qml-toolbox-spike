#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>

class ImageProvider : public QQuickImageProvider
{
public:
    ImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;

    /// @returns anImageName, prepended with "image://tbe/"
    static QString setPath(QString& anImageName)
    { return "image://tbe/"+anImageName; }
};

#define IMG(A) ImageProvider::setPath(A)

#endif // IMAGEPROVIDER_H
