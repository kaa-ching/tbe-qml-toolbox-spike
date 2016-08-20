#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>

class ImageProvider : public QQuickImageProvider
{
public:
    ImageProvider();

    /// aPixmapName      the file name of the requested pixmap
    /// @aFinalSizePtr   OUTPUT pointer to a size struct with the final size of the pixmap
    /// @aRequestedSize  (if provided) the requested size of the pixmap
    QPixmap requestPixmap(const QString &aPixmapName,
                          QSize *aFinalSizePr,
                          const QSize &aRequestedSize) override;

    /// Simple static, public member: adds "image://tbe/" in front of image name.
    /// Used to ensure we don't have "image://tbe/" everywhere in the code.
    /// @returns anImageName, prepended with "image://tbe/"
    static QString setPath(QString& anImageName)
    { return "image://tbe/"+anImageName; }
};

#define IMG(A) ImageProvider::setPath(A)

#endif // IMAGEPROVIDER_H
