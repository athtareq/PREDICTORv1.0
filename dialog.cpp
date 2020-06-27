#include "dialog.h"
#include "ui_dialog.h"
#include "ui_mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     ui->label_8->setOpenExternalLinks(true);
     setFixedSize(width(), height());
     //ui->label->setText(MainWindow::ui->hometeam->currentTex());

}


Dialog::~Dialog()
{
    delete ui;
}
