/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QDir>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickView> //Not using QQmlApplicationEngine because many examples don't have a Window{}

#include "ImageProvider.h"
#include "gui/ToolboxGroup.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc,argv);
    app.setOrganizationName("QtProject");
    app.setOrganizationDomain("qt-project.org");
    app.setApplicationName(QFileInfo(app.applicationFilePath()).baseName());
    QQuickView view;

    QQmlEngine *engine = view.engine();
    engine->addImageProvider(QLatin1String("tbe"), new ImageProvider);

    qmlRegisterType<ToolboxGroup>("TBEView", 1, 0, "ToolboxGroup");

    QList<QObject*> myTBGList;
    myTBGList.append(new ToolboxGroup("Volley Ball", 3, 0.21, 0.21, "VolleyBall", "A volleyball is light and very bouncy."));
    myTBGList.append(new ToolboxGroup("Slightly Bigger Left Ramp", 1, 1.0, 0.4, "LeftRamp", "This is a ramp.\nThe left is lower than the right, so things slide to the left."));
    myTBGList.append(new ToolboxGroup("Penguin", 2, 0.28, 0.28, "pinguswalkleft", "A penguin walks left or right and turns around when it collides with something heavy. It can push light objects around. It also likes to slide down slopes but can’t take much abuse."));
    myTBGList.append(new ToolboxGroup("Balloon", 5, 0.27, 0.36, "Balloon", "A helium balloon. Lighter than air, it moves up.\nIt will pop when it hits sharp objects or gets squashed."));
    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myToolboxModel", QVariant::fromValue(myTBGList));

    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
    view.setSource(QUrl("qrc:/main.qml"));
    if (view.status() == QQuickView::Error)
        return -1;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();
    return app.exec();
}
