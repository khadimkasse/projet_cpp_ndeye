#include "noteretudiant.h"
#include "ui_noteretudiant.h"
#include "gestionetudiants.h"
#include "../connectdb.h"
#include <QtSql>
#include <QtDebug>
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>

NoterEtudiant::NoterEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoterEtudiant)
{
    ui->setupUi(this);
    loadComboBox();
}

void NoterEtudiant::loadComboBox() {
    ui -> matieres -> clear();
    ui -> matieres ->blockSignals(true);
    ui -> matieres -> addItem("-", 0);
    ConnectDB connectDB;
    connectDB.openConnexion();
    QSqlQuery* qry=new QSqlQuery(connectDB.getConnexion());
    qry -> prepare("select * from matieres order by nom;");
    qry->exec();
    int i = 1;
    while(qry->next()) {
        this -> matiere = new Matiere(qry -> value(0).toString().toStdString(), qry -> value(1).toInt());
        ui -> matieres -> addItem(QString::fromStdString(matiere->getNomMatiere()), i);
        i = i+1 ;
        delete matiere;
    }
    ui -> matieres ->blockSignals(false);
}

NoterEtudiant::~NoterEtudiant()
{
    delete ui;
}

void NoterEtudiant::on_retour_clicked()
{
    hide();
    GestionEtudiants gestionsEtudiants;
    gestionsEtudiants.setModal(true);
    gestionsEtudiants.exec();
}

void NoterEtudiant::on_enregistrerNote_clicked()
{
    ConnectDB connectDB;
     connectDB.openConnexion();
     QString nomMatiere =  ui -> matieres -> currentText();
     int numeroEtudiant = ui -> inputNumeroEtudiant -> text().toInt();
     if(connectDB.dbIsOpened()){
         QSqlQuery* qryMatiere=new QSqlQuery(connectDB.getConnexion());
         qryMatiere->prepare("select * from matieres where nom=:nomDeLaMatiere;");
         qryMatiere->bindValue(":nomDeLaMatiere", nomMatiere );
         bool qryMatiereOK = qryMatiere->exec();
         if(qryMatiereOK) {
             qryMatiere->next();
             this -> matiere = new Matiere(qryMatiere -> value(0).toString().toStdString(), qryMatiere -> value(1).toInt());
             this -> note = new Note(ui -> inputNote-> text().toFloat(), matiere);
             QSqlQuery* qryNote=new QSqlQuery(connectDB.getConnexion());
             qryNote->prepare("insert into notes(numero_etudiant, nom_matiere, note) values(:newNumeroEtudiant, :newNomMatiere, :newNote)");
             qryNote->bindValue(":newNumeroEtudiant", numeroEtudiant);
             qryNote->bindValue(":newNomMatiere", QString::fromStdString(note -> getMatiere() -> getNomMatiere()));
             qryNote->bindValue(":newNote", note -> getNoteSurVingt());
             bool qryNoteOK = qryNote->exec();
             if(qryNoteOK) {
                 connectDB.closeConnexion();
                 QMessageBox::information(this, "Sauvegarde", "La note de l'étudiant a bie été sauvegardée.");
             } else {
                 QMessageBox::critical(this,"Erreur","Une erreur s'est produite lors de la sauvegarde de la note.");
             }
         } else {
             QMessageBox::critical(this,"Erreur","Une erreur s'est produite lors de la sauvegarde de la note.");
         }
     }
     ui -> matieres -> setCurrentIndex(0);
     ui -> inputNote -> setText("");
}
