#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>

namespace Ui {
class mainGui;
}

class mainGui : public QWidget
{
    Q_OBJECT

public:
    explicit mainGui(QWidget *parent = 0);
    ~mainGui();

private:
    Ui::mainGui *ui;
};

#endif // MAINGUI_H
