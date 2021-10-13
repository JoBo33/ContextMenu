#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_form.h"

class QTableView;
QT_FORWARD_DECLARE_CLASS(QTableView)
QT_FORWARD_DECLARE_CLASS(QStandardItemModel)

class Widget : public QWidget, private Ui::form
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void customMenuRequested(QPoint pos);
    void on_action1_triggered();
    void on_action2_triggered();
    void on_action3_triggered();

private:
    QStandardItemModel *model;
};

#endif // WIDGET_H
