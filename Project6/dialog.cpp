#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Competing Species");

    QVBoxLayout *main_layout = new QVBoxLayout;

    createInitialPopulationForm();
    createOutputLabels();
    createQuitButton();

    main_layout->addWidget(form_group_box);
    main_layout->addWidget(output_group_box);
    main_layout->addWidget(quit_group_box);

    setLayout(main_layout);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createInitialPopulationForm()
{
    form_group_box = new QGroupBox(tr("Initial Populations (millions):"));
        QFormLayout *layout = new QFormLayout;


    for(int i = 0; i < NumberofSpecies; i++)
    {
        input_labels[i] = new QLabel(tr("Species %1 : ").arg(i + 1));
        line_edits[i] = new QLineEdit;
        line_edits[i]->setValidator(new QIntValidator);
        layout->addRow(input_labels[i], line_edits[i]);
    }

    start_sim = new QPushButton("Start Simulation");
        connect(start_sim, SIGNAL(clicked()), this, SLOT(startSimulation()));

    layout->addWidget(start_sim);
    form_group_box->setLayout(layout);
}

void Dialog::createOutputLabels()
{
    output_group_box = new QGroupBox;
        QGridLayout *layout = new QGridLayout;

    for(int i = 0; i < NumberofSpecies; i++)
    {
        output_labels[i] = new QLabel(tr("Population of Species %1 : ").arg(i + 1));
        outputs[i] = new QLabel("1");
        layout->addWidget(output_labels[i], i, 0);
        layout->addWidget(outputs[i], i, 1);
    }

    layout->setSpacing(20);
    output_group_box->setLayout(layout);
}

void Dialog::createQuitButton()
{
    quit_group_box = new QGroupBox;
        QHBoxLayout *layout = new QHBoxLayout;

    quit_button = new QPushButton("Quit");
        connect(quit_button, SIGNAL(clicked()), this, SLOT(close()));

    layout->addWidget(quit_button);
    quit_group_box->setLayout(layout);

}

void Dialog::startSimulation()
{
    for(int i = 0; i < NumberofSpecies; i++)
    {
        line_edits[i]->setEnabled(false);
    }

    QTimer *timer = new QTimer;
         connect(timer, SIGNAL(timeout()), this, SLOT(updateOutputs()));
         timer->start(1000);

    //start_sim->setEnabled(false);
}

void updateOutputs()
{

}


