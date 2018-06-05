#ifndef QUERY_H
#define QUERY_H

#include <QWidget>

namespace Ui {
class query;
}

class query : public QWidget
{
    Q_OBJECT

public:
    explicit query(QWidget *parent = 0);
    ~query();

private:
    Ui::query *ui;
};

#endif // QUERY_H
