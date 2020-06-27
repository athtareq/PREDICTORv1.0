#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include "howto.h"
#include<vector>
#include<iostream>
#include<math.h>
#include<QMessageBox>
#include<dialog.h>
#include<tools.h>
using namespace std;

double htas,htds,atas,atds,ahg,aag;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setFixedSize(width(),height());


        QSqlDatabase teams=QSqlDatabase::addDatabase("QSQLITE");                     //ouverture de la bdd
        teams.setDatabaseName("/home/tareq/FinalPredictor/Files/top5leagueteams.db");
        if (!teams.open())
        {
            qDebug() << teams.lastError().text();
            ui->error->setText("failed");
            }
        else ui->error->setText("success");
        if(teams.open()){
        qDebug()<<"Database Open!!";
        }


    }

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::resizeEvent(QResizeEvent* evt)
{
    QPixmap bkgnd(":/photos/kickoff.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); //fond d'ecran et aussi
                                                                                           //taille

    QPalette palette;

    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QMainWindow::resizeEvent(evt);
}



void MainWindow::on_comboBox_currentIndexChanged(const QString &country)
{
    if(country=="Pick a country") {
        ui->hometeam->clear();
        ui->awayteam->clear();
        ui->hometeam->addItem("----");
        ui->awayteam->addItem("----");
        }


    if(country=="Premier League"){

        ui->hometeam->clear();
        ui->awayteam->clear();
            ui->hometeam->addItem("Choose a team");
            ui->hometeam->addItem("Arsenal");
            ui->hometeam->addItem("Aston Villa");
            ui->hometeam->addItem("Bournemouth");
            ui->hometeam->addItem("Brighton");
            ui->hometeam->addItem("Burnley");
            ui->hometeam->addItem("Chelsea");
            ui->hometeam->addItem("Crystal Palace");
            ui->hometeam->addItem("Everton");
            ui->hometeam->addItem("Leicester City");
            ui->hometeam->addItem("Liverpool");
            ui->hometeam->addItem("Manchester City");
            ui->hometeam->addItem("Manchester United");
            ui->hometeam->addItem("Newcastle United");
            ui->hometeam->addItem("Norwich City");
            ui->hometeam->addItem("Sheffield United");
            ui->hometeam->addItem("Southampton");
            ui->hometeam->addItem("Tottenham");
            ui->hometeam->addItem("Watford");
            ui->hometeam->addItem("West Ham");
            ui->hometeam->addItem("Wolverhampton");
            ui->awayteam->addItem("Choose a team");
            ui->awayteam->addItem("Arsenal");
            ui->awayteam->addItem("Aston Villa");
            ui->awayteam->addItem("Bournemouth");
            ui->awayteam->addItem("Brighton");
            ui->awayteam->addItem("Burnley");
            ui->awayteam->addItem("Chelsea");
            ui->awayteam->addItem("Crystal Palace");
            ui->awayteam->addItem("Everton");
            ui->awayteam->addItem("Leicester City");
            ui->awayteam->addItem("Liverpool");
            ui->awayteam->addItem("Manchester City");
            ui->awayteam->addItem("Manchester United");
            ui->awayteam->addItem("Newcastle United");
            ui->awayteam->addItem("Norwich City");
            ui->awayteam->addItem("Sheffield United");
            ui->awayteam->addItem("Southampton");
            ui->awayteam->addItem("Tottenham");
            ui->awayteam->addItem("Watford");
            ui->awayteam->addItem("West Ham");
            ui->awayteam->addItem("Wolverhampton");
    }
    if(country=="Bundesliga"){
          ui->hometeam->clear();
          ui->awayteam->clear();
            ui->hometeam->addItem("Choose a team");
            ui->hometeam->addItem("Augsburg");
            ui->hometeam->addItem("Hertha BSC");
            ui->hometeam->addItem("Union Berlin");
            ui->hometeam->addItem("Werder Bremen");
            ui->hometeam->addItem("Borussia Dortmund");
            ui->hometeam->addItem("Fortuna Dusseldorf");
            ui->hometeam->addItem("Eintracht Frankfurt");
            ui->hometeam->addItem("SC Freiburg");
            ui->hometeam->addItem("Hoffenheim");
            ui->hometeam->addItem("Koln");
            ui->hometeam->addItem("Leipzig");
            ui->hometeam->addItem("Leverkusen");
            ui->hometeam->addItem("Mainz 05");
            ui->hometeam->addItem("Borussia Monchengladbach");
            ui->hometeam->addItem("Bayern Munich");
            ui->hometeam->addItem("SC Paderborn");
            ui->hometeam->addItem("Schalke 04");
            ui->hometeam->addItem("Wolfsburg");
            ui->awayteam->clear();
              ui->awayteam->addItem("Choose a team");
              ui->awayteam->addItem("Augsburg");
              ui->awayteam->addItem("Hertha BSC");
              ui->awayteam->addItem("Union Berlin");
              ui->awayteam->addItem("Werder Bremen");
              ui->awayteam->addItem("Borussia Dortmund");
              ui->awayteam->addItem("Fortuna Dusseldorf");
              ui->awayteam->addItem("Eintracht Frankfurt");
              ui->awayteam->addItem("SC Freiburg");
              ui->awayteam->addItem("Hoffenheim");
              ui->awayteam->addItem("Koln");
              ui->awayteam->addItem("Leipzig");
              ui->awayteam->addItem("Leverkusen");
              ui->awayteam->addItem("Mainz 05");
              ui->awayteam->addItem("Borussia Monchengladbach");
              ui->awayteam->addItem("Bayern Munich");
              ui->awayteam->addItem("SC Paderborn");
              ui->awayteam->addItem("Schalke 04");
              ui->awayteam->addItem("Wolfsburg");
    }
    if(country=="La Liga"){
        ui->hometeam->clear();
        ui->awayteam->clear();
            ui->hometeam->addItem("Choose a team");
            ui->hometeam->addItem("Alaves");
            ui->hometeam->addItem("Athletic Bilbao");
            ui->hometeam->addItem("Atletico Madrid");
            ui->hometeam->addItem("Barcelona");
            ui->hometeam->addItem("Betis");
            ui->hometeam->addItem("CA Osasuna");
            ui->hometeam->addItem("Celta Vigo");
            ui->hometeam->addItem("Eibar");
            ui->hometeam->addItem("Getafe");
            ui->hometeam->addItem("Granada");
            ui->hometeam->addItem("Leganes");
            ui->hometeam->addItem("Levante");
            ui->hometeam->addItem("Espanyol");
            ui->hometeam->addItem("Real Majorque");
            ui->hometeam->addItem("Real Madrid");
            ui->hometeam->addItem("Real Sociedad");
            ui->hometeam->addItem("Real Valladolid");
            ui->hometeam->addItem("Sevilla");
            ui->hometeam->addItem("Valencia");
            ui->hometeam->addItem("Villareal");
            ui->awayteam->clear();
              ui->awayteam->addItem("Choose a team");
              ui->awayteam->addItem("Alaves");
              ui->awayteam->addItem("Athletic Bilbao");
              ui->awayteam->addItem("Atletico Madrid");
              ui->awayteam->addItem("Barcelona");
              ui->awayteam->addItem("Betis");
              ui->awayteam->addItem("CA Osasuna");
              ui->awayteam->addItem("Celta Vigo");
              ui->awayteam->addItem("Eibar");
              ui->awayteam->addItem("Getafe");
              ui->awayteam->addItem("Granada");
              ui->awayteam->addItem("Leganes");
              ui->awayteam->addItem("Levante");
              ui->awayteam->addItem("Espanyol");
              ui->awayteam->addItem("Real Majorque");
              ui->awayteam->addItem("Real Madrid");
              ui->awayteam->addItem("Real Sociedad");
              ui->awayteam->addItem("Real Valladolid");
              ui->awayteam->addItem("Sevilla");
              ui->awayteam->addItem("Valencia");
              ui->awayteam->addItem("Villareal");
    }
    if(country=="Serie A"){
        ui->hometeam->clear();
        ui->awayteam->clear();
        ui->hometeam->addItem("Choose a team");
            ui->hometeam->addItem("Atalanta");
            ui->hometeam->addItem("Bologna");
            ui->hometeam->addItem("Brescia");
            ui->hometeam->addItem("Cagliari");
            ui->hometeam->addItem("Fiorentina");
            ui->hometeam->addItem("Genoa");
            ui->hometeam->addItem("Inter");
            ui->hometeam->addItem("Juventus");
            ui->hometeam->addItem("Lazio");
            ui->hometeam->addItem("Lecce");
            ui->hometeam->addItem("Milan");
            ui->hometeam->addItem("Napoli");
            ui->hometeam->addItem("Parma");
            ui->hometeam->addItem("Roma");
            ui->hometeam->addItem("Sampdoria");
            ui->hometeam->addItem("Sassuolo");
            ui->hometeam->addItem("SPAL");
            ui->hometeam->addItem("Torino");
            ui->hometeam->addItem("Udinese");
            ui->hometeam->addItem("Verona");
            ui->awayteam->clear();
              ui->awayteam->addItem("Choose a team");
              ui->awayteam->addItem("Atalanta");
              ui->awayteam->addItem("Bologna");
              ui->awayteam->addItem("Brescia");
              ui->awayteam->addItem("Cagliari");
              ui->awayteam->addItem("Fiorentina");
              ui->awayteam->addItem("Genoa");
              ui->awayteam->addItem("Inter");
              ui->awayteam->addItem("Juventus");
              ui->awayteam->addItem("Lazio");
              ui->awayteam->addItem("Lecce");
              ui->awayteam->addItem("Milan");
              ui->awayteam->addItem("Napoli");
              ui->awayteam->addItem("Parma");
              ui->awayteam->addItem("Roma");
              ui->awayteam->addItem("Sampdoria");
              ui->awayteam->addItem("Sassuolo");
              ui->awayteam->addItem("SPAL");
              ui->awayteam->addItem("Torino");
              ui->awayteam->addItem("Udinese");
              ui->awayteam->addItem("Verona");
    }
    if(country=="Ligue 1"){
        ui->hometeam->clear();
        ui->awayteam->clear();
        ui->hometeam->addItem("Choose a team");
            ui->hometeam->addItem("Amiens");
            ui->hometeam->addItem("Angers");
            ui->hometeam->addItem("Bordeaux");
            ui->hometeam->addItem("Brest");
            ui->hometeam->addItem("Dijon");
            ui->hometeam->addItem("Lille");
            ui->hometeam->addItem("Lyon");
            ui->hometeam->addItem("Marseille");
            ui->hometeam->addItem("Metz");
            ui->hometeam->addItem("Monaco");
            ui->hometeam->addItem("Montpellier");
            ui->hometeam->addItem("Nantes");
            ui->hometeam->addItem("Nice");
            ui->hometeam->addItem("Nimes");
            ui->hometeam->addItem("Paris Saint Germain");
            ui->hometeam->addItem("Reims");
            ui->hometeam->addItem("Rennes");
            ui->hometeam->addItem("Saint Etienne");
            ui->hometeam->addItem("Strasbourg");
            ui->hometeam->addItem("Toulouse");
              ui->awayteam->addItem("Choose a team");
              ui->awayteam->addItem("Amiens");
              ui->awayteam->addItem("Angers");
              ui->awayteam->addItem("Bordeaux");
              ui->awayteam->addItem("Brest");
              ui->awayteam->addItem("Dijon");
              ui->awayteam->addItem("Lille");
              ui->awayteam->addItem("Lyon");
              ui->awayteam->addItem("Marseille");
              ui->awayteam->addItem("Metz");
              ui->awayteam->addItem("Monaco");
              ui->awayteam->addItem("Montpellier");
              ui->awayteam->addItem("Nantes");
              ui->awayteam->addItem("Nice");
              ui->awayteam->addItem("Nimes");
              ui->awayteam->addItem("Paris Saint Germain");
              ui->awayteam->addItem("Reims");
              ui->awayteam->addItem("Rennes");
              ui->awayteam->addItem("Saint Etienne");
              ui->awayteam->addItem("Strasbourg");
              ui->awayteam->addItem("Toulouse");
    }









        }


void MainWindow::on_hometeam_currentIndexChanged(const QString &hometeam)
{
  if(ui->comboBox->currentText()=="Premier League"){
      QString hteam(hometeam);
      QSqlQuery thas;
        thas.prepare("SELECT THAS FROM pl WHERE TEAM=:hteam");
        thas.bindValue(":hteam", hteam);
        thas.exec();
        int fieldNo = thas.record().indexOf("THAS");
         thas.next();
         qDebug() <<"THAS for "<<hteam<<" = "<< thas.value(fieldNo).toDouble();
          if(thas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
          else ui->error->setText("no");
          htas=thas.value(fieldNo).toDouble();

          QSqlQuery thdv;
            thdv.prepare("SELECT THDV FROM pl WHERE TEAM=:hteam");
            thdv.bindValue(":hteam", hteam);
            thdv.exec();
            int fieldNo1 = thdv.record().indexOf("THDV");
             thdv.next();
             qDebug() <<"THDV for "<<hteam<<"= "<< thdv.value(fieldNo1).toDouble();

             htds=thdv.value(fieldNo1).toDouble();

             QSqlQuery avgHG;
               avgHG.prepare("SELECT THAS FROM pl WHERE TEAM='Total'");
               avgHG.bindValue("Total", "Total");
               avgHG.exec();
               int fieldNo2 = avgHG.record().indexOf("THAS");
                avgHG.next();
                qDebug() <<"Average home goals = "<< avgHG.value(fieldNo2).toDouble();

             ahg=avgHG.value(fieldNo2).toDouble();  }

  if(ui->comboBox->currentText()=="Bundesliga"){
      QString hteam(hometeam);
      QSqlQuery thas;
        thas.prepare("SELECT THAS FROM buli WHERE TEAM=:hteam");
        thas.bindValue(":hteam", hteam);
        thas.exec();
        int fieldNo = thas.record().indexOf("THAS");
         thas.next();
         qDebug() <<"THAS for "<<hteam<<" = "<< thas.value(fieldNo).toDouble();
          if(thas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
          else ui->error->setText("no");
          htas=thas.value(fieldNo).toDouble();

          QSqlQuery thdv;
            thdv.prepare("SELECT THDV FROM buli WHERE TEAM=:hteam");
            thdv.bindValue(":hteam", hteam);
            thdv.exec();
            int fieldNo1 = thdv.record().indexOf("THDV");
             thdv.next();
             qDebug() <<"THDV for "<<hteam<<"= "<< thdv.value(fieldNo1).toDouble();

             htds=thdv.value(fieldNo1).toDouble();

             QSqlQuery avgHG;
               avgHG.prepare("SELECT THAS FROM buli WHERE TEAM='Total'");
               avgHG.bindValue("Total", "Total");
               avgHG.exec();
               int fieldNo2 = avgHG.record().indexOf("THAS");
                avgHG.next();
                qDebug() <<"Average home goals = "<< avgHG.value(fieldNo2).toDouble();

             ahg=avgHG.value(fieldNo2).toDouble();

  }
  if(ui->comboBox->currentText()=="La Liga"){
      QString hteam(hometeam);
      QSqlQuery thas;
        thas.prepare("SELECT THAS FROM liga WHERE TEAM=:a");
        thas.bindValue(":a", hteam);
        thas.exec();
        int fieldNo = thas.record().indexOf("THAS");
         thas.next();
         qDebug() <<"THAS for "<<hteam<<" = "<< thas.value(fieldNo).toDouble();
          if(thas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
          else ui->error->setText("no");
          htas=thas.value(fieldNo).toDouble();

          QSqlQuery thdv;
            thdv.prepare("SELECT THDV FROM liga WHERE TEAM=:hteam");
            thdv.bindValue(":hteam", hteam);
            thdv.exec();
            int fieldNo1 = thdv.record().indexOf("THDV");
             thdv.next();
             qDebug() <<"THDV for "<<hteam<<"= "<< thdv.value(fieldNo1).toDouble();

             htds=thdv.value(fieldNo1).toDouble();

             QSqlQuery avgHG;
               avgHG.prepare("SELECT THAS FROM liga WHERE TEAM='Total'");
               avgHG.bindValue("Total", "Total");
               avgHG.exec();
               int fieldNo2 = avgHG.record().indexOf("THAS");
                avgHG.next();
                qDebug() <<"Average home goals = "<< avgHG.value(fieldNo2).toDouble();

             ahg=avgHG.value(fieldNo2).toDouble();

  }    if(ui->comboBox->currentText()=="Serie A"){
      QString hteam(hometeam);
      QSqlQuery thas;
        thas.prepare("SELECT THAS FROM calcio WHERE TEAM=:hteam");
        thas.bindValue(":hteam", hteam);
        thas.exec();
        int fieldNo = thas.record().indexOf("THAS");
         thas.next();
         qDebug() <<"THAS for "<<hteam<<" = "<< thas.value(fieldNo).toDouble();
          if(thas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
          else ui->error->setText("no");
          htas=thas.value(fieldNo).toDouble();

          QSqlQuery thdv;
            thdv.prepare("SELECT THDV FROM calcio WHERE TEAM=:hteam");
            thdv.bindValue(":hteam", hteam);
            thdv.exec();
            int fieldNo1 = thdv.record().indexOf("THDV");
             thdv.next();
             qDebug() <<"THDV for "<<hteam<<"= "<< thdv.value(fieldNo1).toDouble();

             htds=thdv.value(fieldNo1).toDouble();

             QSqlQuery avgHG;
               avgHG.prepare("SELECT THAS FROM calcio WHERE TEAM='Total'");
               avgHG.bindValue("Total", "Total");
               avgHG.exec();
               int fieldNo2 = avgHG.record().indexOf("THAS");
                avgHG.next();
                qDebug() <<"Average home goals = "<< avgHG.value(fieldNo2).toDouble();

             ahg=avgHG.value(fieldNo2).toDouble();

  }    if(ui->comboBox->currentText()=="Ligue 1"){
      QString hteam(hometeam);
      QSqlQuery thas;
        thas.prepare("SELECT THAS FROM french WHERE TEAM=:hteam");
        thas.bindValue(":hteam", hteam);
        thas.exec();
        int fieldNo = thas.record().indexOf("THAS");
         thas.next();
         qDebug() <<"THAS for "<<hteam<<" = "<< thas.value(fieldNo).toDouble();
          if(thas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
          else ui->error->setText("no");
          htas=thas.value(fieldNo).toDouble();

          QSqlQuery thdv;
            thdv.prepare("SELECT THDV FROM french WHERE TEAM=:hteam");
            thdv.bindValue(":hteam", hteam);
            thdv.exec();
            int fieldNo1 = thdv.record().indexOf("THDV");
             thdv.next();
             qDebug() <<"THDV for "<<hteam<<"= "<< thdv.value(fieldNo1).toDouble();

             htds=thdv.value(fieldNo1).toDouble();

             QSqlQuery avgHG;
               avgHG.prepare("SELECT THAS FROM french WHERE TEAM='Total'");
               avgHG.bindValue("Total", "Total");
               avgHG.exec();
               int fieldNo2 = avgHG.record().indexOf("THAS");
                avgHG.next();
                qDebug() <<"Average home goals = "<< avgHG.value(fieldNo2).toDouble();

             ahg=avgHG.value(fieldNo2).toDouble();

  }

}
void MainWindow::on_awayteam_currentIndexChanged(const QString &awayteam)
{

    if(ui->comboBox->currentText()=="Premier League"){
        QString ateam(awayteam);
          QSqlQuery taas;
            taas.prepare("SELECT taas FROM pl WHERE TEAM=:ateam");
            taas.bindValue(":ateam", ateam);
            taas.exec();
            int fieldNo = taas.record().indexOf("taas");
             taas.next();
             qDebug() <<"taas for "<<ateam<<" = "<< taas.value(fieldNo).toDouble();
              if(taas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
              else ui->error->setText("no");
              atas=taas.value(fieldNo).toDouble();

              QSqlQuery tadv;
                tadv.prepare("SELECT tadv FROM pl WHERE TEAM=:ateam");
                tadv.bindValue(":ateam", ateam);
                tadv.exec();
                int fieldNo1 = tadv.record().indexOf("tadv");
                 tadv.next();
                 qDebug() <<"tadv for "<<ateam<<"= "<< tadv.value(fieldNo1).toDouble();

              atds=tadv.value(fieldNo1).toDouble();

                 QSqlQuery avgAG;
                   avgAG.prepare("SELECT taas FROM pl WHERE TEAM='Total'");
                   avgAG.bindValue("Total", "Total");
                   avgAG.exec();
                   int fieldNo2 = avgAG.record().indexOf("taas");
                    avgAG.next();
                    qDebug() <<"Average away goals = "<< avgAG.value(fieldNo2).toDouble();

               aag=avgAG.value(fieldNo2).toDouble();
    }
    if(ui->comboBox->currentText()=="La Liga"){
        QString ateam(awayteam);
          QSqlQuery taas;
            taas.prepare("SELECT taas FROM liga WHERE TEAM=:ateam");
            taas.bindValue(":ateam", ateam);
            taas.exec();
            int fieldNo = taas.record().indexOf("taas");
             taas.next();
             qDebug() <<"taas for "<<ateam<<" = "<< taas.value(fieldNo).toDouble();
              if(taas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
              else ui->error->setText("no");
              atas=taas.value(fieldNo).toDouble();

              QSqlQuery tadv;
                tadv.prepare("SELECT tadv FROM liga WHERE TEAM=:ateam");
                tadv.bindValue(":ateam", ateam);
                tadv.exec();
                int fieldNo1 = tadv.record().indexOf("tadv");
                 tadv.next();
                 qDebug() <<"tadv for "<<ateam<<"= "<< tadv.value(fieldNo1).toDouble();

              atds=tadv.value(fieldNo1).toDouble();

                 QSqlQuery avgAG;
                   avgAG.prepare("SELECT taas FROM liga WHERE TEAM='Total'");
                   avgAG.bindValue("Total", "Total");
                   avgAG.exec();
                   int fieldNo2 = avgAG.record().indexOf("taas");
                    avgAG.next();
                    qDebug() <<"Average away goals = "<< avgAG.value(fieldNo2).toDouble();

               aag=avgAG.value(fieldNo2).toDouble();
    }    if(ui->comboBox->currentText()=="Bundesliga"){
        QString ateam(awayteam);
          QSqlQuery taas;
            taas.prepare("SELECT taas FROM buli WHERE TEAM=:ateam");
            taas.bindValue(":ateam", ateam);
            taas.exec();
            int fieldNo = taas.record().indexOf("taas");
             taas.next();
             qDebug() <<"taas for "<<ateam<<" = "<< taas.value(fieldNo).toDouble();
              if(taas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
              else ui->error->setText("no");
              atas=taas.value(fieldNo).toDouble();

              QSqlQuery tadv;
                tadv.prepare("SELECT tadv FROM buli WHERE TEAM=:ateam");
                tadv.bindValue(":ateam", ateam);
                tadv.exec();
                int fieldNo1 = tadv.record().indexOf("tadv");
                 tadv.next();
                 qDebug() <<"tadv for "<<ateam<<"= "<< tadv.value(fieldNo1).toDouble();

              atds=tadv.value(fieldNo1).toDouble();

                 QSqlQuery avgAG;
                   avgAG.prepare("SELECT taas FROM buli WHERE TEAM='Total'");
                   avgAG.bindValue("Total", "Total");
                   avgAG.exec();
                   int fieldNo2 = avgAG.record().indexOf("taas");
                    avgAG.next();
                    qDebug() <<"Average away goals = "<< avgAG.value(fieldNo2).toDouble();

               aag=avgAG.value(fieldNo2).toDouble();
    }    if(ui->comboBox->currentText()=="Serie A"){
        QString ateam(awayteam);
          QSqlQuery taas;
            taas.prepare("SELECT taas FROM calcio WHERE TEAM=:ateam");
            taas.bindValue(":ateam", ateam);
            taas.exec();
            int fieldNo = taas.record().indexOf("taas");
             taas.next();
             qDebug() <<"taas for "<<ateam<<" = "<< taas.value(fieldNo).toDouble();
              if(taas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
              else ui->error->setText("no");
              atas=taas.value(fieldNo).toDouble();

              QSqlQuery tadv;
                tadv.prepare("SELECT tadv FROM calcio WHERE TEAM=:ateam");
                tadv.bindValue(":ateam", ateam);
                tadv.exec();
                int fieldNo1 = tadv.record().indexOf("tadv");
                 tadv.next();
                 qDebug() <<"tadv for "<<ateam<<"= "<< tadv.value(fieldNo1).toDouble();

              atds=tadv.value(fieldNo1).toDouble();

                 QSqlQuery avgAG;
                   avgAG.prepare("SELECT taas FROM calcio WHERE TEAM='Total'");
                   avgAG.bindValue("Total", "Total");
                   avgAG.exec();
                   int fieldNo2 = avgAG.record().indexOf("taas");
                    avgAG.next();
                    qDebug() <<"Average away goals = "<< avgAG.value(fieldNo2).toDouble();

               aag=avgAG.value(fieldNo2).toDouble();
    }    if(ui->comboBox->currentText()=="Ligue 1"){
        QString ateam(awayteam);
          QSqlQuery taas;
            taas.prepare("SELECT taas FROM french WHERE TEAM=:ateam");
            taas.bindValue(":ateam", ateam);
            taas.exec();
            int fieldNo = taas.record().indexOf("taas");
             taas.next();
             qDebug() <<"taas for "<<ateam<<" = "<< taas.value(fieldNo).toDouble();
              if(taas.value(fieldNo).toDouble() > 1.2) ui->error->setText("yes");
              else ui->error->setText("no");
              atas=taas.value(fieldNo).toDouble();

              QSqlQuery tadv;
                tadv.prepare("SELECT tadv FROM french WHERE TEAM=:ateam");
                tadv.bindValue(":ateam", ateam);
                tadv.exec();
                int fieldNo1 = tadv.record().indexOf("tadv");
                 tadv.next();
                 qDebug() <<"tadv for "<<ateam<<"= "<< tadv.value(fieldNo1).toDouble();

              atds=tadv.value(fieldNo1).toDouble();

                 QSqlQuery avgAG;
                   avgAG.prepare("SELECT taas FROM french WHERE TEAM='Total'");
                   avgAG.bindValue("Total", "Total");
                   avgAG.exec();
                   int fieldNo2 = avgAG.record().indexOf("taas");
                    avgAG.next();
                    qDebug() <<"Average away goals = "<< avgAG.value(fieldNo2).toDouble();

               aag=avgAG.value(fieldNo2).toDouble();
    }



}






double fact(int);
double fact(int n){
if (n==0) return 1;
else return n*fact(n-1);
}
void MainWindow::on_predict_clicked()
{
    ui->outcome1->clear();
    ui->outcome2->clear();
    ui->outcome3->clear();


    double xHG=htas*atds*ahg;

    double xAG=atas*htds*aag;
    qDebug() <<"xHG = "<<xHG;
    qDebug() <<"xAG = "<<xAG;
    xHG=xHG-0.3*ui->homeinjuries->value();
    xAG=xAG-0.3*ui->awayinjuries->value();
    qDebug() <<"after injuries xHG = "<<xHG;
    qDebug() <<"after injuries xAG = "<<xAG;
    if(ui->homemidweek->checkState()){
        xHG=xHG-0.4;
    }
    if(ui->awaymidweek->checkState()){
        xAG=xAG-0.8;
    }

    double PxHG[6]; //tableaux bleus
    double PxAG[6];
    for(int i(0);i<6;i++){
        PxHG[i]=pow(xHG,i)*exp(-xHG)/fact(i);
    }
    for(int i(0);i<6;i++){
        PxAG[i]=pow(xAG,i)*exp(-xAG)/fact(i);
    }
    double Probas[6][6]; //tableau pricnipale
    for(int i(0);i<6;i++){
        for(int j(0);j<6;j++){
            Probas[i][j]=PxHG[i]*PxAG[j];
        }
    }
    double mx(0); //max
    for(int i(0);i<6;i++){
        for(int j(0);j<6;j++){
            if (Probas[i][j]>mx) mx=Probas[i][j];
        }
    }
    for(int i(0);i<6;i++){ //indice max
        for(int j(0);j<6;j++){
            if (Probas[i][j]==mx) {
              qDebug() <<"Home Goals = "<<i;
              qDebug() <<"Away Goals = "<<j;
              ui->homegoals->display(i); //affichage du resultat
              ui->awaygoals->display(j);
              if(i>=2){
                  ui->outcome1->setText(ui->hometeam->currentText()+ " scoring at least a goal ");
               }
              if(j>=2){
                  ui->outcome3->setText(ui->awayteam->currentText()+ " scoring at least a goal ");
              }
              if(i-j>2){
                  QString outcome1=ui->hometeam->currentText() + " is likely to win" ;
                  ui->outcome2->setText(outcome1);
              }
              if(j-i>=2){
                  QString outcome1=ui->awayteam->currentText() + " is likely to win" ;
                  ui->outcome2->setText(outcome1);
              }
            }
    }
}


    }









void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}



void MainWindow::on_tools_clicked()
{
    tools tools  ;
    tools.setModal(true);
    tools.exec();

}
