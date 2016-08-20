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

import QtQuick 2.0

ListModel {
    ListElement {
        name: "Volley Ball"
        count: 3
        picture: "VolleyBall"
        owidth: 0.21
        oheight: 0.21
        tooltip: "A volleyball is light and very bouncy."
    }
    ListElement {
        name: "Left Ramp"
        count: 1
        owidth: 1.0
        oheight: 0.4
        picture: "LeftRamp"
        tooltip: "This is a ramp.\nThe left is lower than the right, so things slide to the left."
    }
    ListElement {
        name: "Penguin"
        count: 2
        owidth: 0.28
        oheight: 0.28
        picture: "pinguswalkleft"
        tooltip: "A penguin walks left or right and turns around when it collides with something heavy. It can push light objects around. It also likes to slide down slopes but can’t take much abuse."
    }
    ListElement {
        name: "Balloon"
        count: 5
        owidth: 0.27
        oheight: 0.36
        picture: "Balloon"
        tooltip: "A helium balloon. Lighter than air, it moves up.\nIt will pop when it hits sharp objects or gets squashed."
    }
}
