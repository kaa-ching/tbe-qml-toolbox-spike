#ifndef TOOLBOXGROUP_H
#define TOOLBOXGROUP_H

#include <QObject>

/// This class manages one group of identical items in the toolbox.
/// This class is responible for keeping refs to (maybe again) unused
/// AbstractObjects and/or ViewItems.
class ToolboxGroup : public QObject
{
    Q_OBJECT
public:
    explicit ToolboxGroup(QObject *parent = nullptr);
    ToolboxGroup(const QString &aName, int aCount, qreal aWidth, qreal aHeight,
                 const QString& aPicture, const QString &aTooltip,
                 QObject *parent = 0);

    Q_PROPERTY(QString name MEMBER m_name NOTIFY nameChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(qreal owidth MEMBER  m_width NOTIFY owidthChanged)
    Q_PROPERTY(qreal oheight MEMBER m_height NOTIFY oheightChanged)
    Q_PROPERTY(QString picture MEMBER m_picture NOTIFY pictureChanged)
    Q_PROPERTY(QString tooltip MEMBER m_tooltip NOTIFY tooltipChanged)

    QString name();
    int count() { return m_count; }
    qreal owidth();
    qreal oheight();
    QString picture();
    QString tooltip();

    void setCount(int aNewCount)
    {m_count = aNewCount; emit countChanged(); printf("count adjusted to %d\n", m_count);}

signals:
    void nameChanged();
    void countChanged();
    void owidthChanged();
    void oheightChanged();
    void pictureChanged();
    void tooltipChanged();

public slots:

private:
    QString m_name;
    int     m_count;
    qreal   m_width;
    qreal   m_height;
    QString m_picture;
    QString m_tooltip;
};

#endif // TOOLBOXGROUP_H
