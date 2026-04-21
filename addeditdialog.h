#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AddEditDialog; }
QT_END_NAMESPACE

class AbstractAircraft;

class AddEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDialog(QWidget *parent = nullptr);
    ~AddEditDialog();

    AbstractAircraft* createAircraft();
    void loadAircraft(AbstractAircraft* ac);
    void updateAircraft(AbstractAircraft *ac);

private slots:
    void on_comboType_currentIndexChanged(int index);
    void on_btnOk_clicked();
    void on_btnCancel_clicked();

private:
    Ui::AddEditDialog *ui;
};

#endif // ADDEDITDIALOG_H
