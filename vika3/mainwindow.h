#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <vector>
#include <QTreeWidget>
#include "core.h"
#include "people.h"
#include "machines.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SelectingDatabase_activated(const QString &arg1);
    void on_sortByDrop_activated();

    void on_Button_addSci_clicked();

    void on_Button_editSci_clicked();

private:
    Ui::MainWindow *ui;
    Core core;
    void displayScientists(const People& p1);
    void displayComputers(const Machines& c1);
    void createDropSortForSci();
    void createDropSortForComp();
    void sortSci(const string sorting);
    void sortComp(const string sorting);

    void setTreeSci();
    void setTreeSci(People& scientists);
    void setTreeComp();
    void setTreeComp(Machines& computers);
    void addTreeRootSci(Individual scientist);
    void addTreeChildSci(QTreeWidgetItem *parent, Computer computer);
    void addTreeRootComp(Computer computer);
    void addTreeChildComp(QTreeWidgetItem *parent, Individual scientist);
};

#endif // MAINWINDOW_H
