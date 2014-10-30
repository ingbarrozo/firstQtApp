#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QtWidgets>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void textEditCleaner();

private:
    void modalAndTable();
    void createDockWidget();
    void createListView();
    void createTree();

    QPlainTextEdit *textEdit;
    QPushButton *btnClean;
    QFormLayout *layout;
    QHBoxLayout *layout2;
    QLineEdit *lnNum1;
    QDockWidget *dockWidget;
    QWidget *widget;
    QWidget *widget2;
    QStandardItemModel *model;
    QTableView *table;
    QTabWidget *tabs;
    QListView *listView;
    QTreeView *treeView;
};

#endif // MAINWINDOW_H
