//#include <QtGui>
#include "widget.h"
#include <QtWidgets>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    QVBoxLayout *l=new QVBoxLayout(this);
    table->setContextMenuPolicy(Qt::CustomContextMenu);
    model = new QStandardItemModel();
    table->setModel(model);
    model->setHorizontalHeaderItem(0, new QStandardItem("String Column"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Int Column"));
    QList<QStandardItem*> rowData;
        for(int i =0; i<5; i++){
            rowData.clear();
            rowData << new QStandardItem(QString(i));
            rowData << new QStandardItem(QString("%1").arg(i));
            model->appendRow(rowData);

    connect(table, SIGNAL(customContextMenuRequested(QPoint)),
            SLOT(customMenuRequested(QPoint)));
    l->addWidget(table);

    }


}
void Widget::customMenuRequested(QPoint pos){
    //QModelIndex index=table->indexAt(pos);

    QMenu *menu=new QMenu(this);
    menu->addAction(action1);
    menu->addAction(action2);
    menu->addAction(action3);
    menu->popup(table->viewport()->mapToGlobal(pos));
}
Widget::~Widget(){};


void Widget::on_action1_triggered(){
    QItemSelection selection( table->selectionModel()->selection() );

    QList<int> rows;
    foreach( const QModelIndex & index, selection.indexes() ) {
       rows.append( index.row() );
    }

    int prev = -1;
    for( int i = rows.count() - 1; i >= 0; i -= 1 ) {
       int current = rows[i];
       if( current != prev ) {
          model->removeRows( current, 1 );
          prev = current;
       }
    }
}

void Widget::on_action2_triggered(){
    model->appendRow(new QStandardItem(1,model->columnCount()));
}

void Widget::on_action3_triggered(){
    QList<QStandardItem*> list;
    list.append(new QStandardItem(model->rowCount(), 1));
    model->appendColumn(list);


}

















