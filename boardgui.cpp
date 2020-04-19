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
    //it->
    return it;
}

void BoardGui::init(int N)
{
    this->N = N;
    for(int r = 0; r < N; ++r)
    {
        for(int c = 0; c < N; ++c)
        {
            if(this->acitve(r, c))
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
