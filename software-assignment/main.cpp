


#include "widget.h"
#include <QApplication>

#include "login.h"
#include"maingui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainGui w;
    w.show();

    return a.exec();
}



/*

select eiinfo.goodsname,ei,eiinfo.contact,source,place,number,price,catogory,tel,apartment from eiinfo,goodsinfo,contact  
where eiinfo.contact = goodsinfo.contact and goodsinfo.contact = contact.contact 
and goodsinfo.goodsname like "% 铁 %"
*/