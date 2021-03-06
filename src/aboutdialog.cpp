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
#include "aboutdialog.h"
#include<QLabel>
#include<QPixmap>
#include<QVBoxLayout>
#include<QTabWidget>
#include<QPalette>
AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout * mainLayout=new QVBoxLayout(this);

    QLabel *splash=new QLabel(this);

    QImage img(":/images/icons/kis.jpg");

    splash->setPixmap(QPixmap::fromImage(img));
    splash->setScaledContents(true);
    splash->setFixedSize(img.size());

    this->setWindowFlags(Qt::Tool);

    this->setWindowTitle(tr("About KISLab"));

    QLabel *developer=new QLabel(this);
    developer->setText(tr("<b>KISLab</b> was developed by"
                          "<p> Mohamed Hussein"
                          "<p> Feb,2017"));
    developer->setAlignment(Qt::AlignCenter);
    QLabel *developerContact=new QLabel(this);
    developerContact->setText(tr("<br>for contribution or bugs "
                                 "<p>please contact us"
                                 "<p><a href=\"mailto:m.hussein1389@gmail.com\">m.hussein1389@gmail.com</a>"
                                 "<p><a href=\"https://github.com/mo7amed-hussein/KISLab\">Github</a><br>"));

    developerContact->setOpenExternalLinks(true);

    developerContact->setAlignment(Qt::AlignCenter);
    QLabel *license=new QLabel(this);
    license->setText(tr("<b>KISLab</b> was distributed "
                        "under the terms of<p> GNU public license (GPL)"));

    license->setAlignment(Qt::AlignCenter);
    QLabel *credits=new QLabel(this);
    credits->setText(tr("Thanks to<p>Qt"
                        "<p>QsciScintilla"
                        "<p>QTermWidget<br>"));
    credits->setAlignment(Qt::AlignCenter);

    QTabWidget *aboutTabs=new QTabWidget;
    aboutTabs->addTab(developer,"Developer");
    aboutTabs->addTab(license,"License");
    aboutTabs->addTab(developerContact,"Contact");
    aboutTabs->addTab(credits,"Credits");
    aboutTabs->setContentsMargins(10,20,10,20);

    mainLayout->setAlignment(Qt::AlignVCenter);

    mainLayout->addWidget(splash,0,Qt::AlignCenter);
    mainLayout->addWidget(aboutTabs,0,Qt::AlignCenter);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
