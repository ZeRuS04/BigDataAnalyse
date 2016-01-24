/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chartview.h"
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLegendMarker>
#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtCore/QtMath>

ChartView::ChartView(QWidget *parent) :
    QChartView(new QChart(), parent)
{
//    series0->append(0, 6);
//    series0->append(2, 4);
//    series0->append(3, 8);
//    series0->append(7, 4);
//    series0->append(10, 5);

//    *series1 << QPointF(1, 1) << QPointF(3, 3) << QPointF(7, 6) << QPointF(8, 3) << QPointF(10, 2);
//    *series2 << QPointF(1, 5) << QPointF(4, 6) << QPointF(6, 3) << QPointF(9, 5);
    //![2]

    //![3]
//    QPainterPath starPath;
//    starPath.moveTo(30, 15);
//    for (int i = 1; i < 5; ++i) {
//        starPath.lineTo(15 + 15 * qCos(0.8 * i * Pi),
//                        15 + 15 * qSin(0.8 * i * Pi));
//    }
//    starPath.closeSubpath();

//    QImage star(30, 30, QImage::Format_ARGB32);
//    star.fill(Qt::transparent);

//    QPainter painter(&star);
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setPen(QRgb(0xf6a625));
//    painter.setBrush(painter.pen().color());
//    painter.drawPath(starPath);

//    series2->setBrush(star);
//    //![3]

//    //![4]
//    setRenderHint(QPainter::Antialiasing);

//    chart()->createDefaultAxes();
    chart()->setTitle("Simple scatterchart example");
//    //![4]

//    //![5]
//    QList<QLegendMarker *> markers = chart()->legend()->markers(series2);
//    for (int i = 0; i < markers.count(); i++)
//        markers.at(i)->setBrush(painter.pen().color());
//    //![5]
}

void ChartView::newScatter(const QString &name, QVector<QPointF> points)
{
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName(name);
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(4);

    foreach(QPointF point, points) {
        *series0 << point;
    }
    setRenderHint(QPainter::Antialiasing);
    chart()->addSeries(series0);
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);
}
