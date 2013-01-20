/*
    ThinkGUI - thinkpad laptop power consumption GUI
    Copyright (C) 2012  Piotr Krzemiński <pio.krzeminski@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "thinkgui.h"

int main(int argc, char * argv[]) {

    QApplication app(argc, argv);
    ThinkGui gui(0, Qt::Dialog);
    gui.show();
    gui.setGeometry(QStyle::alignedRect(
                        Qt::LeftToRight,
                        Qt::AlignCenter,
                        gui.size(),
                        app.desktop()->availableGeometry()
                    ));

    return app.exec();
}
