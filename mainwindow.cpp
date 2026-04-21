#include "mainwindow.h"
#include "CargoPlane.h"
#include "ui_mainwindow.h"
#include "addeditdialog.h"
#include "PassengerJet.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_airline("My Airline Fleet")
{
    ui->setupUi(this);
    setWindowTitle("Airline Fleet Management");

    // Initialize interface
    refreshList();
    refreshInfoLabel();
    refreshFleetDisplay();
}

MainWindow::~MainWindow()
{
    // Free memory
    auto& fleet = m_airline.GetFleet();
    for (auto ac : fleet) delete ac;
    delete ui;
}

// Refresh aircraft list in ComboBox
void MainWindow::refreshList()
{
    ui->comboBox->clear();
    auto& fleet = m_airline.GetFleet();
    for (size_t i = 0; i < fleet.size(); ++i) {
        QString type = dynamic_cast<PassengerJet*>(fleet[i]) ? "Passenger" : "Cargo";
        QString name = QString::fromStdString(fleet[i]->GetModel());
        ui->comboBox->addItem(QString("%1. [%2] %3").arg(i+1).arg(type).arg(name));
    }
}

// Auto-update calculated parameters
void MainWindow::refreshInfoLabel()
{
    int totalCount = m_airline.GetFleet().size();
    int totalPass = calculateTotalPassenger();
    ui->labelInfo->setText(QString("Parameters:\nTotal Aircraft: %1\nTotal Passenger Capacity: %2 persons")
                               .arg(totalCount).arg(totalPass));
}

// Refresh full fleet details in text box
void MainWindow::refreshFleetDisplay()
{
    QString text;
    text += "Airline Fleet Information\n";

    auto& fleet = m_airline.GetFleet();
    for (size_t i = 0; i < fleet.size(); ++i) {
        AbstractAircraft* ac = fleet[i];
        QString type = dynamic_cast<PassengerJet*>(ac) ? "Passenger Aircraft" : "Cargo Aircraft";

        text += QString("\n#%1 Type: %2\n").arg(i+1).arg(type);
        text += "Model: " + QString::fromStdString(ac->GetModel()) + "\n";
        text += "Max Speed: " + QString::number(ac->GetMaxSpeed()) + " km/h\n";
        text += "Max Altitude: " + QString::number(ac->GetMaxAltitude()) + " m\n";

        if (PassengerJet* p = dynamic_cast<PassengerJet*>(ac)){
            text += "Passengers: " + QString::number(p->GetPassengerCapacity()) + "\n";
            text += "Flight Range: " + QString::number(p->GetRange()) + " km\n";
        }
        else if (CargoPlane* c = dynamic_cast<CargoPlane*>(ac)){
            text += "Cargo Capacity: " + QString::number(c->GetCargoCapacity()) + " kg\n";
        }
    }

    ui->textEdit_fleet->setPlainText(text);
}

// Calculate total passenger capacity
int MainWindow::calculateTotalPassenger()
{
    int sum = 0;
    for(auto ac : m_airline.GetFleet()){
        if(auto p = dynamic_cast<PassengerJet*>(ac)) sum += p->GetPassengerCapacity();
    }
    return sum;
}

// Add aircraft button
void MainWindow::on_btnAdd_clicked()
{
    AddEditDialog dlg(this);
    dlg.setWindowTitle("Add Aircraft");
    if (dlg.exec() == QDialog::Accepted) {
        AbstractAircraft* ac = dlg.createAircraft();
        auto& fleet = const_cast<std::vector<AbstractAircraft*>&>(m_airline.GetFleet());
        fleet.push_back(ac);

        refreshList();
        refreshInfoLabel();
        refreshFleetDisplay();
    }
}

// Edit aircraft button
void MainWindow::on_btnEdit_clicked()
{
    int idx = ui->comboBox->currentIndex();
    if (idx < 0) {
        QMessageBox::warning(this, "Error", "Please select an aircraft first!");
        return;
    }

    auto& fleet = const_cast<std::vector<AbstractAircraft*>&>(m_airline.GetFleet());
    AddEditDialog dlg(this);
    dlg.setWindowTitle("Edit Aircraft");
    dlg.loadAircraft(fleet[idx]);

    if (dlg.exec() == QDialog::Accepted) {
        dlg.updateAircraft(fleet[idx]);
        refreshList();
        refreshInfoLabel();
        refreshFleetDisplay();
    }
}

// Delete aircraft button
void MainWindow::on_btnDelete_clicked()
{
    int idx = ui->comboBox->currentIndex();
    if (idx < 0) {
        QMessageBox::warning(this, "Error", "Please select an aircraft first!");
        return;
    }

    size_t index = static_cast<size_t>(idx);
    auto& fleet = const_cast<std::vector<AbstractAircraft*>&>(m_airline.GetFleet());

    delete fleet[index];
    fleet.erase(fleet.begin() + index);

    refreshList();
    refreshInfoLabel();
    refreshFleetDisplay();
    ui->comboBox->setCurrentIndex(-1);
}
