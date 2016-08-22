#include "ToolboxGroup.h"

ToolboxGroup::ToolboxGroup(QObject *parent) : QObject(parent)
{

}


ToolboxGroup::ToolboxGroup(const QString &aName, int aCount, qreal aWidth, qreal aHeight,
             const QString& aPicture, const QString &aTooltip,
             QObject *parent)
    : m_name(aName), m_count (aCount), m_width(aWidth), m_height(aHeight),
      m_picture(aPicture), m_tooltip(aTooltip), QObject(parent)
{
}
