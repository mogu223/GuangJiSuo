#include "robotcontrolform.h"
#include "ui_robotcontrolform.h"
#include <QDebug>
#include <QtOpenGL>

RobotControlForm::RobotControlForm(QWidget *parent)
        : QWidget(parent), ui(new Ui::RobotControlForm) {
    ui->setupUi(this);

    initializeWindow();
}

RobotControlForm::~RobotControlForm() {
    delete ui;
}

void RobotControlForm::initializeWindow() {
    //隐藏关节坐标系
    QList<QCheckBox *> cks =  ui->groupBoxRobot->findChildren<QCheckBox *>();
    for (auto &item : cks) {
        item->hide();
    }

    // 滑动条
    QList < QSlider * > SliderList = ui->groupBoxRobot->findChildren<QSlider *>();

    for (int i = 0; i < SliderList.size(); i++) {
        QSlider *slider = SliderList.at(i);
        slider->setMinimum(-180);
        slider->setMaximum(180);
        slider->setTickInterval(1);
        // if(i!=1)
        connect(slider, &QSlider::valueChanged, this, &RobotControlForm::slotUpdateJVarsValue, Qt::UniqueConnection);
        // else
        //     connect(slider, &QSlider::valueChanged, this, &RobotControlForm::slotUpdateAlphaValue, Qt::UniqueConnection);

        slider->setValue(0);
    }

    // checkBox 环境变化
    connect(ui->checkBoxGrid_real, &QCheckBox::stateChanged, this, [=](int state) {
        if (state == 0) {
            slotCheckStateChanged(false);
        } else if (state == 2) {
            slotCheckStateChanged(true);
        }
    });
    connect(ui->checkBoxWorldCoordinate_real, &QCheckBox::stateChanged, this, [=](int state) {
        if (state == 0) {
            slotCheckStateChanged(false);
        } else if (state == 2) {
            slotCheckStateChanged(true);
        }
    });
    connect(ui->checkBoxDesk_real, &QCheckBox::stateChanged, this, [=](int state) {
        if (state == 0) {
            slotCheckStateChanged(false);
        } else if (state == 2) {
            slotCheckStateChanged(true);
        }
    });
}

void RobotControlForm::slotUpdateJVarsValue(int value) {
    QSlider *slider = (QSlider *) sender();
    QString objectName = slider->objectName();
    QString index = objectName.at(objectName.size() - 1);
    emit sigJoinValueChanged(index.toInt(), value);
}

void RobotControlForm::slotUpdateAlphaValue(int value) {
    QSlider *slider = (QSlider *) sender();
    QString objectName = slider->objectName();
    QString index = objectName.at(objectName.size() - 1);
    emit sigAlphaValueChanged(index.toInt(), value);
}

void RobotControlForm::slotDebugRobotConfig(double value) {
    QDoubleSpinBox *dsb = (QDoubleSpinBox *) sender();
    QString objectName = dsb->objectName();
    QString index = objectName.at(objectName.size() - 1);

    if (objectName.contains("doubleSpinBox_d")) {
        emit sigDValueChanged(index.toInt(), value);
    } else if (objectName.contains("doubleSpinBox_JVars")) {
        emit sigJoinValueChanged(index.toInt(), value);
    } else if (objectName.contains("doubleSpinBox_alpha")) {
        emit sigAlphaValueChanged(index.toInt(), value);
    } else if (objectName.contains("doubleSpinBox_a")) {
        emit sigAValueChanged(index.toInt(), value);
    }
}

void RobotControlForm::setJVarsValue(QVector<float> JVars) {
    // 0号表示底座
    ui->sliderQ1->setValue(JVars[1]);
    ui->sliderQ2->setValue(JVars[2]);
    ui->sliderQ3->setValue(JVars[3]);
    ui->sliderQ4->setValue(JVars[4]);
    ui->sliderQ5->setValue(JVars[5]);
    ui->sliderQ6->setValue(JVars[6]);
}

bool RobotControlForm::getIsJointChecked(int jointNum) {
    //"checkBoxJ1"
    QString tObjectName = "checkBoxJ" + QString::number(jointNum);
    QList < QCheckBox * > checkBoxList = ui->groupBoxRobot->findChildren<QCheckBox *>();
    for (int i = 0; i < checkBoxList.size(); i++) {
        QCheckBox *checkBox = checkBoxList.at(i);
        if (checkBox->objectName() == tObjectName) {
            return checkBox->isChecked();
        }
    }
    return false;
}

bool RobotControlForm::getIsRealGridChecked() {
    return ui->checkBoxGrid_real->isChecked();
}

bool RobotControlForm::getIsRealWorldCoord() {
    return ui->checkBoxWorldCoordinate_real->isChecked();
}

bool RobotControlForm::getIsRealShowDesk() {
    return ui->checkBoxDesk_real->isChecked();
}

void RobotControlForm::slotCheckStateChanged(bool value) {
    if (sender()->objectName() == "checkBox_showModel") {
        emit sigSetModelRealTimeShow(value);
        return;
    }
    emit sigCheckStateChanged();
}

void RobotControlForm::setControlBoxVisible(const bool &visible) {
    ui->groupBoxRobot->setVisible(visible);
}

void RobotControlForm::setSliderValue(const QVector<double> &joints) {
    if (joints.size() != 6) return;
    ui->sliderQ1->setValue(static_cast<int>(joints.at(0)));
    ui->sliderQ2->setValue(static_cast<int>(joints.at(1)));
    ui->sliderQ3->setValue(static_cast<int>(joints.at(2)));
    ui->sliderQ4->setValue(static_cast<int>(joints.at(3)));
    ui->sliderQ5->setValue(static_cast<int>(joints.at(4)));
    ui->sliderQ6->setValue(static_cast<int>(joints.at(5)));
}
