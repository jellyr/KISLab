/***************************************************************************
 *   Copyright (C) 2017 by Mohamed Hussein                                 *
 *   m.hussein1389@gmail.com                                               *
     https://github.com/mo7amed-hussein/                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/
#ifndef BROWSER_H
#define BROWSER_H

#include <QWidget>
#include<QListWidget>
#include<QTreeWidget>

class Browser : public QWidget
{
    Q_OBJECT
public:
    explicit Browser(QWidget *parent = 0);
    void addfile(QString name,QString desc);
    void showContextMenu(QTreeWidgetItem * item,const QPoint& gPos);
    bool checkOpenedFile(QString name,QString path);
    void removeAll();
    void removeAllBut();

signals:
    void showFile(QString filePath);
    void closeFile(QString filename,QString filePath);

public slots:

    void itemDClicked(QTreeWidgetItem * item, int column);
    void onCustomContextMenuRequested(const QPoint& pos);
    void showFileAction();
    void removefile();
   void openFolder();
   void changeFilename(QString oldname,QString oldPath,QString newPath);
    void removeChild(QString name,QString path);
private:
    QListWidget*fileList;
    QTreeWidget *filesTree;
    QTreeWidgetItem *filesRoot;
    QTreeWidgetItem *itemPopup;

};

#endif // BROWSER_H
