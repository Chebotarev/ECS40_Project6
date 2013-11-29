#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QFormLayout>
#include <qtimer.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void createInitialPopulationForm();
    void createOutputLabels();
    void createQuitButton();

private slots:
    void startSimulation();
    void updateOutputs();
    
private:
    Ui::Dialog *ui;

    enum { NumberofSpecies = 3 };

    QGroupBox *form_group_box;
    QGroupBox *output_group_box;
    QGroupBox *quit_group_box;

    QLabel *input_labels[NumberofSpecies];
    QLineEdit *line_edits[NumberofSpecies];
    QLabel *output_labels[NumberofSpecies];
    QLabel *outputs[NumberofSpecies];

    QPushButton *start_sim;
    QPushButton *quit_button;

};

#endif // DIALOG_H
