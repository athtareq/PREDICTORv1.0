#include "tools.h"
#include "ui_tools.h"
#include<math.h>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QSqlRecord>



tools::tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tools)
{
    ui->setupUi(this);
    setFixedSize(width(),height());
}

tools::~tools()
{
    delete ui;
}
double facto(int);
double facto(int n){
if (n==0) return 1;
else return n*facto(n-1);
}

void tools::on_calcpoisson_clicked()
{
    double k=ui->nbK->text().toInt();
    double lbd=ui->lamda->text().toDouble();
    ui->respoissuser->setNum(pow(lbd,k)*exp(-lbd)/facto(k));
}

void tools::on_league_currentTextChanged(const QString &country)
{
    if(country=="Pick a country") {
        ui->team->clear();
        ui->team->addItem("----");
        //ui->awayui->team->addItem("----");
        }


    if(country=="Premier League"){

        ui->team->clear();
        ui->team->clear();
            ui->team->addItem("Choose a team");
            ui->team->addItem("Arsenal");
            ui->team->addItem("Aston Villa");
            ui->team->addItem("Bournemouth");
            ui->team->addItem("Brighton");
            ui->team->addItem("Burnley");
            ui->team->addItem("Chelsea");
            ui->team->addItem("Crystal Palace");
            ui->team->addItem("Everton");
            ui->team->addItem("Leicester City");
            ui->team->addItem("Liverpool");
            ui->team->addItem("Manchester City");
            ui->team->addItem("Manchester United");
            ui->team->addItem("Newcastle United");
            ui->team->addItem("Norwich City");
            ui->team->addItem("Sheffield United");
            ui->team->addItem("Southampton");
            ui->team->addItem("Tottenham");
            ui->team->addItem("Watford");
            ui->team->addItem("West Ham");
            ui->team->addItem("Wolverhampton");

}


    }

void tools::on_pushButton_clicked()
{
    if(ui->comboBox->currentText()=="Home"){
        QString hteam(ui->team->currentText());
        QSqlQuery thas;
          thas.prepare("SELECT THAS FROM pl WHERE team=:hteam");
          thas.bindValue(":hteam", hteam);
          thas.exec();
          int fieldNo = thas.record().indexOf("THAS");
           thas.next();
           qDebug() <<"THAS for "<<hteam<<" = "<< thas.value(fieldNo).toDouble();
           ui->ats->setNum(thas.value(fieldNo).toDouble());
            QSqlQuery thdv;
              thdv.prepare("SELECT THDV FROM pl WHERE team=:hteam");
              thdv.bindValue(":hteam", hteam);
              thdv.exec();
              int fieldNo1 = thdv.record().indexOf("THDV");
               thdv.next();
               qDebug() <<"THDV for "<<hteam<<"= "<< thdv.value(fieldNo1).toDouble();

            ui->dfv->setNum(thdv.value(fieldNo1).toDouble());
              /* QSqlQuery avgHG;
                 avgHG.prepare("SELECT THAS FROM pl WHERE team='Total'");
                 avgHG.bindValue("Total", "Total");
                 avgHG.exec();
                 int fieldNo2 = avgHG.record().indexOf("THAS");
                  avgHG.next();
                  qDebug() <<"Average home goals = "<< avgHG.value(fieldNo2).toDouble();
            ui->alg->setNum(avgHG.value(fieldNo2).toDouble());*/
    }



    if(ui->comboBox->currentText()=="Away"){
          QString ateam(ui->team->currentText());
            QSqlQuery taas;
              taas.prepare("SELECT taas FROM pl WHERE team=:ateam");
              taas.bindValue(":ateam", ateam);
              taas.exec();
              int fieldNo = taas.record().indexOf("taas");
               taas.next();
               qDebug() <<"taas for "<<ui->team->currentText()<<" = "<< taas.value(fieldNo).toDouble();
                ui->ats->setNum(taas.value(fieldNo).toDouble());

                QSqlQuery tadv;
                  tadv.prepare("SELECT tadv FROM pl WHERE team=:ateam");
                  tadv.bindValue(":ateam", ateam);
                  tadv.exec();
                  int fieldNo1 = tadv.record().indexOf("tadv");
                   tadv.next();
                   qDebug() <<"tadv for "<<ui->team->currentText()<<"= "<< tadv.value(fieldNo1).toDouble();

                ui->dfv->setNum(tadv.value(fieldNo1).toDouble());
                   /*QSqlQuery avgAG;
                     avgAG.prepare("SELECT taas FROM pl WHERE ateam='Total'");
                     avgAG.bindValue("Total", "Total");
                     avgAG.exec();
                     int fieldNo2 = avgAG.record().indexOf("taas");
                      avgAG.next();
                      qDebug() <<"Average away goals = "<< avgAG.value(fieldNo2).toDouble();
                      ui->alg->setNum(avgAG.value(fieldNo2).toDouble());*/
                              }



}

void tools::on_pushButton_2_clicked()
{
    QVector<double>PxHG;
    QVector<double>PxAG;
    for(int i(0);i<5;i++){
        QTableWidgetItem *item = ui->tableWidget->item(0,i+1);
        PxHG.push_back(item->text().toDouble());
    }
    for(int j(0);j<5;j++){
        QTableWidgetItem *item = ui->tableWidget->item(j+1,0);
        PxAG.push_back(item->text().toDouble());
    }
    double mat[5][5];
    for(int i(0);i<5;i++){
        for(int j(0);j<5;j++){
            mat[i][j]=PxHG[i]*PxAG[j];
        }
        for(int i(0);i<5;i++){
            for(int j(0);j<5;j++){
                qDebug()<<"Les elmts produits sont: "<<mat[i][j];
            }

    for(int i(0);i<5;i++){
        for(int j(0);j<5;j++){
            QString E=QString::number(mat[i][j],'f',3);
            QTableWidgetItem* item=new QTableWidgetItem(tr("%1").arg(E));
            ui->tableWidget->setItem(i+1,j+1,item);
        }
    }
}

    }
    }

void tools::on_pushButton_3_clicked(bool checked)
{
    if(checked){
        ui->pushButton_3->setText("-");
        ui->tableWidget->setVisible(true);
    }
    else{
        ui->pushButton_3->setText("+");
        ui->tableWidget->setVisible(false);
    }
}
