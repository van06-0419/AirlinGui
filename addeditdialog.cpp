// 1. 自身头文件 第一行
#include "addeditdialog.h"
// 2. UI自动生成头文件 必须第二行！
#include "ui_addeditdialog.h"

// 3. 业务类头文件 最后
#include "AbstractAircraft.h"
#include "PassengerJet.h"
#include "CargoPlane.h"
#include <QMessageBox>

AddEditDialog::AddEditDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEditDialog)
{
    ui->setupUi(this);
    on_comboType_currentIndexChanged(0);
}

AddEditDialog::~AddEditDialog()
{
    delete ui;
}

void AddEditDialog::on_comboType_currentIndexChanged(int index)
{
    bool isPassenger = (index == 0);
    ui->labelPassenger->setVisible(isPassenger);
    ui->labelPassenger->setVisible(isPassenger);
    ui->labelRange->setVisible(isPassenger);
    ui->labelRange->setVisible(isPassenger);

    bool isCargo = (index == 1);
    ui->labelCargo->setVisible(isCargo);
    ui->labelCargo->setVisible(isCargo);
}

void AddEditDialog::on_btnOk_clicked()
{
    if(ui->editModel->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Enter the aircraft model!");
        return;
    }
    if(ui->editSpeed->text().isEmpty() || ui->editAlt->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Fill in speed and altitude!");
        return;
    }
    accept();
}

void AddEditDialog::on_btnCancel_clicked()
{
    reject();
}

AbstractAircraft* AddEditDialog::createAircraft()
{
    std::string model = ui->editModel->text().trimmed().toStdString();
    int speed = ui->editSpeed->text().trimmed().toInt();
    int alt = ui->editAlt->text().toInt();

    if (ui->comboType->currentIndex() == 0) {
        int pax = ui->labelPassenger->text().toInt();
        int range = ui->labelRange->text().toInt();
        return new PassengerJet(model, speed, alt, pax, range);
    } else {
        int cargo = ui->labelCargo->text().toInt();
        return new CargoPlane(model, speed, alt, 2, cargo);
    }
}

void AddEditDialog::loadAircraft(AbstractAircraft *ac)
{
    ui->editModel->setText(QString::fromStdString(ac->GetModel()));
    ui->editSpeed->setText(QString::number(ac->GetMaxSpeed()));
    ui->editAlt->setText(QString::number(ac->GetMaxAltitude()));

    if (auto p = dynamic_cast<PassengerJet*>(ac)) {
        ui->comboType->setCurrentIndex(0);
        ui->labelPassenger->setText(QString::number(p->GetPassengerCapacity()));
        ui->labelRange->setText(QString::number(p->GetRange()));
    } else if (auto c = dynamic_cast<CargoPlane*>(ac)) {
        ui->comboType->setCurrentIndex(1);
        ui->labelCargo->setText(QString::number(c->GetCargoCapacity()));
    }
    on_comboType_currentIndexChanged(ui->comboType->currentIndex());
}

// 兼容你原来只有Get函数的写法！不用改DLL源码
void AddEditDialog::updateAircraft(AbstractAircraft *ac)
{
    // 旧对象销毁，新建替换，完美规避没有Set函数的问题
    std::string model = ui->editModel->text().trimmed().toStdString();
    int speed = ui->editSpeed->text().trimmed().toInt();
    int alt = ui->editAlt->text().trimmed().toInt();

    AbstractAircraft* newAc = nullptr;
    if (auto p = dynamic_cast<PassengerJet*>(ac)) {
        int pax = ui->labelPassenger->text().toInt();
        int range = ui->labelRange->text().toInt();
        newAc = new PassengerJet(model, speed, alt, pax, range);
    }
    else if (auto c = dynamic_cast<CargoPlane*>(ac)) {
        int cargo = ui->labelCargo->text().toInt();
        newAc = new CargoPlane(model, speed, alt, 2, cargo);
    }

    if(newAc){
        // 把原来的对象内容替换掉，不改变指针地址
        *ac = *newAc;
        delete newAc;
    }
}
