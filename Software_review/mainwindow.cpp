#include "mainwindow.h"
#include "softwarelist.h"
#include "softwarereview.h"

#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QList>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent},

    edtName(new QLineEdit),
    edtDate(new QDateEdit),
    cboxRecommend(new QCheckBox),
    btnAdd(new QPushButton("Add")),
    btnDisplay(new QPushButton("Display"))
{
    //Call SetupGui to show GUI
    setupGUI();

    setWindowTitle("Software Review");
    setMinimumSize(150, 100);

    //connect signals and slots
    connect(edtName, &QLineEdit::textChanged, this, &MainWindow::enableAddButton);
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::addToList);
    connect(btnDisplay, &QPushButton::clicked, this, &MainWindow::displayList);
}
//enable add button when there's input in the name edit box
void MainWindow::enableAddButton( )
{
    if (edtName->text().size() != 0)
        {
            btnAdd->setEnabled(true);
        }
}
//add user input to list
void MainWindow::addToList()
{
    QString name = edtName->text();
    QDate date  = edtDate->date();
    bool recommend = cboxRecommend->isChecked();
    SoftwareReview sRev(name, date, recommend); //assign widgets to appropriate parameters

    softwareList.addReview(sRev); //add user input to the review list
    //clear Gui
    edtName->clear();
    QDate currentDate = QDate::currentDate();
    edtDate->setDate(currentDate);
    cboxRecommend->setChecked(false);
    btnAdd->setEnabled(false);
    btnDisplay->setEnabled(true);
    QMessageBox::information(this, "Software Reviews", "Review added");
}

//display items in list
void MainWindow::displayList()
{
    QList<SoftwareReview> list = softwareList.getSoftwareReview();

    foreach (SoftwareReview s, list) {
        qDebug().noquote() << s.toString(); //call the toString function for
    }                                       //the appropriate format to display items in container in
}

//Setup GUI
void MainWindow::setupGUI()
{
    QGridLayout *layout = (new QGridLayout(this));
    QLabel *lblTitle(new QLabel("Fill in the data and click Add"));
    QLabel *lblName(new QLabel("Name"));
    QLabel *lblDate(new QLabel("Date:"));
    QLabel *lblRecommend(new QLabel("Recommend"));

    layout->addWidget(lblTitle,0,0);
    layout->addWidget(lblName,1,0);
    layout->addWidget(edtName,1,1);
    layout->addWidget(lblDate,2,0);
    layout->addWidget(edtDate,2,1);
    layout->addWidget(lblRecommend,3,0);
    layout->addWidget(cboxRecommend,3,1);
    layout->addWidget(btnAdd,4,0);
    layout->addWidget(btnDisplay,4,1);

    //set date to current date when run
    QDate date = QDate::currentDate();
    edtDate->setDate(date);

    btnAdd->setEnabled(false);
    btnDisplay->setEnabled(false);
    setLayout(layout);
}




