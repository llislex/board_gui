#include "boardgui.h"


BoardGui::BoardGui(QWidget *parent) :
    QTableWidget(parent), N(0)
{
}


QTableWidgetItem* new_active_site(int r, int c)
{
    QTableWidgetItem* it = new QTableWidgetItem(QTableWidgetItem::UserType);
    it->setBackground(QBrush(QColor(0,0,0)));
    it->setTextColor(QColor(255,255,255));
    it->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    return it;
}

QTableWidgetItem* passive_site(int r, int c)
{
    QTableWidgetItem* it = new QTableWidgetItem(QTableWidgetItem::UserType);
    it->setFlags(Qt::NoItemFlags);
    return it;
}

void BoardGui::init(int N)
{
    this->N = N;
    setRowCount(N);
    setColumnCount(N);
    for(int r = 0; r < N; ++r)
    {
        setColumnWidth(r, rowHeight(r));
        for(int c = 0; c < N; ++c)
        {
            if(this->acitve_site(r, c))
            {
                QTableWidgetItem* it = new_active_site(r, c);
                this->setItem(r, c, it);
            }
            else
            {
                QTableWidgetItem* it = passive_site(r, c);
                this->setItem(r, c, it);
            }
        }
    }


}

void BoardGui::resizeEvent(QResizeEvent* evt)
{
    if(N > 0)
    {
        int size = qMin(evt->size().width(), evt->size().height()) / N ;
        for (int i = 0; i < 0; ++i)
        {
            setColumnWidth(i, size);
            setRowHeight(i, size);
        }
    }
    QTableWidget::resizeEvent(evt);
}
