#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("my son Yajie Xing");
    double speed = 2;
    Simulator *IMU = new Simulator("avoidPeople_module","Sensor_IMU","IMU","config.xml",QTime(),speed);
    IMU->setOutputNodesName(QStringList()<<"RoutePlanning");

    Simulator *Laser = new Simulator("avoidPeople_module","Sensor_Laser","Laser","config.xml",QTime(),speed);
    Laser->setOutputNodesName(QStringList()<<"RoutePlanning");

    ProcessorMulti *RoutePlanning = new ProcessorMulti("avoidPeople_module", "Algorithm_RoutePlanning", "RoutePlanning", "config.xml");
    RoutePlanning->setInputNodesName(QStringList()<<"Laser;IMU");
    RoutePlanning->setOutputNodesName(QStringList()<<"Mapshow");
    RoutePlanning->connectExternalTrigger(0, PROCESSORSLOT);

    VisualizationMono *Mapshow = new VisualizationMono("avoidPeople_module", "Algorithm_Visualization", "Mapshow", "config.xml");
    Mapshow->setInputNodesName(QStringList()<<"RoutePlanning");
    Mapshow->connectExternalTrigger(0, DRAINSLOT);

    edge.addNode(IMU,1,1);
    edge.addNode(Laser,1,1);
    edge.addNode(RoutePlanning,1,1);
    edge.addNode(Mapshow,0,1);
    edge.connectAll();

    connect(ui->open, SIGNAL(clicked()), &edge, SLOT(openAllNodesSlot()));
    connect(ui->open, &QPushButton::clicked, this, [=]() {
        ui->open->setDisabled(true);
    });

    connect(ui->close, SIGNAL(clicked()), &edge, SLOT(closeAllNodesSlot()));
    connect(ui->close, &QPushButton::clicked, this, [=]() {
        ui->open->setDisabled(false);
    });

    connect(ui->set, SIGNAL(clicked()), this, SLOT(setSimuSlot()));
    connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), IMU, SLOT(setStartTimeSlot(QTime)));
    connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), Laser, SLOT(setStartTimeSlot(QTime)));

    connect(ui->sync,SIGNAL(clicked()), IMU,SLOT(syncTimeTrackSlot()));
    connect(ui->sync,SIGNAL(clicked()), Laser,SLOT(syncTimeTrackSlot()));

    connect(ui->start, SIGNAL(clicked()), IMU, SLOT(startSimulatorSlot()));
    connect(ui->start, SIGNAL(clicked()), Laser, SLOT(startSimulatorSlot()));

    connect(ui->stop, SIGNAL(clicked()), IMU,SLOT(stopSimulatorSlot()));
    connect(ui->stop, SIGNAL(clicked()), Laser,SLOT(stopSimulatorSlot()));


    ui->tabWidget->addTab(&edge,"Monitor");
    QList<QWidget *> widgets;
    widgets= Mapshow->getVisualizationWidgets();
//    ui->scrollArea->setWidget(widgets[0]);
//    ui->scrollArea2->setWidget(widgets[1]);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setSimuSlot()
{
    emit setSimuStartTimeSignal(QTime::fromMSecsSinceStartOfDay(ui->lineEdit->text().toInt()));
}
