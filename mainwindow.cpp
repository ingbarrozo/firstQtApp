#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 400);

    //textEdit
    textEdit = new QPlainTextEdit;
    textEdit->setPlainText(tr("The text"));

    //QPushButton
    btnClean = new QPushButton("&Clean", this);
    connect(btnClean, SIGNAL(clicked()), this, SLOT(textEditCleaner()));

    //Layout
    modalAndTable();
    layout = new QFormLayout;
    lnNum1 = new QLineEdit;
    layout->addRow(new QLabel(tr("Line 1:")), lnNum1);
    layout->addRow(textEdit);
    layout->addRow(btnClean);
    layout->addRow(table);

    createListView();
    createTree();
    layout2 = new QHBoxLayout;
    layout2->addWidget(listView);
    layout2->addWidget(treeView);


    //QWidget
    widget = new QWidget;
    widget->setLayout(layout);

    widget2 = new QWidget;
    widget2->setLayout(layout2);


    //QTabs
    tabs = new QTabWidget;
    tabs->addTab(widget, "exam1");
    tabs->addTab(widget2, "exam2");


    createDockWidget();
    dockWidget->setWidget(tabs);
}

void MainWindow::textEditCleaner(){
    textEdit->clear();
    lnNum1->clear();
}

void MainWindow::modalAndTable(){
    //table and standaritem
    model = new QStandardItemModel(2,3,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(tr("hHeader 1")));
    model->setHorizontalHeaderItem(1,new QStandardItem(tr("hHeader 2")));
    model->setHorizontalHeaderItem(2,new QStandardItem(tr("hHeader 3")));

    model->setVerticalHeaderItem(0,new QStandardItem(tr("vHeader 1")));
    model->setVerticalHeaderItem(1,new QStandardItem(tr("vHeader 2")));
    model->setVerticalHeaderItem(2,new QStandardItem(tr("vHeader 3")));

    table = new QTableView;
    table->setModel(model);
}

void MainWindow::createDockWidget()
{
    //dockWidget
    dockWidget = new QDockWidget(tr("Dock Widget"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                    Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}

void MainWindow::createListView()
{
    QStringListModel *strListModel = new QStringListModel(this);
    QStringList list;
    listView = new QListView;
    list << "element1";
    list << "element2";
    list << "element2";
    strListModel->setStringList(list);
    listView->setModel(strListModel);
}

void MainWindow::createTree()
{
    //table and standaritem
    QStandardItemModel *treeModel = new QStandardItemModel(2,3,this);
    treeModel->setHorizontalHeaderItem(0,new QStandardItem(tr("hHeader 1")));
    treeModel->setHorizontalHeaderItem(1,new QStandardItem(tr("hHeader 2")));
    treeModel->setHorizontalHeaderItem(2,new QStandardItem(tr("hHeader 3")));

    QStandardItem *father = new QStandardItem( tr("nomas"));

    QStandardItem *child = new QStandardItem( tr("Item 1"));
    father->appendRow(child);
    treeModel->setItem(0,0,father);

    treeView = new QTreeView;
    treeView->setModel(treeModel);
}

MainWindow::~MainWindow()
{

}
