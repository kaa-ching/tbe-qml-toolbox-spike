#include "ImageProvider.h"

#include <QFile>
#include <QPainter>
#include <QPixmapCache>
#include <QSvgRenderer>

const char *ASCII(const QString &aQString)
{
    static char myString[256];
    strncpy(myString, aQString.toLatin1().constData(), 255);
    return myString;
}

#define DEBUG5(format, ...) {qDebug("     t=%03ld: " format, time(NULL)%1000, ## __VA_ARGS__);}

ImageProvider::ImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

QPixmap ImageProvider::requestPixmap(const QString &aPixmapName,
                                     QSize *aFinalSizePr,
                                     const QSize &aRequestedSize)
{
    QSize myRequestedSize(aRequestedSize);
    if (myRequestedSize.isEmpty()) {
        myRequestedSize.setWidth(100);
        myRequestedSize.setHeight(100);
    }

    QPixmap myTempPixmap;
    Q_ASSERT(aPixmapName.isEmpty() == false);
    if (aPixmapName.isEmpty())
        return myTempPixmap;

    // only names, no paths, no extensions
    Q_ASSERT(aPixmapName.contains(".") == false);
    Q_ASSERT(aPixmapName.contains("/") == false);

    // No, it isn't. Let's try to load the image.
    QString myFullPathName;

    // we have several locations to search for:
    QStringList mySearchPath;
    mySearchPath << "../images";
    mySearchPath << "images";
    mySearchPath << "qrc:/";    // this is Qt-speak for compiled-in resources

    for (int i = 0; i < mySearchPath.count() + 1; i++) {
        // if i equals that, we know we have exhausted our search paths
        if (i == mySearchPath.count()) {
            if (aPixmapName!="NotFound.png")
                return requestPixmap("NotFound.png", aFinalSizePr, myRequestedSize);
            else
                return myTempPixmap;
            break;
        }

        myFullPathName = QString(mySearchPath[i] + "/%1.svg").arg(aPixmapName);
        DEBUG5("attempt to load '%s'", ASCII(myFullPathName));
        if (QFile::exists(myFullPathName)) {
            // render the SVG into the Pixmap
            // rely on operator= to make copy
            myTempPixmap = QPixmap(myRequestedSize);
            myTempPixmap.fill(QColor(255, 255, 255, 0));

            QSvgRenderer myRenderer(myFullPathName);
            QPainter myPainter;
            myPainter.begin(&myTempPixmap);
            myRenderer.render(&myPainter);
            myPainter.end();
            break;
        }

        myFullPathName = QString(mySearchPath[i] + "/%1.png").arg(aPixmapName);
        DEBUG5("attempt to load '%s'", ASCII(myFullPathName));
        if (QFile::exists(myFullPathName))
            break;

        myFullPathName = QString(mySearchPath[i] + "/%1.jpg").arg(aPixmapName);
        DEBUG5("attempt to load '%s'", ASCII(myFullPathName));
        if (QFile::exists(myFullPathName))
            break;
    }

    // if the PNG or JPG was found, load it:
    if (myTempPixmap.isNull()) {
        myTempPixmap = QPixmap(myFullPathName).scaled(myRequestedSize);
    }

    printf("pixmap size: %dx%d\n", myRequestedSize.width(), myRequestedSize.height());
    if (nullptr != aFinalSizePr) {
        *aFinalSizePr = myRequestedSize;
    }
    return myTempPixmap;
}
