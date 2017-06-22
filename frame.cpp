#include <QPainter>

#include "frame.h"
#include "nightcharts-master/nightcharts.h"
#include "nightcharts-master/nightchartswidget.h"
#include "mainwindow.h"

Frame::Frame( QWidget* parent )
    : QFrame( parent )
    , m_radius( 0 )
{
    setFrameStyle( QFrame::Box );

    qDebug()<<"araaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<ob->Chart_words1;


}

void Frame::setCircleRadius( int radius )
{
    m_radius = radius;
}

void Frame::paintEvent( QPaintEvent* pe )
{
    QWidget::paintEvent(pe);
            QPainter painter;
            QFont font;
            painter.begin(this);
            Nightcharts PieChart;


            // = "ob->Chart_words1.at(1);";
            PieChart.setType(Nightcharts::Histogramm);//{Histogramm,Pie,DPie};
            PieChart.setLegendType(Nightcharts::Vertical);//{Round,Vertical}
            PieChart.setCords(20,20,this->width()/1.5,this->height()/1.5);
            for (int i=0;i<10;i++){
               // qDebug()<<"araaaaaaaaaaaaaa"<<ob->Chart_words1[i];
           // aaa = ob->Chart_words1[i];
            PieChart.addPiece(aaa,QColor(200,10,50),3);

            }
            PieChart.draw(&painter);
            PieChart.drawLegend(&painter);

   // }
}


void Frame::drawLines(QPainter *painter)
{


//repaint();
// <<-- new end
}
