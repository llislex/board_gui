#ifndef BOARDGUI_H
#define BOARDGUI_H

#include <QTableWidget>

typedef enum {White, Black, WhiteDam, BlackDam, Marker} GameItem;

/*class GameSite: public QTableWidgetItem
{
    int index;
    GameItem m_it;
public:
    GameSite(int r, int c);
    void setItem(GameItem it);
    GameItem item() const {m_it;}
    QChar ch() const;
    QIcon icon() const;
};*/

class BoardGui : public QTableWidget
{
    Q_OBJECT
protected:
    int N;
    bool acitve(int r, int c) const {return ((r, c) % 2) != 0;}
public:
    explicit BoardGui(QWidget *parent = 0);
    void init(int N = 8);
signals:

public slots:

};

#endif // BOARDGUI_H
