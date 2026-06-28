#ifndef ROBOTDIALOG_H
#define ROBOTDIALOG_H

#include <QWidget>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QButtonGroup>
#include <array>
#include "robotview/robot3dforddr6form.h"


namespace Ui {
    class RobotDialog;
}

class RobotDialog : public QWidget {
    Q_OBJECT

public:
    explicit RobotDialog(QWidget *parent = nullptr);

    ~RobotDialog();

private:
    Ui::RobotDialog *ui;
    Robot3DForDDR6Form *mRobot3DForDDR6Form;

private:
    void initializeWindow();

};

#endif // ROBOTDIALOG_H
