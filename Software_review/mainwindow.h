#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "softwarelist.h"
#include <QString>
#include <QWidget>
class QLineEdit;
class QPushButton;
class QCheckBox;
class QDateEdit;
class QLabel;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void enableAddButton();
    void addToList();
    void displayList();

private:
    void setupGUI();

    SoftwareList softwareList;

    QLabel *lblTitle;
    QLabel *lblName;
    QLabel *lblDate;
    QLabel *lblRecommend;
    QLineEdit *edtName;
    QDateEdit *edtDate;
    QCheckBox *cboxRecommend;
    QPushButton *btnAdd;
    QPushButton *btnDisplay;

};

#endif // MAINWINDOW_H
