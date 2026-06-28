/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *StartMonitor;
    QAction *StartAGVMonitor;
    QAction *StartLevelMonitor;
    QAction *StartLiftMonitor;
    QAction *StartCoverPlateMonitor;
    QAction *StartPinMonitor;
    QAction *Camera;
    QAction *StartVision;
    QAction *StartSee;
    QAction *StartCamera;
    QAction *StartCoverPlate3D;
    QWidget *centralWidget;
    QGridLayout *gridLayout_26;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_36;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_41;
    QLabel *lbl_Auto;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_50;
    QLabel *lbl_Manual;
    QTableView *tableView_SystemStatus;
    QGroupBox *groupBox_37;
    QGridLayout *gridLayout_62;
    QComboBox *cbxShowType;
    QPushButton *btnGenerateChart;
    QComboBox *cbxSensorType;
    QChartView *cvData;
    QGroupBox *groupBox_TaskMgr;
    QGridLayout *gridLayout_2;
    QLabel *label_231;
    QLabel *label_34;
    QLabel *label_33;
    QLabel *label_248;
    QLabel *label_249;
    QLabel *label_252;
    QLabel *label_260;
    QLabel *lbl_AGV;
    QLabel *lbl_VehTaskForward;
    QLabel *lbl_VehTaskBackward;
    QLabel *lbl_AGV_Ready;
    QLabel *lbl_AGV_Running;
    QLabel *lbl_AGV_Complete;
    QLabel *lbl_AGV_Error;
    QLabel *label_232;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *lbl_Level;
    QLabel *lbl_LevelTaskForward;
    QLabel *lbl_LevelTaskBackward;
    QLabel *lbl_Level_Ready;
    QLabel *lbl_Level_Running;
    QLabel *lbl_Level_Complete;
    QLabel *lbl_Level_Error;
    QLabel *label_233;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *lbl_MainLift;
    QLabel *lbl_MainLiftTaskForward;
    QLabel *lbl_MainLiftTaskBackward;
    QLabel *lbl_MainLift_Ready;
    QLabel *lbl_MainLift_Running;
    QLabel *lbl_MainLift_Complete;
    QLabel *lbl_MainLift_Error;
    QLabel *label_234;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *lbl_CoverPlate;
    QLabel *lbl_CoverPlateTaskForward;
    QLabel *lbl_LiftTaskBackward;
    QLabel *lbl_CoverPlate_Ready;
    QLabel *lbl_CoverPlate_Running;
    QLabel *lbl_CoverPlate_Complete;
    QLabel *lbl_CoverPlate_Error;
    QLabel *label_239;
    QLabel *label_8;
    QLabel *label_35;
    QLabel *lbl_Lift;
    QLabel *lbl_LiftTaskForward;
    QLabel *lbl_CoverPlateTaskBackward;
    QLabel *lbl_Lift_Ready;
    QLabel *lbl_Lift_Running;
    QLabel *lbl_Lift_Complete;
    QLabel *lbl_Lift_Error;
    QLabel *label_236;
    QLabel *label_36;
    QLabel *lbl_Pin;
    QLabel *lbl_PinTask;
    QLabel *lbl_Pin_Ready;
    QLabel *lbl_Pin_Running;
    QLabel *lbl_Pin_Complete;
    QLabel *lbl_Pin_Error;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_39;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_50;
    QLabel *label_119;
    QLineEdit *lineEdit_NaviSvr;
    QLabel *label_153;
    QComboBox *comBox_NavigatePort;
    QPushButton *btn_CnntNavigateSvr;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_117;
    QLineEdit *lineEdit_PushSvr;
    QLabel *label_118;
    QComboBox *comBox_PushPort;
    QPushButton *btn_CnntPushSvr;
    QHBoxLayout *horizontalLayout_80;
    QLabel *label_170;
    QComboBox *comboBox_Map;
    QLabel *label_172;
    QLineEdit *lineEdit_loadmap_status2;
    QPushButton *btn_MapLoad;
    QHBoxLayout *horizontalLayout_74;
    QLabel *label_162;
    QLineEdit *lineEdit_StatusSvr;
    QLabel *label_169;
    QComboBox *comBox_StatusPort;
    QPushButton *btn_CnntStatusSvr;
    QHBoxLayout *horizontalLayout_56;
    QLabel *label_167;
    QLineEdit *lineEdit_ContSvr;
    QLabel *label_168;
    QComboBox *comBox_ControlPort;
    QPushButton *btn_CnntControlSvr;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_29;
    QGroupBox *groupBox_ManualMode;
    QGridLayout *gridLayout_43;
    QComboBox *comboBox_LRUdata;
    QGridLayout *gridLayout_44;
    QPushButton *btn_MainLiftManual;
    QPushButton *btn_PinManual;
    QPushButton *btn_AGVManual;
    QPushButton *btn_LiftManual;
    QPushButton *btn_LevelManual;
    QPushButton *btn_CoverPlateManual;
    QRadioButton *radioButton_ManualMode;
    QGroupBox *groupBox_AutoMode;
    QGridLayout *gridLayout_37;
    QRadioButton *radioButton_AutoMode;
    QRadioButton *radioButton_leftPlate;
    QRadioButton *radioButton_middlePlate;
    QRadioButton *radioButton_rightPlate;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btn_StartTask;
    QPushButton *btn_PauseTask;
    QPushButton *btn_ContinueTask;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_238;
    QComboBox *comboBox_LRU;
    QLabel *label_255;
    QComboBox *comboBox_Station;
    QPushButton *btn_InitialAll;
    QPushButton *btn_AllRapidStop;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_20;
    QProgressBar *init_progressBar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *lbl_isConnect;
    QPushButton *btnConnect;
    QPushButton *btnConnectSimulation;
    QPushButton *btnDisconnect;
    QLabel *label_2;
    QLabel *ledMotion;
    QComboBox *cBoxConnectType;
    QPushButton *btnInitBus;
    QPushButton *btnInitAxis;
    QPushButton *btnEnableAxis;
    QLabel *label_3;
    QTextEdit *txtEditConnectContent;
    QPushButton *btnDisableAxis;
    QPushButton *btnType0;
    QPushButton *btnType65;
    QWidget *tab_3;
    QGridLayout *gridLayout_63;
    QGroupBox *groupBox_33;
    QGridLayout *gridLayout_38;
    QGridLayout *gridLayout_34;
    QPushButton *btn_AGVOpen;
    QPushButton *btn_AGVClose;
    QPushButton *btn_AGVRapidStop;
    QPushButton *btn_AGVToAuto;
    QPushButton *btn_AGVPauseNavigate;
    QPushButton *btn_AGVContinueNavigate;
    QPushButton *btn_AGVCancelNavigate;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btn_AGV_Translate;
    QDoubleSpinBox *doubleSpinBox_AGV_Translate;
    QPushButton *btn_AGVToTarget;
    QPushButton *btn_AGVToOrigin;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_AGV_Turn;
    QDoubleSpinBox *doubleSpinBox_AGV_Turn;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btn_AGV_Transverse;
    QDoubleSpinBox *doubleSpinBox_AGV_Transverse;
    QGridLayout *gridLayout_11;
    QSpinBox *spinBox_Timeout;
    QLabel *label_134;
    QLabel *label_128;
    QSpinBox *spinBox_Byte15;
    QSpinBox *spinBox_Type;
    QLabel *label_131;
    QLabel *label_130;
    QSpinBox *spinBox_Num;
    QGroupBox *groupBox_34;
    QVBoxLayout *verticalLayout_15;
    QTextEdit *textEdit_Data;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *btn_Send;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_CancleTask;
    QGroupBox *groupBox_36;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_23;
    QLabel *label_343;
    QLineEdit *Distance3;
    QLineEdit *Distance0;
    QComboBox *comboBoxPortNameDistance;
    QPushButton *btn_ShowDistance;
    QPushButton *btnOpenDistanceCOM;
    QLabel *label_341;
    QLabel *label_342;
    QLabel *label_344;
    QLineEdit *Distance1;
    QLineEdit *Distance2;
    QGroupBox *groupBox_35;
    QGridLayout *gridLayout_28;
    QLineEdit *tag_diff_y;
    QLabel *label_155;
    QLabel *lbl_handle;
    QLineEdit *packTotalCurrent;
    QLineEdit *tag_diff_angle;
    QLabel *label_148;
    QLineEdit *packTotalVoltage;
    QLineEdit *lineEdit_batt_level;
    QLabel *label_140;
    QLabel *label_149;
    QLabel *label_166;
    QLabel *label_165;
    QLabel *label_144;
    QLineEdit *lineEdit_brake;
    QLabel *label_164;
    QLineEdit *lineEdit_driver_emc;
    QLabel *label_137;
    QLineEdit *tag_diff_x;
    QLabel *label_141;
    QLineEdit *lineEdit_loadmap_status;
    QLineEdit *lineEdit_current_station;
    QLabel *label_138;
    QLabel *label_145;
    QLabel *label_154;
    QLineEdit *lineEdit_emergency;
    QLineEdit *remainingmAh;
    QLabel *label_160;
    QLabel *label_139;
    QLineEdit *lineEdit_taskStatus;
    QLabel *label_152;
    QLabel *label_147;
    QLabel *label_136;
    QLabel *label_142;
    QLineEdit *lineEdit_block_reason;
    QLineEdit *lineEdit_electric;
    QLineEdit *lineEdit_agv_blocked;
    QLabel *label_151;
    QLineEdit *lineEdit_task_type;
    QLabel *label_143;
    QLineEdit *lineEdit_target_dist;
    QLineEdit *lineEdit_reloc_status;
    QLineEdit *lineEdit_soft_emc;
    QPushButton *btn_AGVPositionAdjust;
    QPushButton *btn_Battery2;
    QWidget *tab_7;
    QGridLayout *gridLayout_35;
    QGroupBox *groupBox_20;
    QGridLayout *gridLayout_5;
    QLabel *label_163;
    QLineEdit *AngleX;
    QPushButton *btnOpenAngleCOM;
    QLabel *label_340;
    QLineEdit *AngleY;
    QComboBox *comboBoxPortNameAngle;
    QLabel *label_330;
    QHBoxLayout *horizontalLayout_124;
    QLabel *lbl_SymbolAll;
    QPushButton *btn_ShowAngle;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_21;
    QGridLayout *gridLayout_15;
    QLabel *label_157;
    QLabel *label_240;
    QLabel *lbl_Symbol0;
    QLabel *label_333;
    QLineEdit *sensor0;
    QLabel *label_337;
    QLineEdit *Current0;
    QPushButton *btnOpenForceCOM;
    QLabel *label_156;
    QLabel *label_244;
    QLabel *lbl_Symbol1;
    QLabel *label_336;
    QLineEdit *sensor1;
    QLabel *label_326;
    QLineEdit *Current1;
    QComboBox *comboBoxPortNameForce;
    QLabel *label_158;
    QLabel *label_242;
    QLabel *lbl_Symbol2;
    QLabel *label_334;
    QLineEdit *sensor2;
    QLabel *label_332;
    QLineEdit *Current2;
    QPushButton *btn_ShowForce;
    QLabel *label_159;
    QLabel *label_246;
    QLabel *lbl_Symbol3;
    QLabel *label_338;
    QLineEdit *sensor3;
    QLabel *label_335;
    QLineEdit *Current3;
    QPushButton *btn_ShowCurrent;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_18;
    QLabel *lbl_LevelPosi1;
    QLabel *lblAxisStatusColor3;
    QLabel *label_266;
    QPushButton *btnZero0_4;
    QLabel *lbl_LevelPosi3;
    QLabel *label_150;
    QLabel *label_265;
    QLabel *lblAxisStatusColor1;
    QLabel *label_243;
    QLabel *label_146;
    QLabel *label_245;
    QPushButton *btnInit0_4;
    QLabel *label_267;
    QLabel *lbl_LevelPosi2;
    QLabel *lblAxisStatusColor2;
    QLabel *label_161;
    QLabel *label_113;
    QLabel *label_241;
    QLabel *lblAxisStatusColor0;
    QLabel *label_247;
    QLabel *label_264;
    QLabel *lbl_LevelPosi0;
    QPushButton *btnForward0;
    QPushButton *btnBackward1;
    QPushButton *btnBackward2;
    QPushButton *btnForward3;
    QPushButton *btnBackward0;
    QPushButton *btnForward1;
    QPushButton *btnForward2;
    QPushButton *btnBackward3;
    QPushButton *btnDisAbsMove0_4;
    QPushButton *btnDisMove0_4;
    QSpinBox *spinBox_PosMove0_4;
    QSpinBox *spinBox_PosAbsMove0_4;
    QGroupBox *groupBox_22;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_86;
    QPushButton *btn_FeetToGround;
    QPushButton *btn_BalanceBody;
    QPushButton *btn_BodyToGround;
    QPushButton *btn_LevelRapidStop;
    QPushButton *btn_LevelToAuto;
    QHBoxLayout *horizontalLayout_105;
    QGroupBox *groupBox_23;
    QGridLayout *gridLayout_24;
    QPushButton *btn_SpeedBodyUp;
    QPushButton *btn_SpeedBodyDown;
    QGroupBox *groupBox_24;
    QGridLayout *gridLayout_25;
    QPushButton *btn_PosBodyUp;
    QPushButton *btn_PosBodyDown;
    QHBoxLayout *horizontalLayout_85;
    QLabel *label_4;
    QDoubleSpinBox *spinBox_Distance;
    QWidget *tab_5;
    QGridLayout *gridLayout_17;
    QGroupBox *groupBox_25;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_49;
    QPushButton *btn_MainLiftToAuto;
    QPushButton *btnInit4;
    QLabel *label_122;
    QLabel *label_219;
    QPushButton *btnForward4;
    QLabel *lblAxisStatusColor4;
    QPushButton *btn_MainLiftRapidStop;
    QPushButton *btnBackward4;
    QPushButton *btnDisMove4;
    QHBoxLayout *horizontalLayout_48;
    QLabel *label_114;
    QSpinBox *spinBox_PosMove4;
    QHBoxLayout *horizontalLayout_25;
    QLabel *left_laser;
    QPushButton *btnDisableMainLiftAxis;
    QPushButton *btnEnableMainLiftAxis;
    QLabel *lbl_MainLiftPosi4;
    QPushButton *btn_MainLiftBackward;
    QLabel *label_105;
    QPushButton *btnZero4;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_121;
    QSpinBox *spinBox_PosAbsMove4;
    QHBoxLayout *horizontalLayout_23;
    QLabel *right_laser;
    QPushButton *btnDisAbsMove4;
    QPushButton *btn_MainLiftForward;
    QGroupBox *groupBox_29;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_12;
    QPushButton *btnForward9_10;
    QPushButton *btnBackward5_6;
    QSpinBox *spinBox_PosMove9_10;
    QPushButton *btnForward7;
    QSpinBox *spinBox_PosMove5_6;
    QLabel *label_179;
    QPushButton *btnDisAbsMove9_10;
    QPushButton *btnZero9_10;
    QPushButton *btnZero7_8;
    QLabel *lbl_CoverPlatePosi5;
    QLabel *lblAxisStatusColor6;
    QLabel *lblAxisStatusColor9;
    QPushButton *btnDisAbsMove11;
    QLabel *lblAxisStatusColor5;
    QLabel *label_104;
    QSpinBox *spinBox_PosAbsMove7_8;
    QSpinBox *spinBox_PosAbsMove5_6;
    QPushButton *btnBackward7;
    QPushButton *btnForward10;
    QLabel *lblAxisStatusColor7;
    QPushButton *btnBackward6;
    QPushButton *btnBackward10;
    QLabel *label_213;
    QLabel *lblAxisStatusColor8;
    QPushButton *btnForward9;
    QLabel *lbl_CoverPlatePosi6;
    QLabel *label_227;
    QLabel *label_181;
    QLabel *lbl_CoverPlatePosi7;
    QPushButton *btnDisMove7_8;
    QLabel *label_225;
    QPushButton *btnInit7_8;
    QLabel *lblAxisStatusColor10;
    QPushButton *btnForward6;
    QPushButton *btnBackward5;
    QLabel *label_89;
    QPushButton *btnDisAbsMove5_6;
    QLabel *label_102;
    QPushButton *btnForward8;
    QPushButton *btnZero11;
    QPushButton *btnForward11;
    QPushButton *btnInit11;
    QPushButton *btnForward5;
    QSpinBox *spinBox_PosAbsMove9_10;
    QLabel *label_183;
    QPushButton *btnDisMove11;
    QSpinBox *spinBox_PosAbsMove11;
    QLabel *label_178;
    QLabel *label_224;
    QLabel *label_214;
    QPushButton *btnBackward9;
    QSpinBox *spinBox_PosMove7_8;
    QPushButton *btnBackward9_10;
    QLabel *lbl_CoverPlatePosi11;
    QPushButton *btnDisAbsMove7_8;
    QLabel *lblAxisStatusColor11;
    QLabel *lbl_CoverPlatePosi8;
    QLabel *label_83;
    QLabel *label_215;
    QLabel *lbl_CoverPlatePosi9;
    QPushButton *btnZero5_6;
    QPushButton *btnForward5_6;
    QPushButton *btnBackward7_8;
    QLabel *lbl_CoverPlatePosi10;
    QLabel *label_184;
    QPushButton *btnBackward11;
    QPushButton *btnInit5_6;
    QLabel *label_180;
    QLabel *label_103;
    QLabel *label_88;
    QPushButton *btnDisMove9_10;
    QSpinBox *spinBox_PosMove11;
    QLabel *label_107;
    QPushButton *btnInit9_10;
    QLabel *label_182;
    QLabel *label_223;
    QPushButton *btnForward7_8;
    QPushButton *btnDisMove5_6;
    QPushButton *btnBackward8;
    QGroupBox *groupBox_30;
    QGridLayout *gridLayout_4;
    QPushButton *btn_CloseDoor;
    QPushButton *btn_TakePlate;
    QPushButton *btn_CoverPlateToAuto;
    QPushButton *btn_OpenDoor;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout;
    QLabel *label_253;
    QLabel *lbl_TakeDoor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_250;
    QLabel *lbl_TakePlate;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_251;
    QLabel *lbl_FixPlate;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_322;
    QLabel *lbl_FixDoor;
    QPushButton *btn_AutoTakePlate;
    QPushButton *btn_CoverPlateRapidStop;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout;
    QLabel *label_53;
    QLabel *label_60;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_current9;
    QLabel *lbl_current10;
    QPushButton *btn_CoverPlate;
    QPushButton *btn_AutoCoverPlate;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_52;
    QLabel *label_angle;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_49;
    QLabel *label_y;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_47;
    QLabel *label_x;
    QWidget *tab_4;
    QGridLayout *gridLayout_50;
    QGroupBox *groupBox_28;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_47;
    QGridLayout *gridLayout_31;
    QLabel *label_10;
    QLabel *label_96;
    QLabel *lbl_PlatformIsTarget;
    QLabel *lbl_PlatformInfoRy;
    QLabel *lbl_PlatformInfoZ;
    QLabel *label_56;
    QLabel *label_55;
    QLabel *lbl_PlatformStatus;
    QLabel *label_95;
    QLabel *label_57;
    QLabel *label_100;
    QLabel *lbl_PlatformInfoRx;
    QLabel *lbl_PlatformEnable;
    QLabel *label_54;
    QLabel *lbl_PlatformInfoY;
    QLabel *label_44;
    QLabel *label_94;
    QLabel *lbl_PlatformInfoX;
    QLabel *lbl_PlatformWarning;
    QLabel *lbl_PlatformInfoRz;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_8;
    QLabel *label_79;
    QDoubleSpinBox *SpinBox_PlatformMoveRx;
    QLabel *label_93;
    QLabel *label_85;
    QDoubleSpinBox *SpinBox_PlatformMoveX;
    QLabel *label_86;
    QDoubleSpinBox *SpinBox_PlatformMoveRz;
    QDoubleSpinBox *SpinBox_PlatformMoveY;
    QDoubleSpinBox *SpinBox_PlatformMoveZ;
    QDoubleSpinBox *SpinBox_PlatformMoveRy;
    QLabel *label_87;
    QLabel *label_80;
    QHBoxLayout *horizontalLayout_27;
    QPushButton *btn_PlatformGo;
    QPushButton *btn_PlatformStop;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *btn_PlatformOpen;
    QPushButton *btn_PlatformClose;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *btn_PlatformInitial;
    QPushButton *btn_PlatformGoZero;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *btn_PlatformLeveling;
    QPushButton *btn_PlatformReset;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_61;
    QLabel *groypitch;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_62;
    QLabel *groyroll;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_63;
    QLabel *final_x;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_66;
    QLabel *final_y;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_45;
    QGridLayout *gridLayout_32;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_111;
    QSpinBox *spinBox_PosAbsMove12;
    QLabel *label_97;
    QLabel *lblAxisStatusColor12;
    QPushButton *btn_LiftRapidStop;
    QHBoxLayout *horizontalLayout_47;
    QLabel *label_112;
    QSpinBox *spinBox_PosMove12;
    QLabel *label_99;
    QLabel *lbl_LiftPosi12;
    QPushButton *btn_LiftToAuto;
    QPushButton *btnForward12;
    QPushButton *btnZero12;
    QLabel *label_218;
    QPushButton *btnBackward12;
    QPushButton *btnInit12;
    QPushButton *btnDisAbsMove12;
    QPushButton *btnDisMove12;
    QGroupBox *groupBox_21;
    QGridLayout *gridLayout_48;
    QGridLayout *gridLayout_13;
    QLabel *label_132;
    QLabel *lbl_GapWidth_y;
    QPushButton *btn_auto_descent;
    QSpinBox *light2_value;
    QPushButton *btn_CheckStatus;
    QLabel *lbl_GapWidth_x;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_48;
    QDoubleSpinBox *x_offset;
    QSpinBox *light1_value;
    QPushButton *btn_stop_secondry;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label2222;
    QDoubleSpinBox *rz_offset;
    QLabel *label_129;
    QLabel *label_58;
    QPushButton *btn_StatusModifyLatter;
    QLabel *label_59;
    QPushButton *btn_secondary_lift;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_51;
    QDoubleSpinBox *y_offset;
    QLabel *distance1;
    QLabel *lbl_GapAngle;
    QLabel *label_133;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_22;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox_27;
    QGridLayout *gridLayout_27;
    QGridLayout *gridLayout_20;
    QLabel *label_13;
    QLabel *lbl_FX;
    QLabel *label_16;
    QLabel *lbl_FY;
    QLabel *label_17;
    QLabel *lbl_FZ;
    QLabel *label_108;
    QLabel *lbl_MX;
    QLabel *label_115;
    QLabel *lbl_MY;
    QLabel *label_116;
    QLabel *lbl_MZ;
    QGroupBox *groupBox_32;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_CrashInfo;
    QLabel *lbl_isCrash;
    QPushButton *btn_ShowForceInfo;
    QPushButton *btn_GoZero;
    QPushButton *btn_CheckCollision;
    QPushButton *btn_FindCamera;
    QPushButton *btn_CameraMonitor;
    QPushButton *btn_IOForward;
    QPushButton *btn_IOBackward;
    QPushButton *btn_PMCConnect;
    QPushButton *btn_PMCSpeedBackward;
    QPushButton *btn_PMCSpeedForward;
    QPushButton *btn_LightSongKai;
    QPushButton *btn_LightGuDing;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_52;
    QPushButton *btn_ExeVehTaskBackward;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btn_Motor78Backward;
    QPushButton *btn_ExeMainLiftTaskBackward;
    QPushButton *btn_Motor78Forward_16;
    QPushButton *btn_XYSame;
    QPushButton *btn_Motor78Forward_6;
    QPushButton *btn_ExeMainLiftTaskForward;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *btn_Motor78Forward_9;
    QPushButton *btn_Motor78Forward_10;
    QPushButton *btn_Motor78Forward_15;
    QPushButton *btn_ExeLevelTaskBackward;
    QPushButton *btn_AngleSame;
    QPushButton *pushButton_3;
    QPushButton *btn_ExeLiftTaskBackward;
    QPushButton *btn_ExeLiftTaskForward;
    QPushButton *btn_Motor78Forward_13;
    QPushButton *btn_Motor78Forward_4;
    QPushButton *btn_ExeCoverPlateTaskForward;
    QPushButton *btn_Motor78Forward_12;
    QPushButton *btn_Motor78Forward;
    QPushButton *btn_ExePinTaskForward;
    QPushButton *btn_ExeLevelTaskForward;
    QPushButton *btn_Motor78Forward_17;
    QPushButton *btn_Motor78Forward_5;
    QPushButton *btn_Motor78Forward_2;
    QPushButton *btn_Motor78Forward_14;
    QPushButton *btn_Motor78Forward_8;
    QPushButton *btn_ExeVehTaskForward;
    QPushButton *btn_Motor78Forward_3;
    QPushButton *btn_Motor78Forward_7;
    QPushButton *btn_Motor78Forward_11;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *btn_ExeCoverPlateTaskBackward;
    QPushButton *btn_PMCSpeedBackward_2;
    QPushButton *btn_CheckDetach;
    QPushButton *btn_LightRelease;
    QPushButton *btn_LightClamp;
    QPushButton *btn_CheckDetach_2;
    QSpinBox *spinBox;
    QWidget *tab_6;
    QGridLayout *gridLayout_46;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_53;
    QPushButton *btnLevelSave;
    QGridLayout *gridLayout_42;
    QLabel *label_25;
    QComboBox *cBoxCurrent3;
    QLabel *label_26;
    QComboBox *cBoxAngleY;
    QComboBox *cBoxCurrent0;
    QLabel *label_27;
    QComboBox *cBoxAngleX;
    QLabel *label_24;
    QLabel *label_29;
    QComboBox *cBoxCurrent1;
    QLabel *label_28;
    QComboBox *cBoxCurrent2;
    QComboBox *cBoxAngleX_2;
    QComboBox *cBoxAngleY_2;
    QLabel *label_64;
    QLabel *label_65;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_57;
    QGridLayout *gridLayout_56;
    QComboBox *cBoxTorqueX;
    QLabel *label_31;
    QComboBox *cBoxForceX;
    QLabel *label_37;
    QLabel *label_39;
    QComboBox *cBoxForceY;
    QLabel *label_30;
    QLabel *label_40;
    QComboBox *cBoxTorqueY;
    QComboBox *cBoxForceZ;
    QLabel *label_38;
    QComboBox *cBoxTorqueZ;
    QPushButton *btnSixForceSave;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_40;
    QGridLayout *gridLayout_41;
    QLabel *label_120;
    QComboBox *cBoxAxisDecel;
    QComboBox *cBoxAxisNum;
    QComboBox *cBoxAxisAccel;
    QLabel *label_32;
    QLabel *label_14;
    QComboBox *cBoxAxisSpeed;
    QLabel *label_15;
    QComboBox *cBoxAxisRSLimit;
    QLabel *label_21;
    QLabel *label_22;
    QComboBox *cBoxAxisInit;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *lbl_HeartBeatInfo_2;
    QComboBox *cBoxAxisFSLimit;
    QComboBox *cBoxAxisUnits;
    QPushButton *btnAxisSave;
    QWidget *tab_8;
    QGridLayout *gridLayout_61;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_55;
    QGridLayout *gridLayout_54;
    QLabel *label_18;
    QLineEdit *leDbName;
    QLabel *label_42;
    QLineEdit *leDbUser;
    QLabel *label_43;
    QLineEdit *leDbPassword;
    QLineEdit *leDbHost;
    QLabel *label_45;
    QPushButton *btnDbConnect;
    QPushButton *btnDbDisconnect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_46;
    QLabel *lbl_database;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_59;
    QGridLayout *gridLayout_58;
    QPushButton *btnDbAdd;
    QPushButton *btnDbDelete;
    QPushButton *btnDbQuery;
    QComboBox *cbxDbTables;
    QPushButton *btnDbShow;
    QPushButton *btnDbSave;
    QLineEdit *leQueryCondition;
    QGroupBox *groupBox_26;
    QGridLayout *gridLayout_60;
    QTableView *tvDbData;
    QToolBar *mainToolBar;
    QMenuBar *StartVision_2;
    QMenu *LRUMonitor;
    QMenu *AGVMonitor;
    QMenu *LevelMonitor;
    QMenu *LiftMonitor;
    QMenu *CoverPlateMonitor;
    QMenu *PinMonitor;
    QMenu *Camera_2;
    QMenu *CoverPlate3D;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1694, 883);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1600, 800));
        MainWindow->setMaximumSize(QSize(1694, 900));
        MainWindow->setTabletTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        StartMonitor = new QAction(MainWindow);
        StartMonitor->setObjectName(QString::fromUtf8("StartMonitor"));
        StartAGVMonitor = new QAction(MainWindow);
        StartAGVMonitor->setObjectName(QString::fromUtf8("StartAGVMonitor"));
        StartLevelMonitor = new QAction(MainWindow);
        StartLevelMonitor->setObjectName(QString::fromUtf8("StartLevelMonitor"));
        StartLiftMonitor = new QAction(MainWindow);
        StartLiftMonitor->setObjectName(QString::fromUtf8("StartLiftMonitor"));
        StartCoverPlateMonitor = new QAction(MainWindow);
        StartCoverPlateMonitor->setObjectName(QString::fromUtf8("StartCoverPlateMonitor"));
        StartPinMonitor = new QAction(MainWindow);
        StartPinMonitor->setObjectName(QString::fromUtf8("StartPinMonitor"));
        Camera = new QAction(MainWindow);
        Camera->setObjectName(QString::fromUtf8("Camera"));
        StartVision = new QAction(MainWindow);
        StartVision->setObjectName(QString::fromUtf8("StartVision"));
        StartSee = new QAction(MainWindow);
        StartSee->setObjectName(QString::fromUtf8("StartSee"));
        StartCamera = new QAction(MainWindow);
        StartCamera->setObjectName(QString::fromUtf8("StartCamera"));
        StartCoverPlate3D = new QAction(MainWindow);
        StartCoverPlate3D->setObjectName(QString::fromUtf8("StartCoverPlate3D"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout_26 = new QGridLayout(centralWidget);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy2);
        groupBox_6->setMinimumSize(QSize(630, 200));
        groupBox_6->setMaximumSize(QSize(16777215, 500));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(11);
        font.setBold(true);
        groupBox_6->setFont(font);
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_36 = new QGridLayout(groupBox_6);
        gridLayout_36->setSpacing(6);
        gridLayout_36->setContentsMargins(11, 11, 11, 11);
        gridLayout_36->setObjectName(QString::fromUtf8("gridLayout_36"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_41 = new QLabel(groupBox_6);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_7->addWidget(label_41);

        lbl_Auto = new QLabel(groupBox_6);
        lbl_Auto->setObjectName(QString::fromUtf8("lbl_Auto"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_Auto->sizePolicy().hasHeightForWidth());
        lbl_Auto->setSizePolicy(sizePolicy3);
        lbl_Auto->setMinimumSize(QSize(15, 15));
        lbl_Auto->setMaximumSize(QSize(15, 15));
        lbl_Auto->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_7->addWidget(lbl_Auto);


        gridLayout_36->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_50 = new QLabel(groupBox_6);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_5->addWidget(label_50);

        lbl_Manual = new QLabel(groupBox_6);
        lbl_Manual->setObjectName(QString::fromUtf8("lbl_Manual"));
        sizePolicy3.setHeightForWidth(lbl_Manual->sizePolicy().hasHeightForWidth());
        lbl_Manual->setSizePolicy(sizePolicy3);
        lbl_Manual->setMinimumSize(QSize(15, 15));
        lbl_Manual->setMaximumSize(QSize(15, 15));
        lbl_Manual->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_5->addWidget(lbl_Manual);


        gridLayout_36->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        tableView_SystemStatus = new QTableView(groupBox_6);
        tableView_SystemStatus->setObjectName(QString::fromUtf8("tableView_SystemStatus"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MingLiU-ExtB"));
        tableView_SystemStatus->setFont(font1);
        tableView_SystemStatus->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableView_SystemStatus->setStyleSheet(QString::fromUtf8("/* QTableView \346\225\264\344\275\223\346\240\267\345\274\217 */\n"
"QTableView {\n"
"    /* \345\244\226\350\276\271\346\241\206\357\274\2321\345\203\217\347\264\240 \351\273\221\350\211\262 \345\256\236\347\272\277 */\n"
"    border: 1px solid #000000;\n"
"    /* \347\275\221\346\240\274\347\272\277\357\274\2321\345\203\217\347\264\240 \347\201\260\350\211\262 \345\256\236\347\272\277\357\274\211 */\n"
"    gridline-color: #888888;\n"
"}\n"
"\n"
"/* \350\241\250\345\244\264\346\240\267\345\274\217 */\n"
"QHeaderView::section {\n"
"    border: 1px solid #000000;  /* \350\241\250\345\244\264\345\215\225\345\205\203\346\240\274\350\276\271\346\241\206 */\n"
"    background-color: #f0f0f0;  /* \350\241\250\345\244\264\350\203\214\346\231\257\350\211\262 */\n"
"}"));
        tableView_SystemStatus->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView_SystemStatus->horizontalHeader()->setStretchLastSection(false);
        tableView_SystemStatus->verticalHeader()->setVisible(false);

        gridLayout_36->addWidget(tableView_SystemStatus, 2, 0, 1, 2);


        gridLayout_26->addWidget(groupBox_6, 2, 1, 1, 1);

        groupBox_37 = new QGroupBox(centralWidget);
        groupBox_37->setObjectName(QString::fromUtf8("groupBox_37"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_37->sizePolicy().hasHeightForWidth());
        groupBox_37->setSizePolicy(sizePolicy4);
        groupBox_37->setMinimumSize(QSize(750, 350));
        groupBox_37->setMaximumSize(QSize(650, 350));
        groupBox_37->setFont(font);
        groupBox_37->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_62 = new QGridLayout(groupBox_37);
        gridLayout_62->setSpacing(6);
        gridLayout_62->setContentsMargins(11, 11, 11, 11);
        gridLayout_62->setObjectName(QString::fromUtf8("gridLayout_62"));
        cbxShowType = new QComboBox(groupBox_37);
        cbxShowType->addItem(QString());
        cbxShowType->addItem(QString());
        cbxShowType->setObjectName(QString::fromUtf8("cbxShowType"));
        cbxShowType->setEnabled(false);
        cbxShowType->setEditable(true);

        gridLayout_62->addWidget(cbxShowType, 3, 0, 1, 1);

        btnGenerateChart = new QPushButton(groupBox_37);
        btnGenerateChart->setObjectName(QString::fromUtf8("btnGenerateChart"));
        btnGenerateChart->setEnabled(false);
        btnGenerateChart->setCheckable(false);

        gridLayout_62->addWidget(btnGenerateChart, 3, 2, 1, 1);

        cbxSensorType = new QComboBox(groupBox_37);
        cbxSensorType->addItem(QString());
        cbxSensorType->addItem(QString());
        cbxSensorType->addItem(QString());
        cbxSensorType->addItem(QString());
        cbxSensorType->addItem(QString());
        cbxSensorType->addItem(QString());
        cbxSensorType->setObjectName(QString::fromUtf8("cbxSensorType"));
        cbxSensorType->setEnabled(false);

        gridLayout_62->addWidget(cbxSensorType, 3, 1, 1, 1);

        cvData = new QChartView(groupBox_37);
        cvData->setObjectName(QString::fromUtf8("cvData"));
        cvData->setStyleSheet(QString::fromUtf8("Background:white;\n"
"border: 1px solid #000000;\n"
""));

        gridLayout_62->addWidget(cvData, 1, 0, 1, 3);


        gridLayout_26->addWidget(groupBox_37, 0, 1, 1, 1);

        groupBox_TaskMgr = new QGroupBox(centralWidget);
        groupBox_TaskMgr->setObjectName(QString::fromUtf8("groupBox_TaskMgr"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_TaskMgr->sizePolicy().hasHeightForWidth());
        groupBox_TaskMgr->setSizePolicy(sizePolicy5);
        groupBox_TaskMgr->setMinimumSize(QSize(750, 270));
        groupBox_TaskMgr->setMaximumSize(QSize(600, 270));
        groupBox_TaskMgr->setFont(font);
        groupBox_TaskMgr->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"    background:White;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_2 = new QGridLayout(groupBox_TaskMgr);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_231 = new QLabel(groupBox_TaskMgr);
        label_231->setObjectName(QString::fromUtf8("label_231"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_231->sizePolicy().hasHeightForWidth());
        label_231->setSizePolicy(sizePolicy6);
        label_231->setMinimumSize(QSize(0, 30));
        label_231->setMaximumSize(QSize(150, 16777215));
        label_231->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_231, 0, 0, 1, 1);

        label_34 = new QLabel(groupBox_TaskMgr);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy6.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy6);
        label_34->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_34, 0, 1, 1, 1);

        label_33 = new QLabel(groupBox_TaskMgr);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        sizePolicy6.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(label_33, 0, 2, 1, 1);

        label_248 = new QLabel(groupBox_TaskMgr);
        label_248->setObjectName(QString::fromUtf8("label_248"));
        sizePolicy6.setHeightForWidth(label_248->sizePolicy().hasHeightForWidth());
        label_248->setSizePolicy(sizePolicy6);
        label_248->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_248, 0, 3, 1, 1);

        label_249 = new QLabel(groupBox_TaskMgr);
        label_249->setObjectName(QString::fromUtf8("label_249"));
        sizePolicy6.setHeightForWidth(label_249->sizePolicy().hasHeightForWidth());
        label_249->setSizePolicy(sizePolicy6);
        label_249->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_249, 0, 4, 1, 1);

        label_252 = new QLabel(groupBox_TaskMgr);
        label_252->setObjectName(QString::fromUtf8("label_252"));
        sizePolicy6.setHeightForWidth(label_252->sizePolicy().hasHeightForWidth());
        label_252->setSizePolicy(sizePolicy6);
        label_252->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_252, 0, 5, 1, 1);

        label_260 = new QLabel(groupBox_TaskMgr);
        label_260->setObjectName(QString::fromUtf8("label_260"));
        sizePolicy6.setHeightForWidth(label_260->sizePolicy().hasHeightForWidth());
        label_260->setSizePolicy(sizePolicy6);
        label_260->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_260, 0, 6, 1, 1);

        lbl_AGV = new QLabel(groupBox_TaskMgr);
        lbl_AGV->setObjectName(QString::fromUtf8("lbl_AGV"));
        sizePolicy6.setHeightForWidth(lbl_AGV->sizePolicy().hasHeightForWidth());
        lbl_AGV->setSizePolicy(sizePolicy6);
        lbl_AGV->setMinimumSize(QSize(15, 15));
        lbl_AGV->setMaximumSize(QSize(15, 15));
        lbl_AGV->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_AGV, 1, 0, 1, 1);

        lbl_VehTaskForward = new QLabel(groupBox_TaskMgr);
        lbl_VehTaskForward->setObjectName(QString::fromUtf8("lbl_VehTaskForward"));
        sizePolicy6.setHeightForWidth(lbl_VehTaskForward->sizePolicy().hasHeightForWidth());
        lbl_VehTaskForward->setSizePolicy(sizePolicy6);
        lbl_VehTaskForward->setMinimumSize(QSize(15, 15));
        lbl_VehTaskForward->setMaximumSize(QSize(15, 15));
        lbl_VehTaskForward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_VehTaskForward, 1, 1, 1, 1);

        lbl_VehTaskBackward = new QLabel(groupBox_TaskMgr);
        lbl_VehTaskBackward->setObjectName(QString::fromUtf8("lbl_VehTaskBackward"));
        sizePolicy3.setHeightForWidth(lbl_VehTaskBackward->sizePolicy().hasHeightForWidth());
        lbl_VehTaskBackward->setSizePolicy(sizePolicy3);
        lbl_VehTaskBackward->setMinimumSize(QSize(15, 15));
        lbl_VehTaskBackward->setMaximumSize(QSize(15, 15));
        lbl_VehTaskBackward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_VehTaskBackward, 1, 2, 1, 1);

        lbl_AGV_Ready = new QLabel(groupBox_TaskMgr);
        lbl_AGV_Ready->setObjectName(QString::fromUtf8("lbl_AGV_Ready"));
        sizePolicy3.setHeightForWidth(lbl_AGV_Ready->sizePolicy().hasHeightForWidth());
        lbl_AGV_Ready->setSizePolicy(sizePolicy3);
        lbl_AGV_Ready->setMinimumSize(QSize(15, 15));
        lbl_AGV_Ready->setMaximumSize(QSize(15, 15));
        lbl_AGV_Ready->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_AGV_Ready, 1, 3, 2, 1);

        lbl_AGV_Running = new QLabel(groupBox_TaskMgr);
        lbl_AGV_Running->setObjectName(QString::fromUtf8("lbl_AGV_Running"));
        sizePolicy3.setHeightForWidth(lbl_AGV_Running->sizePolicy().hasHeightForWidth());
        lbl_AGV_Running->setSizePolicy(sizePolicy3);
        lbl_AGV_Running->setMinimumSize(QSize(15, 15));
        lbl_AGV_Running->setMaximumSize(QSize(15, 15));
        lbl_AGV_Running->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_AGV_Running, 1, 4, 2, 1);

        lbl_AGV_Complete = new QLabel(groupBox_TaskMgr);
        lbl_AGV_Complete->setObjectName(QString::fromUtf8("lbl_AGV_Complete"));
        sizePolicy3.setHeightForWidth(lbl_AGV_Complete->sizePolicy().hasHeightForWidth());
        lbl_AGV_Complete->setSizePolicy(sizePolicy3);
        lbl_AGV_Complete->setMinimumSize(QSize(15, 15));
        lbl_AGV_Complete->setMaximumSize(QSize(15, 15));
        lbl_AGV_Complete->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_AGV_Complete, 1, 5, 2, 1);

        lbl_AGV_Error = new QLabel(groupBox_TaskMgr);
        lbl_AGV_Error->setObjectName(QString::fromUtf8("lbl_AGV_Error"));
        sizePolicy3.setHeightForWidth(lbl_AGV_Error->sizePolicy().hasHeightForWidth());
        lbl_AGV_Error->setSizePolicy(sizePolicy3);
        lbl_AGV_Error->setMinimumSize(QSize(15, 15));
        lbl_AGV_Error->setMaximumSize(QSize(15, 15));
        lbl_AGV_Error->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_AGV_Error, 1, 6, 2, 1);

        label_232 = new QLabel(groupBox_TaskMgr);
        label_232->setObjectName(QString::fromUtf8("label_232"));
        sizePolicy6.setHeightForWidth(label_232->sizePolicy().hasHeightForWidth());
        label_232->setSizePolicy(sizePolicy6);
        label_232->setMinimumSize(QSize(40, 20));
        label_232->setMaximumSize(QSize(150, 40));

        gridLayout_2->addWidget(label_232, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_TaskMgr);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_TaskMgr);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 2, 2, 1, 1);

        lbl_Level = new QLabel(groupBox_TaskMgr);
        lbl_Level->setObjectName(QString::fromUtf8("lbl_Level"));
        sizePolicy3.setHeightForWidth(lbl_Level->sizePolicy().hasHeightForWidth());
        lbl_Level->setSizePolicy(sizePolicy3);
        lbl_Level->setMinimumSize(QSize(15, 15));
        lbl_Level->setMaximumSize(QSize(15, 15));
        lbl_Level->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Level, 3, 0, 1, 1);

        lbl_LevelTaskForward = new QLabel(groupBox_TaskMgr);
        lbl_LevelTaskForward->setObjectName(QString::fromUtf8("lbl_LevelTaskForward"));
        sizePolicy3.setHeightForWidth(lbl_LevelTaskForward->sizePolicy().hasHeightForWidth());
        lbl_LevelTaskForward->setSizePolicy(sizePolicy3);
        lbl_LevelTaskForward->setMinimumSize(QSize(15, 15));
        lbl_LevelTaskForward->setMaximumSize(QSize(15, 15));
        lbl_LevelTaskForward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_LevelTaskForward, 3, 1, 1, 1);

        lbl_LevelTaskBackward = new QLabel(groupBox_TaskMgr);
        lbl_LevelTaskBackward->setObjectName(QString::fromUtf8("lbl_LevelTaskBackward"));
        sizePolicy3.setHeightForWidth(lbl_LevelTaskBackward->sizePolicy().hasHeightForWidth());
        lbl_LevelTaskBackward->setSizePolicy(sizePolicy3);
        lbl_LevelTaskBackward->setMinimumSize(QSize(15, 15));
        lbl_LevelTaskBackward->setMaximumSize(QSize(15, 15));
        lbl_LevelTaskBackward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_LevelTaskBackward, 3, 2, 1, 1);

        lbl_Level_Ready = new QLabel(groupBox_TaskMgr);
        lbl_Level_Ready->setObjectName(QString::fromUtf8("lbl_Level_Ready"));
        sizePolicy3.setHeightForWidth(lbl_Level_Ready->sizePolicy().hasHeightForWidth());
        lbl_Level_Ready->setSizePolicy(sizePolicy3);
        lbl_Level_Ready->setMinimumSize(QSize(15, 15));
        lbl_Level_Ready->setMaximumSize(QSize(15, 15));
        lbl_Level_Ready->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Level_Ready, 3, 3, 1, 1);

        lbl_Level_Running = new QLabel(groupBox_TaskMgr);
        lbl_Level_Running->setObjectName(QString::fromUtf8("lbl_Level_Running"));
        sizePolicy3.setHeightForWidth(lbl_Level_Running->sizePolicy().hasHeightForWidth());
        lbl_Level_Running->setSizePolicy(sizePolicy3);
        lbl_Level_Running->setMinimumSize(QSize(15, 15));
        lbl_Level_Running->setMaximumSize(QSize(15, 15));
        lbl_Level_Running->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Level_Running, 3, 4, 1, 1);

        lbl_Level_Complete = new QLabel(groupBox_TaskMgr);
        lbl_Level_Complete->setObjectName(QString::fromUtf8("lbl_Level_Complete"));
        sizePolicy3.setHeightForWidth(lbl_Level_Complete->sizePolicy().hasHeightForWidth());
        lbl_Level_Complete->setSizePolicy(sizePolicy3);
        lbl_Level_Complete->setMinimumSize(QSize(15, 15));
        lbl_Level_Complete->setMaximumSize(QSize(15, 15));
        lbl_Level_Complete->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Level_Complete, 3, 5, 1, 1);

        lbl_Level_Error = new QLabel(groupBox_TaskMgr);
        lbl_Level_Error->setObjectName(QString::fromUtf8("lbl_Level_Error"));
        sizePolicy3.setHeightForWidth(lbl_Level_Error->sizePolicy().hasHeightForWidth());
        lbl_Level_Error->setSizePolicy(sizePolicy3);
        lbl_Level_Error->setMinimumSize(QSize(15, 15));
        lbl_Level_Error->setMaximumSize(QSize(15, 15));
        lbl_Level_Error->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Level_Error, 3, 6, 1, 1);

        label_233 = new QLabel(groupBox_TaskMgr);
        label_233->setObjectName(QString::fromUtf8("label_233"));
        sizePolicy6.setHeightForWidth(label_233->sizePolicy().hasHeightForWidth());
        label_233->setSizePolicy(sizePolicy6);
        label_233->setMinimumSize(QSize(0, 20));
        label_233->setMaximumSize(QSize(150, 40));

        gridLayout_2->addWidget(label_233, 4, 0, 1, 1);

        label_6 = new QLabel(groupBox_TaskMgr);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox_TaskMgr);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 4, 2, 1, 1);

        lbl_MainLift = new QLabel(groupBox_TaskMgr);
        lbl_MainLift->setObjectName(QString::fromUtf8("lbl_MainLift"));
        sizePolicy3.setHeightForWidth(lbl_MainLift->sizePolicy().hasHeightForWidth());
        lbl_MainLift->setSizePolicy(sizePolicy3);
        lbl_MainLift->setMinimumSize(QSize(15, 15));
        lbl_MainLift->setMaximumSize(QSize(15, 15));
        lbl_MainLift->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLift, 5, 0, 1, 1);

        lbl_MainLiftTaskForward = new QLabel(groupBox_TaskMgr);
        lbl_MainLiftTaskForward->setObjectName(QString::fromUtf8("lbl_MainLiftTaskForward"));
        sizePolicy3.setHeightForWidth(lbl_MainLiftTaskForward->sizePolicy().hasHeightForWidth());
        lbl_MainLiftTaskForward->setSizePolicy(sizePolicy3);
        lbl_MainLiftTaskForward->setMinimumSize(QSize(15, 15));
        lbl_MainLiftTaskForward->setMaximumSize(QSize(15, 15));
        lbl_MainLiftTaskForward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLiftTaskForward, 5, 1, 1, 1);

        lbl_MainLiftTaskBackward = new QLabel(groupBox_TaskMgr);
        lbl_MainLiftTaskBackward->setObjectName(QString::fromUtf8("lbl_MainLiftTaskBackward"));
        sizePolicy3.setHeightForWidth(lbl_MainLiftTaskBackward->sizePolicy().hasHeightForWidth());
        lbl_MainLiftTaskBackward->setSizePolicy(sizePolicy3);
        lbl_MainLiftTaskBackward->setMinimumSize(QSize(15, 15));
        lbl_MainLiftTaskBackward->setMaximumSize(QSize(15, 15));
        lbl_MainLiftTaskBackward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLiftTaskBackward, 5, 2, 1, 1);

        lbl_MainLift_Ready = new QLabel(groupBox_TaskMgr);
        lbl_MainLift_Ready->setObjectName(QString::fromUtf8("lbl_MainLift_Ready"));
        sizePolicy3.setHeightForWidth(lbl_MainLift_Ready->sizePolicy().hasHeightForWidth());
        lbl_MainLift_Ready->setSizePolicy(sizePolicy3);
        lbl_MainLift_Ready->setMinimumSize(QSize(15, 15));
        lbl_MainLift_Ready->setMaximumSize(QSize(15, 15));
        lbl_MainLift_Ready->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLift_Ready, 5, 3, 2, 1);

        lbl_MainLift_Running = new QLabel(groupBox_TaskMgr);
        lbl_MainLift_Running->setObjectName(QString::fromUtf8("lbl_MainLift_Running"));
        sizePolicy3.setHeightForWidth(lbl_MainLift_Running->sizePolicy().hasHeightForWidth());
        lbl_MainLift_Running->setSizePolicy(sizePolicy3);
        lbl_MainLift_Running->setMinimumSize(QSize(15, 15));
        lbl_MainLift_Running->setMaximumSize(QSize(15, 15));
        lbl_MainLift_Running->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLift_Running, 5, 4, 2, 1);

        lbl_MainLift_Complete = new QLabel(groupBox_TaskMgr);
        lbl_MainLift_Complete->setObjectName(QString::fromUtf8("lbl_MainLift_Complete"));
        sizePolicy3.setHeightForWidth(lbl_MainLift_Complete->sizePolicy().hasHeightForWidth());
        lbl_MainLift_Complete->setSizePolicy(sizePolicy3);
        lbl_MainLift_Complete->setMinimumSize(QSize(15, 15));
        lbl_MainLift_Complete->setMaximumSize(QSize(15, 15));
        lbl_MainLift_Complete->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLift_Complete, 5, 5, 2, 1);

        lbl_MainLift_Error = new QLabel(groupBox_TaskMgr);
        lbl_MainLift_Error->setObjectName(QString::fromUtf8("lbl_MainLift_Error"));
        sizePolicy3.setHeightForWidth(lbl_MainLift_Error->sizePolicy().hasHeightForWidth());
        lbl_MainLift_Error->setSizePolicy(sizePolicy3);
        lbl_MainLift_Error->setMinimumSize(QSize(15, 15));
        lbl_MainLift_Error->setMaximumSize(QSize(15, 15));
        lbl_MainLift_Error->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_MainLift_Error, 5, 6, 2, 1);

        label_234 = new QLabel(groupBox_TaskMgr);
        label_234->setObjectName(QString::fromUtf8("label_234"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_234->sizePolicy().hasHeightForWidth());
        label_234->setSizePolicy(sizePolicy7);
        label_234->setMinimumSize(QSize(0, 20));
        label_234->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_234, 6, 0, 1, 1);

        label_7 = new QLabel(groupBox_TaskMgr);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 6, 1, 1, 1);

        label_11 = new QLabel(groupBox_TaskMgr);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 6, 2, 1, 1);

        lbl_CoverPlate = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlate->setObjectName(QString::fromUtf8("lbl_CoverPlate"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlate->sizePolicy().hasHeightForWidth());
        lbl_CoverPlate->setSizePolicy(sizePolicy3);
        lbl_CoverPlate->setMinimumSize(QSize(15, 15));
        lbl_CoverPlate->setMaximumSize(QSize(15, 15));
        lbl_CoverPlate->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlate, 7, 0, 1, 1);

        lbl_CoverPlateTaskForward = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlateTaskForward->setObjectName(QString::fromUtf8("lbl_CoverPlateTaskForward"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlateTaskForward->sizePolicy().hasHeightForWidth());
        lbl_CoverPlateTaskForward->setSizePolicy(sizePolicy3);
        lbl_CoverPlateTaskForward->setMinimumSize(QSize(15, 15));
        lbl_CoverPlateTaskForward->setMaximumSize(QSize(15, 15));
        lbl_CoverPlateTaskForward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlateTaskForward, 7, 1, 1, 1);

        lbl_LiftTaskBackward = new QLabel(groupBox_TaskMgr);
        lbl_LiftTaskBackward->setObjectName(QString::fromUtf8("lbl_LiftTaskBackward"));
        sizePolicy3.setHeightForWidth(lbl_LiftTaskBackward->sizePolicy().hasHeightForWidth());
        lbl_LiftTaskBackward->setSizePolicy(sizePolicy3);
        lbl_LiftTaskBackward->setMinimumSize(QSize(15, 15));
        lbl_LiftTaskBackward->setMaximumSize(QSize(15, 15));
        lbl_LiftTaskBackward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_LiftTaskBackward, 7, 2, 1, 1);

        lbl_CoverPlate_Ready = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlate_Ready->setObjectName(QString::fromUtf8("lbl_CoverPlate_Ready"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlate_Ready->sizePolicy().hasHeightForWidth());
        lbl_CoverPlate_Ready->setSizePolicy(sizePolicy3);
        lbl_CoverPlate_Ready->setMinimumSize(QSize(15, 15));
        lbl_CoverPlate_Ready->setMaximumSize(QSize(15, 15));
        lbl_CoverPlate_Ready->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlate_Ready, 7, 3, 1, 1);

        lbl_CoverPlate_Running = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlate_Running->setObjectName(QString::fromUtf8("lbl_CoverPlate_Running"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlate_Running->sizePolicy().hasHeightForWidth());
        lbl_CoverPlate_Running->setSizePolicy(sizePolicy3);
        lbl_CoverPlate_Running->setMinimumSize(QSize(15, 15));
        lbl_CoverPlate_Running->setMaximumSize(QSize(15, 15));
        lbl_CoverPlate_Running->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlate_Running, 7, 4, 1, 1);

        lbl_CoverPlate_Complete = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlate_Complete->setObjectName(QString::fromUtf8("lbl_CoverPlate_Complete"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlate_Complete->sizePolicy().hasHeightForWidth());
        lbl_CoverPlate_Complete->setSizePolicy(sizePolicy3);
        lbl_CoverPlate_Complete->setMinimumSize(QSize(15, 15));
        lbl_CoverPlate_Complete->setMaximumSize(QSize(15, 15));
        lbl_CoverPlate_Complete->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlate_Complete, 7, 5, 1, 1);

        lbl_CoverPlate_Error = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlate_Error->setObjectName(QString::fromUtf8("lbl_CoverPlate_Error"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlate_Error->sizePolicy().hasHeightForWidth());
        lbl_CoverPlate_Error->setSizePolicy(sizePolicy3);
        lbl_CoverPlate_Error->setMinimumSize(QSize(15, 15));
        lbl_CoverPlate_Error->setMaximumSize(QSize(15, 15));
        lbl_CoverPlate_Error->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlate_Error, 7, 6, 1, 1);

        label_239 = new QLabel(groupBox_TaskMgr);
        label_239->setObjectName(QString::fromUtf8("label_239"));
        sizePolicy7.setHeightForWidth(label_239->sizePolicy().hasHeightForWidth());
        label_239->setSizePolicy(sizePolicy7);
        label_239->setMinimumSize(QSize(0, 20));
        label_239->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_239, 8, 0, 1, 1);

        label_8 = new QLabel(groupBox_TaskMgr);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 8, 1, 1, 1);

        label_35 = new QLabel(groupBox_TaskMgr);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_2->addWidget(label_35, 8, 2, 1, 1);

        lbl_Lift = new QLabel(groupBox_TaskMgr);
        lbl_Lift->setObjectName(QString::fromUtf8("lbl_Lift"));
        sizePolicy3.setHeightForWidth(lbl_Lift->sizePolicy().hasHeightForWidth());
        lbl_Lift->setSizePolicy(sizePolicy3);
        lbl_Lift->setMinimumSize(QSize(15, 15));
        lbl_Lift->setMaximumSize(QSize(15, 15));
        lbl_Lift->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Lift, 9, 0, 1, 1);

        lbl_LiftTaskForward = new QLabel(groupBox_TaskMgr);
        lbl_LiftTaskForward->setObjectName(QString::fromUtf8("lbl_LiftTaskForward"));
        sizePolicy3.setHeightForWidth(lbl_LiftTaskForward->sizePolicy().hasHeightForWidth());
        lbl_LiftTaskForward->setSizePolicy(sizePolicy3);
        lbl_LiftTaskForward->setMinimumSize(QSize(15, 15));
        lbl_LiftTaskForward->setMaximumSize(QSize(15, 15));
        lbl_LiftTaskForward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_LiftTaskForward, 9, 1, 1, 1);

        lbl_CoverPlateTaskBackward = new QLabel(groupBox_TaskMgr);
        lbl_CoverPlateTaskBackward->setObjectName(QString::fromUtf8("lbl_CoverPlateTaskBackward"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlateTaskBackward->sizePolicy().hasHeightForWidth());
        lbl_CoverPlateTaskBackward->setSizePolicy(sizePolicy3);
        lbl_CoverPlateTaskBackward->setMinimumSize(QSize(15, 15));
        lbl_CoverPlateTaskBackward->setMaximumSize(QSize(15, 15));
        lbl_CoverPlateTaskBackward->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_CoverPlateTaskBackward, 9, 2, 2, 1);

        lbl_Lift_Ready = new QLabel(groupBox_TaskMgr);
        lbl_Lift_Ready->setObjectName(QString::fromUtf8("lbl_Lift_Ready"));
        sizePolicy3.setHeightForWidth(lbl_Lift_Ready->sizePolicy().hasHeightForWidth());
        lbl_Lift_Ready->setSizePolicy(sizePolicy3);
        lbl_Lift_Ready->setMinimumSize(QSize(15, 15));
        lbl_Lift_Ready->setMaximumSize(QSize(15, 15));
        lbl_Lift_Ready->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Lift_Ready, 9, 3, 2, 1);

        lbl_Lift_Running = new QLabel(groupBox_TaskMgr);
        lbl_Lift_Running->setObjectName(QString::fromUtf8("lbl_Lift_Running"));
        sizePolicy3.setHeightForWidth(lbl_Lift_Running->sizePolicy().hasHeightForWidth());
        lbl_Lift_Running->setSizePolicy(sizePolicy3);
        lbl_Lift_Running->setMinimumSize(QSize(15, 15));
        lbl_Lift_Running->setMaximumSize(QSize(15, 15));
        lbl_Lift_Running->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Lift_Running, 9, 4, 2, 1);

        lbl_Lift_Complete = new QLabel(groupBox_TaskMgr);
        lbl_Lift_Complete->setObjectName(QString::fromUtf8("lbl_Lift_Complete"));
        sizePolicy3.setHeightForWidth(lbl_Lift_Complete->sizePolicy().hasHeightForWidth());
        lbl_Lift_Complete->setSizePolicy(sizePolicy3);
        lbl_Lift_Complete->setMinimumSize(QSize(15, 15));
        lbl_Lift_Complete->setMaximumSize(QSize(15, 15));
        lbl_Lift_Complete->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Lift_Complete, 9, 5, 2, 1);

        lbl_Lift_Error = new QLabel(groupBox_TaskMgr);
        lbl_Lift_Error->setObjectName(QString::fromUtf8("lbl_Lift_Error"));
        sizePolicy3.setHeightForWidth(lbl_Lift_Error->sizePolicy().hasHeightForWidth());
        lbl_Lift_Error->setSizePolicy(sizePolicy3);
        lbl_Lift_Error->setMinimumSize(QSize(15, 15));
        lbl_Lift_Error->setMaximumSize(QSize(15, 15));
        lbl_Lift_Error->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Lift_Error, 9, 6, 2, 1);

        label_236 = new QLabel(groupBox_TaskMgr);
        label_236->setObjectName(QString::fromUtf8("label_236"));
        sizePolicy7.setHeightForWidth(label_236->sizePolicy().hasHeightForWidth());
        label_236->setSizePolicy(sizePolicy7);
        label_236->setMinimumSize(QSize(0, 20));
        label_236->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(label_236, 10, 0, 1, 1);

        label_36 = new QLabel(groupBox_TaskMgr);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_2->addWidget(label_36, 10, 1, 1, 1);

        lbl_Pin = new QLabel(groupBox_TaskMgr);
        lbl_Pin->setObjectName(QString::fromUtf8("lbl_Pin"));
        sizePolicy3.setHeightForWidth(lbl_Pin->sizePolicy().hasHeightForWidth());
        lbl_Pin->setSizePolicy(sizePolicy3);
        lbl_Pin->setMinimumSize(QSize(15, 15));
        lbl_Pin->setMaximumSize(QSize(15, 15));
        lbl_Pin->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Pin, 11, 0, 1, 1);

        lbl_PinTask = new QLabel(groupBox_TaskMgr);
        lbl_PinTask->setObjectName(QString::fromUtf8("lbl_PinTask"));
        sizePolicy2.setHeightForWidth(lbl_PinTask->sizePolicy().hasHeightForWidth());
        lbl_PinTask->setSizePolicy(sizePolicy2);
        lbl_PinTask->setMinimumSize(QSize(15, 15));
        lbl_PinTask->setMaximumSize(QSize(15, 15));
        lbl_PinTask->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_PinTask, 11, 1, 1, 1);

        lbl_Pin_Ready = new QLabel(groupBox_TaskMgr);
        lbl_Pin_Ready->setObjectName(QString::fromUtf8("lbl_Pin_Ready"));
        sizePolicy3.setHeightForWidth(lbl_Pin_Ready->sizePolicy().hasHeightForWidth());
        lbl_Pin_Ready->setSizePolicy(sizePolicy3);
        lbl_Pin_Ready->setMinimumSize(QSize(15, 15));
        lbl_Pin_Ready->setMaximumSize(QSize(15, 15));
        lbl_Pin_Ready->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Pin_Ready, 11, 3, 1, 1);

        lbl_Pin_Running = new QLabel(groupBox_TaskMgr);
        lbl_Pin_Running->setObjectName(QString::fromUtf8("lbl_Pin_Running"));
        sizePolicy3.setHeightForWidth(lbl_Pin_Running->sizePolicy().hasHeightForWidth());
        lbl_Pin_Running->setSizePolicy(sizePolicy3);
        lbl_Pin_Running->setMinimumSize(QSize(15, 15));
        lbl_Pin_Running->setMaximumSize(QSize(15, 15));
        lbl_Pin_Running->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Pin_Running, 11, 4, 1, 1);

        lbl_Pin_Complete = new QLabel(groupBox_TaskMgr);
        lbl_Pin_Complete->setObjectName(QString::fromUtf8("lbl_Pin_Complete"));
        sizePolicy3.setHeightForWidth(lbl_Pin_Complete->sizePolicy().hasHeightForWidth());
        lbl_Pin_Complete->setSizePolicy(sizePolicy3);
        lbl_Pin_Complete->setMinimumSize(QSize(15, 15));
        lbl_Pin_Complete->setMaximumSize(QSize(15, 15));
        lbl_Pin_Complete->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Pin_Complete, 11, 5, 1, 1);

        lbl_Pin_Error = new QLabel(groupBox_TaskMgr);
        lbl_Pin_Error->setObjectName(QString::fromUtf8("lbl_Pin_Error"));
        sizePolicy3.setHeightForWidth(lbl_Pin_Error->sizePolicy().hasHeightForWidth());
        lbl_Pin_Error->setSizePolicy(sizePolicy3);
        lbl_Pin_Error->setMinimumSize(QSize(15, 15));
        lbl_Pin_Error->setMaximumSize(QSize(15, 15));
        lbl_Pin_Error->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_2->addWidget(lbl_Pin_Error, 11, 6, 1, 1);


        gridLayout_26->addWidget(groupBox_TaskMgr, 1, 1, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        sizePolicy4.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy4);
        tabWidget->setMinimumSize(QSize(920, 0));
        tabWidget->setMaximumSize(QSize(920, 900));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(12);
        tabWidget->setFont(font2);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy8);
        gridLayout_39 = new QGridLayout(tab);
        gridLayout_39->setSpacing(6);
        gridLayout_39->setContentsMargins(11, 11, 11, 11);
        gridLayout_39->setObjectName(QString::fromUtf8("gridLayout_39"));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        sizePolicy6.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy6);
        groupBox_7->setMaximumSize(QSize(16777215, 300));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(11);
        font3.setBold(true);
        groupBox_7->setFont(font3);
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setSpacing(6);
        horizontalLayout_50->setObjectName(QString::fromUtf8("horizontalLayout_50"));
        label_119 = new QLabel(groupBox_7);
        label_119->setObjectName(QString::fromUtf8("label_119"));
        sizePolicy5.setHeightForWidth(label_119->sizePolicy().hasHeightForWidth());
        label_119->setSizePolicy(sizePolicy5);
        label_119->setMinimumSize(QSize(120, 0));
        label_119->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_50->addWidget(label_119);

        lineEdit_NaviSvr = new QLineEdit(groupBox_7);
        lineEdit_NaviSvr->setObjectName(QString::fromUtf8("lineEdit_NaviSvr"));

        horizontalLayout_50->addWidget(lineEdit_NaviSvr);

        label_153 = new QLabel(groupBox_7);
        label_153->setObjectName(QString::fromUtf8("label_153"));
        sizePolicy5.setHeightForWidth(label_153->sizePolicy().hasHeightForWidth());
        label_153->setSizePolicy(sizePolicy5);
        label_153->setMinimumSize(QSize(45, 0));

        horizontalLayout_50->addWidget(label_153);

        comBox_NavigatePort = new QComboBox(groupBox_7);
        comBox_NavigatePort->setObjectName(QString::fromUtf8("comBox_NavigatePort"));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(comBox_NavigatePort->sizePolicy().hasHeightForWidth());
        comBox_NavigatePort->setSizePolicy(sizePolicy9);
        comBox_NavigatePort->setMinimumSize(QSize(155, 0));
        comBox_NavigatePort->setEditable(true);

        horizontalLayout_50->addWidget(comBox_NavigatePort);

        btn_CnntNavigateSvr = new QPushButton(groupBox_7);
        btn_CnntNavigateSvr->setObjectName(QString::fromUtf8("btn_CnntNavigateSvr"));
        btn_CnntNavigateSvr->setMinimumSize(QSize(100, 0));

        horizontalLayout_50->addWidget(btn_CnntNavigateSvr);


        gridLayout_6->addLayout(horizontalLayout_50, 1, 0, 1, 1);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_117 = new QLabel(groupBox_7);
        label_117->setObjectName(QString::fromUtf8("label_117"));
        QSizePolicy sizePolicy10(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_117->sizePolicy().hasHeightForWidth());
        label_117->setSizePolicy(sizePolicy10);
        label_117->setMinimumSize(QSize(120, 0));
        label_117->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_28->addWidget(label_117);

        lineEdit_PushSvr = new QLineEdit(groupBox_7);
        lineEdit_PushSvr->setObjectName(QString::fromUtf8("lineEdit_PushSvr"));

        horizontalLayout_28->addWidget(lineEdit_PushSvr);

        label_118 = new QLabel(groupBox_7);
        label_118->setObjectName(QString::fromUtf8("label_118"));
        sizePolicy5.setHeightForWidth(label_118->sizePolicy().hasHeightForWidth());
        label_118->setSizePolicy(sizePolicy5);
        label_118->setMinimumSize(QSize(45, 0));

        horizontalLayout_28->addWidget(label_118);

        comBox_PushPort = new QComboBox(groupBox_7);
        comBox_PushPort->setObjectName(QString::fromUtf8("comBox_PushPort"));
        sizePolicy9.setHeightForWidth(comBox_PushPort->sizePolicy().hasHeightForWidth());
        comBox_PushPort->setSizePolicy(sizePolicy9);
        comBox_PushPort->setMinimumSize(QSize(155, 0));
        comBox_PushPort->setEditable(true);

        horizontalLayout_28->addWidget(comBox_PushPort);

        btn_CnntPushSvr = new QPushButton(groupBox_7);
        btn_CnntPushSvr->setObjectName(QString::fromUtf8("btn_CnntPushSvr"));
        btn_CnntPushSvr->setMinimumSize(QSize(100, 0));

        horizontalLayout_28->addWidget(btn_CnntPushSvr);


        gridLayout_6->addLayout(horizontalLayout_28, 0, 0, 1, 1);

        horizontalLayout_80 = new QHBoxLayout();
        horizontalLayout_80->setSpacing(6);
        horizontalLayout_80->setObjectName(QString::fromUtf8("horizontalLayout_80"));
        label_170 = new QLabel(groupBox_7);
        label_170->setObjectName(QString::fromUtf8("label_170"));
        sizePolicy5.setHeightForWidth(label_170->sizePolicy().hasHeightForWidth());
        label_170->setSizePolicy(sizePolicy5);
        label_170->setMinimumSize(QSize(120, 0));
        label_170->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_80->addWidget(label_170);

        comboBox_Map = new QComboBox(groupBox_7);
        comboBox_Map->setObjectName(QString::fromUtf8("comboBox_Map"));
        QSizePolicy sizePolicy11(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(comboBox_Map->sizePolicy().hasHeightForWidth());
        comboBox_Map->setSizePolicy(sizePolicy11);
        comboBox_Map->setMinimumSize(QSize(345, 0));
        comboBox_Map->setMaximumSize(QSize(410, 16777215));

        horizontalLayout_80->addWidget(comboBox_Map);

        label_172 = new QLabel(groupBox_7);
        label_172->setObjectName(QString::fromUtf8("label_172"));
        sizePolicy5.setHeightForWidth(label_172->sizePolicy().hasHeightForWidth());
        label_172->setSizePolicy(sizePolicy5);
        label_172->setMinimumSize(QSize(45, 0));

        horizontalLayout_80->addWidget(label_172);

        lineEdit_loadmap_status2 = new QLineEdit(groupBox_7);
        lineEdit_loadmap_status2->setObjectName(QString::fromUtf8("lineEdit_loadmap_status2"));
        sizePolicy9.setHeightForWidth(lineEdit_loadmap_status2->sizePolicy().hasHeightForWidth());
        lineEdit_loadmap_status2->setSizePolicy(sizePolicy9);
        lineEdit_loadmap_status2->setMinimumSize(QSize(155, 0));

        horizontalLayout_80->addWidget(lineEdit_loadmap_status2);

        btn_MapLoad = new QPushButton(groupBox_7);
        btn_MapLoad->setObjectName(QString::fromUtf8("btn_MapLoad"));
        btn_MapLoad->setMinimumSize(QSize(100, 0));

        horizontalLayout_80->addWidget(btn_MapLoad);


        gridLayout_6->addLayout(horizontalLayout_80, 4, 0, 1, 1);

        horizontalLayout_74 = new QHBoxLayout();
        horizontalLayout_74->setSpacing(6);
        horizontalLayout_74->setObjectName(QString::fromUtf8("horizontalLayout_74"));
        label_162 = new QLabel(groupBox_7);
        label_162->setObjectName(QString::fromUtf8("label_162"));
        sizePolicy5.setHeightForWidth(label_162->sizePolicy().hasHeightForWidth());
        label_162->setSizePolicy(sizePolicy5);
        label_162->setMinimumSize(QSize(120, 0));
        label_162->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_74->addWidget(label_162);

        lineEdit_StatusSvr = new QLineEdit(groupBox_7);
        lineEdit_StatusSvr->setObjectName(QString::fromUtf8("lineEdit_StatusSvr"));

        horizontalLayout_74->addWidget(lineEdit_StatusSvr);

        label_169 = new QLabel(groupBox_7);
        label_169->setObjectName(QString::fromUtf8("label_169"));
        sizePolicy5.setHeightForWidth(label_169->sizePolicy().hasHeightForWidth());
        label_169->setSizePolicy(sizePolicy5);
        label_169->setMinimumSize(QSize(45, 0));

        horizontalLayout_74->addWidget(label_169);

        comBox_StatusPort = new QComboBox(groupBox_7);
        comBox_StatusPort->setObjectName(QString::fromUtf8("comBox_StatusPort"));
        sizePolicy9.setHeightForWidth(comBox_StatusPort->sizePolicy().hasHeightForWidth());
        comBox_StatusPort->setSizePolicy(sizePolicy9);
        comBox_StatusPort->setMinimumSize(QSize(155, 0));
        comBox_StatusPort->setEditable(true);

        horizontalLayout_74->addWidget(comBox_StatusPort);

        btn_CnntStatusSvr = new QPushButton(groupBox_7);
        btn_CnntStatusSvr->setObjectName(QString::fromUtf8("btn_CnntStatusSvr"));
        btn_CnntStatusSvr->setMinimumSize(QSize(100, 0));

        horizontalLayout_74->addWidget(btn_CnntStatusSvr);


        gridLayout_6->addLayout(horizontalLayout_74, 3, 0, 1, 1);

        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setSpacing(6);
        horizontalLayout_56->setObjectName(QString::fromUtf8("horizontalLayout_56"));
        label_167 = new QLabel(groupBox_7);
        label_167->setObjectName(QString::fromUtf8("label_167"));
        sizePolicy5.setHeightForWidth(label_167->sizePolicy().hasHeightForWidth());
        label_167->setSizePolicy(sizePolicy5);
        label_167->setMinimumSize(QSize(120, 0));
        label_167->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_56->addWidget(label_167);

        lineEdit_ContSvr = new QLineEdit(groupBox_7);
        lineEdit_ContSvr->setObjectName(QString::fromUtf8("lineEdit_ContSvr"));

        horizontalLayout_56->addWidget(lineEdit_ContSvr);

        label_168 = new QLabel(groupBox_7);
        label_168->setObjectName(QString::fromUtf8("label_168"));
        sizePolicy5.setHeightForWidth(label_168->sizePolicy().hasHeightForWidth());
        label_168->setSizePolicy(sizePolicy5);
        label_168->setMinimumSize(QSize(45, 0));

        horizontalLayout_56->addWidget(label_168);

        comBox_ControlPort = new QComboBox(groupBox_7);
        comBox_ControlPort->setObjectName(QString::fromUtf8("comBox_ControlPort"));
        sizePolicy9.setHeightForWidth(comBox_ControlPort->sizePolicy().hasHeightForWidth());
        comBox_ControlPort->setSizePolicy(sizePolicy9);
        comBox_ControlPort->setMinimumSize(QSize(155, 0));
        comBox_ControlPort->setEditable(true);

        horizontalLayout_56->addWidget(comBox_ControlPort);

        btn_CnntControlSvr = new QPushButton(groupBox_7);
        btn_CnntControlSvr->setObjectName(QString::fromUtf8("btn_CnntControlSvr"));
        btn_CnntControlSvr->setMinimumSize(QSize(100, 0));

        horizontalLayout_56->addWidget(btn_CnntControlSvr);


        gridLayout_6->addLayout(horizontalLayout_56, 2, 0, 1, 1);


        gridLayout_39->addWidget(groupBox_7, 3, 0, 1, 1);

        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setFont(font3);
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_29 = new QGridLayout(groupBox_8);
        gridLayout_29->setSpacing(6);
        gridLayout_29->setContentsMargins(11, 11, 11, 11);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        groupBox_ManualMode = new QGroupBox(groupBox_8);
        groupBox_ManualMode->setObjectName(QString::fromUtf8("groupBox_ManualMode"));
        QFont font4;
        font4.setBold(true);
        groupBox_ManualMode->setFont(font4);
        gridLayout_43 = new QGridLayout(groupBox_ManualMode);
        gridLayout_43->setSpacing(6);
        gridLayout_43->setContentsMargins(11, 11, 11, 11);
        gridLayout_43->setObjectName(QString::fromUtf8("gridLayout_43"));
        comboBox_LRUdata = new QComboBox(groupBox_ManualMode);
        comboBox_LRUdata->setObjectName(QString::fromUtf8("comboBox_LRUdata"));

        gridLayout_43->addWidget(comboBox_LRUdata, 2, 0, 1, 1);

        gridLayout_44 = new QGridLayout();
        gridLayout_44->setSpacing(6);
        gridLayout_44->setObjectName(QString::fromUtf8("gridLayout_44"));
        btn_MainLiftManual = new QPushButton(groupBox_ManualMode);
        btn_MainLiftManual->setObjectName(QString::fromUtf8("btn_MainLiftManual"));
        btn_MainLiftManual->setEnabled(false);
        btn_MainLiftManual->setFont(font2);

        gridLayout_44->addWidget(btn_MainLiftManual, 0, 2, 1, 1);

        btn_PinManual = new QPushButton(groupBox_ManualMode);
        btn_PinManual->setObjectName(QString::fromUtf8("btn_PinManual"));
        btn_PinManual->setEnabled(false);
        btn_PinManual->setFont(font2);

        gridLayout_44->addWidget(btn_PinManual, 2, 2, 1, 1);

        btn_AGVManual = new QPushButton(groupBox_ManualMode);
        btn_AGVManual->setObjectName(QString::fromUtf8("btn_AGVManual"));
        btn_AGVManual->setEnabled(false);
        btn_AGVManual->setFont(font2);

        gridLayout_44->addWidget(btn_AGVManual, 0, 0, 1, 1);

        btn_LiftManual = new QPushButton(groupBox_ManualMode);
        btn_LiftManual->setObjectName(QString::fromUtf8("btn_LiftManual"));
        btn_LiftManual->setEnabled(false);
        btn_LiftManual->setFont(font2);

        gridLayout_44->addWidget(btn_LiftManual, 2, 1, 1, 1);

        btn_LevelManual = new QPushButton(groupBox_ManualMode);
        btn_LevelManual->setObjectName(QString::fromUtf8("btn_LevelManual"));
        btn_LevelManual->setEnabled(false);
        btn_LevelManual->setFont(font2);

        gridLayout_44->addWidget(btn_LevelManual, 0, 1, 1, 1);

        btn_CoverPlateManual = new QPushButton(groupBox_ManualMode);
        btn_CoverPlateManual->setObjectName(QString::fromUtf8("btn_CoverPlateManual"));
        btn_CoverPlateManual->setEnabled(false);
        btn_CoverPlateManual->setFont(font2);

        gridLayout_44->addWidget(btn_CoverPlateManual, 2, 0, 1, 1);


        gridLayout_43->addLayout(gridLayout_44, 1, 0, 1, 1);

        radioButton_ManualMode = new QRadioButton(groupBox_ManualMode);
        radioButton_ManualMode->setObjectName(QString::fromUtf8("radioButton_ManualMode"));

        gridLayout_43->addWidget(radioButton_ManualMode, 0, 0, 1, 1);


        gridLayout_29->addWidget(groupBox_ManualMode, 1, 0, 1, 1);

        groupBox_AutoMode = new QGroupBox(groupBox_8);
        groupBox_AutoMode->setObjectName(QString::fromUtf8("groupBox_AutoMode"));
        groupBox_AutoMode->setFont(font4);
        gridLayout_37 = new QGridLayout(groupBox_AutoMode);
        gridLayout_37->setSpacing(6);
        gridLayout_37->setContentsMargins(11, 11, 11, 11);
        gridLayout_37->setObjectName(QString::fromUtf8("gridLayout_37"));
        radioButton_AutoMode = new QRadioButton(groupBox_AutoMode);
        radioButton_AutoMode->setObjectName(QString::fromUtf8("radioButton_AutoMode"));
        radioButton_AutoMode->setCheckable(true);
        radioButton_AutoMode->setChecked(false);

        gridLayout_37->addWidget(radioButton_AutoMode, 0, 0, 1, 1);

        radioButton_leftPlate = new QRadioButton(groupBox_AutoMode);
        radioButton_leftPlate->setObjectName(QString::fromUtf8("radioButton_leftPlate"));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        radioButton_leftPlate->setFont(font5);

        gridLayout_37->addWidget(radioButton_leftPlate, 0, 1, 1, 1);

        radioButton_middlePlate = new QRadioButton(groupBox_AutoMode);
        radioButton_middlePlate->setObjectName(QString::fromUtf8("radioButton_middlePlate"));
        radioButton_middlePlate->setFont(font5);

        gridLayout_37->addWidget(radioButton_middlePlate, 0, 2, 1, 1);

        radioButton_rightPlate = new QRadioButton(groupBox_AutoMode);
        radioButton_rightPlate->setObjectName(QString::fromUtf8("radioButton_rightPlate"));
        radioButton_rightPlate->setFont(font5);

        gridLayout_37->addWidget(radioButton_rightPlate, 0, 3, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        btn_StartTask = new QPushButton(groupBox_AutoMode);
        btn_StartTask->setObjectName(QString::fromUtf8("btn_StartTask"));
        btn_StartTask->setFont(font2);

        horizontalLayout_10->addWidget(btn_StartTask);

        btn_PauseTask = new QPushButton(groupBox_AutoMode);
        btn_PauseTask->setObjectName(QString::fromUtf8("btn_PauseTask"));
        btn_PauseTask->setFont(font2);

        horizontalLayout_10->addWidget(btn_PauseTask);

        btn_ContinueTask = new QPushButton(groupBox_AutoMode);
        btn_ContinueTask->setObjectName(QString::fromUtf8("btn_ContinueTask"));
        btn_ContinueTask->setFont(font2);

        horizontalLayout_10->addWidget(btn_ContinueTask);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_238 = new QLabel(groupBox_AutoMode);
        label_238->setObjectName(QString::fromUtf8("label_238"));
        sizePolicy6.setHeightForWidth(label_238->sizePolicy().hasHeightForWidth());
        label_238->setSizePolicy(sizePolicy6);
        label_238->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_12->addWidget(label_238);

        comboBox_LRU = new QComboBox(groupBox_AutoMode);
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->addItem(QString());
        comboBox_LRU->setObjectName(QString::fromUtf8("comboBox_LRU"));
        sizePolicy9.setHeightForWidth(comboBox_LRU->sizePolicy().hasHeightForWidth());
        comboBox_LRU->setSizePolicy(sizePolicy9);
        comboBox_LRU->setMinimumSize(QSize(70, 0));

        horizontalLayout_12->addWidget(comboBox_LRU);

        label_255 = new QLabel(groupBox_AutoMode);
        label_255->setObjectName(QString::fromUtf8("label_255"));
        sizePolicy6.setHeightForWidth(label_255->sizePolicy().hasHeightForWidth());
        label_255->setSizePolicy(sizePolicy6);
        label_255->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_12->addWidget(label_255);

        comboBox_Station = new QComboBox(groupBox_AutoMode);
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->addItem(QString());
        comboBox_Station->setObjectName(QString::fromUtf8("comboBox_Station"));
        sizePolicy9.setHeightForWidth(comboBox_Station->sizePolicy().hasHeightForWidth());
        comboBox_Station->setSizePolicy(sizePolicy9);
        comboBox_Station->setMinimumSize(QSize(70, 0));

        horizontalLayout_12->addWidget(comboBox_Station);

        btn_InitialAll = new QPushButton(groupBox_AutoMode);
        btn_InitialAll->setObjectName(QString::fromUtf8("btn_InitialAll"));
        sizePolicy3.setHeightForWidth(btn_InitialAll->sizePolicy().hasHeightForWidth());
        btn_InitialAll->setSizePolicy(sizePolicy3);
        btn_InitialAll->setMinimumSize(QSize(60, 60));
        btn_InitialAll->setMaximumSize(QSize(60, 60));
        btn_InitialAll->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
"border-image: url(:/Initial.svg) 0 stretch;\n"
"border: 2px solid black;\n"
"\n"
""));

        horizontalLayout_12->addWidget(btn_InitialAll);

        btn_AllRapidStop = new QPushButton(groupBox_AutoMode);
        btn_AllRapidStop->setObjectName(QString::fromUtf8("btn_AllRapidStop"));
        sizePolicy3.setHeightForWidth(btn_AllRapidStop->sizePolicy().hasHeightForWidth());
        btn_AllRapidStop->setSizePolicy(sizePolicy3);
        btn_AllRapidStop->setMinimumSize(QSize(60, 60));
        btn_AllRapidStop->setMaximumSize(QSize(60, 60));
        btn_AllRapidStop->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/RapidStop.svg) 0 stretch;\n"
"border: 2px solid black; "));

        horizontalLayout_12->addWidget(btn_AllRapidStop);


        horizontalLayout_10->addLayout(horizontalLayout_12);


        gridLayout_37->addLayout(horizontalLayout_10, 1, 0, 1, 4);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_20 = new QLabel(groupBox_AutoMode);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setLayoutDirection(Qt::LeftToRight);
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_20);

        init_progressBar = new QProgressBar(groupBox_AutoMode);
        init_progressBar->setObjectName(QString::fromUtf8("init_progressBar"));
        init_progressBar->setValue(0);

        horizontalLayout_17->addWidget(init_progressBar);


        gridLayout_37->addLayout(horizontalLayout_17, 2, 0, 1, 4);


        gridLayout_29->addWidget(groupBox_AutoMode, 0, 0, 1, 1);


        gridLayout_39->addWidget(groupBox_8, 1, 0, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy12(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy12.setHorizontalStretch(1);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy12);
        groupBox->setMaximumSize(QSize(16777215, 200));
        groupBox->setFont(font3);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lbl_isConnect = new QLabel(groupBox);
        lbl_isConnect->setObjectName(QString::fromUtf8("lbl_isConnect"));
        sizePolicy2.setHeightForWidth(lbl_isConnect->sizePolicy().hasHeightForWidth());
        lbl_isConnect->setSizePolicy(sizePolicy2);
        lbl_isConnect->setMinimumSize(QSize(34, 34));
        lbl_isConnect->setMaximumSize(QSize(34, 34));
        lbl_isConnect->setStyleSheet(QString::fromUtf8("border-radius: 17px; \n"
"border: 2px solid black; \n"
"background:red;"));

        gridLayout->addWidget(lbl_isConnect, 0, 2, 1, 1);

        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        gridLayout->addWidget(btnConnect, 0, 3, 1, 1);

        btnConnectSimulation = new QPushButton(groupBox);
        btnConnectSimulation->setObjectName(QString::fromUtf8("btnConnectSimulation"));

        gridLayout->addWidget(btnConnectSimulation, 0, 4, 1, 1);

        btnDisconnect = new QPushButton(groupBox);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));

        gridLayout->addWidget(btnDisconnect, 0, 5, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        ledMotion = new QLabel(groupBox);
        ledMotion->setObjectName(QString::fromUtf8("ledMotion"));
        ledMotion->setLayoutDirection(Qt::LeftToRight);
        ledMotion->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ledMotion->setWordWrap(false);

        gridLayout->addWidget(ledMotion, 1, 1, 1, 1);

        cBoxConnectType = new QComboBox(groupBox);
        cBoxConnectType->addItem(QString());
        cBoxConnectType->addItem(QString());
        cBoxConnectType->addItem(QString());
        cBoxConnectType->addItem(QString());
        cBoxConnectType->addItem(QString());
        cBoxConnectType->setObjectName(QString::fromUtf8("cBoxConnectType"));

        gridLayout->addWidget(cBoxConnectType, 1, 2, 1, 1);

        btnInitBus = new QPushButton(groupBox);
        btnInitBus->setObjectName(QString::fromUtf8("btnInitBus"));

        gridLayout->addWidget(btnInitBus, 1, 3, 1, 1);

        btnInitAxis = new QPushButton(groupBox);
        btnInitAxis->setObjectName(QString::fromUtf8("btnInitAxis"));

        gridLayout->addWidget(btnInitAxis, 1, 4, 1, 1);

        btnEnableAxis = new QPushButton(groupBox);
        btnEnableAxis->setObjectName(QString::fromUtf8("btnEnableAxis"));

        gridLayout->addWidget(btnEnableAxis, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        txtEditConnectContent = new QTextEdit(groupBox);
        txtEditConnectContent->setObjectName(QString::fromUtf8("txtEditConnectContent"));
        sizePolicy1.setHeightForWidth(txtEditConnectContent->sizePolicy().hasHeightForWidth());
        txtEditConnectContent->setSizePolicy(sizePolicy1);
        txtEditConnectContent->setMinimumSize(QSize(290, 0));
        txtEditConnectContent->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(txtEditConnectContent, 2, 2, 1, 1);

        btnDisableAxis = new QPushButton(groupBox);
        btnDisableAxis->setObjectName(QString::fromUtf8("btnDisableAxis"));

        gridLayout->addWidget(btnDisableAxis, 2, 3, 1, 1);

        btnType0 = new QPushButton(groupBox);
        btnType0->setObjectName(QString::fromUtf8("btnType0"));

        gridLayout->addWidget(btnType0, 2, 4, 1, 1);

        btnType65 = new QPushButton(groupBox);
        btnType65->setObjectName(QString::fromUtf8("btnType65"));

        gridLayout->addWidget(btnType65, 2, 5, 1, 1);


        gridLayout_39->addWidget(groupBox, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_63 = new QGridLayout(tab_3);
        gridLayout_63->setSpacing(6);
        gridLayout_63->setContentsMargins(11, 11, 11, 11);
        gridLayout_63->setObjectName(QString::fromUtf8("gridLayout_63"));
        groupBox_33 = new QGroupBox(tab_3);
        groupBox_33->setObjectName(QString::fromUtf8("groupBox_33"));
        groupBox_33->setMaximumSize(QSize(16777215, 350));
        groupBox_33->setFont(font3);
        groupBox_33->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_38 = new QGridLayout(groupBox_33);
        gridLayout_38->setSpacing(6);
        gridLayout_38->setContentsMargins(11, 11, 11, 11);
        gridLayout_38->setObjectName(QString::fromUtf8("gridLayout_38"));
        gridLayout_34 = new QGridLayout();
        gridLayout_34->setSpacing(6);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        btn_AGVOpen = new QPushButton(groupBox_33);
        btn_AGVOpen->setObjectName(QString::fromUtf8("btn_AGVOpen"));
        btn_AGVOpen->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVOpen, 0, 0, 1, 1);

        btn_AGVClose = new QPushButton(groupBox_33);
        btn_AGVClose->setObjectName(QString::fromUtf8("btn_AGVClose"));
        btn_AGVClose->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVClose, 0, 1, 1, 1);

        btn_AGVRapidStop = new QPushButton(groupBox_33);
        btn_AGVRapidStop->setObjectName(QString::fromUtf8("btn_AGVRapidStop"));
        sizePolicy3.setHeightForWidth(btn_AGVRapidStop->sizePolicy().hasHeightForWidth());
        btn_AGVRapidStop->setSizePolicy(sizePolicy3);
        btn_AGVRapidStop->setMinimumSize(QSize(60, 60));
        btn_AGVRapidStop->setMaximumSize(QSize(60, 60));
        btn_AGVRapidStop->setCursor(QCursor(Qt::ArrowCursor));
        btn_AGVRapidStop->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/RapidStop.svg) 0 stretch;\n"
"border: 2px solid black; "));
        btn_AGVRapidStop->setIconSize(QSize(16, 15));

        gridLayout_34->addWidget(btn_AGVRapidStop, 0, 5, 2, 1);

        btn_AGVToAuto = new QPushButton(groupBox_33);
        btn_AGVToAuto->setObjectName(QString::fromUtf8("btn_AGVToAuto"));
        QSizePolicy sizePolicy13(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(btn_AGVToAuto->sizePolicy().hasHeightForWidth());
        btn_AGVToAuto->setSizePolicy(sizePolicy13);
        btn_AGVToAuto->setMinimumSize(QSize(90, 100));
        btn_AGVToAuto->setMaximumSize(QSize(90, 100));
        btn_AGVToAuto->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/ManualToAuto.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_34->addWidget(btn_AGVToAuto, 0, 6, 2, 1);

        btn_AGVPauseNavigate = new QPushButton(groupBox_33);
        btn_AGVPauseNavigate->setObjectName(QString::fromUtf8("btn_AGVPauseNavigate"));
        btn_AGVPauseNavigate->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVPauseNavigate, 1, 0, 1, 1);

        btn_AGVContinueNavigate = new QPushButton(groupBox_33);
        btn_AGVContinueNavigate->setObjectName(QString::fromUtf8("btn_AGVContinueNavigate"));
        btn_AGVContinueNavigate->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVContinueNavigate, 1, 1, 1, 1);

        btn_AGVCancelNavigate = new QPushButton(groupBox_33);
        btn_AGVCancelNavigate->setObjectName(QString::fromUtf8("btn_AGVCancelNavigate"));
        btn_AGVCancelNavigate->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVCancelNavigate, 0, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        btn_AGV_Translate = new QPushButton(groupBox_33);
        btn_AGV_Translate->setObjectName(QString::fromUtf8("btn_AGV_Translate"));
        QSizePolicy sizePolicy14(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(btn_AGV_Translate->sizePolicy().hasHeightForWidth());
        btn_AGV_Translate->setSizePolicy(sizePolicy14);
        btn_AGV_Translate->setMinimumSize(QSize(60, 0));
        btn_AGV_Translate->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_8->addWidget(btn_AGV_Translate);

        doubleSpinBox_AGV_Translate = new QDoubleSpinBox(groupBox_33);
        doubleSpinBox_AGV_Translate->setObjectName(QString::fromUtf8("doubleSpinBox_AGV_Translate"));
        doubleSpinBox_AGV_Translate->setMinimum(-90.000000000000000);
        doubleSpinBox_AGV_Translate->setMaximum(90.000000000000000);

        horizontalLayout_8->addWidget(doubleSpinBox_AGV_Translate);


        gridLayout_34->addLayout(horizontalLayout_8, 1, 2, 1, 1);

        btn_AGVToTarget = new QPushButton(groupBox_33);
        btn_AGVToTarget->setObjectName(QString::fromUtf8("btn_AGVToTarget"));
        btn_AGVToTarget->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVToTarget, 0, 4, 1, 1);

        btn_AGVToOrigin = new QPushButton(groupBox_33);
        btn_AGVToOrigin->setObjectName(QString::fromUtf8("btn_AGVToOrigin"));
        btn_AGVToOrigin->setMinimumSize(QSize(100, 0));

        gridLayout_34->addWidget(btn_AGVToOrigin, 1, 4, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btn_AGV_Turn = new QPushButton(groupBox_33);
        btn_AGV_Turn->setObjectName(QString::fromUtf8("btn_AGV_Turn"));
        sizePolicy9.setHeightForWidth(btn_AGV_Turn->sizePolicy().hasHeightForWidth());
        btn_AGV_Turn->setSizePolicy(sizePolicy9);
        btn_AGV_Turn->setMinimumSize(QSize(60, 0));
        btn_AGV_Turn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_9->addWidget(btn_AGV_Turn);

        doubleSpinBox_AGV_Turn = new QDoubleSpinBox(groupBox_33);
        doubleSpinBox_AGV_Turn->setObjectName(QString::fromUtf8("doubleSpinBox_AGV_Turn"));
        doubleSpinBox_AGV_Turn->setMinimum(-90.000000000000000);
        doubleSpinBox_AGV_Turn->setMaximum(90.000000000000000);

        horizontalLayout_9->addWidget(doubleSpinBox_AGV_Turn);


        gridLayout_34->addLayout(horizontalLayout_9, 1, 3, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        btn_AGV_Transverse = new QPushButton(groupBox_33);
        btn_AGV_Transverse->setObjectName(QString::fromUtf8("btn_AGV_Transverse"));
        sizePolicy14.setHeightForWidth(btn_AGV_Transverse->sizePolicy().hasHeightForWidth());
        btn_AGV_Transverse->setSizePolicy(sizePolicy14);
        btn_AGV_Transverse->setMinimumSize(QSize(60, 0));
        btn_AGV_Transverse->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_11->addWidget(btn_AGV_Transverse);

        doubleSpinBox_AGV_Transverse = new QDoubleSpinBox(groupBox_33);
        doubleSpinBox_AGV_Transverse->setObjectName(QString::fromUtf8("doubleSpinBox_AGV_Transverse"));
        doubleSpinBox_AGV_Transverse->setMinimum(-90.000000000000000);
        doubleSpinBox_AGV_Transverse->setMaximum(90.000000000000000);

        horizontalLayout_11->addWidget(doubleSpinBox_AGV_Transverse);


        gridLayout_34->addLayout(horizontalLayout_11, 0, 3, 1, 1);


        gridLayout_38->addLayout(gridLayout_34, 0, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        spinBox_Timeout = new QSpinBox(groupBox_33);
        spinBox_Timeout->setObjectName(QString::fromUtf8("spinBox_Timeout"));
        spinBox_Timeout->setMaximum(65535);
        spinBox_Timeout->setValue(6000);

        gridLayout_11->addWidget(spinBox_Timeout, 0, 7, 1, 1);

        label_134 = new QLabel(groupBox_33);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        sizePolicy10.setHeightForWidth(label_134->sizePolicy().hasHeightForWidth());
        label_134->setSizePolicy(sizePolicy10);
        label_134->setMaximumSize(QSize(70, 16777215));

        gridLayout_11->addWidget(label_134, 0, 6, 1, 1);

        label_128 = new QLabel(groupBox_33);
        label_128->setObjectName(QString::fromUtf8("label_128"));
        sizePolicy10.setHeightForWidth(label_128->sizePolicy().hasHeightForWidth());
        label_128->setSizePolicy(sizePolicy10);
        label_128->setMaximumSize(QSize(65, 16777215));

        gridLayout_11->addWidget(label_128, 0, 2, 1, 1);

        spinBox_Byte15 = new QSpinBox(groupBox_33);
        spinBox_Byte15->setObjectName(QString::fromUtf8("spinBox_Byte15"));
        spinBox_Byte15->setMaximum(65535);
        spinBox_Byte15->setValue(0);

        gridLayout_11->addWidget(spinBox_Byte15, 0, 5, 1, 1);

        spinBox_Type = new QSpinBox(groupBox_33);
        spinBox_Type->setObjectName(QString::fromUtf8("spinBox_Type"));
        spinBox_Type->setMaximum(65535);
        spinBox_Type->setValue(1100);

        gridLayout_11->addWidget(spinBox_Type, 0, 1, 1, 1);

        label_131 = new QLabel(groupBox_33);
        label_131->setObjectName(QString::fromUtf8("label_131"));
        sizePolicy10.setHeightForWidth(label_131->sizePolicy().hasHeightForWidth());
        label_131->setSizePolicy(sizePolicy10);
        label_131->setMaximumSize(QSize(60, 16777215));

        gridLayout_11->addWidget(label_131, 0, 4, 1, 1);

        label_130 = new QLabel(groupBox_33);
        label_130->setObjectName(QString::fromUtf8("label_130"));
        sizePolicy10.setHeightForWidth(label_130->sizePolicy().hasHeightForWidth());
        label_130->setSizePolicy(sizePolicy10);
        label_130->setMaximumSize(QSize(50, 16777215));

        gridLayout_11->addWidget(label_130, 0, 0, 1, 1);

        spinBox_Num = new QSpinBox(groupBox_33);
        spinBox_Num->setObjectName(QString::fromUtf8("spinBox_Num"));
        spinBox_Num->setMaximum(65535);
        spinBox_Num->setValue(0);

        gridLayout_11->addWidget(spinBox_Num, 0, 3, 1, 1);


        gridLayout_38->addLayout(gridLayout_11, 1, 0, 1, 1);

        groupBox_34 = new QGroupBox(groupBox_33);
        groupBox_34->setObjectName(QString::fromUtf8("groupBox_34"));
        verticalLayout_15 = new QVBoxLayout(groupBox_34);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        textEdit_Data = new QTextEdit(groupBox_34);
        textEdit_Data->setObjectName(QString::fromUtf8("textEdit_Data"));

        verticalLayout_15->addWidget(textEdit_Data);


        gridLayout_38->addWidget(groupBox_34, 2, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        btn_Send = new QPushButton(groupBox_33);
        btn_Send->setObjectName(QString::fromUtf8("btn_Send"));

        horizontalLayout_18->addWidget(btn_Send);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_3);

        btn_CancleTask = new QPushButton(groupBox_33);
        btn_CancleTask->setObjectName(QString::fromUtf8("btn_CancleTask"));

        horizontalLayout_18->addWidget(btn_CancleTask);


        gridLayout_38->addLayout(horizontalLayout_18, 3, 0, 1, 1);


        gridLayout_63->addWidget(groupBox_33, 0, 0, 1, 1);

        groupBox_36 = new QGroupBox(tab_3);
        groupBox_36->setObjectName(QString::fromUtf8("groupBox_36"));
        sizePolicy6.setHeightForWidth(groupBox_36->sizePolicy().hasHeightForWidth());
        groupBox_36->setSizePolicy(sizePolicy6);
        groupBox_36->setMaximumSize(QSize(16777215, 170));
        groupBox_36->setFont(font3);
        groupBox_36->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_16 = new QGridLayout(groupBox_36);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setSpacing(6);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        label_343 = new QLabel(groupBox_36);
        label_343->setObjectName(QString::fromUtf8("label_343"));
        sizePolicy5.setHeightForWidth(label_343->sizePolicy().hasHeightForWidth());
        label_343->setSizePolicy(sizePolicy5);
        label_343->setMinimumSize(QSize(80, 0));
        label_343->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_343, 0, 2, 1, 1);

        Distance3 = new QLineEdit(groupBox_36);
        Distance3->setObjectName(QString::fromUtf8("Distance3"));

        gridLayout_23->addWidget(Distance3, 2, 3, 1, 1);

        Distance0 = new QLineEdit(groupBox_36);
        Distance0->setObjectName(QString::fromUtf8("Distance0"));

        gridLayout_23->addWidget(Distance0, 0, 1, 1, 1);

        comboBoxPortNameDistance = new QComboBox(groupBox_36);
        comboBoxPortNameDistance->setObjectName(QString::fromUtf8("comboBoxPortNameDistance"));
        sizePolicy3.setHeightForWidth(comboBoxPortNameDistance->sizePolicy().hasHeightForWidth());
        comboBoxPortNameDistance->setSizePolicy(sizePolicy3);
        comboBoxPortNameDistance->setMinimumSize(QSize(20, 0));
        comboBoxPortNameDistance->setMaximumSize(QSize(200, 30));

        gridLayout_23->addWidget(comboBoxPortNameDistance, 1, 4, 1, 1);

        btn_ShowDistance = new QPushButton(groupBox_36);
        btn_ShowDistance->setObjectName(QString::fromUtf8("btn_ShowDistance"));
        sizePolicy14.setHeightForWidth(btn_ShowDistance->sizePolicy().hasHeightForWidth());
        btn_ShowDistance->setSizePolicy(sizePolicy14);
        btn_ShowDistance->setMaximumSize(QSize(200, 16777215));

        gridLayout_23->addWidget(btn_ShowDistance, 2, 4, 1, 1);

        btnOpenDistanceCOM = new QPushButton(groupBox_36);
        btnOpenDistanceCOM->setObjectName(QString::fromUtf8("btnOpenDistanceCOM"));
        sizePolicy14.setHeightForWidth(btnOpenDistanceCOM->sizePolicy().hasHeightForWidth());
        btnOpenDistanceCOM->setSizePolicy(sizePolicy14);
        btnOpenDistanceCOM->setMaximumSize(QSize(200, 16777215));

        gridLayout_23->addWidget(btnOpenDistanceCOM, 0, 4, 1, 1);

        label_341 = new QLabel(groupBox_36);
        label_341->setObjectName(QString::fromUtf8("label_341"));
        sizePolicy5.setHeightForWidth(label_341->sizePolicy().hasHeightForWidth());
        label_341->setSizePolicy(sizePolicy5);
        label_341->setMinimumSize(QSize(80, 0));
        label_341->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_341, 0, 0, 1, 1);

        label_342 = new QLabel(groupBox_36);
        label_342->setObjectName(QString::fromUtf8("label_342"));
        sizePolicy5.setHeightForWidth(label_342->sizePolicy().hasHeightForWidth());
        label_342->setSizePolicy(sizePolicy5);
        label_342->setMinimumSize(QSize(80, 0));
        label_342->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_342, 2, 0, 1, 1);

        label_344 = new QLabel(groupBox_36);
        label_344->setObjectName(QString::fromUtf8("label_344"));
        sizePolicy5.setHeightForWidth(label_344->sizePolicy().hasHeightForWidth());
        label_344->setSizePolicy(sizePolicy5);
        label_344->setMinimumSize(QSize(80, 0));
        label_344->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_344, 2, 2, 1, 1);

        Distance1 = new QLineEdit(groupBox_36);
        Distance1->setObjectName(QString::fromUtf8("Distance1"));

        gridLayout_23->addWidget(Distance1, 0, 3, 1, 1);

        Distance2 = new QLineEdit(groupBox_36);
        Distance2->setObjectName(QString::fromUtf8("Distance2"));

        gridLayout_23->addWidget(Distance2, 2, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_23, 0, 0, 1, 1);


        gridLayout_63->addWidget(groupBox_36, 3, 0, 1, 1);

        groupBox_35 = new QGroupBox(tab_3);
        groupBox_35->setObjectName(QString::fromUtf8("groupBox_35"));
        groupBox_35->setFont(font3);
        groupBox_35->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_28 = new QGridLayout(groupBox_35);
        gridLayout_28->setSpacing(6);
        gridLayout_28->setContentsMargins(11, 11, 11, 11);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        tag_diff_y = new QLineEdit(groupBox_35);
        tag_diff_y->setObjectName(QString::fromUtf8("tag_diff_y"));

        gridLayout_28->addWidget(tag_diff_y, 2, 7, 1, 1);

        label_155 = new QLabel(groupBox_35);
        label_155->setObjectName(QString::fromUtf8("label_155"));

        gridLayout_28->addWidget(label_155, 0, 6, 1, 1);

        lbl_handle = new QLabel(groupBox_35);
        lbl_handle->setObjectName(QString::fromUtf8("lbl_handle"));
        sizePolicy6.setHeightForWidth(lbl_handle->sizePolicy().hasHeightForWidth());
        lbl_handle->setSizePolicy(sizePolicy6);
        lbl_handle->setMinimumSize(QSize(15, 15));
        lbl_handle->setMaximumSize(QSize(15, 15));
        lbl_handle->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_28->addWidget(lbl_handle, 7, 5, 1, 1);

        packTotalCurrent = new QLineEdit(groupBox_35);
        packTotalCurrent->setObjectName(QString::fromUtf8("packTotalCurrent"));
        QSizePolicy sizePolicy15(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(packTotalCurrent->sizePolicy().hasHeightForWidth());
        packTotalCurrent->setSizePolicy(sizePolicy15);

        gridLayout_28->addWidget(packTotalCurrent, 1, 3, 1, 1);

        tag_diff_angle = new QLineEdit(groupBox_35);
        tag_diff_angle->setObjectName(QString::fromUtf8("tag_diff_angle"));

        gridLayout_28->addWidget(tag_diff_angle, 0, 7, 1, 1);

        label_148 = new QLabel(groupBox_35);
        label_148->setObjectName(QString::fromUtf8("label_148"));

        gridLayout_28->addWidget(label_148, 5, 4, 1, 1);

        packTotalVoltage = new QLineEdit(groupBox_35);
        packTotalVoltage->setObjectName(QString::fromUtf8("packTotalVoltage"));
        sizePolicy15.setHeightForWidth(packTotalVoltage->sizePolicy().hasHeightForWidth());
        packTotalVoltage->setSizePolicy(sizePolicy15);

        gridLayout_28->addWidget(packTotalVoltage, 1, 5, 1, 1);

        lineEdit_batt_level = new QLineEdit(groupBox_35);
        lineEdit_batt_level->setObjectName(QString::fromUtf8("lineEdit_batt_level"));
        sizePolicy15.setHeightForWidth(lineEdit_batt_level->sizePolicy().hasHeightForWidth());
        lineEdit_batt_level->setSizePolicy(sizePolicy15);

        gridLayout_28->addWidget(lineEdit_batt_level, 0, 1, 1, 1);

        label_140 = new QLabel(groupBox_35);
        label_140->setObjectName(QString::fromUtf8("label_140"));

        gridLayout_28->addWidget(label_140, 2, 0, 1, 1);

        label_149 = new QLabel(groupBox_35);
        label_149->setObjectName(QString::fromUtf8("label_149"));

        gridLayout_28->addWidget(label_149, 5, 0, 1, 1);

        label_166 = new QLabel(groupBox_35);
        label_166->setObjectName(QString::fromUtf8("label_166"));

        gridLayout_28->addWidget(label_166, 7, 2, 1, 1);

        label_165 = new QLabel(groupBox_35);
        label_165->setObjectName(QString::fromUtf8("label_165"));

        gridLayout_28->addWidget(label_165, 7, 0, 1, 1);

        label_144 = new QLabel(groupBox_35);
        label_144->setObjectName(QString::fromUtf8("label_144"));

        gridLayout_28->addWidget(label_144, 4, 0, 1, 1);

        lineEdit_brake = new QLineEdit(groupBox_35);
        lineEdit_brake->setObjectName(QString::fromUtf8("lineEdit_brake"));

        gridLayout_28->addWidget(lineEdit_brake, 4, 3, 1, 1);

        label_164 = new QLabel(groupBox_35);
        label_164->setObjectName(QString::fromUtf8("label_164"));

        gridLayout_28->addWidget(label_164, 2, 6, 1, 1);

        lineEdit_driver_emc = new QLineEdit(groupBox_35);
        lineEdit_driver_emc->setObjectName(QString::fromUtf8("lineEdit_driver_emc"));

        gridLayout_28->addWidget(lineEdit_driver_emc, 5, 1, 1, 1);

        label_137 = new QLabel(groupBox_35);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        sizePolicy5.setHeightForWidth(label_137->sizePolicy().hasHeightForWidth());
        label_137->setSizePolicy(sizePolicy5);
        label_137->setMinimumSize(QSize(80, 0));
        label_137->setScaledContents(false);

        gridLayout_28->addWidget(label_137, 1, 0, 1, 1);

        tag_diff_x = new QLineEdit(groupBox_35);
        tag_diff_x->setObjectName(QString::fromUtf8("tag_diff_x"));

        gridLayout_28->addWidget(tag_diff_x, 1, 7, 1, 1);

        label_141 = new QLabel(groupBox_35);
        label_141->setObjectName(QString::fromUtf8("label_141"));

        gridLayout_28->addWidget(label_141, 2, 2, 1, 1);

        lineEdit_loadmap_status = new QLineEdit(groupBox_35);
        lineEdit_loadmap_status->setObjectName(QString::fromUtf8("lineEdit_loadmap_status"));

        gridLayout_28->addWidget(lineEdit_loadmap_status, 7, 1, 1, 1);

        lineEdit_current_station = new QLineEdit(groupBox_35);
        lineEdit_current_station->setObjectName(QString::fromUtf8("lineEdit_current_station"));

        gridLayout_28->addWidget(lineEdit_current_station, 4, 1, 1, 1);

        label_138 = new QLabel(groupBox_35);
        label_138->setObjectName(QString::fromUtf8("label_138"));

        gridLayout_28->addWidget(label_138, 0, 2, 1, 1);

        label_145 = new QLabel(groupBox_35);
        label_145->setObjectName(QString::fromUtf8("label_145"));

        gridLayout_28->addWidget(label_145, 4, 2, 1, 1);

        label_154 = new QLabel(groupBox_35);
        label_154->setObjectName(QString::fromUtf8("label_154"));
        sizePolicy5.setHeightForWidth(label_154->sizePolicy().hasHeightForWidth());
        label_154->setSizePolicy(sizePolicy5);
        label_154->setMinimumSize(QSize(80, 0));
        label_154->setScaledContents(false);

        gridLayout_28->addWidget(label_154, 1, 4, 1, 1);

        lineEdit_emergency = new QLineEdit(groupBox_35);
        lineEdit_emergency->setObjectName(QString::fromUtf8("lineEdit_emergency"));

        gridLayout_28->addWidget(lineEdit_emergency, 2, 3, 1, 1);

        remainingmAh = new QLineEdit(groupBox_35);
        remainingmAh->setObjectName(QString::fromUtf8("remainingmAh"));
        sizePolicy15.setHeightForWidth(remainingmAh->sizePolicy().hasHeightForWidth());
        remainingmAh->setSizePolicy(sizePolicy15);

        gridLayout_28->addWidget(remainingmAh, 1, 1, 1, 1);

        label_160 = new QLabel(groupBox_35);
        label_160->setObjectName(QString::fromUtf8("label_160"));

        gridLayout_28->addWidget(label_160, 1, 6, 1, 1);

        label_139 = new QLabel(groupBox_35);
        label_139->setObjectName(QString::fromUtf8("label_139"));

        gridLayout_28->addWidget(label_139, 0, 4, 1, 1);

        lineEdit_taskStatus = new QLineEdit(groupBox_35);
        lineEdit_taskStatus->setObjectName(QString::fromUtf8("lineEdit_taskStatus"));

        gridLayout_28->addWidget(lineEdit_taskStatus, 2, 1, 1, 1);

        label_152 = new QLabel(groupBox_35);
        label_152->setObjectName(QString::fromUtf8("label_152"));

        gridLayout_28->addWidget(label_152, 7, 4, 1, 1);

        label_147 = new QLabel(groupBox_35);
        label_147->setObjectName(QString::fromUtf8("label_147"));

        gridLayout_28->addWidget(label_147, 4, 4, 1, 1);

        label_136 = new QLabel(groupBox_35);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        sizePolicy5.setHeightForWidth(label_136->sizePolicy().hasHeightForWidth());
        label_136->setSizePolicy(sizePolicy5);
        label_136->setMinimumSize(QSize(80, 0));
        label_136->setScaledContents(false);

        gridLayout_28->addWidget(label_136, 0, 0, 1, 1);

        label_142 = new QLabel(groupBox_35);
        label_142->setObjectName(QString::fromUtf8("label_142"));

        gridLayout_28->addWidget(label_142, 2, 4, 1, 1);

        lineEdit_block_reason = new QLineEdit(groupBox_35);
        lineEdit_block_reason->setObjectName(QString::fromUtf8("lineEdit_block_reason"));

        gridLayout_28->addWidget(lineEdit_block_reason, 0, 5, 1, 1);

        lineEdit_electric = new QLineEdit(groupBox_35);
        lineEdit_electric->setObjectName(QString::fromUtf8("lineEdit_electric"));

        gridLayout_28->addWidget(lineEdit_electric, 5, 3, 1, 1);

        lineEdit_agv_blocked = new QLineEdit(groupBox_35);
        lineEdit_agv_blocked->setObjectName(QString::fromUtf8("lineEdit_agv_blocked"));

        gridLayout_28->addWidget(lineEdit_agv_blocked, 0, 3, 1, 1);

        label_151 = new QLabel(groupBox_35);
        label_151->setObjectName(QString::fromUtf8("label_151"));

        gridLayout_28->addWidget(label_151, 5, 2, 1, 1);

        lineEdit_task_type = new QLineEdit(groupBox_35);
        lineEdit_task_type->setObjectName(QString::fromUtf8("lineEdit_task_type"));

        gridLayout_28->addWidget(lineEdit_task_type, 4, 5, 1, 1);

        label_143 = new QLabel(groupBox_35);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        sizePolicy5.setHeightForWidth(label_143->sizePolicy().hasHeightForWidth());
        label_143->setSizePolicy(sizePolicy5);
        label_143->setMinimumSize(QSize(80, 0));
        label_143->setScaledContents(false);

        gridLayout_28->addWidget(label_143, 1, 2, 1, 1);

        lineEdit_target_dist = new QLineEdit(groupBox_35);
        lineEdit_target_dist->setObjectName(QString::fromUtf8("lineEdit_target_dist"));

        gridLayout_28->addWidget(lineEdit_target_dist, 5, 5, 1, 1);

        lineEdit_reloc_status = new QLineEdit(groupBox_35);
        lineEdit_reloc_status->setObjectName(QString::fromUtf8("lineEdit_reloc_status"));

        gridLayout_28->addWidget(lineEdit_reloc_status, 7, 3, 1, 1);

        lineEdit_soft_emc = new QLineEdit(groupBox_35);
        lineEdit_soft_emc->setObjectName(QString::fromUtf8("lineEdit_soft_emc"));

        gridLayout_28->addWidget(lineEdit_soft_emc, 2, 5, 1, 1);

        btn_AGVPositionAdjust = new QPushButton(groupBox_35);
        btn_AGVPositionAdjust->setObjectName(QString::fromUtf8("btn_AGVPositionAdjust"));
        sizePolicy14.setHeightForWidth(btn_AGVPositionAdjust->sizePolicy().hasHeightForWidth());
        btn_AGVPositionAdjust->setSizePolicy(sizePolicy14);
        btn_AGVPositionAdjust->setMinimumSize(QSize(50, 0));
        btn_AGVPositionAdjust->setMaximumSize(QSize(180, 16777215));

        gridLayout_28->addWidget(btn_AGVPositionAdjust, 4, 6, 1, 2);

        btn_Battery2 = new QPushButton(groupBox_35);
        btn_Battery2->setObjectName(QString::fromUtf8("btn_Battery2"));
        sizePolicy14.setHeightForWidth(btn_Battery2->sizePolicy().hasHeightForWidth());
        btn_Battery2->setSizePolicy(sizePolicy14);
        btn_Battery2->setMinimumSize(QSize(50, 0));
        btn_Battery2->setMaximumSize(QSize(180, 16777215));

        gridLayout_28->addWidget(btn_Battery2, 5, 6, 1, 2);


        gridLayout_63->addWidget(groupBox_35, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_35 = new QGridLayout(tab_7);
        gridLayout_35->setSpacing(6);
        gridLayout_35->setContentsMargins(11, 11, 11, 11);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        groupBox_20 = new QGroupBox(tab_7);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        sizePolicy4.setHeightForWidth(groupBox_20->sizePolicy().hasHeightForWidth());
        groupBox_20->setSizePolicy(sizePolicy4);
        groupBox_20->setMinimumSize(QSize(800, 0));
        groupBox_20->setMaximumSize(QSize(900, 120));
        groupBox_20->setFont(font3);
        groupBox_20->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_5 = new QGridLayout(groupBox_20);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_163 = new QLabel(groupBox_20);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        sizePolicy5.setHeightForWidth(label_163->sizePolicy().hasHeightForWidth());
        label_163->setSizePolicy(sizePolicy5);
        label_163->setMaximumSize(QSize(120, 16777215));
        label_163->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_163, 0, 0, 1, 1);

        AngleX = new QLineEdit(groupBox_20);
        AngleX->setObjectName(QString::fromUtf8("AngleX"));
        sizePolicy9.setHeightForWidth(AngleX->sizePolicy().hasHeightForWidth());
        AngleX->setSizePolicy(sizePolicy9);
        AngleX->setMinimumSize(QSize(305, 0));
        AngleX->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(AngleX, 0, 1, 1, 1);

        btnOpenAngleCOM = new QPushButton(groupBox_20);
        btnOpenAngleCOM->setObjectName(QString::fromUtf8("btnOpenAngleCOM"));
        sizePolicy5.setHeightForWidth(btnOpenAngleCOM->sizePolicy().hasHeightForWidth());
        btnOpenAngleCOM->setSizePolicy(sizePolicy5);
        btnOpenAngleCOM->setMinimumSize(QSize(350, 0));
        btnOpenAngleCOM->setMaximumSize(QSize(200, 16777215));

        gridLayout_5->addWidget(btnOpenAngleCOM, 0, 2, 1, 1);

        label_340 = new QLabel(groupBox_20);
        label_340->setObjectName(QString::fromUtf8("label_340"));
        QSizePolicy sizePolicy16(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy16.setHorizontalStretch(0);
        sizePolicy16.setVerticalStretch(0);
        sizePolicy16.setHeightForWidth(label_340->sizePolicy().hasHeightForWidth());
        label_340->setSizePolicy(sizePolicy16);
        label_340->setMinimumSize(QSize(80, 0));
        label_340->setMaximumSize(QSize(80, 16777215));

        gridLayout_5->addWidget(label_340, 1, 0, 1, 1);

        AngleY = new QLineEdit(groupBox_20);
        AngleY->setObjectName(QString::fromUtf8("AngleY"));
        sizePolicy9.setHeightForWidth(AngleY->sizePolicy().hasHeightForWidth());
        AngleY->setSizePolicy(sizePolicy9);
        AngleY->setMinimumSize(QSize(305, 0));
        AngleY->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(AngleY, 1, 1, 1, 1);

        comboBoxPortNameAngle = new QComboBox(groupBox_20);
        comboBoxPortNameAngle->setObjectName(QString::fromUtf8("comboBoxPortNameAngle"));
        sizePolicy5.setHeightForWidth(comboBoxPortNameAngle->sizePolicy().hasHeightForWidth());
        comboBoxPortNameAngle->setSizePolicy(sizePolicy5);
        comboBoxPortNameAngle->setMinimumSize(QSize(350, 0));
        comboBoxPortNameAngle->setMaximumSize(QSize(200, 30));

        gridLayout_5->addWidget(comboBoxPortNameAngle, 1, 2, 1, 1);

        label_330 = new QLabel(groupBox_20);
        label_330->setObjectName(QString::fromUtf8("label_330"));
        sizePolicy16.setHeightForWidth(label_330->sizePolicy().hasHeightForWidth());
        label_330->setSizePolicy(sizePolicy16);
        label_330->setMaximumSize(QSize(90, 16777215));

        gridLayout_5->addWidget(label_330, 2, 0, 1, 1);

        horizontalLayout_124 = new QHBoxLayout();
        horizontalLayout_124->setSpacing(6);
        horizontalLayout_124->setObjectName(QString::fromUtf8("horizontalLayout_124"));
        lbl_SymbolAll = new QLabel(groupBox_20);
        lbl_SymbolAll->setObjectName(QString::fromUtf8("lbl_SymbolAll"));
        sizePolicy2.setHeightForWidth(lbl_SymbolAll->sizePolicy().hasHeightForWidth());
        lbl_SymbolAll->setSizePolicy(sizePolicy2);
        lbl_SymbolAll->setMinimumSize(QSize(15, 15));
        lbl_SymbolAll->setMaximumSize(QSize(15, 15));
        lbl_SymbolAll->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_124->addWidget(lbl_SymbolAll);


        gridLayout_5->addLayout(horizontalLayout_124, 2, 1, 1, 1);

        btn_ShowAngle = new QPushButton(groupBox_20);
        btn_ShowAngle->setObjectName(QString::fromUtf8("btn_ShowAngle"));
        sizePolicy4.setHeightForWidth(btn_ShowAngle->sizePolicy().hasHeightForWidth());
        btn_ShowAngle->setSizePolicy(sizePolicy4);
        btn_ShowAngle->setMinimumSize(QSize(350, 0));
        btn_ShowAngle->setMaximumSize(QSize(200, 16777215));

        gridLayout_5->addWidget(btn_ShowAngle, 2, 2, 1, 1);


        gridLayout_35->addWidget(groupBox_20, 4, 0, 1, 1);

        groupBox_19 = new QGroupBox(tab_7);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        sizePolicy6.setHeightForWidth(groupBox_19->sizePolicy().hasHeightForWidth());
        groupBox_19->setSizePolicy(sizePolicy6);
        groupBox_19->setMaximumSize(QSize(16777215, 190));
        groupBox_19->setFont(font3);
        groupBox_19->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_21 = new QGridLayout(groupBox_19);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setHorizontalSpacing(35);
        gridLayout_15->setVerticalSpacing(20);
        label_157 = new QLabel(groupBox_19);
        label_157->setObjectName(QString::fromUtf8("label_157"));
        sizePolicy10.setHeightForWidth(label_157->sizePolicy().hasHeightForWidth());
        label_157->setSizePolicy(sizePolicy10);
        label_157->setMaximumSize(QSize(120, 16777215));
        label_157->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_157, 0, 0, 1, 1);

        label_240 = new QLabel(groupBox_19);
        label_240->setObjectName(QString::fromUtf8("label_240"));
        sizePolicy6.setHeightForWidth(label_240->sizePolicy().hasHeightForWidth());
        label_240->setSizePolicy(sizePolicy6);
        label_240->setMaximumSize(QSize(40, 16777215));

        gridLayout_15->addWidget(label_240, 0, 1, 1, 1);

        lbl_Symbol0 = new QLabel(groupBox_19);
        lbl_Symbol0->setObjectName(QString::fromUtf8("lbl_Symbol0"));
        sizePolicy2.setHeightForWidth(lbl_Symbol0->sizePolicy().hasHeightForWidth());
        lbl_Symbol0->setSizePolicy(sizePolicy2);
        lbl_Symbol0->setMinimumSize(QSize(15, 15));
        lbl_Symbol0->setMaximumSize(QSize(15, 15));
        lbl_Symbol0->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_15->addWidget(lbl_Symbol0, 0, 2, 1, 1);

        label_333 = new QLabel(groupBox_19);
        label_333->setObjectName(QString::fromUtf8("label_333"));
        sizePolicy16.setHeightForWidth(label_333->sizePolicy().hasHeightForWidth());
        label_333->setSizePolicy(sizePolicy16);
        label_333->setMinimumSize(QSize(80, 0));
        label_333->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_333, 0, 3, 1, 1);

        sensor0 = new QLineEdit(groupBox_19);
        sensor0->setObjectName(QString::fromUtf8("sensor0"));
        QSizePolicy sizePolicy17(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy17.setHorizontalStretch(0);
        sizePolicy17.setVerticalStretch(0);
        sizePolicy17.setHeightForWidth(sensor0->sizePolicy().hasHeightForWidth());
        sensor0->setSizePolicy(sizePolicy17);
        sensor0->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(sensor0, 0, 4, 1, 1);

        label_337 = new QLabel(groupBox_19);
        label_337->setObjectName(QString::fromUtf8("label_337"));
        sizePolicy16.setHeightForWidth(label_337->sizePolicy().hasHeightForWidth());
        label_337->setSizePolicy(sizePolicy16);
        label_337->setMinimumSize(QSize(80, 0));
        label_337->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_337, 0, 5, 1, 1);

        Current0 = new QLineEdit(groupBox_19);
        Current0->setObjectName(QString::fromUtf8("Current0"));
        sizePolicy17.setHeightForWidth(Current0->sizePolicy().hasHeightForWidth());
        Current0->setSizePolicy(sizePolicy17);
        Current0->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(Current0, 0, 6, 1, 1);

        btnOpenForceCOM = new QPushButton(groupBox_19);
        btnOpenForceCOM->setObjectName(QString::fromUtf8("btnOpenForceCOM"));
        sizePolicy6.setHeightForWidth(btnOpenForceCOM->sizePolicy().hasHeightForWidth());
        btnOpenForceCOM->setSizePolicy(sizePolicy6);
        btnOpenForceCOM->setMaximumSize(QSize(150, 16777215));

        gridLayout_15->addWidget(btnOpenForceCOM, 0, 7, 1, 1);

        label_156 = new QLabel(groupBox_19);
        label_156->setObjectName(QString::fromUtf8("label_156"));
        sizePolicy10.setHeightForWidth(label_156->sizePolicy().hasHeightForWidth());
        label_156->setSizePolicy(sizePolicy10);
        label_156->setMaximumSize(QSize(120, 16777215));
        label_156->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_156, 1, 0, 1, 1);

        label_244 = new QLabel(groupBox_19);
        label_244->setObjectName(QString::fromUtf8("label_244"));
        sizePolicy16.setHeightForWidth(label_244->sizePolicy().hasHeightForWidth());
        label_244->setSizePolicy(sizePolicy16);
        label_244->setMaximumSize(QSize(40, 16777215));

        gridLayout_15->addWidget(label_244, 1, 1, 1, 1);

        lbl_Symbol1 = new QLabel(groupBox_19);
        lbl_Symbol1->setObjectName(QString::fromUtf8("lbl_Symbol1"));
        sizePolicy13.setHeightForWidth(lbl_Symbol1->sizePolicy().hasHeightForWidth());
        lbl_Symbol1->setSizePolicy(sizePolicy13);
        lbl_Symbol1->setMinimumSize(QSize(0, 15));
        lbl_Symbol1->setMaximumSize(QSize(15, 15));
        lbl_Symbol1->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_15->addWidget(lbl_Symbol1, 1, 2, 1, 1);

        label_336 = new QLabel(groupBox_19);
        label_336->setObjectName(QString::fromUtf8("label_336"));
        sizePolicy16.setHeightForWidth(label_336->sizePolicy().hasHeightForWidth());
        label_336->setSizePolicy(sizePolicy16);
        label_336->setMinimumSize(QSize(80, 0));
        label_336->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_336, 1, 3, 1, 1);

        sensor1 = new QLineEdit(groupBox_19);
        sensor1->setObjectName(QString::fromUtf8("sensor1"));
        sizePolicy17.setHeightForWidth(sensor1->sizePolicy().hasHeightForWidth());
        sensor1->setSizePolicy(sizePolicy17);
        sensor1->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(sensor1, 1, 4, 1, 1);

        label_326 = new QLabel(groupBox_19);
        label_326->setObjectName(QString::fromUtf8("label_326"));
        sizePolicy16.setHeightForWidth(label_326->sizePolicy().hasHeightForWidth());
        label_326->setSizePolicy(sizePolicy16);
        label_326->setMinimumSize(QSize(80, 0));
        label_326->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_326, 1, 5, 1, 1);

        Current1 = new QLineEdit(groupBox_19);
        Current1->setObjectName(QString::fromUtf8("Current1"));
        sizePolicy17.setHeightForWidth(Current1->sizePolicy().hasHeightForWidth());
        Current1->setSizePolicy(sizePolicy17);
        Current1->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(Current1, 1, 6, 1, 1);

        comboBoxPortNameForce = new QComboBox(groupBox_19);
        comboBoxPortNameForce->setObjectName(QString::fromUtf8("comboBoxPortNameForce"));
        sizePolicy6.setHeightForWidth(comboBoxPortNameForce->sizePolicy().hasHeightForWidth());
        comboBoxPortNameForce->setSizePolicy(sizePolicy6);
        comboBoxPortNameForce->setMaximumSize(QSize(150, 30));

        gridLayout_15->addWidget(comboBoxPortNameForce, 1, 7, 1, 1);

        label_158 = new QLabel(groupBox_19);
        label_158->setObjectName(QString::fromUtf8("label_158"));
        sizePolicy10.setHeightForWidth(label_158->sizePolicy().hasHeightForWidth());
        label_158->setSizePolicy(sizePolicy10);
        label_158->setMaximumSize(QSize(120, 16777215));
        label_158->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_158, 2, 0, 1, 1);

        label_242 = new QLabel(groupBox_19);
        label_242->setObjectName(QString::fromUtf8("label_242"));
        sizePolicy16.setHeightForWidth(label_242->sizePolicy().hasHeightForWidth());
        label_242->setSizePolicy(sizePolicy16);
        label_242->setMaximumSize(QSize(40, 16777215));

        gridLayout_15->addWidget(label_242, 2, 1, 1, 1);

        lbl_Symbol2 = new QLabel(groupBox_19);
        lbl_Symbol2->setObjectName(QString::fromUtf8("lbl_Symbol2"));
        sizePolicy13.setHeightForWidth(lbl_Symbol2->sizePolicy().hasHeightForWidth());
        lbl_Symbol2->setSizePolicy(sizePolicy13);
        lbl_Symbol2->setMinimumSize(QSize(0, 15));
        lbl_Symbol2->setMaximumSize(QSize(15, 15));
        lbl_Symbol2->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_15->addWidget(lbl_Symbol2, 2, 2, 1, 1);

        label_334 = new QLabel(groupBox_19);
        label_334->setObjectName(QString::fromUtf8("label_334"));
        sizePolicy6.setHeightForWidth(label_334->sizePolicy().hasHeightForWidth());
        label_334->setSizePolicy(sizePolicy6);
        label_334->setMinimumSize(QSize(80, 0));
        label_334->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_334, 2, 3, 1, 1);

        sensor2 = new QLineEdit(groupBox_19);
        sensor2->setObjectName(QString::fromUtf8("sensor2"));
        sizePolicy17.setHeightForWidth(sensor2->sizePolicy().hasHeightForWidth());
        sensor2->setSizePolicy(sizePolicy17);
        sensor2->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(sensor2, 2, 4, 1, 1);

        label_332 = new QLabel(groupBox_19);
        label_332->setObjectName(QString::fromUtf8("label_332"));
        sizePolicy6.setHeightForWidth(label_332->sizePolicy().hasHeightForWidth());
        label_332->setSizePolicy(sizePolicy6);
        label_332->setMinimumSize(QSize(80, 0));
        label_332->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_332, 2, 5, 1, 1);

        Current2 = new QLineEdit(groupBox_19);
        Current2->setObjectName(QString::fromUtf8("Current2"));
        sizePolicy17.setHeightForWidth(Current2->sizePolicy().hasHeightForWidth());
        Current2->setSizePolicy(sizePolicy17);
        Current2->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(Current2, 2, 6, 1, 1);

        btn_ShowForce = new QPushButton(groupBox_19);
        btn_ShowForce->setObjectName(QString::fromUtf8("btn_ShowForce"));
        sizePolicy14.setHeightForWidth(btn_ShowForce->sizePolicy().hasHeightForWidth());
        btn_ShowForce->setSizePolicy(sizePolicy14);
        btn_ShowForce->setMaximumSize(QSize(150, 16777215));

        gridLayout_15->addWidget(btn_ShowForce, 2, 7, 1, 1);

        label_159 = new QLabel(groupBox_19);
        label_159->setObjectName(QString::fromUtf8("label_159"));
        sizePolicy3.setHeightForWidth(label_159->sizePolicy().hasHeightForWidth());
        label_159->setSizePolicy(sizePolicy3);
        label_159->setMaximumSize(QSize(120, 16777215));
        label_159->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_159, 3, 0, 1, 1);

        label_246 = new QLabel(groupBox_19);
        label_246->setObjectName(QString::fromUtf8("label_246"));
        sizePolicy6.setHeightForWidth(label_246->sizePolicy().hasHeightForWidth());
        label_246->setSizePolicy(sizePolicy6);
        label_246->setMaximumSize(QSize(40, 16777215));

        gridLayout_15->addWidget(label_246, 3, 1, 1, 1);

        lbl_Symbol3 = new QLabel(groupBox_19);
        lbl_Symbol3->setObjectName(QString::fromUtf8("lbl_Symbol3"));
        sizePolicy13.setHeightForWidth(lbl_Symbol3->sizePolicy().hasHeightForWidth());
        lbl_Symbol3->setSizePolicy(sizePolicy13);
        lbl_Symbol3->setMinimumSize(QSize(0, 15));
        lbl_Symbol3->setMaximumSize(QSize(15, 15));
        lbl_Symbol3->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_15->addWidget(lbl_Symbol3, 3, 2, 1, 1);

        label_338 = new QLabel(groupBox_19);
        label_338->setObjectName(QString::fromUtf8("label_338"));
        sizePolicy16.setHeightForWidth(label_338->sizePolicy().hasHeightForWidth());
        label_338->setSizePolicy(sizePolicy16);
        label_338->setMinimumSize(QSize(80, 0));
        label_338->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_338, 3, 3, 1, 1);

        sensor3 = new QLineEdit(groupBox_19);
        sensor3->setObjectName(QString::fromUtf8("sensor3"));
        sizePolicy17.setHeightForWidth(sensor3->sizePolicy().hasHeightForWidth());
        sensor3->setSizePolicy(sizePolicy17);
        sensor3->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(sensor3, 3, 4, 1, 1);

        label_335 = new QLabel(groupBox_19);
        label_335->setObjectName(QString::fromUtf8("label_335"));
        sizePolicy16.setHeightForWidth(label_335->sizePolicy().hasHeightForWidth());
        label_335->setSizePolicy(sizePolicy16);
        label_335->setMinimumSize(QSize(80, 0));
        label_335->setMaximumSize(QSize(80, 16777215));

        gridLayout_15->addWidget(label_335, 3, 5, 1, 1);

        Current3 = new QLineEdit(groupBox_19);
        Current3->setObjectName(QString::fromUtf8("Current3"));
        sizePolicy17.setHeightForWidth(Current3->sizePolicy().hasHeightForWidth());
        Current3->setSizePolicy(sizePolicy17);
        Current3->setMaximumSize(QSize(100, 16777215));

        gridLayout_15->addWidget(Current3, 3, 6, 1, 1);

        btn_ShowCurrent = new QPushButton(groupBox_19);
        btn_ShowCurrent->setObjectName(QString::fromUtf8("btn_ShowCurrent"));
        sizePolicy14.setHeightForWidth(btn_ShowCurrent->sizePolicy().hasHeightForWidth());
        btn_ShowCurrent->setSizePolicy(sizePolicy14);
        btn_ShowCurrent->setMaximumSize(QSize(150, 16777215));

        gridLayout_15->addWidget(btn_ShowCurrent, 3, 7, 1, 1);


        gridLayout_21->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_35->addWidget(groupBox_19, 3, 0, 1, 1);

        groupBox_14 = new QGroupBox(tab_7);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        sizePolicy7.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy7);
        groupBox_14->setMinimumSize(QSize(0, 220));
        groupBox_14->setMaximumSize(QSize(16777215, 270));
        groupBox_14->setFont(font3);
        groupBox_14->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_19 = new QGridLayout(groupBox_14);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setSpacing(6);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_18->setHorizontalSpacing(20);
        lbl_LevelPosi1 = new QLabel(groupBox_14);
        lbl_LevelPosi1->setObjectName(QString::fromUtf8("lbl_LevelPosi1"));
        sizePolicy6.setHeightForWidth(lbl_LevelPosi1->sizePolicy().hasHeightForWidth());
        lbl_LevelPosi1->setSizePolicy(sizePolicy6);
        lbl_LevelPosi1->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(lbl_LevelPosi1, 4, 2, 3, 1);

        lblAxisStatusColor3 = new QLabel(groupBox_14);
        lblAxisStatusColor3->setObjectName(QString::fromUtf8("lblAxisStatusColor3"));
        sizePolicy4.setHeightForWidth(lblAxisStatusColor3->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor3->setSizePolicy(sizePolicy4);
        lblAxisStatusColor3->setMinimumSize(QSize(15, 0));
        lblAxisStatusColor3->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor3->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_18->addWidget(lblAxisStatusColor3, 9, 2, 1, 1);

        label_266 = new QLabel(groupBox_14);
        label_266->setObjectName(QString::fromUtf8("label_266"));
        sizePolicy6.setHeightForWidth(label_266->sizePolicy().hasHeightForWidth());
        label_266->setSizePolicy(sizePolicy6);
        label_266->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(label_266, 8, 1, 1, 1);

        btnZero0_4 = new QPushButton(groupBox_14);
        btnZero0_4->setObjectName(QString::fromUtf8("btnZero0_4"));
        sizePolicy3.setHeightForWidth(btnZero0_4->sizePolicy().hasHeightForWidth());
        btnZero0_4->setSizePolicy(sizePolicy3);
        btnZero0_4->setMaximumSize(QSize(500, 16777215));

        gridLayout_18->addWidget(btnZero0_4, 0, 8, 7, 1);

        lbl_LevelPosi3 = new QLabel(groupBox_14);
        lbl_LevelPosi3->setObjectName(QString::fromUtf8("lbl_LevelPosi3"));
        sizePolicy6.setHeightForWidth(lbl_LevelPosi3->sizePolicy().hasHeightForWidth());
        lbl_LevelPosi3->setSizePolicy(sizePolicy6);
        lbl_LevelPosi3->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(lbl_LevelPosi3, 10, 2, 1, 1);

        label_150 = new QLabel(groupBox_14);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        sizePolicy5.setHeightForWidth(label_150->sizePolicy().hasHeightForWidth());
        label_150->setSizePolicy(sizePolicy5);
        label_150->setMinimumSize(QSize(80, 0));
        label_150->setMaximumSize(QSize(60, 16777215));
        label_150->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_150, 9, 0, 2, 1);

        label_265 = new QLabel(groupBox_14);
        label_265->setObjectName(QString::fromUtf8("label_265"));
        sizePolicy6.setHeightForWidth(label_265->sizePolicy().hasHeightForWidth());
        label_265->setSizePolicy(sizePolicy6);
        label_265->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(label_265, 4, 1, 3, 1);

        lblAxisStatusColor1 = new QLabel(groupBox_14);
        lblAxisStatusColor1->setObjectName(QString::fromUtf8("lblAxisStatusColor1"));
        sizePolicy4.setHeightForWidth(lblAxisStatusColor1->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor1->setSizePolicy(sizePolicy4);
        lblAxisStatusColor1->setMinimumSize(QSize(15, 0));
        lblAxisStatusColor1->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor1->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_18->addWidget(lblAxisStatusColor1, 3, 2, 1, 1);

        label_243 = new QLabel(groupBox_14);
        label_243->setObjectName(QString::fromUtf8("label_243"));
        sizePolicy10.setHeightForWidth(label_243->sizePolicy().hasHeightForWidth());
        label_243->setSizePolicy(sizePolicy10);
        label_243->setMaximumSize(QSize(60, 16777215));

        gridLayout_18->addWidget(label_243, 9, 1, 1, 1);

        label_146 = new QLabel(groupBox_14);
        label_146->setObjectName(QString::fromUtf8("label_146"));
        sizePolicy5.setHeightForWidth(label_146->sizePolicy().hasHeightForWidth());
        label_146->setSizePolicy(sizePolicy5);
        label_146->setMinimumSize(QSize(80, 0));
        label_146->setMaximumSize(QSize(60, 16777215));
        label_146->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_146, 0, 0, 3, 1);

        label_245 = new QLabel(groupBox_14);
        label_245->setObjectName(QString::fromUtf8("label_245"));
        sizePolicy10.setHeightForWidth(label_245->sizePolicy().hasHeightForWidth());
        label_245->setSizePolicy(sizePolicy10);
        label_245->setMaximumSize(QSize(60, 16777215));

        gridLayout_18->addWidget(label_245, 7, 1, 1, 1);

        btnInit0_4 = new QPushButton(groupBox_14);
        btnInit0_4->setObjectName(QString::fromUtf8("btnInit0_4"));
        sizePolicy3.setHeightForWidth(btnInit0_4->sizePolicy().hasHeightForWidth());
        btnInit0_4->setSizePolicy(sizePolicy3);
        btnInit0_4->setMaximumSize(QSize(500, 16777215));

        gridLayout_18->addWidget(btnInit0_4, 7, 8, 4, 1);

        label_267 = new QLabel(groupBox_14);
        label_267->setObjectName(QString::fromUtf8("label_267"));
        sizePolicy6.setHeightForWidth(label_267->sizePolicy().hasHeightForWidth());
        label_267->setSizePolicy(sizePolicy6);
        label_267->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(label_267, 10, 1, 1, 1);

        lbl_LevelPosi2 = new QLabel(groupBox_14);
        lbl_LevelPosi2->setObjectName(QString::fromUtf8("lbl_LevelPosi2"));
        sizePolicy6.setHeightForWidth(lbl_LevelPosi2->sizePolicy().hasHeightForWidth());
        lbl_LevelPosi2->setSizePolicy(sizePolicy6);
        lbl_LevelPosi2->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(lbl_LevelPosi2, 8, 2, 1, 1);

        lblAxisStatusColor2 = new QLabel(groupBox_14);
        lblAxisStatusColor2->setObjectName(QString::fromUtf8("lblAxisStatusColor2"));
        sizePolicy4.setHeightForWidth(lblAxisStatusColor2->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor2->setSizePolicy(sizePolicy4);
        lblAxisStatusColor2->setMinimumSize(QSize(15, 0));
        lblAxisStatusColor2->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor2->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_18->addWidget(lblAxisStatusColor2, 7, 2, 1, 1);

        label_161 = new QLabel(groupBox_14);
        label_161->setObjectName(QString::fromUtf8("label_161"));
        sizePolicy5.setHeightForWidth(label_161->sizePolicy().hasHeightForWidth());
        label_161->setSizePolicy(sizePolicy5);
        label_161->setMinimumSize(QSize(80, 0));
        label_161->setMaximumSize(QSize(60, 16777215));
        label_161->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_161, 3, 0, 4, 1);

        label_113 = new QLabel(groupBox_14);
        label_113->setObjectName(QString::fromUtf8("label_113"));
        sizePolicy5.setHeightForWidth(label_113->sizePolicy().hasHeightForWidth());
        label_113->setSizePolicy(sizePolicy5);
        label_113->setMinimumSize(QSize(80, 0));
        label_113->setMaximumSize(QSize(60, 16777215));
        label_113->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_113, 7, 0, 2, 1);

        label_241 = new QLabel(groupBox_14);
        label_241->setObjectName(QString::fromUtf8("label_241"));
        sizePolicy10.setHeightForWidth(label_241->sizePolicy().hasHeightForWidth());
        label_241->setSizePolicy(sizePolicy10);
        label_241->setMaximumSize(QSize(60, 16777215));

        gridLayout_18->addWidget(label_241, 3, 1, 1, 1);

        lblAxisStatusColor0 = new QLabel(groupBox_14);
        lblAxisStatusColor0->setObjectName(QString::fromUtf8("lblAxisStatusColor0"));
        sizePolicy4.setHeightForWidth(lblAxisStatusColor0->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor0->setSizePolicy(sizePolicy4);
        lblAxisStatusColor0->setMinimumSize(QSize(15, 0));
        lblAxisStatusColor0->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor0->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_18->addWidget(lblAxisStatusColor0, 0, 2, 1, 1);

        label_247 = new QLabel(groupBox_14);
        label_247->setObjectName(QString::fromUtf8("label_247"));
        sizePolicy5.setHeightForWidth(label_247->sizePolicy().hasHeightForWidth());
        label_247->setSizePolicy(sizePolicy5);
        label_247->setMinimumSize(QSize(40, 0));
        label_247->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(label_247, 0, 1, 1, 1);

        label_264 = new QLabel(groupBox_14);
        label_264->setObjectName(QString::fromUtf8("label_264"));
        sizePolicy6.setHeightForWidth(label_264->sizePolicy().hasHeightForWidth());
        label_264->setSizePolicy(sizePolicy6);
        label_264->setMaximumSize(QSize(40, 16777215));

        gridLayout_18->addWidget(label_264, 1, 1, 2, 1);

        lbl_LevelPosi0 = new QLabel(groupBox_14);
        lbl_LevelPosi0->setObjectName(QString::fromUtf8("lbl_LevelPosi0"));
        sizePolicy4.setHeightForWidth(lbl_LevelPosi0->sizePolicy().hasHeightForWidth());
        lbl_LevelPosi0->setSizePolicy(sizePolicy4);
        lbl_LevelPosi0->setMinimumSize(QSize(40, 0));
        lbl_LevelPosi0->setMaximumSize(QSize(60, 16777215));

        gridLayout_18->addWidget(lbl_LevelPosi0, 1, 2, 2, 1);

        btnForward0 = new QPushButton(groupBox_14);
        btnForward0->setObjectName(QString::fromUtf8("btnForward0"));
        QSizePolicy sizePolicy18(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy18.setHorizontalStretch(0);
        sizePolicy18.setVerticalStretch(3);
        sizePolicy18.setHeightForWidth(btnForward0->sizePolicy().hasHeightForWidth());
        btnForward0->setSizePolicy(sizePolicy18);
        btnForward0->setMinimumSize(QSize(90, 0));
        btnForward0->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnForward0, 0, 3, 3, 1);

        btnBackward1 = new QPushButton(groupBox_14);
        btnBackward1->setObjectName(QString::fromUtf8("btnBackward1"));
        sizePolicy3.setHeightForWidth(btnBackward1->sizePolicy().hasHeightForWidth());
        btnBackward1->setSizePolicy(sizePolicy3);
        btnBackward1->setMinimumSize(QSize(90, 0));
        btnBackward1->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnBackward1, 3, 3, 4, 1);

        btnBackward2 = new QPushButton(groupBox_14);
        btnBackward2->setObjectName(QString::fromUtf8("btnBackward2"));
        sizePolicy3.setHeightForWidth(btnBackward2->sizePolicy().hasHeightForWidth());
        btnBackward2->setSizePolicy(sizePolicy3);
        btnBackward2->setMinimumSize(QSize(90, 0));
        btnBackward2->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnBackward2, 7, 3, 2, 1);

        btnForward3 = new QPushButton(groupBox_14);
        btnForward3->setObjectName(QString::fromUtf8("btnForward3"));
        sizePolicy18.setHeightForWidth(btnForward3->sizePolicy().hasHeightForWidth());
        btnForward3->setSizePolicy(sizePolicy18);
        btnForward3->setMinimumSize(QSize(90, 0));
        btnForward3->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnForward3, 9, 3, 2, 1);

        btnBackward0 = new QPushButton(groupBox_14);
        btnBackward0->setObjectName(QString::fromUtf8("btnBackward0"));
        sizePolicy3.setHeightForWidth(btnBackward0->sizePolicy().hasHeightForWidth());
        btnBackward0->setSizePolicy(sizePolicy3);
        btnBackward0->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnBackward0, 0, 4, 3, 1);

        btnForward1 = new QPushButton(groupBox_14);
        btnForward1->setObjectName(QString::fromUtf8("btnForward1"));
        sizePolicy18.setHeightForWidth(btnForward1->sizePolicy().hasHeightForWidth());
        btnForward1->setSizePolicy(sizePolicy18);
        btnForward1->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnForward1, 3, 4, 4, 1);

        btnForward2 = new QPushButton(groupBox_14);
        btnForward2->setObjectName(QString::fromUtf8("btnForward2"));
        sizePolicy18.setHeightForWidth(btnForward2->sizePolicy().hasHeightForWidth());
        btnForward2->setSizePolicy(sizePolicy18);
        btnForward2->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnForward2, 7, 4, 2, 1);

        btnBackward3 = new QPushButton(groupBox_14);
        btnBackward3->setObjectName(QString::fromUtf8("btnBackward3"));
        sizePolicy3.setHeightForWidth(btnBackward3->sizePolicy().hasHeightForWidth());
        btnBackward3->setSizePolicy(sizePolicy3);
        btnBackward3->setMaximumSize(QSize(90, 16777215));

        gridLayout_18->addWidget(btnBackward3, 9, 4, 2, 1);

        btnDisAbsMove0_4 = new QPushButton(groupBox_14);
        btnDisAbsMove0_4->setObjectName(QString::fromUtf8("btnDisAbsMove0_4"));
        sizePolicy4.setHeightForWidth(btnDisAbsMove0_4->sizePolicy().hasHeightForWidth());
        btnDisAbsMove0_4->setSizePolicy(sizePolicy4);
        btnDisAbsMove0_4->setMinimumSize(QSize(120, 0));
        btnDisAbsMove0_4->setMaximumSize(QSize(120, 16777215));

        gridLayout_18->addWidget(btnDisAbsMove0_4, 7, 5, 4, 1);

        btnDisMove0_4 = new QPushButton(groupBox_14);
        btnDisMove0_4->setObjectName(QString::fromUtf8("btnDisMove0_4"));
        sizePolicy4.setHeightForWidth(btnDisMove0_4->sizePolicy().hasHeightForWidth());
        btnDisMove0_4->setSizePolicy(sizePolicy4);
        btnDisMove0_4->setMinimumSize(QSize(120, 0));
        btnDisMove0_4->setMaximumSize(QSize(120, 16777215));

        gridLayout_18->addWidget(btnDisMove0_4, 0, 5, 7, 1);

        spinBox_PosMove0_4 = new QSpinBox(groupBox_14);
        spinBox_PosMove0_4->setObjectName(QString::fromUtf8("spinBox_PosMove0_4"));
        spinBox_PosMove0_4->setMinimumSize(QSize(100, 0));
        spinBox_PosMove0_4->setMaximumSize(QSize(70, 16777215));

        gridLayout_18->addWidget(spinBox_PosMove0_4, 0, 6, 7, 2);

        spinBox_PosAbsMove0_4 = new QSpinBox(groupBox_14);
        spinBox_PosAbsMove0_4->setObjectName(QString::fromUtf8("spinBox_PosAbsMove0_4"));
        spinBox_PosAbsMove0_4->setMinimumSize(QSize(100, 0));
        spinBox_PosAbsMove0_4->setMaximumSize(QSize(70, 16777215));

        gridLayout_18->addWidget(spinBox_PosAbsMove0_4, 7, 6, 4, 2);


        gridLayout_19->addLayout(gridLayout_18, 0, 1, 1, 1);


        gridLayout_35->addWidget(groupBox_14, 0, 0, 1, 1);

        groupBox_22 = new QGroupBox(tab_7);
        groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
        sizePolicy6.setHeightForWidth(groupBox_22->sizePolicy().hasHeightForWidth());
        groupBox_22->setSizePolicy(sizePolicy6);
        groupBox_22->setMaximumSize(QSize(16777215, 205));
        groupBox_22->setFont(font3);
        groupBox_22->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        verticalLayout_16 = new QVBoxLayout(groupBox_22);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        horizontalLayout_86 = new QHBoxLayout();
        horizontalLayout_86->setSpacing(6);
        horizontalLayout_86->setObjectName(QString::fromUtf8("horizontalLayout_86"));
        btn_FeetToGround = new QPushButton(groupBox_22);
        btn_FeetToGround->setObjectName(QString::fromUtf8("btn_FeetToGround"));

        horizontalLayout_86->addWidget(btn_FeetToGround);

        btn_BalanceBody = new QPushButton(groupBox_22);
        btn_BalanceBody->setObjectName(QString::fromUtf8("btn_BalanceBody"));

        horizontalLayout_86->addWidget(btn_BalanceBody);

        btn_BodyToGround = new QPushButton(groupBox_22);
        btn_BodyToGround->setObjectName(QString::fromUtf8("btn_BodyToGround"));

        horizontalLayout_86->addWidget(btn_BodyToGround);

        btn_LevelRapidStop = new QPushButton(groupBox_22);
        btn_LevelRapidStop->setObjectName(QString::fromUtf8("btn_LevelRapidStop"));
        sizePolicy3.setHeightForWidth(btn_LevelRapidStop->sizePolicy().hasHeightForWidth());
        btn_LevelRapidStop->setSizePolicy(sizePolicy3);
        btn_LevelRapidStop->setMinimumSize(QSize(60, 60));
        btn_LevelRapidStop->setMaximumSize(QSize(60, 60));
        btn_LevelRapidStop->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/RapidStop.svg) 0 stretch;\n"
"border: 2px solid black; "));

        horizontalLayout_86->addWidget(btn_LevelRapidStop);

        btn_LevelToAuto = new QPushButton(groupBox_22);
        btn_LevelToAuto->setObjectName(QString::fromUtf8("btn_LevelToAuto"));
        sizePolicy3.setHeightForWidth(btn_LevelToAuto->sizePolicy().hasHeightForWidth());
        btn_LevelToAuto->setSizePolicy(sizePolicy3);
        btn_LevelToAuto->setMinimumSize(QSize(90, 100));
        btn_LevelToAuto->setMaximumSize(QSize(90, 100));
        btn_LevelToAuto->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/ManualToAuto.svg) 0 stretch;\n"
"border: 2px solid black; "));

        horizontalLayout_86->addWidget(btn_LevelToAuto);


        verticalLayout_16->addLayout(horizontalLayout_86);

        horizontalLayout_105 = new QHBoxLayout();
        horizontalLayout_105->setSpacing(6);
        horizontalLayout_105->setObjectName(QString::fromUtf8("horizontalLayout_105"));
        groupBox_23 = new QGroupBox(groupBox_22);
        groupBox_23->setObjectName(QString::fromUtf8("groupBox_23"));
        gridLayout_24 = new QGridLayout(groupBox_23);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        btn_SpeedBodyUp = new QPushButton(groupBox_23);
        btn_SpeedBodyUp->setObjectName(QString::fromUtf8("btn_SpeedBodyUp"));

        gridLayout_24->addWidget(btn_SpeedBodyUp, 0, 0, 1, 1);

        btn_SpeedBodyDown = new QPushButton(groupBox_23);
        btn_SpeedBodyDown->setObjectName(QString::fromUtf8("btn_SpeedBodyDown"));

        gridLayout_24->addWidget(btn_SpeedBodyDown, 0, 1, 1, 1);


        horizontalLayout_105->addWidget(groupBox_23);

        groupBox_24 = new QGroupBox(groupBox_22);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        gridLayout_25 = new QGridLayout(groupBox_24);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        btn_PosBodyUp = new QPushButton(groupBox_24);
        btn_PosBodyUp->setObjectName(QString::fromUtf8("btn_PosBodyUp"));

        gridLayout_25->addWidget(btn_PosBodyUp, 0, 0, 1, 1);

        btn_PosBodyDown = new QPushButton(groupBox_24);
        btn_PosBodyDown->setObjectName(QString::fromUtf8("btn_PosBodyDown"));

        gridLayout_25->addWidget(btn_PosBodyDown, 0, 1, 1, 1);

        horizontalLayout_85 = new QHBoxLayout();
        horizontalLayout_85->setSpacing(6);
        horizontalLayout_85->setObjectName(QString::fromUtf8("horizontalLayout_85"));
        label_4 = new QLabel(groupBox_24);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_85->addWidget(label_4);

        spinBox_Distance = new QDoubleSpinBox(groupBox_24);
        spinBox_Distance->setObjectName(QString::fromUtf8("spinBox_Distance"));
        spinBox_Distance->setMinimum(-99.000000000000000);

        horizontalLayout_85->addWidget(spinBox_Distance);


        gridLayout_25->addLayout(horizontalLayout_85, 0, 3, 1, 1);


        horizontalLayout_105->addWidget(groupBox_24);


        verticalLayout_16->addLayout(horizontalLayout_105);


        gridLayout_35->addWidget(groupBox_22, 1, 0, 1, 1);

        tabWidget->addTab(tab_7, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_17 = new QGridLayout(tab_5);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        groupBox_25 = new QGroupBox(tab_5);
        groupBox_25->setObjectName(QString::fromUtf8("groupBox_25"));
        sizePolicy6.setHeightForWidth(groupBox_25->sizePolicy().hasHeightForWidth());
        groupBox_25->setSizePolicy(sizePolicy6);
        groupBox_25->setMaximumSize(QSize(16777215, 130));
        groupBox_25->setFont(font);
        groupBox_25->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_7 = new QGridLayout(groupBox_25);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_49 = new QGridLayout();
        gridLayout_49->setSpacing(6);
        gridLayout_49->setObjectName(QString::fromUtf8("gridLayout_49"));
        btn_MainLiftToAuto = new QPushButton(groupBox_25);
        btn_MainLiftToAuto->setObjectName(QString::fromUtf8("btn_MainLiftToAuto"));
        sizePolicy3.setHeightForWidth(btn_MainLiftToAuto->sizePolicy().hasHeightForWidth());
        btn_MainLiftToAuto->setSizePolicy(sizePolicy3);
        btn_MainLiftToAuto->setMinimumSize(QSize(90, 100));
        btn_MainLiftToAuto->setMaximumSize(QSize(90, 100));
        btn_MainLiftToAuto->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/ManualToAuto.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_49->addWidget(btn_MainLiftToAuto, 0, 11, 3, 1);

        btnInit4 = new QPushButton(groupBox_25);
        btnInit4->setObjectName(QString::fromUtf8("btnInit4"));
        sizePolicy6.setHeightForWidth(btnInit4->sizePolicy().hasHeightForWidth());
        btnInit4->setSizePolicy(sizePolicy6);
        btnInit4->setMaximumSize(QSize(16777215, 25));

        gridLayout_49->addWidget(btnInit4, 1, 4, 1, 1);

        label_122 = new QLabel(groupBox_25);
        label_122->setObjectName(QString::fromUtf8("label_122"));
        sizePolicy3.setHeightForWidth(label_122->sizePolicy().hasHeightForWidth());
        label_122->setSizePolicy(sizePolicy3);

        gridLayout_49->addWidget(label_122, 2, 1, 1, 1);

        label_219 = new QLabel(groupBox_25);
        label_219->setObjectName(QString::fromUtf8("label_219"));
        sizePolicy3.setHeightForWidth(label_219->sizePolicy().hasHeightForWidth());
        label_219->setSizePolicy(sizePolicy3);
        label_219->setMaximumSize(QSize(40, 16777215));

        gridLayout_49->addWidget(label_219, 0, 1, 1, 1);

        btnForward4 = new QPushButton(groupBox_25);
        btnForward4->setObjectName(QString::fromUtf8("btnForward4"));
        btnForward4->setMinimumSize(QSize(70, 0));
        btnForward4->setMaximumSize(QSize(20, 25));

        gridLayout_49->addWidget(btnForward4, 1, 3, 1, 1);

        lblAxisStatusColor4 = new QLabel(groupBox_25);
        lblAxisStatusColor4->setObjectName(QString::fromUtf8("lblAxisStatusColor4"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor4->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor4->setSizePolicy(sizePolicy2);
        lblAxisStatusColor4->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor4->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor4->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_49->addWidget(lblAxisStatusColor4, 0, 2, 1, 1);

        btn_MainLiftRapidStop = new QPushButton(groupBox_25);
        btn_MainLiftRapidStop->setObjectName(QString::fromUtf8("btn_MainLiftRapidStop"));
        sizePolicy3.setHeightForWidth(btn_MainLiftRapidStop->sizePolicy().hasHeightForWidth());
        btn_MainLiftRapidStop->setSizePolicy(sizePolicy3);
        btn_MainLiftRapidStop->setMinimumSize(QSize(60, 60));
        btn_MainLiftRapidStop->setMaximumSize(QSize(60, 60));
        btn_MainLiftRapidStop->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/RapidStop.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_49->addWidget(btn_MainLiftRapidStop, 0, 10, 3, 1);

        btnBackward4 = new QPushButton(groupBox_25);
        btnBackward4->setObjectName(QString::fromUtf8("btnBackward4"));
        btnBackward4->setMaximumSize(QSize(16777215, 25));

        gridLayout_49->addWidget(btnBackward4, 2, 3, 1, 1);

        btnDisMove4 = new QPushButton(groupBox_25);
        btnDisMove4->setObjectName(QString::fromUtf8("btnDisMove4"));
        btnDisMove4->setMinimumSize(QSize(80, 0));

        gridLayout_49->addWidget(btnDisMove4, 2, 6, 1, 1);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setSpacing(6);
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        label_114 = new QLabel(groupBox_25);
        label_114->setObjectName(QString::fromUtf8("label_114"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font6.setPointSize(9);
        label_114->setFont(font6);

        horizontalLayout_48->addWidget(label_114);

        spinBox_PosMove4 = new QSpinBox(groupBox_25);
        spinBox_PosMove4->setObjectName(QString::fromUtf8("spinBox_PosMove4"));
        spinBox_PosMove4->setMaximum(500);

        horizontalLayout_48->addWidget(spinBox_PosMove4);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        left_laser = new QLabel(groupBox_25);
        left_laser->setObjectName(QString::fromUtf8("left_laser"));

        horizontalLayout_25->addWidget(left_laser);


        horizontalLayout_48->addLayout(horizontalLayout_25);


        gridLayout_49->addLayout(horizontalLayout_48, 2, 7, 1, 3);

        btnDisableMainLiftAxis = new QPushButton(groupBox_25);
        btnDisableMainLiftAxis->setObjectName(QString::fromUtf8("btnDisableMainLiftAxis"));
        btnDisableMainLiftAxis->setMinimumSize(QSize(80, 0));

        gridLayout_49->addWidget(btnDisableMainLiftAxis, 0, 4, 1, 1);

        btnEnableMainLiftAxis = new QPushButton(groupBox_25);
        btnEnableMainLiftAxis->setObjectName(QString::fromUtf8("btnEnableMainLiftAxis"));
        btnEnableMainLiftAxis->setMinimumSize(QSize(80, 0));

        gridLayout_49->addWidget(btnEnableMainLiftAxis, 0, 3, 1, 1);

        lbl_MainLiftPosi4 = new QLabel(groupBox_25);
        lbl_MainLiftPosi4->setObjectName(QString::fromUtf8("lbl_MainLiftPosi4"));
        sizePolicy3.setHeightForWidth(lbl_MainLiftPosi4->sizePolicy().hasHeightForWidth());
        lbl_MainLiftPosi4->setSizePolicy(sizePolicy3);
        lbl_MainLiftPosi4->setMinimumSize(QSize(50, 0));
        lbl_MainLiftPosi4->setMaximumSize(QSize(50, 16777215));

        gridLayout_49->addWidget(lbl_MainLiftPosi4, 2, 2, 1, 1);

        btn_MainLiftBackward = new QPushButton(groupBox_25);
        btn_MainLiftBackward->setObjectName(QString::fromUtf8("btn_MainLiftBackward"));
        btn_MainLiftBackward->setMinimumSize(QSize(80, 0));

        gridLayout_49->addWidget(btn_MainLiftBackward, 2, 5, 1, 1);

        label_105 = new QLabel(groupBox_25);
        label_105->setObjectName(QString::fromUtf8("label_105"));
        sizePolicy10.setHeightForWidth(label_105->sizePolicy().hasHeightForWidth());
        label_105->setSizePolicy(sizePolicy10);
        label_105->setMaximumSize(QSize(90, 16777215));

        gridLayout_49->addWidget(label_105, 0, 0, 3, 1);

        btnZero4 = new QPushButton(groupBox_25);
        btnZero4->setObjectName(QString::fromUtf8("btnZero4"));
        sizePolicy6.setHeightForWidth(btnZero4->sizePolicy().hasHeightForWidth());
        btnZero4->setSizePolicy(sizePolicy6);
        btnZero4->setMaximumSize(QSize(16777215, 25));

        gridLayout_49->addWidget(btnZero4, 2, 4, 1, 1);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setSpacing(6);
        horizontalLayout_49->setObjectName(QString::fromUtf8("horizontalLayout_49"));
        label_121 = new QLabel(groupBox_25);
        label_121->setObjectName(QString::fromUtf8("label_121"));
        label_121->setFont(font6);

        horizontalLayout_49->addWidget(label_121);

        spinBox_PosAbsMove4 = new QSpinBox(groupBox_25);
        spinBox_PosAbsMove4->setObjectName(QString::fromUtf8("spinBox_PosAbsMove4"));
        spinBox_PosAbsMove4->setMaximum(2250);
        spinBox_PosAbsMove4->setSingleStep(1);

        horizontalLayout_49->addWidget(spinBox_PosAbsMove4);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        right_laser = new QLabel(groupBox_25);
        right_laser->setObjectName(QString::fromUtf8("right_laser"));

        horizontalLayout_23->addWidget(right_laser);


        horizontalLayout_49->addLayout(horizontalLayout_23);


        gridLayout_49->addLayout(horizontalLayout_49, 0, 7, 1, 3);

        btnDisAbsMove4 = new QPushButton(groupBox_25);
        btnDisAbsMove4->setObjectName(QString::fromUtf8("btnDisAbsMove4"));
        btnDisAbsMove4->setMinimumSize(QSize(80, 0));

        gridLayout_49->addWidget(btnDisAbsMove4, 0, 6, 1, 1);

        btn_MainLiftForward = new QPushButton(groupBox_25);
        btn_MainLiftForward->setObjectName(QString::fromUtf8("btn_MainLiftForward"));
        btn_MainLiftForward->setMinimumSize(QSize(80, 0));

        gridLayout_49->addWidget(btn_MainLiftForward, 0, 5, 1, 1);


        gridLayout_7->addLayout(gridLayout_49, 0, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_25, 0, 0, 1, 1);

        groupBox_29 = new QGroupBox(tab_5);
        groupBox_29->setObjectName(QString::fromUtf8("groupBox_29"));
        sizePolicy6.setHeightForWidth(groupBox_29->sizePolicy().hasHeightForWidth());
        groupBox_29->setSizePolicy(sizePolicy6);
        groupBox_29->setMinimumSize(QSize(0, 180));
        groupBox_29->setMaximumSize(QSize(16777215, 480));
        groupBox_29->setFont(font3);
        groupBox_29->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_14 = new QGridLayout(groupBox_29);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_12->setVerticalSpacing(2);
        btnForward9_10 = new QPushButton(groupBox_29);
        btnForward9_10->setObjectName(QString::fromUtf8("btnForward9_10"));
        sizePolicy4.setHeightForWidth(btnForward9_10->sizePolicy().hasHeightForWidth());
        btnForward9_10->setSizePolicy(sizePolicy4);
        btnForward9_10->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnForward9_10, 12, 5, 4, 1);

        btnBackward5_6 = new QPushButton(groupBox_29);
        btnBackward5_6->setObjectName(QString::fromUtf8("btnBackward5_6"));
        sizePolicy4.setHeightForWidth(btnBackward5_6->sizePolicy().hasHeightForWidth());
        btnBackward5_6->setSizePolicy(sizePolicy4);
        btnBackward5_6->setMinimumSize(QSize(0, 30));

        gridLayout_12->addWidget(btnBackward5_6, 3, 5, 3, 1);

        spinBox_PosMove9_10 = new QSpinBox(groupBox_29);
        spinBox_PosMove9_10->setObjectName(QString::fromUtf8("spinBox_PosMove9_10"));
        spinBox_PosMove9_10->setMinimum(-2000);
        spinBox_PosMove9_10->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosMove9_10, 12, 8, 4, 1);

        btnForward7 = new QPushButton(groupBox_29);
        btnForward7->setObjectName(QString::fromUtf8("btnForward7"));
        btnForward7->setEnabled(true);
        sizePolicy9.setHeightForWidth(btnForward7->sizePolicy().hasHeightForWidth());
        btnForward7->setSizePolicy(sizePolicy9);
        btnForward7->setMouseTracking(false);
        btnForward7->setTabletTracking(false);
        btnForward7->setCheckable(false);
        btnForward7->setChecked(false);
        btnForward7->setAutoRepeat(false);
        btnForward7->setAutoExclusive(false);

        gridLayout_12->addWidget(btnForward7, 6, 3, 3, 1);

        spinBox_PosMove5_6 = new QSpinBox(groupBox_29);
        spinBox_PosMove5_6->setObjectName(QString::fromUtf8("spinBox_PosMove5_6"));
        spinBox_PosMove5_6->setMinimum(-2000);
        spinBox_PosMove5_6->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosMove5_6, 0, 8, 3, 1);

        label_179 = new QLabel(groupBox_29);
        label_179->setObjectName(QString::fromUtf8("label_179"));
        sizePolicy3.setHeightForWidth(label_179->sizePolicy().hasHeightForWidth());
        label_179->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_179, 1, 1, 2, 1);

        btnDisAbsMove9_10 = new QPushButton(groupBox_29);
        btnDisAbsMove9_10->setObjectName(QString::fromUtf8("btnDisAbsMove9_10"));

        gridLayout_12->addWidget(btnDisAbsMove9_10, 16, 7, 3, 1);

        btnZero9_10 = new QPushButton(groupBox_29);
        btnZero9_10->setObjectName(QString::fromUtf8("btnZero9_10"));

        gridLayout_12->addWidget(btnZero9_10, 16, 6, 3, 1);

        btnZero7_8 = new QPushButton(groupBox_29);
        btnZero7_8->setObjectName(QString::fromUtf8("btnZero7_8"));
        sizePolicy4.setHeightForWidth(btnZero7_8->sizePolicy().hasHeightForWidth());
        btnZero7_8->setSizePolicy(sizePolicy4);
        btnZero7_8->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnZero7_8, 9, 6, 3, 1);

        lbl_CoverPlatePosi5 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi5->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi5"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi5->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi5->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi5->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi5->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi5, 1, 2, 2, 1);

        lblAxisStatusColor6 = new QLabel(groupBox_29);
        lblAxisStatusColor6->setObjectName(QString::fromUtf8("lblAxisStatusColor6"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor6->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor6->setSizePolicy(sizePolicy2);
        lblAxisStatusColor6->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor6->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor6->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor6, 3, 2, 1, 1);

        lblAxisStatusColor9 = new QLabel(groupBox_29);
        lblAxisStatusColor9->setObjectName(QString::fromUtf8("lblAxisStatusColor9"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor9->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor9->setSizePolicy(sizePolicy2);
        lblAxisStatusColor9->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor9->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor9->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor9, 12, 2, 1, 1);

        btnDisAbsMove11 = new QPushButton(groupBox_29);
        btnDisAbsMove11->setObjectName(QString::fromUtf8("btnDisAbsMove11"));
        sizePolicy9.setHeightForWidth(btnDisAbsMove11->sizePolicy().hasHeightForWidth());
        btnDisAbsMove11->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnDisAbsMove11, 20, 5, 1, 2);

        lblAxisStatusColor5 = new QLabel(groupBox_29);
        lblAxisStatusColor5->setObjectName(QString::fromUtf8("lblAxisStatusColor5"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor5->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor5->setSizePolicy(sizePolicy2);
        lblAxisStatusColor5->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor5->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor5->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor5, 0, 2, 1, 1);

        label_104 = new QLabel(groupBox_29);
        label_104->setObjectName(QString::fromUtf8("label_104"));
        sizePolicy10.setHeightForWidth(label_104->sizePolicy().hasHeightForWidth());
        label_104->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_104, 0, 0, 3, 1);

        spinBox_PosAbsMove7_8 = new QSpinBox(groupBox_29);
        spinBox_PosAbsMove7_8->setObjectName(QString::fromUtf8("spinBox_PosAbsMove7_8"));
        spinBox_PosAbsMove7_8->setMinimum(-2000);
        spinBox_PosAbsMove7_8->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosAbsMove7_8, 9, 8, 3, 1);

        spinBox_PosAbsMove5_6 = new QSpinBox(groupBox_29);
        spinBox_PosAbsMove5_6->setObjectName(QString::fromUtf8("spinBox_PosAbsMove5_6"));
        spinBox_PosAbsMove5_6->setMinimum(-2000);
        spinBox_PosAbsMove5_6->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosAbsMove5_6, 3, 8, 3, 1);

        btnBackward7 = new QPushButton(groupBox_29);
        btnBackward7->setObjectName(QString::fromUtf8("btnBackward7"));
        btnBackward7->setEnabled(true);
        sizePolicy9.setHeightForWidth(btnBackward7->sizePolicy().hasHeightForWidth());
        btnBackward7->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnBackward7, 6, 4, 3, 1);

        btnForward10 = new QPushButton(groupBox_29);
        btnForward10->setObjectName(QString::fromUtf8("btnForward10"));

        gridLayout_12->addWidget(btnForward10, 16, 3, 3, 1);

        lblAxisStatusColor7 = new QLabel(groupBox_29);
        lblAxisStatusColor7->setObjectName(QString::fromUtf8("lblAxisStatusColor7"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor7->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor7->setSizePolicy(sizePolicy2);
        lblAxisStatusColor7->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor7->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor7->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor7, 6, 2, 1, 1);

        btnBackward6 = new QPushButton(groupBox_29);
        btnBackward6->setObjectName(QString::fromUtf8("btnBackward6"));
        sizePolicy9.setHeightForWidth(btnBackward6->sizePolicy().hasHeightForWidth());
        btnBackward6->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnBackward6, 3, 4, 3, 1);

        btnBackward10 = new QPushButton(groupBox_29);
        btnBackward10->setObjectName(QString::fromUtf8("btnBackward10"));

        gridLayout_12->addWidget(btnBackward10, 16, 4, 3, 1);

        label_213 = new QLabel(groupBox_29);
        label_213->setObjectName(QString::fromUtf8("label_213"));
        sizePolicy10.setHeightForWidth(label_213->sizePolicy().hasHeightForWidth());
        label_213->setSizePolicy(sizePolicy10);
        label_213->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_213, 3, 1, 1, 1);

        lblAxisStatusColor8 = new QLabel(groupBox_29);
        lblAxisStatusColor8->setObjectName(QString::fromUtf8("lblAxisStatusColor8"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor8->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor8->setSizePolicy(sizePolicy2);
        lblAxisStatusColor8->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor8->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor8->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor8, 9, 2, 1, 1);

        btnForward9 = new QPushButton(groupBox_29);
        btnForward9->setObjectName(QString::fromUtf8("btnForward9"));
        sizePolicy9.setHeightForWidth(btnForward9->sizePolicy().hasHeightForWidth());
        btnForward9->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnForward9, 12, 3, 4, 1);

        lbl_CoverPlatePosi6 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi6->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi6"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi6->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi6->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi6->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi6->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi6, 4, 2, 2, 1);

        label_227 = new QLabel(groupBox_29);
        label_227->setObjectName(QString::fromUtf8("label_227"));
        sizePolicy10.setHeightForWidth(label_227->sizePolicy().hasHeightForWidth());
        label_227->setSizePolicy(sizePolicy10);
        label_227->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_227, 19, 1, 1, 1);

        label_181 = new QLabel(groupBox_29);
        label_181->setObjectName(QString::fromUtf8("label_181"));
        sizePolicy3.setHeightForWidth(label_181->sizePolicy().hasHeightForWidth());
        label_181->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_181, 10, 1, 2, 1);

        lbl_CoverPlatePosi7 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi7->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi7"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi7->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi7->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi7->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi7->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi7, 7, 2, 2, 1);

        btnDisMove7_8 = new QPushButton(groupBox_29);
        btnDisMove7_8->setObjectName(QString::fromUtf8("btnDisMove7_8"));
        sizePolicy4.setHeightForWidth(btnDisMove7_8->sizePolicy().hasHeightForWidth());
        btnDisMove7_8->setSizePolicy(sizePolicy4);
        btnDisMove7_8->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnDisMove7_8, 6, 7, 3, 1);

        label_225 = new QLabel(groupBox_29);
        label_225->setObjectName(QString::fromUtf8("label_225"));
        sizePolicy10.setHeightForWidth(label_225->sizePolicy().hasHeightForWidth());
        label_225->setSizePolicy(sizePolicy10);
        label_225->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_225, 16, 1, 1, 1);

        btnInit7_8 = new QPushButton(groupBox_29);
        btnInit7_8->setObjectName(QString::fromUtf8("btnInit7_8"));
        sizePolicy14.setHeightForWidth(btnInit7_8->sizePolicy().hasHeightForWidth());
        btnInit7_8->setSizePolicy(sizePolicy14);
        btnInit7_8->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnInit7_8, 6, 6, 3, 1);

        lblAxisStatusColor10 = new QLabel(groupBox_29);
        lblAxisStatusColor10->setObjectName(QString::fromUtf8("lblAxisStatusColor10"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor10->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor10->setSizePolicy(sizePolicy2);
        lblAxisStatusColor10->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor10->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor10->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor10, 16, 2, 1, 1);

        btnForward6 = new QPushButton(groupBox_29);
        btnForward6->setObjectName(QString::fromUtf8("btnForward6"));
        sizePolicy9.setHeightForWidth(btnForward6->sizePolicy().hasHeightForWidth());
        btnForward6->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnForward6, 3, 3, 3, 1);

        btnBackward5 = new QPushButton(groupBox_29);
        btnBackward5->setObjectName(QString::fromUtf8("btnBackward5"));
        sizePolicy9.setHeightForWidth(btnBackward5->sizePolicy().hasHeightForWidth());
        btnBackward5->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnBackward5, 0, 4, 3, 1);

        label_89 = new QLabel(groupBox_29);
        label_89->setObjectName(QString::fromUtf8("label_89"));
        sizePolicy10.setHeightForWidth(label_89->sizePolicy().hasHeightForWidth());
        label_89->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_89, 9, 0, 3, 1);

        btnDisAbsMove5_6 = new QPushButton(groupBox_29);
        btnDisAbsMove5_6->setObjectName(QString::fromUtf8("btnDisAbsMove5_6"));
        sizePolicy4.setHeightForWidth(btnDisAbsMove5_6->sizePolicy().hasHeightForWidth());
        btnDisAbsMove5_6->setSizePolicy(sizePolicy4);
        btnDisAbsMove5_6->setMinimumSize(QSize(80, 0));
        btnDisAbsMove5_6->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnDisAbsMove5_6, 3, 7, 3, 1);

        label_102 = new QLabel(groupBox_29);
        label_102->setObjectName(QString::fromUtf8("label_102"));
        sizePolicy10.setHeightForWidth(label_102->sizePolicy().hasHeightForWidth());
        label_102->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_102, 12, 0, 4, 1);

        btnForward8 = new QPushButton(groupBox_29);
        btnForward8->setObjectName(QString::fromUtf8("btnForward8"));
        btnForward8->setEnabled(true);
        sizePolicy9.setHeightForWidth(btnForward8->sizePolicy().hasHeightForWidth());
        btnForward8->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnForward8, 9, 3, 3, 1);

        btnZero11 = new QPushButton(groupBox_29);
        btnZero11->setObjectName(QString::fromUtf8("btnZero11"));
        btnZero11->setMaximumSize(QSize(140, 16777215));

        gridLayout_12->addWidget(btnZero11, 20, 7, 1, 1);

        btnForward11 = new QPushButton(groupBox_29);
        btnForward11->setObjectName(QString::fromUtf8("btnForward11"));
        sizePolicy14.setHeightForWidth(btnForward11->sizePolicy().hasHeightForWidth());
        btnForward11->setSizePolicy(sizePolicy14);
        btnForward11->setMaximumSize(QSize(135, 16777215));

        gridLayout_12->addWidget(btnForward11, 19, 4, 2, 1);

        btnInit11 = new QPushButton(groupBox_29);
        btnInit11->setObjectName(QString::fromUtf8("btnInit11"));
        sizePolicy14.setHeightForWidth(btnInit11->sizePolicy().hasHeightForWidth());
        btnInit11->setSizePolicy(sizePolicy14);
        btnInit11->setMaximumSize(QSize(140, 16777215));

        gridLayout_12->addWidget(btnInit11, 19, 7, 1, 1);

        btnForward5 = new QPushButton(groupBox_29);
        btnForward5->setObjectName(QString::fromUtf8("btnForward5"));
        sizePolicy4.setHeightForWidth(btnForward5->sizePolicy().hasHeightForWidth());
        btnForward5->setSizePolicy(sizePolicy4);

        gridLayout_12->addWidget(btnForward5, 0, 3, 3, 1);

        spinBox_PosAbsMove9_10 = new QSpinBox(groupBox_29);
        spinBox_PosAbsMove9_10->setObjectName(QString::fromUtf8("spinBox_PosAbsMove9_10"));
        spinBox_PosAbsMove9_10->setMinimum(-2000);
        spinBox_PosAbsMove9_10->setMaximum(2000);
        spinBox_PosAbsMove9_10->setSingleStep(1);

        gridLayout_12->addWidget(spinBox_PosAbsMove9_10, 16, 8, 3, 1);

        label_183 = new QLabel(groupBox_29);
        label_183->setObjectName(QString::fromUtf8("label_183"));
        sizePolicy3.setHeightForWidth(label_183->sizePolicy().hasHeightForWidth());
        label_183->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_183, 17, 1, 2, 1);

        btnDisMove11 = new QPushButton(groupBox_29);
        btnDisMove11->setObjectName(QString::fromUtf8("btnDisMove11"));
        sizePolicy14.setHeightForWidth(btnDisMove11->sizePolicy().hasHeightForWidth());
        btnDisMove11->setSizePolicy(sizePolicy14);
        btnDisMove11->setMinimumSize(QSize(140, 0));
        btnDisMove11->setMaximumSize(QSize(200, 16777215));

        gridLayout_12->addWidget(btnDisMove11, 19, 5, 1, 2);

        spinBox_PosAbsMove11 = new QSpinBox(groupBox_29);
        spinBox_PosAbsMove11->setObjectName(QString::fromUtf8("spinBox_PosAbsMove11"));
        spinBox_PosAbsMove11->setMinimumSize(QSize(50, 0));
        spinBox_PosAbsMove11->setMinimum(-2000);
        spinBox_PosAbsMove11->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosAbsMove11, 20, 8, 1, 1);

        label_178 = new QLabel(groupBox_29);
        label_178->setObjectName(QString::fromUtf8("label_178"));
        sizePolicy3.setHeightForWidth(label_178->sizePolicy().hasHeightForWidth());
        label_178->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_178, 7, 1, 2, 1);

        label_224 = new QLabel(groupBox_29);
        label_224->setObjectName(QString::fromUtf8("label_224"));
        sizePolicy10.setHeightForWidth(label_224->sizePolicy().hasHeightForWidth());
        label_224->setSizePolicy(sizePolicy10);
        label_224->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_224, 12, 1, 1, 1);

        label_214 = new QLabel(groupBox_29);
        label_214->setObjectName(QString::fromUtf8("label_214"));
        sizePolicy10.setHeightForWidth(label_214->sizePolicy().hasHeightForWidth());
        label_214->setSizePolicy(sizePolicy10);
        label_214->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_214, 0, 1, 1, 1);

        btnBackward9 = new QPushButton(groupBox_29);
        btnBackward9->setObjectName(QString::fromUtf8("btnBackward9"));
        sizePolicy9.setHeightForWidth(btnBackward9->sizePolicy().hasHeightForWidth());
        btnBackward9->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnBackward9, 12, 4, 4, 1);

        spinBox_PosMove7_8 = new QSpinBox(groupBox_29);
        spinBox_PosMove7_8->setObjectName(QString::fromUtf8("spinBox_PosMove7_8"));
        spinBox_PosMove7_8->setMinimum(-2000);
        spinBox_PosMove7_8->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosMove7_8, 6, 8, 3, 1);

        btnBackward9_10 = new QPushButton(groupBox_29);
        btnBackward9_10->setObjectName(QString::fromUtf8("btnBackward9_10"));

        gridLayout_12->addWidget(btnBackward9_10, 16, 5, 3, 1);

        lbl_CoverPlatePosi11 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi11->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi11"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi11->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi11->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi11->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi11->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi11, 20, 2, 1, 1);

        btnDisAbsMove7_8 = new QPushButton(groupBox_29);
        btnDisAbsMove7_8->setObjectName(QString::fromUtf8("btnDisAbsMove7_8"));
        sizePolicy4.setHeightForWidth(btnDisAbsMove7_8->sizePolicy().hasHeightForWidth());
        btnDisAbsMove7_8->setSizePolicy(sizePolicy4);
        btnDisAbsMove7_8->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnDisAbsMove7_8, 9, 7, 3, 1);

        lblAxisStatusColor11 = new QLabel(groupBox_29);
        lblAxisStatusColor11->setObjectName(QString::fromUtf8("lblAxisStatusColor11"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor11->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor11->setSizePolicy(sizePolicy2);
        lblAxisStatusColor11->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor11->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor11->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_12->addWidget(lblAxisStatusColor11, 19, 2, 1, 1);

        lbl_CoverPlatePosi8 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi8->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi8"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi8->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi8->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi8->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi8->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi8, 10, 2, 2, 1);

        label_83 = new QLabel(groupBox_29);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        sizePolicy10.setHeightForWidth(label_83->sizePolicy().hasHeightForWidth());
        label_83->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_83, 3, 0, 3, 1);

        label_215 = new QLabel(groupBox_29);
        label_215->setObjectName(QString::fromUtf8("label_215"));
        sizePolicy10.setHeightForWidth(label_215->sizePolicy().hasHeightForWidth());
        label_215->setSizePolicy(sizePolicy10);
        label_215->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_215, 6, 1, 1, 1);

        lbl_CoverPlatePosi9 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi9->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi9"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi9->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi9->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi9->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi9->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi9, 13, 2, 3, 1);

        btnZero5_6 = new QPushButton(groupBox_29);
        btnZero5_6->setObjectName(QString::fromUtf8("btnZero5_6"));
        sizePolicy4.setHeightForWidth(btnZero5_6->sizePolicy().hasHeightForWidth());
        btnZero5_6->setSizePolicy(sizePolicy4);
        btnZero5_6->setMinimumSize(QSize(0, 30));

        gridLayout_12->addWidget(btnZero5_6, 3, 6, 3, 1);

        btnForward5_6 = new QPushButton(groupBox_29);
        btnForward5_6->setObjectName(QString::fromUtf8("btnForward5_6"));
        sizePolicy4.setHeightForWidth(btnForward5_6->sizePolicy().hasHeightForWidth());
        btnForward5_6->setSizePolicy(sizePolicy4);
        btnForward5_6->setMinimumSize(QSize(0, 30));

        gridLayout_12->addWidget(btnForward5_6, 0, 5, 3, 1);

        btnBackward7_8 = new QPushButton(groupBox_29);
        btnBackward7_8->setObjectName(QString::fromUtf8("btnBackward7_8"));
        sizePolicy4.setHeightForWidth(btnBackward7_8->sizePolicy().hasHeightForWidth());
        btnBackward7_8->setSizePolicy(sizePolicy4);
        btnBackward7_8->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnBackward7_8, 9, 5, 3, 1);

        lbl_CoverPlatePosi10 = new QLabel(groupBox_29);
        lbl_CoverPlatePosi10->setObjectName(QString::fromUtf8("lbl_CoverPlatePosi10"));
        sizePolicy3.setHeightForWidth(lbl_CoverPlatePosi10->sizePolicy().hasHeightForWidth());
        lbl_CoverPlatePosi10->setSizePolicy(sizePolicy3);
        lbl_CoverPlatePosi10->setMinimumSize(QSize(50, 0));
        lbl_CoverPlatePosi10->setMaximumSize(QSize(50, 16777215));

        gridLayout_12->addWidget(lbl_CoverPlatePosi10, 17, 2, 2, 1);

        label_184 = new QLabel(groupBox_29);
        label_184->setObjectName(QString::fromUtf8("label_184"));
        sizePolicy3.setHeightForWidth(label_184->sizePolicy().hasHeightForWidth());
        label_184->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_184, 20, 1, 1, 1);

        btnBackward11 = new QPushButton(groupBox_29);
        btnBackward11->setObjectName(QString::fromUtf8("btnBackward11"));

        gridLayout_12->addWidget(btnBackward11, 19, 3, 2, 1);

        btnInit5_6 = new QPushButton(groupBox_29);
        btnInit5_6->setObjectName(QString::fromUtf8("btnInit5_6"));
        sizePolicy4.setHeightForWidth(btnInit5_6->sizePolicy().hasHeightForWidth());
        btnInit5_6->setSizePolicy(sizePolicy4);
        btnInit5_6->setMinimumSize(QSize(0, 30));

        gridLayout_12->addWidget(btnInit5_6, 0, 6, 3, 1);

        label_180 = new QLabel(groupBox_29);
        label_180->setObjectName(QString::fromUtf8("label_180"));
        sizePolicy3.setHeightForWidth(label_180->sizePolicy().hasHeightForWidth());
        label_180->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_180, 4, 1, 2, 1);

        label_103 = new QLabel(groupBox_29);
        label_103->setObjectName(QString::fromUtf8("label_103"));
        sizePolicy10.setHeightForWidth(label_103->sizePolicy().hasHeightForWidth());
        label_103->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_103, 16, 0, 3, 1);

        label_88 = new QLabel(groupBox_29);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        sizePolicy10.setHeightForWidth(label_88->sizePolicy().hasHeightForWidth());
        label_88->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_88, 6, 0, 3, 1);

        btnDisMove9_10 = new QPushButton(groupBox_29);
        btnDisMove9_10->setObjectName(QString::fromUtf8("btnDisMove9_10"));
        sizePolicy4.setHeightForWidth(btnDisMove9_10->sizePolicy().hasHeightForWidth());
        btnDisMove9_10->setSizePolicy(sizePolicy4);
        btnDisMove9_10->setMaximumSize(QSize(16777215, 40));

        gridLayout_12->addWidget(btnDisMove9_10, 12, 7, 4, 1);

        spinBox_PosMove11 = new QSpinBox(groupBox_29);
        spinBox_PosMove11->setObjectName(QString::fromUtf8("spinBox_PosMove11"));
        spinBox_PosMove11->setMinimumSize(QSize(50, 0));
        spinBox_PosMove11->setMinimum(-2000);
        spinBox_PosMove11->setMaximum(2000);

        gridLayout_12->addWidget(spinBox_PosMove11, 19, 8, 1, 1);

        label_107 = new QLabel(groupBox_29);
        label_107->setObjectName(QString::fromUtf8("label_107"));
        sizePolicy10.setHeightForWidth(label_107->sizePolicy().hasHeightForWidth());
        label_107->setSizePolicy(sizePolicy10);

        gridLayout_12->addWidget(label_107, 19, 0, 2, 1);

        btnInit9_10 = new QPushButton(groupBox_29);
        btnInit9_10->setObjectName(QString::fromUtf8("btnInit9_10"));
        sizePolicy4.setHeightForWidth(btnInit9_10->sizePolicy().hasHeightForWidth());
        btnInit9_10->setSizePolicy(sizePolicy4);
        btnInit9_10->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnInit9_10, 12, 6, 4, 1);

        label_182 = new QLabel(groupBox_29);
        label_182->setObjectName(QString::fromUtf8("label_182"));
        sizePolicy3.setHeightForWidth(label_182->sizePolicy().hasHeightForWidth());
        label_182->setSizePolicy(sizePolicy3);

        gridLayout_12->addWidget(label_182, 13, 1, 3, 1);

        label_223 = new QLabel(groupBox_29);
        label_223->setObjectName(QString::fromUtf8("label_223"));
        sizePolicy10.setHeightForWidth(label_223->sizePolicy().hasHeightForWidth());
        label_223->setSizePolicy(sizePolicy10);
        label_223->setMaximumSize(QSize(40, 16777215));

        gridLayout_12->addWidget(label_223, 9, 1, 1, 1);

        btnForward7_8 = new QPushButton(groupBox_29);
        btnForward7_8->setObjectName(QString::fromUtf8("btnForward7_8"));
        sizePolicy4.setHeightForWidth(btnForward7_8->sizePolicy().hasHeightForWidth());
        btnForward7_8->setSizePolicy(sizePolicy4);
        btnForward7_8->setMaximumSize(QSize(16777215, 30));
        btnForward7_8->setCheckable(false);

        gridLayout_12->addWidget(btnForward7_8, 6, 5, 3, 1);

        btnDisMove5_6 = new QPushButton(groupBox_29);
        btnDisMove5_6->setObjectName(QString::fromUtf8("btnDisMove5_6"));
        sizePolicy4.setHeightForWidth(btnDisMove5_6->sizePolicy().hasHeightForWidth());
        btnDisMove5_6->setSizePolicy(sizePolicy4);
        btnDisMove5_6->setMinimumSize(QSize(80, 30));
        btnDisMove5_6->setMaximumSize(QSize(16777215, 30));

        gridLayout_12->addWidget(btnDisMove5_6, 0, 7, 3, 1);

        btnBackward8 = new QPushButton(groupBox_29);
        btnBackward8->setObjectName(QString::fromUtf8("btnBackward8"));
        btnBackward8->setEnabled(true);
        sizePolicy9.setHeightForWidth(btnBackward8->sizePolicy().hasHeightForWidth());
        btnBackward8->setSizePolicy(sizePolicy9);

        gridLayout_12->addWidget(btnBackward8, 9, 4, 3, 1);


        gridLayout_14->addLayout(gridLayout_12, 0, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_29, 1, 0, 1, 1);

        groupBox_30 = new QGroupBox(tab_5);
        groupBox_30->setObjectName(QString::fromUtf8("groupBox_30"));
        sizePolicy7.setHeightForWidth(groupBox_30->sizePolicy().hasHeightForWidth());
        groupBox_30->setSizePolicy(sizePolicy7);
        groupBox_30->setMinimumSize(QSize(0, 130));
        groupBox_30->setFont(font);
        groupBox_30->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_4 = new QGridLayout(groupBox_30);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btn_CloseDoor = new QPushButton(groupBox_30);
        btn_CloseDoor->setObjectName(QString::fromUtf8("btn_CloseDoor"));
        sizePolicy9.setHeightForWidth(btn_CloseDoor->sizePolicy().hasHeightForWidth());
        btn_CloseDoor->setSizePolicy(sizePolicy9);
        btn_CloseDoor->setMinimumSize(QSize(100, 0));
        btn_CloseDoor->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(btn_CloseDoor, 1, 0, 1, 1);

        btn_TakePlate = new QPushButton(groupBox_30);
        btn_TakePlate->setObjectName(QString::fromUtf8("btn_TakePlate"));
        sizePolicy14.setHeightForWidth(btn_TakePlate->sizePolicy().hasHeightForWidth());
        btn_TakePlate->setSizePolicy(sizePolicy14);
        btn_TakePlate->setMinimumSize(QSize(100, 0));
        btn_TakePlate->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(btn_TakePlate, 0, 1, 1, 1);

        btn_CoverPlateToAuto = new QPushButton(groupBox_30);
        btn_CoverPlateToAuto->setObjectName(QString::fromUtf8("btn_CoverPlateToAuto"));
        sizePolicy3.setHeightForWidth(btn_CoverPlateToAuto->sizePolicy().hasHeightForWidth());
        btn_CoverPlateToAuto->setSizePolicy(sizePolicy3);
        btn_CoverPlateToAuto->setMinimumSize(QSize(50, 100));
        btn_CoverPlateToAuto->setMaximumSize(QSize(90, 100));
        btn_CoverPlateToAuto->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/ManualToAuto.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_4->addWidget(btn_CoverPlateToAuto, 0, 4, 2, 1);

        btn_OpenDoor = new QPushButton(groupBox_30);
        btn_OpenDoor->setObjectName(QString::fromUtf8("btn_OpenDoor"));
        sizePolicy14.setHeightForWidth(btn_OpenDoor->sizePolicy().hasHeightForWidth());
        btn_OpenDoor->setSizePolicy(sizePolicy14);
        btn_OpenDoor->setMinimumSize(QSize(100, 0));
        btn_OpenDoor->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(btn_OpenDoor, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_30);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy6.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy6);
        groupBox_5->setMinimumSize(QSize(0, 90));
        groupBox_5->setFont(font);
        gridLayout_10 = new QGridLayout(groupBox_5);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_253 = new QLabel(groupBox_5);
        label_253->setObjectName(QString::fromUtf8("label_253"));
        sizePolicy10.setHeightForWidth(label_253->sizePolicy().hasHeightForWidth());
        label_253->setSizePolicy(sizePolicy10);
        label_253->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(label_253);

        lbl_TakeDoor = new QLabel(groupBox_5);
        lbl_TakeDoor->setObjectName(QString::fromUtf8("lbl_TakeDoor"));
        sizePolicy3.setHeightForWidth(lbl_TakeDoor->sizePolicy().hasHeightForWidth());
        lbl_TakeDoor->setSizePolicy(sizePolicy3);
        lbl_TakeDoor->setMinimumSize(QSize(15, 15));
        lbl_TakeDoor->setMaximumSize(QSize(15, 15));
        lbl_TakeDoor->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout->addWidget(lbl_TakeDoor);


        gridLayout_10->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_250 = new QLabel(groupBox_5);
        label_250->setObjectName(QString::fromUtf8("label_250"));
        sizePolicy10.setHeightForWidth(label_250->sizePolicy().hasHeightForWidth());
        label_250->setSizePolicy(sizePolicy10);
        label_250->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(label_250);

        lbl_TakePlate = new QLabel(groupBox_5);
        lbl_TakePlate->setObjectName(QString::fromUtf8("lbl_TakePlate"));
        sizePolicy3.setHeightForWidth(lbl_TakePlate->sizePolicy().hasHeightForWidth());
        lbl_TakePlate->setSizePolicy(sizePolicy3);
        lbl_TakePlate->setMinimumSize(QSize(15, 15));
        lbl_TakePlate->setMaximumSize(QSize(15, 15));
        lbl_TakePlate->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_3->addWidget(lbl_TakePlate);


        gridLayout_10->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_251 = new QLabel(groupBox_5);
        label_251->setObjectName(QString::fromUtf8("label_251"));
        sizePolicy10.setHeightForWidth(label_251->sizePolicy().hasHeightForWidth());
        label_251->setSizePolicy(sizePolicy10);
        label_251->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(label_251);

        lbl_FixPlate = new QLabel(groupBox_5);
        lbl_FixPlate->setObjectName(QString::fromUtf8("lbl_FixPlate"));
        sizePolicy3.setHeightForWidth(lbl_FixPlate->sizePolicy().hasHeightForWidth());
        lbl_FixPlate->setSizePolicy(sizePolicy3);
        lbl_FixPlate->setMinimumSize(QSize(15, 15));
        lbl_FixPlate->setMaximumSize(QSize(15, 15));
        lbl_FixPlate->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_6->addWidget(lbl_FixPlate);


        gridLayout_10->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_322 = new QLabel(groupBox_5);
        label_322->setObjectName(QString::fromUtf8("label_322"));
        sizePolicy10.setHeightForWidth(label_322->sizePolicy().hasHeightForWidth());
        label_322->setSizePolicy(sizePolicy10);
        label_322->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_44->addWidget(label_322);

        lbl_FixDoor = new QLabel(groupBox_5);
        lbl_FixDoor->setObjectName(QString::fromUtf8("lbl_FixDoor"));
        sizePolicy3.setHeightForWidth(lbl_FixDoor->sizePolicy().hasHeightForWidth());
        lbl_FixDoor->setSizePolicy(sizePolicy3);
        lbl_FixDoor->setMinimumSize(QSize(15, 15));
        lbl_FixDoor->setMaximumSize(QSize(15, 15));
        lbl_FixDoor->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_44->addWidget(lbl_FixDoor);


        gridLayout_10->addLayout(horizontalLayout_44, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 3, 0, 1, 5);

        btn_AutoTakePlate = new QPushButton(groupBox_30);
        btn_AutoTakePlate->setObjectName(QString::fromUtf8("btn_AutoTakePlate"));
        sizePolicy14.setHeightForWidth(btn_AutoTakePlate->sizePolicy().hasHeightForWidth());
        btn_AutoTakePlate->setSizePolicy(sizePolicy14);
        btn_AutoTakePlate->setMinimumSize(QSize(100, 0));
        btn_AutoTakePlate->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(btn_AutoTakePlate, 0, 2, 1, 1);

        btn_CoverPlateRapidStop = new QPushButton(groupBox_30);
        btn_CoverPlateRapidStop->setObjectName(QString::fromUtf8("btn_CoverPlateRapidStop"));
        sizePolicy3.setHeightForWidth(btn_CoverPlateRapidStop->sizePolicy().hasHeightForWidth());
        btn_CoverPlateRapidStop->setSizePolicy(sizePolicy3);
        btn_CoverPlateRapidStop->setMinimumSize(QSize(60, 60));
        btn_CoverPlateRapidStop->setMaximumSize(QSize(60, 60));
        btn_CoverPlateRapidStop->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/RapidStop.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_4->addWidget(btn_CoverPlateRapidStop, 0, 3, 2, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_53 = new QLabel(groupBox_30);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        verticalLayout->addWidget(label_53);

        label_60 = new QLabel(groupBox_30);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        verticalLayout->addWidget(label_60);


        horizontalLayout_22->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbl_current9 = new QLabel(groupBox_30);
        lbl_current9->setObjectName(QString::fromUtf8("lbl_current9"));
        lbl_current9->setStyleSheet(QString::fromUtf8("Background:white;"));

        verticalLayout_2->addWidget(lbl_current9);

        lbl_current10 = new QLabel(groupBox_30);
        lbl_current10->setObjectName(QString::fromUtf8("lbl_current10"));
        lbl_current10->setStyleSheet(QString::fromUtf8("Background:white;"));

        verticalLayout_2->addWidget(lbl_current10);


        horizontalLayout_22->addLayout(verticalLayout_2);


        gridLayout_4->addLayout(horizontalLayout_22, 2, 3, 1, 2);

        btn_CoverPlate = new QPushButton(groupBox_30);
        btn_CoverPlate->setObjectName(QString::fromUtf8("btn_CoverPlate"));
        sizePolicy14.setHeightForWidth(btn_CoverPlate->sizePolicy().hasHeightForWidth());
        btn_CoverPlate->setSizePolicy(sizePolicy14);
        btn_CoverPlate->setMinimumSize(QSize(100, 0));
        btn_CoverPlate->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(btn_CoverPlate, 1, 1, 1, 1);

        btn_AutoCoverPlate = new QPushButton(groupBox_30);
        btn_AutoCoverPlate->setObjectName(QString::fromUtf8("btn_AutoCoverPlate"));
        sizePolicy14.setHeightForWidth(btn_AutoCoverPlate->sizePolicy().hasHeightForWidth());
        btn_AutoCoverPlate->setSizePolicy(sizePolicy14);
        btn_AutoCoverPlate->setMinimumSize(QSize(100, 0));
        btn_AutoCoverPlate->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(btn_AutoCoverPlate, 1, 2, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_52 = new QLabel(groupBox_30);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        horizontalLayout_16->addWidget(label_52);

        label_angle = new QLabel(groupBox_30);
        label_angle->setObjectName(QString::fromUtf8("label_angle"));

        horizontalLayout_16->addWidget(label_angle);


        gridLayout_4->addLayout(horizontalLayout_16, 2, 2, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_49 = new QLabel(groupBox_30);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_15->addWidget(label_49);

        label_y = new QLabel(groupBox_30);
        label_y->setObjectName(QString::fromUtf8("label_y"));

        horizontalLayout_15->addWidget(label_y);


        gridLayout_4->addLayout(horizontalLayout_15, 2, 1, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_47 = new QLabel(groupBox_30);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout_13->addWidget(label_47);

        label_x = new QLabel(groupBox_30);
        label_x->setObjectName(QString::fromUtf8("label_x"));

        horizontalLayout_13->addWidget(label_x);


        gridLayout_4->addLayout(horizontalLayout_13, 2, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_30, 2, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_50 = new QGridLayout(tab_4);
        gridLayout_50->setSpacing(6);
        gridLayout_50->setContentsMargins(11, 11, 11, 11);
        gridLayout_50->setObjectName(QString::fromUtf8("gridLayout_50"));
        groupBox_28 = new QGroupBox(tab_4);
        groupBox_28->setObjectName(QString::fromUtf8("groupBox_28"));
        sizePolicy7.setHeightForWidth(groupBox_28->sizePolicy().hasHeightForWidth());
        groupBox_28->setSizePolicy(sizePolicy7);
        groupBox_28->setMinimumSize(QSize(0, 200));
        groupBox_28->setMaximumSize(QSize(16777215, 16777215));
        groupBox_28->setFont(font);
        groupBox_28->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_9 = new QGridLayout(groupBox_28);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox_15 = new QGroupBox(groupBox_28);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        gridLayout_47 = new QGridLayout(groupBox_15);
        gridLayout_47->setSpacing(6);
        gridLayout_47->setContentsMargins(11, 11, 11, 11);
        gridLayout_47->setObjectName(QString::fromUtf8("gridLayout_47"));
        gridLayout_31 = new QGridLayout();
        gridLayout_31->setSpacing(6);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setHorizontalSpacing(5);
        gridLayout_31->setVerticalSpacing(7);
        label_10 = new QLabel(groupBox_15);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy5.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy5);
        label_10->setMinimumSize(QSize(30, 0));

        gridLayout_31->addWidget(label_10, 0, 0, 1, 1);

        label_96 = new QLabel(groupBox_15);
        label_96->setObjectName(QString::fromUtf8("label_96"));

        gridLayout_31->addWidget(label_96, 0, 11, 1, 1);

        lbl_PlatformIsTarget = new QLabel(groupBox_15);
        lbl_PlatformIsTarget->setObjectName(QString::fromUtf8("lbl_PlatformIsTarget"));
        sizePolicy5.setHeightForWidth(lbl_PlatformIsTarget->sizePolicy().hasHeightForWidth());
        lbl_PlatformIsTarget->setSizePolicy(sizePolicy5);
        lbl_PlatformIsTarget->setMinimumSize(QSize(50, 0));

        gridLayout_31->addWidget(lbl_PlatformIsTarget, 1, 12, 1, 1);

        lbl_PlatformInfoRy = new QLabel(groupBox_15);
        lbl_PlatformInfoRy->setObjectName(QString::fromUtf8("lbl_PlatformInfoRy"));
        sizePolicy16.setHeightForWidth(lbl_PlatformInfoRy->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoRy->setSizePolicy(sizePolicy16);
        lbl_PlatformInfoRy->setMinimumSize(QSize(40, 18));
        lbl_PlatformInfoRy->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(lbl_PlatformInfoRy, 1, 4, 1, 2);

        lbl_PlatformInfoZ = new QLabel(groupBox_15);
        lbl_PlatformInfoZ->setObjectName(QString::fromUtf8("lbl_PlatformInfoZ"));
        sizePolicy16.setHeightForWidth(lbl_PlatformInfoZ->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoZ->setSizePolicy(sizePolicy16);
        lbl_PlatformInfoZ->setMinimumSize(QSize(40, 18));
        lbl_PlatformInfoZ->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(lbl_PlatformInfoZ, 0, 7, 1, 2);

        label_56 = new QLabel(groupBox_15);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        sizePolicy5.setHeightForWidth(label_56->sizePolicy().hasHeightForWidth());
        label_56->setSizePolicy(sizePolicy5);
        label_56->setMinimumSize(QSize(30, 0));

        gridLayout_31->addWidget(label_56, 1, 3, 1, 1);

        label_55 = new QLabel(groupBox_15);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        sizePolicy5.setHeightForWidth(label_55->sizePolicy().hasHeightForWidth());
        label_55->setSizePolicy(sizePolicy5);
        label_55->setMinimumSize(QSize(30, 0));

        gridLayout_31->addWidget(label_55, 1, 6, 1, 1);

        lbl_PlatformStatus = new QLabel(groupBox_15);
        lbl_PlatformStatus->setObjectName(QString::fromUtf8("lbl_PlatformStatus"));

        gridLayout_31->addWidget(lbl_PlatformStatus, 1, 10, 1, 1);

        label_95 = new QLabel(groupBox_15);
        label_95->setObjectName(QString::fromUtf8("label_95"));
        sizePolicy6.setHeightForWidth(label_95->sizePolicy().hasHeightForWidth());
        label_95->setSizePolicy(sizePolicy6);

        gridLayout_31->addWidget(label_95, 1, 9, 1, 1);

        label_57 = new QLabel(groupBox_15);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        sizePolicy5.setHeightForWidth(label_57->sizePolicy().hasHeightForWidth());
        label_57->setSizePolicy(sizePolicy5);
        label_57->setMinimumSize(QSize(30, 0));

        gridLayout_31->addWidget(label_57, 1, 0, 1, 1);

        label_100 = new QLabel(groupBox_15);
        label_100->setObjectName(QString::fromUtf8("label_100"));

        gridLayout_31->addWidget(label_100, 1, 11, 1, 1);

        lbl_PlatformInfoRx = new QLabel(groupBox_15);
        lbl_PlatformInfoRx->setObjectName(QString::fromUtf8("lbl_PlatformInfoRx"));
        sizePolicy16.setHeightForWidth(lbl_PlatformInfoRx->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoRx->setSizePolicy(sizePolicy16);
        lbl_PlatformInfoRx->setMinimumSize(QSize(40, 18));
        lbl_PlatformInfoRx->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(lbl_PlatformInfoRx, 1, 1, 1, 2);

        lbl_PlatformEnable = new QLabel(groupBox_15);
        lbl_PlatformEnable->setObjectName(QString::fromUtf8("lbl_PlatformEnable"));
        sizePolicy5.setHeightForWidth(lbl_PlatformEnable->sizePolicy().hasHeightForWidth());
        lbl_PlatformEnable->setSizePolicy(sizePolicy5);
        lbl_PlatformEnable->setMinimumSize(QSize(50, 0));

        gridLayout_31->addWidget(lbl_PlatformEnable, 0, 12, 1, 1);

        label_54 = new QLabel(groupBox_15);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        sizePolicy5.setHeightForWidth(label_54->sizePolicy().hasHeightForWidth());
        label_54->setSizePolicy(sizePolicy5);
        label_54->setMinimumSize(QSize(30, 0));

        gridLayout_31->addWidget(label_54, 0, 6, 1, 1);

        lbl_PlatformInfoY = new QLabel(groupBox_15);
        lbl_PlatformInfoY->setObjectName(QString::fromUtf8("lbl_PlatformInfoY"));
        sizePolicy16.setHeightForWidth(lbl_PlatformInfoY->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoY->setSizePolicy(sizePolicy16);
        lbl_PlatformInfoY->setMinimumSize(QSize(40, 18));
        lbl_PlatformInfoY->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(lbl_PlatformInfoY, 0, 4, 1, 2);

        label_44 = new QLabel(groupBox_15);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        sizePolicy5.setHeightForWidth(label_44->sizePolicy().hasHeightForWidth());
        label_44->setSizePolicy(sizePolicy5);
        label_44->setMinimumSize(QSize(30, 0));

        gridLayout_31->addWidget(label_44, 0, 3, 1, 1);

        label_94 = new QLabel(groupBox_15);
        label_94->setObjectName(QString::fromUtf8("label_94"));
        sizePolicy6.setHeightForWidth(label_94->sizePolicy().hasHeightForWidth());
        label_94->setSizePolicy(sizePolicy6);
        label_94->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(label_94, 0, 9, 1, 1);

        lbl_PlatformInfoX = new QLabel(groupBox_15);
        lbl_PlatformInfoX->setObjectName(QString::fromUtf8("lbl_PlatformInfoX"));
        sizePolicy16.setHeightForWidth(lbl_PlatformInfoX->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoX->setSizePolicy(sizePolicy16);
        lbl_PlatformInfoX->setMinimumSize(QSize(40, 18));
        lbl_PlatformInfoX->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_PlatformInfoX->setOpenExternalLinks(false);

        gridLayout_31->addWidget(lbl_PlatformInfoX, 0, 1, 1, 2);

        lbl_PlatformWarning = new QLabel(groupBox_15);
        lbl_PlatformWarning->setObjectName(QString::fromUtf8("lbl_PlatformWarning"));

        gridLayout_31->addWidget(lbl_PlatformWarning, 0, 10, 1, 1);

        lbl_PlatformInfoRz = new QLabel(groupBox_15);
        lbl_PlatformInfoRz->setObjectName(QString::fromUtf8("lbl_PlatformInfoRz"));
        sizePolicy5.setHeightForWidth(lbl_PlatformInfoRz->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoRz->setSizePolicy(sizePolicy5);
        lbl_PlatformInfoRz->setMinimumSize(QSize(40, 18));
        lbl_PlatformInfoRz->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_31->addWidget(lbl_PlatformInfoRz, 1, 7, 1, 2);


        gridLayout_47->addLayout(gridLayout_31, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_15, 1, 0, 1, 4);

        groupBox_11 = new QGroupBox(groupBox_28);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setSizeIncrement(QSize(80, 30));
        groupBox_11->setBaseSize(QSize(80, 30));
        gridLayout_8 = new QGridLayout(groupBox_11);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_79 = new QLabel(groupBox_11);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        sizePolicy10.setHeightForWidth(label_79->sizePolicy().hasHeightForWidth());
        label_79->setSizePolicy(sizePolicy10);
        label_79->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_79, 0, 0, 1, 1);

        SpinBox_PlatformMoveRx = new QDoubleSpinBox(groupBox_11);
        SpinBox_PlatformMoveRx->setObjectName(QString::fromUtf8("SpinBox_PlatformMoveRx"));
        SpinBox_PlatformMoveRx->setMinimum(-99.000000000000000);
        SpinBox_PlatformMoveRx->setSingleStep(0.100000000000000);
        SpinBox_PlatformMoveRx->setValue(0.000000000000000);

        gridLayout_8->addWidget(SpinBox_PlatformMoveRx, 0, 7, 1, 1);

        label_93 = new QLabel(groupBox_11);
        label_93->setObjectName(QString::fromUtf8("label_93"));
        sizePolicy5.setHeightForWidth(label_93->sizePolicy().hasHeightForWidth());
        label_93->setSizePolicy(sizePolicy5);
        label_93->setMinimumSize(QSize(50, 0));
        label_93->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_93, 0, 4, 1, 1);

        label_85 = new QLabel(groupBox_11);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        sizePolicy10.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy10);
        label_85->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_85, 0, 6, 1, 1);

        SpinBox_PlatformMoveX = new QDoubleSpinBox(groupBox_11);
        SpinBox_PlatformMoveX->setObjectName(QString::fromUtf8("SpinBox_PlatformMoveX"));
        SpinBox_PlatformMoveX->setMinimum(-99.000000000000000);
        SpinBox_PlatformMoveX->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(SpinBox_PlatformMoveX, 0, 1, 1, 1);

        label_86 = new QLabel(groupBox_11);
        label_86->setObjectName(QString::fromUtf8("label_86"));
        sizePolicy10.setHeightForWidth(label_86->sizePolicy().hasHeightForWidth());
        label_86->setSizePolicy(sizePolicy10);
        label_86->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_86, 0, 8, 1, 1);

        SpinBox_PlatformMoveRz = new QDoubleSpinBox(groupBox_11);
        SpinBox_PlatformMoveRz->setObjectName(QString::fromUtf8("SpinBox_PlatformMoveRz"));
        SpinBox_PlatformMoveRz->setMinimum(-99.000000000000000);
        SpinBox_PlatformMoveRz->setSingleStep(0.100000000000000);
        SpinBox_PlatformMoveRz->setValue(0.000000000000000);

        gridLayout_8->addWidget(SpinBox_PlatformMoveRz, 0, 11, 1, 1);

        SpinBox_PlatformMoveY = new QDoubleSpinBox(groupBox_11);
        SpinBox_PlatformMoveY->setObjectName(QString::fromUtf8("SpinBox_PlatformMoveY"));
        SpinBox_PlatformMoveY->setMinimum(-99.000000000000000);
        SpinBox_PlatformMoveY->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(SpinBox_PlatformMoveY, 0, 3, 1, 1);

        SpinBox_PlatformMoveZ = new QDoubleSpinBox(groupBox_11);
        SpinBox_PlatformMoveZ->setObjectName(QString::fromUtf8("SpinBox_PlatformMoveZ"));
        SpinBox_PlatformMoveZ->setMinimum(-99.000000000000000);
        SpinBox_PlatformMoveZ->setSingleStep(0.100000000000000);

        gridLayout_8->addWidget(SpinBox_PlatformMoveZ, 0, 5, 1, 1);

        SpinBox_PlatformMoveRy = new QDoubleSpinBox(groupBox_11);
        SpinBox_PlatformMoveRy->setObjectName(QString::fromUtf8("SpinBox_PlatformMoveRy"));
        SpinBox_PlatformMoveRy->setMinimum(-99.000000000000000);
        SpinBox_PlatformMoveRy->setSingleStep(0.100000000000000);
        SpinBox_PlatformMoveRy->setValue(0.000000000000000);

        gridLayout_8->addWidget(SpinBox_PlatformMoveRy, 0, 9, 1, 1);

        label_87 = new QLabel(groupBox_11);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        sizePolicy5.setHeightForWidth(label_87->sizePolicy().hasHeightForWidth());
        label_87->setSizePolicy(sizePolicy5);
        label_87->setMinimumSize(QSize(65, 0));
        label_87->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_87, 0, 10, 1, 1);

        label_80 = new QLabel(groupBox_11);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        sizePolicy10.setHeightForWidth(label_80->sizePolicy().hasHeightForWidth());
        label_80->setSizePolicy(sizePolicy10);
        label_80->setMaximumSize(QSize(65, 16777215));

        gridLayout_8->addWidget(label_80, 0, 2, 1, 1);


        gridLayout_9->addWidget(groupBox_11, 0, 0, 1, 4);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        btn_PlatformGo = new QPushButton(groupBox_28);
        btn_PlatformGo->setObjectName(QString::fromUtf8("btn_PlatformGo"));
        btn_PlatformGo->setEnabled(true);

        horizontalLayout_27->addWidget(btn_PlatformGo);

        btn_PlatformStop = new QPushButton(groupBox_28);
        btn_PlatformStop->setObjectName(QString::fromUtf8("btn_PlatformStop"));
        btn_PlatformStop->setEnabled(true);

        horizontalLayout_27->addWidget(btn_PlatformStop);


        gridLayout_9->addLayout(horizontalLayout_27, 2, 1, 1, 1);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        btn_PlatformOpen = new QPushButton(groupBox_28);
        btn_PlatformOpen->setObjectName(QString::fromUtf8("btn_PlatformOpen"));

        horizontalLayout_26->addWidget(btn_PlatformOpen);

        btn_PlatformClose = new QPushButton(groupBox_28);
        btn_PlatformClose->setObjectName(QString::fromUtf8("btn_PlatformClose"));
        btn_PlatformClose->setEnabled(true);

        horizontalLayout_26->addWidget(btn_PlatformClose);


        gridLayout_9->addLayout(horizontalLayout_26, 2, 0, 1, 1);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        btn_PlatformInitial = new QPushButton(groupBox_28);
        btn_PlatformInitial->setObjectName(QString::fromUtf8("btn_PlatformInitial"));
        btn_PlatformInitial->setEnabled(true);

        horizontalLayout_29->addWidget(btn_PlatformInitial);

        btn_PlatformGoZero = new QPushButton(groupBox_28);
        btn_PlatformGoZero->setObjectName(QString::fromUtf8("btn_PlatformGoZero"));
        btn_PlatformGoZero->setEnabled(true);

        horizontalLayout_29->addWidget(btn_PlatformGoZero);


        gridLayout_9->addLayout(horizontalLayout_29, 2, 2, 1, 1);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        btn_PlatformLeveling = new QPushButton(groupBox_28);
        btn_PlatformLeveling->setObjectName(QString::fromUtf8("btn_PlatformLeveling"));

        horizontalLayout_30->addWidget(btn_PlatformLeveling);

        btn_PlatformReset = new QPushButton(groupBox_28);
        btn_PlatformReset->setObjectName(QString::fromUtf8("btn_PlatformReset"));
        btn_PlatformReset->setEnabled(true);

        horizontalLayout_30->addWidget(btn_PlatformReset);


        gridLayout_9->addLayout(horizontalLayout_30, 2, 3, 1, 1);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_61 = new QLabel(groupBox_28);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        horizontalLayout_31->addWidget(label_61);

        groypitch = new QLabel(groupBox_28);
        groypitch->setObjectName(QString::fromUtf8("groypitch"));

        horizontalLayout_31->addWidget(groypitch);


        gridLayout_9->addLayout(horizontalLayout_31, 4, 0, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_62 = new QLabel(groupBox_28);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        horizontalLayout_32->addWidget(label_62);

        groyroll = new QLabel(groupBox_28);
        groyroll->setObjectName(QString::fromUtf8("groyroll"));

        horizontalLayout_32->addWidget(groyroll);


        gridLayout_9->addLayout(horizontalLayout_32, 4, 1, 1, 1);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_63 = new QLabel(groupBox_28);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        horizontalLayout_24->addWidget(label_63);

        final_x = new QLabel(groupBox_28);
        final_x->setObjectName(QString::fromUtf8("final_x"));

        horizontalLayout_24->addWidget(final_x);


        gridLayout_9->addLayout(horizontalLayout_24, 4, 2, 1, 1);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_66 = new QLabel(groupBox_28);
        label_66->setObjectName(QString::fromUtf8("label_66"));

        horizontalLayout_33->addWidget(label_66);

        final_y = new QLabel(groupBox_28);
        final_y->setObjectName(QString::fromUtf8("final_y"));

        horizontalLayout_33->addWidget(final_y);


        gridLayout_9->addLayout(horizontalLayout_33, 4, 3, 1, 1);


        gridLayout_50->addWidget(groupBox_28, 4, 0, 1, 1);

        groupBox_18 = new QGroupBox(tab_4);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setFont(font);
        groupBox_18->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_45 = new QGridLayout(groupBox_18);
        gridLayout_45->setSpacing(6);
        gridLayout_45->setContentsMargins(11, 11, 11, 11);
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_32 = new QGridLayout();
        gridLayout_32->setSpacing(6);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(6);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        label_111 = new QLabel(groupBox_18);
        label_111->setObjectName(QString::fromUtf8("label_111"));
        label_111->setFont(font6);

        horizontalLayout_46->addWidget(label_111);

        spinBox_PosAbsMove12 = new QSpinBox(groupBox_18);
        spinBox_PosAbsMove12->setObjectName(QString::fromUtf8("spinBox_PosAbsMove12"));
        spinBox_PosAbsMove12->setMinimum(0);
        spinBox_PosAbsMove12->setMaximum(2700);

        horizontalLayout_46->addWidget(spinBox_PosAbsMove12);


        gridLayout_32->addLayout(horizontalLayout_46, 0, 6, 1, 1);

        label_97 = new QLabel(groupBox_18);
        label_97->setObjectName(QString::fromUtf8("label_97"));
        sizePolicy3.setHeightForWidth(label_97->sizePolicy().hasHeightForWidth());
        label_97->setSizePolicy(sizePolicy3);

        gridLayout_32->addWidget(label_97, 1, 1, 1, 1);

        lblAxisStatusColor12 = new QLabel(groupBox_18);
        lblAxisStatusColor12->setObjectName(QString::fromUtf8("lblAxisStatusColor12"));
        sizePolicy2.setHeightForWidth(lblAxisStatusColor12->sizePolicy().hasHeightForWidth());
        lblAxisStatusColor12->setSizePolicy(sizePolicy2);
        lblAxisStatusColor12->setMinimumSize(QSize(15, 15));
        lblAxisStatusColor12->setMaximumSize(QSize(15, 15));
        lblAxisStatusColor12->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_32->addWidget(lblAxisStatusColor12, 0, 2, 1, 1);

        btn_LiftRapidStop = new QPushButton(groupBox_18);
        btn_LiftRapidStop->setObjectName(QString::fromUtf8("btn_LiftRapidStop"));
        sizePolicy3.setHeightForWidth(btn_LiftRapidStop->sizePolicy().hasHeightForWidth());
        btn_LiftRapidStop->setSizePolicy(sizePolicy3);
        btn_LiftRapidStop->setMinimumSize(QSize(60, 60));
        btn_LiftRapidStop->setMaximumSize(QSize(60, 60));
        btn_LiftRapidStop->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/RapidStop.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_32->addWidget(btn_LiftRapidStop, 0, 8, 2, 1);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setSpacing(6);
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        label_112 = new QLabel(groupBox_18);
        label_112->setObjectName(QString::fromUtf8("label_112"));
        label_112->setFont(font6);

        horizontalLayout_47->addWidget(label_112);

        spinBox_PosMove12 = new QSpinBox(groupBox_18);
        spinBox_PosMove12->setObjectName(QString::fromUtf8("spinBox_PosMove12"));
        spinBox_PosMove12->setMinimum(-1000);
        spinBox_PosMove12->setMaximum(2000);

        horizontalLayout_47->addWidget(spinBox_PosMove12);


        gridLayout_32->addLayout(horizontalLayout_47, 1, 6, 1, 1);

        label_99 = new QLabel(groupBox_18);
        label_99->setObjectName(QString::fromUtf8("label_99"));
        sizePolicy10.setHeightForWidth(label_99->sizePolicy().hasHeightForWidth());
        label_99->setSizePolicy(sizePolicy10);
        label_99->setMaximumSize(QSize(80, 16777215));

        gridLayout_32->addWidget(label_99, 0, 0, 2, 1);

        lbl_LiftPosi12 = new QLabel(groupBox_18);
        lbl_LiftPosi12->setObjectName(QString::fromUtf8("lbl_LiftPosi12"));
        sizePolicy3.setHeightForWidth(lbl_LiftPosi12->sizePolicy().hasHeightForWidth());
        lbl_LiftPosi12->setSizePolicy(sizePolicy3);
        lbl_LiftPosi12->setMinimumSize(QSize(50, 0));
        lbl_LiftPosi12->setMaximumSize(QSize(50, 16777215));

        gridLayout_32->addWidget(lbl_LiftPosi12, 1, 2, 1, 1);

        btn_LiftToAuto = new QPushButton(groupBox_18);
        btn_LiftToAuto->setObjectName(QString::fromUtf8("btn_LiftToAuto"));
        sizePolicy3.setHeightForWidth(btn_LiftToAuto->sizePolicy().hasHeightForWidth());
        btn_LiftToAuto->setSizePolicy(sizePolicy3);
        btn_LiftToAuto->setMinimumSize(QSize(90, 100));
        btn_LiftToAuto->setMaximumSize(QSize(90, 100));
        btn_LiftToAuto->setStyleSheet(QString::fromUtf8("background-color: transparent; \n"
" border-image: url(:/ManualToAuto.svg) 0 stretch;\n"
"border: 2px solid black; "));

        gridLayout_32->addWidget(btn_LiftToAuto, 0, 9, 2, 1);

        btnForward12 = new QPushButton(groupBox_18);
        btnForward12->setObjectName(QString::fromUtf8("btnForward12"));
        sizePolicy6.setHeightForWidth(btnForward12->sizePolicy().hasHeightForWidth());
        btnForward12->setSizePolicy(sizePolicy6);
        btnForward12->setMinimumSize(QSize(90, 0));
        btnForward12->setMaximumSize(QSize(16777215, 25));

        gridLayout_32->addWidget(btnForward12, 0, 3, 1, 1);

        btnZero12 = new QPushButton(groupBox_18);
        btnZero12->setObjectName(QString::fromUtf8("btnZero12"));
        sizePolicy6.setHeightForWidth(btnZero12->sizePolicy().hasHeightForWidth());
        btnZero12->setSizePolicy(sizePolicy6);
        btnZero12->setMaximumSize(QSize(16777215, 25));

        gridLayout_32->addWidget(btnZero12, 1, 4, 1, 1);

        label_218 = new QLabel(groupBox_18);
        label_218->setObjectName(QString::fromUtf8("label_218"));
        sizePolicy3.setHeightForWidth(label_218->sizePolicy().hasHeightForWidth());
        label_218->setSizePolicy(sizePolicy3);
        label_218->setMaximumSize(QSize(40, 16777215));

        gridLayout_32->addWidget(label_218, 0, 1, 1, 1);

        btnBackward12 = new QPushButton(groupBox_18);
        btnBackward12->setObjectName(QString::fromUtf8("btnBackward12"));
        sizePolicy6.setHeightForWidth(btnBackward12->sizePolicy().hasHeightForWidth());
        btnBackward12->setSizePolicy(sizePolicy6);
        btnBackward12->setMaximumSize(QSize(16777215, 25));

        gridLayout_32->addWidget(btnBackward12, 1, 3, 1, 1);

        btnInit12 = new QPushButton(groupBox_18);
        btnInit12->setObjectName(QString::fromUtf8("btnInit12"));
        sizePolicy6.setHeightForWidth(btnInit12->sizePolicy().hasHeightForWidth());
        btnInit12->setSizePolicy(sizePolicy6);
        btnInit12->setMaximumSize(QSize(16777215, 25));

        gridLayout_32->addWidget(btnInit12, 0, 4, 1, 1);

        btnDisAbsMove12 = new QPushButton(groupBox_18);
        btnDisAbsMove12->setObjectName(QString::fromUtf8("btnDisAbsMove12"));
        btnDisAbsMove12->setMinimumSize(QSize(100, 0));

        gridLayout_32->addWidget(btnDisAbsMove12, 0, 5, 1, 1);

        btnDisMove12 = new QPushButton(groupBox_18);
        btnDisMove12->setObjectName(QString::fromUtf8("btnDisMove12"));
        btnDisMove12->setMinimumSize(QSize(100, 0));

        gridLayout_32->addWidget(btnDisMove12, 1, 5, 1, 1);


        gridLayout_45->addLayout(gridLayout_32, 0, 0, 1, 1);


        gridLayout_50->addWidget(groupBox_18, 0, 0, 1, 1);

        groupBox_21 = new QGroupBox(tab_4);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        groupBox_21->setFont(font);
        groupBox_21->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_48 = new QGridLayout(groupBox_21);
        gridLayout_48->setSpacing(6);
        gridLayout_48->setContentsMargins(11, 11, 11, 11);
        gridLayout_48->setObjectName(QString::fromUtf8("gridLayout_48"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setHorizontalSpacing(40);
        label_132 = new QLabel(groupBox_21);
        label_132->setObjectName(QString::fromUtf8("label_132"));
        sizePolicy3.setHeightForWidth(label_132->sizePolicy().hasHeightForWidth());
        label_132->setSizePolicy(sizePolicy3);
        label_132->setMaximumSize(QSize(120, 16777215));

        gridLayout_13->addWidget(label_132, 0, 5, 1, 1);

        lbl_GapWidth_y = new QLabel(groupBox_21);
        lbl_GapWidth_y->setObjectName(QString::fromUtf8("lbl_GapWidth_y"));
        sizePolicy10.setHeightForWidth(lbl_GapWidth_y->sizePolicy().hasHeightForWidth());
        lbl_GapWidth_y->setSizePolicy(sizePolicy10);
        lbl_GapWidth_y->setMinimumSize(QSize(50, 0));
        lbl_GapWidth_y->setMaximumSize(QSize(50, 16777215));
        lbl_GapWidth_y->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(lbl_GapWidth_y, 2, 6, 1, 1);

        btn_auto_descent = new QPushButton(groupBox_21);
        btn_auto_descent->setObjectName(QString::fromUtf8("btn_auto_descent"));
        btn_auto_descent->setEnabled(true);

        gridLayout_13->addWidget(btn_auto_descent, 0, 2, 1, 1);

        light2_value = new QSpinBox(groupBox_21);
        light2_value->setObjectName(QString::fromUtf8("light2_value"));
        light2_value->setMaximum(255);

        gridLayout_13->addWidget(light2_value, 6, 4, 1, 1);

        btn_CheckStatus = new QPushButton(groupBox_21);
        btn_CheckStatus->setObjectName(QString::fromUtf8("btn_CheckStatus"));
        btn_CheckStatus->setEnabled(true);
        sizePolicy9.setHeightForWidth(btn_CheckStatus->sizePolicy().hasHeightForWidth());
        btn_CheckStatus->setSizePolicy(sizePolicy9);
        btn_CheckStatus->setMinimumSize(QSize(100, 0));

        gridLayout_13->addWidget(btn_CheckStatus, 0, 1, 1, 1);

        lbl_GapWidth_x = new QLabel(groupBox_21);
        lbl_GapWidth_x->setObjectName(QString::fromUtf8("lbl_GapWidth_x"));
        sizePolicy10.setHeightForWidth(lbl_GapWidth_x->sizePolicy().hasHeightForWidth());
        lbl_GapWidth_x->setSizePolicy(sizePolicy10);
        lbl_GapWidth_x->setMinimumSize(QSize(50, 0));
        lbl_GapWidth_x->setMaximumSize(QSize(50, 16777215));

        gridLayout_13->addWidget(lbl_GapWidth_x, 0, 6, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_48 = new QLabel(groupBox_21);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_19->addWidget(label_48);

        x_offset = new QDoubleSpinBox(groupBox_21);
        x_offset->setObjectName(QString::fromUtf8("x_offset"));
        x_offset->setMinimum(-99.000000000000000);
        x_offset->setSingleStep(0.100000000000000);

        horizontalLayout_19->addWidget(x_offset);


        gridLayout_13->addLayout(horizontalLayout_19, 2, 1, 1, 1);

        light1_value = new QSpinBox(groupBox_21);
        light1_value->setObjectName(QString::fromUtf8("light1_value"));
        light1_value->setMaximum(255);

        gridLayout_13->addWidget(light1_value, 0, 4, 1, 1);

        btn_stop_secondry = new QPushButton(groupBox_21);
        btn_stop_secondry->setObjectName(QString::fromUtf8("btn_stop_secondry"));
        btn_stop_secondry->setEnabled(true);

        gridLayout_13->addWidget(btn_stop_secondry, 6, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label2222 = new QLabel(groupBox_21);
        label2222->setObjectName(QString::fromUtf8("label2222"));

        horizontalLayout_21->addWidget(label2222);

        rz_offset = new QDoubleSpinBox(groupBox_21);
        rz_offset->setObjectName(QString::fromUtf8("rz_offset"));
        rz_offset->setMinimum(-10.000000000000000);
        rz_offset->setMaximum(10.000000000000000);
        rz_offset->setSingleStep(0.100000000000000);

        horizontalLayout_21->addWidget(rz_offset);


        gridLayout_13->addLayout(horizontalLayout_21, 2, 3, 1, 1);

        label_129 = new QLabel(groupBox_21);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        sizePolicy3.setHeightForWidth(label_129->sizePolicy().hasHeightForWidth());
        label_129->setSizePolicy(sizePolicy3);
        label_129->setMaximumSize(QSize(120, 16777215));

        gridLayout_13->addWidget(label_129, 6, 5, 1, 1);

        label_58 = new QLabel(groupBox_21);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_13->addWidget(label_58, 6, 3, 1, 1);

        btn_StatusModifyLatter = new QPushButton(groupBox_21);
        btn_StatusModifyLatter->setObjectName(QString::fromUtf8("btn_StatusModifyLatter"));
        btn_StatusModifyLatter->setEnabled(true);
        sizePolicy17.setHeightForWidth(btn_StatusModifyLatter->sizePolicy().hasHeightForWidth());
        btn_StatusModifyLatter->setSizePolicy(sizePolicy17);

        gridLayout_13->addWidget(btn_StatusModifyLatter, 6, 1, 1, 1);

        label_59 = new QLabel(groupBox_21);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_13->addWidget(label_59, 0, 3, 1, 1);

        btn_secondary_lift = new QPushButton(groupBox_21);
        btn_secondary_lift->setObjectName(QString::fromUtf8("btn_secondary_lift"));
        btn_secondary_lift->setEnabled(true);

        gridLayout_13->addWidget(btn_secondary_lift, 0, 0, 1, 1);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_51 = new QLabel(groupBox_21);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        horizontalLayout_20->addWidget(label_51);

        y_offset = new QDoubleSpinBox(groupBox_21);
        y_offset->setObjectName(QString::fromUtf8("y_offset"));
        y_offset->setMinimum(-99.000000000000000);
        y_offset->setSingleStep(0.100000000000000);
        y_offset->setValue(0.000000000000000);

        horizontalLayout_20->addWidget(y_offset);


        gridLayout_13->addLayout(horizontalLayout_20, 2, 2, 1, 1);

        distance1 = new QLabel(groupBox_21);
        distance1->setObjectName(QString::fromUtf8("distance1"));

        gridLayout_13->addWidget(distance1, 2, 0, 1, 1);

        lbl_GapAngle = new QLabel(groupBox_21);
        lbl_GapAngle->setObjectName(QString::fromUtf8("lbl_GapAngle"));
        sizePolicy10.setHeightForWidth(lbl_GapAngle->sizePolicy().hasHeightForWidth());
        lbl_GapAngle->setSizePolicy(sizePolicy10);
        lbl_GapAngle->setMinimumSize(QSize(50, 0));
        lbl_GapAngle->setMaximumSize(QSize(50, 16777215));

        gridLayout_13->addWidget(lbl_GapAngle, 6, 6, 1, 1);

        label_133 = new QLabel(groupBox_21);
        label_133->setObjectName(QString::fromUtf8("label_133"));
        sizePolicy3.setHeightForWidth(label_133->sizePolicy().hasHeightForWidth());
        label_133->setSizePolicy(sizePolicy3);
        label_133->setMaximumSize(QSize(120, 16777215));

        gridLayout_13->addWidget(label_133, 2, 5, 1, 1);


        gridLayout_48->addLayout(gridLayout_13, 0, 0, 1, 1);


        gridLayout_50->addWidget(groupBox_21, 1, 0, 1, 1);

        groupBox_13 = new QGroupBox(tab_4);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        sizePolicy7.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy7);
        groupBox_13->setMinimumSize(QSize(0, 180));
        groupBox_13->setFont(font);
        groupBox_13->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_22 = new QGridLayout(groupBox_13);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        groupBox_27 = new QGroupBox(groupBox_13);
        groupBox_27->setObjectName(QString::fromUtf8("groupBox_27"));
        groupBox_27->setMinimumSize(QSize(0, 100));
        gridLayout_27 = new QGridLayout(groupBox_27);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_20 = new QGridLayout();
        gridLayout_20->setSpacing(6);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setHorizontalSpacing(20);
        label_13 = new QLabel(groupBox_27);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy10.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy10);

        gridLayout_20->addWidget(label_13, 0, 0, 1, 1);

        lbl_FX = new QLabel(groupBox_27);
        lbl_FX->setObjectName(QString::fromUtf8("lbl_FX"));

        gridLayout_20->addWidget(lbl_FX, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_27);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_20->addWidget(label_16, 0, 2, 1, 1);

        lbl_FY = new QLabel(groupBox_27);
        lbl_FY->setObjectName(QString::fromUtf8("lbl_FY"));

        gridLayout_20->addWidget(lbl_FY, 0, 3, 1, 1);

        label_17 = new QLabel(groupBox_27);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_20->addWidget(label_17, 0, 4, 1, 1);

        lbl_FZ = new QLabel(groupBox_27);
        lbl_FZ->setObjectName(QString::fromUtf8("lbl_FZ"));

        gridLayout_20->addWidget(lbl_FZ, 0, 5, 1, 1);

        label_108 = new QLabel(groupBox_27);
        label_108->setObjectName(QString::fromUtf8("label_108"));
        sizePolicy10.setHeightForWidth(label_108->sizePolicy().hasHeightForWidth());
        label_108->setSizePolicy(sizePolicy10);

        gridLayout_20->addWidget(label_108, 1, 0, 1, 1);

        lbl_MX = new QLabel(groupBox_27);
        lbl_MX->setObjectName(QString::fromUtf8("lbl_MX"));

        gridLayout_20->addWidget(lbl_MX, 1, 1, 1, 1);

        label_115 = new QLabel(groupBox_27);
        label_115->setObjectName(QString::fromUtf8("label_115"));

        gridLayout_20->addWidget(label_115, 1, 2, 1, 1);

        lbl_MY = new QLabel(groupBox_27);
        lbl_MY->setObjectName(QString::fromUtf8("lbl_MY"));

        gridLayout_20->addWidget(lbl_MY, 1, 3, 1, 1);

        label_116 = new QLabel(groupBox_27);
        label_116->setObjectName(QString::fromUtf8("label_116"));

        gridLayout_20->addWidget(label_116, 1, 4, 1, 1);

        lbl_MZ = new QLabel(groupBox_27);
        lbl_MZ->setObjectName(QString::fromUtf8("lbl_MZ"));

        gridLayout_20->addWidget(lbl_MZ, 1, 5, 1, 1);


        gridLayout_27->addLayout(gridLayout_20, 0, 0, 1, 1);


        horizontalLayout_14->addWidget(groupBox_27);

        groupBox_32 = new QGroupBox(groupBox_13);
        groupBox_32->setObjectName(QString::fromUtf8("groupBox_32"));
        sizePolicy2.setHeightForWidth(groupBox_32->sizePolicy().hasHeightForWidth());
        groupBox_32->setSizePolicy(sizePolicy2);
        groupBox_32->setMinimumSize(QSize(450, 100));
        horizontalLayout_4 = new QHBoxLayout(groupBox_32);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbl_CrashInfo = new QLabel(groupBox_32);
        lbl_CrashInfo->setObjectName(QString::fromUtf8("lbl_CrashInfo"));

        horizontalLayout_4->addWidget(lbl_CrashInfo);

        lbl_isCrash = new QLabel(groupBox_32);
        lbl_isCrash->setObjectName(QString::fromUtf8("lbl_isCrash"));
        sizePolicy3.setHeightForWidth(lbl_isCrash->sizePolicy().hasHeightForWidth());
        lbl_isCrash->setSizePolicy(sizePolicy3);
        lbl_isCrash->setMaximumSize(QSize(30, 30));
        lbl_isCrash->setStyleSheet(QString::fromUtf8("border-radius: 15px; \n"
"border: 2px solid black; "));

        horizontalLayout_4->addWidget(lbl_isCrash);


        horizontalLayout_14->addWidget(groupBox_32);


        gridLayout_22->addLayout(horizontalLayout_14, 0, 0, 1, 4);

        btn_ShowForceInfo = new QPushButton(groupBox_13);
        btn_ShowForceInfo->setObjectName(QString::fromUtf8("btn_ShowForceInfo"));

        gridLayout_22->addWidget(btn_ShowForceInfo, 1, 0, 1, 1);

        btn_GoZero = new QPushButton(groupBox_13);
        btn_GoZero->setObjectName(QString::fromUtf8("btn_GoZero"));

        gridLayout_22->addWidget(btn_GoZero, 1, 1, 1, 1);

        btn_CheckCollision = new QPushButton(groupBox_13);
        btn_CheckCollision->setObjectName(QString::fromUtf8("btn_CheckCollision"));

        gridLayout_22->addWidget(btn_CheckCollision, 1, 2, 1, 1);

        btn_FindCamera = new QPushButton(groupBox_13);
        btn_FindCamera->setObjectName(QString::fromUtf8("btn_FindCamera"));

        gridLayout_22->addWidget(btn_FindCamera, 1, 3, 1, 1);

        btn_CameraMonitor = new QPushButton(groupBox_13);
        btn_CameraMonitor->setObjectName(QString::fromUtf8("btn_CameraMonitor"));

        gridLayout_22->addWidget(btn_CameraMonitor, 2, 0, 1, 1);

        btn_IOForward = new QPushButton(groupBox_13);
        btn_IOForward->setObjectName(QString::fromUtf8("btn_IOForward"));

        gridLayout_22->addWidget(btn_IOForward, 2, 1, 1, 1);

        btn_IOBackward = new QPushButton(groupBox_13);
        btn_IOBackward->setObjectName(QString::fromUtf8("btn_IOBackward"));

        gridLayout_22->addWidget(btn_IOBackward, 2, 2, 1, 1);

        btn_PMCConnect = new QPushButton(groupBox_13);
        btn_PMCConnect->setObjectName(QString::fromUtf8("btn_PMCConnect"));

        gridLayout_22->addWidget(btn_PMCConnect, 2, 3, 1, 1);

        btn_PMCSpeedBackward = new QPushButton(groupBox_13);
        btn_PMCSpeedBackward->setObjectName(QString::fromUtf8("btn_PMCSpeedBackward"));

        gridLayout_22->addWidget(btn_PMCSpeedBackward, 3, 0, 1, 1);

        btn_PMCSpeedForward = new QPushButton(groupBox_13);
        btn_PMCSpeedForward->setObjectName(QString::fromUtf8("btn_PMCSpeedForward"));

        gridLayout_22->addWidget(btn_PMCSpeedForward, 3, 1, 1, 1);

        btn_LightSongKai = new QPushButton(groupBox_13);
        btn_LightSongKai->setObjectName(QString::fromUtf8("btn_LightSongKai"));

        gridLayout_22->addWidget(btn_LightSongKai, 3, 2, 1, 1);

        btn_LightGuDing = new QPushButton(groupBox_13);
        btn_LightGuDing->setObjectName(QString::fromUtf8("btn_LightGuDing"));

        gridLayout_22->addWidget(btn_LightGuDing, 3, 3, 1, 1);


        gridLayout_50->addWidget(groupBox_13, 2, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 728, 291));
        gridLayout_52 = new QGridLayout(layoutWidget);
        gridLayout_52->setSpacing(6);
        gridLayout_52->setContentsMargins(11, 11, 11, 11);
        gridLayout_52->setObjectName(QString::fromUtf8("gridLayout_52"));
        gridLayout_52->setContentsMargins(0, 0, 0, 0);
        btn_ExeVehTaskBackward = new QPushButton(layoutWidget);
        btn_ExeVehTaskBackward->setObjectName(QString::fromUtf8("btn_ExeVehTaskBackward"));

        gridLayout_52->addWidget(btn_ExeVehTaskBackward, 8, 6, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_52->addItem(horizontalSpacer_11, 5, 5, 1, 1);

        btn_Motor78Backward = new QPushButton(layoutWidget);
        btn_Motor78Backward->setObjectName(QString::fromUtf8("btn_Motor78Backward"));

        gridLayout_52->addWidget(btn_Motor78Backward, 4, 2, 1, 1);

        btn_ExeMainLiftTaskBackward = new QPushButton(layoutWidget);
        btn_ExeMainLiftTaskBackward->setObjectName(QString::fromUtf8("btn_ExeMainLiftTaskBackward"));

        gridLayout_52->addWidget(btn_ExeMainLiftTaskBackward, 8, 2, 1, 1);

        btn_Motor78Forward_16 = new QPushButton(layoutWidget);
        btn_Motor78Forward_16->setObjectName(QString::fromUtf8("btn_Motor78Forward_16"));

        gridLayout_52->addWidget(btn_Motor78Forward_16, 0, 6, 1, 1);

        btn_XYSame = new QPushButton(layoutWidget);
        btn_XYSame->setObjectName(QString::fromUtf8("btn_XYSame"));

        gridLayout_52->addWidget(btn_XYSame, 4, 6, 1, 1);

        btn_Motor78Forward_6 = new QPushButton(layoutWidget);
        btn_Motor78Forward_6->setObjectName(QString::fromUtf8("btn_Motor78Forward_6"));

        gridLayout_52->addWidget(btn_Motor78Forward_6, 2, 2, 1, 1);

        btn_ExeMainLiftTaskForward = new QPushButton(layoutWidget);
        btn_ExeMainLiftTaskForward->setObjectName(QString::fromUtf8("btn_ExeMainLiftTaskForward"));

        gridLayout_52->addWidget(btn_ExeMainLiftTaskForward, 5, 4, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_52->addItem(horizontalSpacer_12, 5, 1, 1, 1);

        btn_Motor78Forward_9 = new QPushButton(layoutWidget);
        btn_Motor78Forward_9->setObjectName(QString::fromUtf8("btn_Motor78Forward_9"));

        gridLayout_52->addWidget(btn_Motor78Forward_9, 1, 2, 1, 1);

        btn_Motor78Forward_10 = new QPushButton(layoutWidget);
        btn_Motor78Forward_10->setObjectName(QString::fromUtf8("btn_Motor78Forward_10"));

        gridLayout_52->addWidget(btn_Motor78Forward_10, 1, 0, 1, 1);

        btn_Motor78Forward_15 = new QPushButton(layoutWidget);
        btn_Motor78Forward_15->setObjectName(QString::fromUtf8("btn_Motor78Forward_15"));

        gridLayout_52->addWidget(btn_Motor78Forward_15, 0, 4, 1, 1);

        btn_ExeLevelTaskBackward = new QPushButton(layoutWidget);
        btn_ExeLevelTaskBackward->setObjectName(QString::fromUtf8("btn_ExeLevelTaskBackward"));

        gridLayout_52->addWidget(btn_ExeLevelTaskBackward, 8, 4, 1, 1);

        btn_AngleSame = new QPushButton(layoutWidget);
        btn_AngleSame->setObjectName(QString::fromUtf8("btn_AngleSame"));

        gridLayout_52->addWidget(btn_AngleSame, 4, 4, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_52->addWidget(pushButton_3, 7, 0, 1, 1);

        btn_ExeLiftTaskBackward = new QPushButton(layoutWidget);
        btn_ExeLiftTaskBackward->setObjectName(QString::fromUtf8("btn_ExeLiftTaskBackward"));

        gridLayout_52->addWidget(btn_ExeLiftTaskBackward, 8, 0, 1, 1);

        btn_ExeLiftTaskForward = new QPushButton(layoutWidget);
        btn_ExeLiftTaskForward->setObjectName(QString::fromUtf8("btn_ExeLiftTaskForward"));

        gridLayout_52->addWidget(btn_ExeLiftTaskForward, 7, 2, 1, 1);

        btn_Motor78Forward_13 = new QPushButton(layoutWidget);
        btn_Motor78Forward_13->setObjectName(QString::fromUtf8("btn_Motor78Forward_13"));

        gridLayout_52->addWidget(btn_Motor78Forward_13, 0, 0, 1, 1);

        btn_Motor78Forward_4 = new QPushButton(layoutWidget);
        btn_Motor78Forward_4->setObjectName(QString::fromUtf8("btn_Motor78Forward_4"));

        gridLayout_52->addWidget(btn_Motor78Forward_4, 3, 4, 1, 1);

        btn_ExeCoverPlateTaskForward = new QPushButton(layoutWidget);
        btn_ExeCoverPlateTaskForward->setObjectName(QString::fromUtf8("btn_ExeCoverPlateTaskForward"));

        gridLayout_52->addWidget(btn_ExeCoverPlateTaskForward, 5, 6, 1, 1);

        btn_Motor78Forward_12 = new QPushButton(layoutWidget);
        btn_Motor78Forward_12->setObjectName(QString::fromUtf8("btn_Motor78Forward_12"));

        gridLayout_52->addWidget(btn_Motor78Forward_12, 1, 6, 1, 1);

        btn_Motor78Forward = new QPushButton(layoutWidget);
        btn_Motor78Forward->setObjectName(QString::fromUtf8("btn_Motor78Forward"));

        gridLayout_52->addWidget(btn_Motor78Forward, 4, 0, 1, 1);

        btn_ExePinTaskForward = new QPushButton(layoutWidget);
        btn_ExePinTaskForward->setObjectName(QString::fromUtf8("btn_ExePinTaskForward"));

        gridLayout_52->addWidget(btn_ExePinTaskForward, 7, 4, 1, 1);

        btn_ExeLevelTaskForward = new QPushButton(layoutWidget);
        btn_ExeLevelTaskForward->setObjectName(QString::fromUtf8("btn_ExeLevelTaskForward"));

        gridLayout_52->addWidget(btn_ExeLevelTaskForward, 5, 2, 1, 1);

        btn_Motor78Forward_17 = new QPushButton(layoutWidget);
        btn_Motor78Forward_17->setObjectName(QString::fromUtf8("btn_Motor78Forward_17"));

        gridLayout_52->addWidget(btn_Motor78Forward_17, 3, 6, 1, 1);

        btn_Motor78Forward_5 = new QPushButton(layoutWidget);
        btn_Motor78Forward_5->setObjectName(QString::fromUtf8("btn_Motor78Forward_5"));

        gridLayout_52->addWidget(btn_Motor78Forward_5, 2, 0, 1, 1);

        btn_Motor78Forward_2 = new QPushButton(layoutWidget);
        btn_Motor78Forward_2->setObjectName(QString::fromUtf8("btn_Motor78Forward_2"));

        gridLayout_52->addWidget(btn_Motor78Forward_2, 3, 0, 1, 1);

        btn_Motor78Forward_14 = new QPushButton(layoutWidget);
        btn_Motor78Forward_14->setObjectName(QString::fromUtf8("btn_Motor78Forward_14"));

        gridLayout_52->addWidget(btn_Motor78Forward_14, 0, 2, 1, 1);

        btn_Motor78Forward_8 = new QPushButton(layoutWidget);
        btn_Motor78Forward_8->setObjectName(QString::fromUtf8("btn_Motor78Forward_8"));

        gridLayout_52->addWidget(btn_Motor78Forward_8, 2, 6, 1, 1);

        btn_ExeVehTaskForward = new QPushButton(layoutWidget);
        btn_ExeVehTaskForward->setObjectName(QString::fromUtf8("btn_ExeVehTaskForward"));

        gridLayout_52->addWidget(btn_ExeVehTaskForward, 5, 0, 1, 1);

        btn_Motor78Forward_3 = new QPushButton(layoutWidget);
        btn_Motor78Forward_3->setObjectName(QString::fromUtf8("btn_Motor78Forward_3"));

        gridLayout_52->addWidget(btn_Motor78Forward_3, 3, 2, 1, 1);

        btn_Motor78Forward_7 = new QPushButton(layoutWidget);
        btn_Motor78Forward_7->setObjectName(QString::fromUtf8("btn_Motor78Forward_7"));

        gridLayout_52->addWidget(btn_Motor78Forward_7, 2, 4, 1, 1);

        btn_Motor78Forward_11 = new QPushButton(layoutWidget);
        btn_Motor78Forward_11->setObjectName(QString::fromUtf8("btn_Motor78Forward_11"));

        gridLayout_52->addWidget(btn_Motor78Forward_11, 1, 4, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_52->addItem(horizontalSpacer_13, 5, 3, 1, 1);

        btn_ExeCoverPlateTaskBackward = new QPushButton(layoutWidget);
        btn_ExeCoverPlateTaskBackward->setObjectName(QString::fromUtf8("btn_ExeCoverPlateTaskBackward"));

        gridLayout_52->addWidget(btn_ExeCoverPlateTaskBackward, 7, 6, 1, 1);

        btn_PMCSpeedBackward_2 = new QPushButton(tab_2);
        btn_PMCSpeedBackward_2->setObjectName(QString::fromUtf8("btn_PMCSpeedBackward_2"));
        btn_PMCSpeedBackward_2->setGeometry(QRect(70, 560, 136, 25));
        btn_CheckDetach = new QPushButton(tab_2);
        btn_CheckDetach->setObjectName(QString::fromUtf8("btn_CheckDetach"));
        btn_CheckDetach->setGeometry(QRect(60, 320, 196, 23));
        btn_LightRelease = new QPushButton(tab_2);
        btn_LightRelease->setObjectName(QString::fromUtf8("btn_LightRelease"));
        btn_LightRelease->setGeometry(QRect(685, 670, 80, 23));
        btn_LightClamp = new QPushButton(tab_2);
        btn_LightClamp->setObjectName(QString::fromUtf8("btn_LightClamp"));
        btn_LightClamp->setGeometry(QRect(470, 670, 80, 23));
        btn_CheckDetach_2 = new QPushButton(tab_2);
        btn_CheckDetach_2->setObjectName(QString::fromUtf8("btn_CheckDetach_2"));
        btn_CheckDetach_2->setGeometry(QRect(60, 390, 196, 23));
        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(300, 390, 42, 22));
        spinBox->setMinimum(-99);
        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_46 = new QGridLayout(tab_6);
        gridLayout_46->setSpacing(6);
        gridLayout_46->setContentsMargins(11, 11, 11, 11);
        gridLayout_46->setObjectName(QString::fromUtf8("gridLayout_46"));
        groupBox_2 = new QGroupBox(tab_6);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_53 = new QGridLayout(groupBox_3);
        gridLayout_53->setSpacing(6);
        gridLayout_53->setContentsMargins(11, 11, 11, 11);
        gridLayout_53->setObjectName(QString::fromUtf8("gridLayout_53"));
        btnLevelSave = new QPushButton(groupBox_3);
        btnLevelSave->setObjectName(QString::fromUtf8("btnLevelSave"));

        gridLayout_53->addWidget(btnLevelSave, 1, 0, 1, 1);

        gridLayout_42 = new QGridLayout();
        gridLayout_42->setSpacing(6);
        gridLayout_42->setObjectName(QString::fromUtf8("gridLayout_42"));
        gridLayout_42->setHorizontalSpacing(30);
        gridLayout_42->setVerticalSpacing(20);
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy10.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy10);
        label_25->setMaximumSize(QSize(120, 16777215));

        gridLayout_42->addWidget(label_25, 0, 2, 1, 1);

        cBoxCurrent3 = new QComboBox(groupBox_3);
        cBoxCurrent3->setObjectName(QString::fromUtf8("cBoxCurrent3"));
        cBoxCurrent3->setEditable(true);
        cBoxCurrent3->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxCurrent3, 3, 3, 1, 1);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy10.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy10);

        gridLayout_42->addWidget(label_26, 3, 0, 1, 1);

        cBoxAngleY = new QComboBox(groupBox_3);
        cBoxAngleY->setObjectName(QString::fromUtf8("cBoxAngleY"));
        sizePolicy14.setHeightForWidth(cBoxAngleY->sizePolicy().hasHeightForWidth());
        cBoxAngleY->setSizePolicy(sizePolicy14);
        cBoxAngleY->setMaximumSize(QSize(250, 16777215));
        cBoxAngleY->setEditable(true);
        cBoxAngleY->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxAngleY, 0, 3, 1, 1);

        cBoxCurrent0 = new QComboBox(groupBox_3);
        cBoxCurrent0->setObjectName(QString::fromUtf8("cBoxCurrent0"));
        sizePolicy14.setHeightForWidth(cBoxCurrent0->sizePolicy().hasHeightForWidth());
        cBoxCurrent0->setSizePolicy(sizePolicy14);
        cBoxCurrent0->setMaximumSize(QSize(250, 16777215));
        cBoxCurrent0->setEditable(true);
        cBoxCurrent0->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxCurrent0, 2, 1, 1, 1);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy10.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy10);

        gridLayout_42->addWidget(label_27, 3, 2, 1, 1);

        cBoxAngleX = new QComboBox(groupBox_3);
        cBoxAngleX->setObjectName(QString::fromUtf8("cBoxAngleX"));
        sizePolicy14.setHeightForWidth(cBoxAngleX->sizePolicy().hasHeightForWidth());
        cBoxAngleX->setSizePolicy(sizePolicy14);
        cBoxAngleX->setMaximumSize(QSize(250, 16777215));
        cBoxAngleX->setEditable(true);
        cBoxAngleX->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxAngleX, 0, 1, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy10.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy10);

        gridLayout_42->addWidget(label_24, 2, 0, 1, 1);

        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy10.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy10);
        label_29->setMaximumSize(QSize(120, 16777215));

        gridLayout_42->addWidget(label_29, 0, 0, 1, 1);

        cBoxCurrent1 = new QComboBox(groupBox_3);
        cBoxCurrent1->setObjectName(QString::fromUtf8("cBoxCurrent1"));
        sizePolicy14.setHeightForWidth(cBoxCurrent1->sizePolicy().hasHeightForWidth());
        cBoxCurrent1->setSizePolicy(sizePolicy14);
        cBoxCurrent1->setMaximumSize(QSize(250, 16777215));
        cBoxCurrent1->setEditable(true);
        cBoxCurrent1->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxCurrent1, 2, 3, 1, 1);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy10.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy10);

        gridLayout_42->addWidget(label_28, 2, 2, 1, 1);

        cBoxCurrent2 = new QComboBox(groupBox_3);
        cBoxCurrent2->setObjectName(QString::fromUtf8("cBoxCurrent2"));
        cBoxCurrent2->setEditable(true);
        cBoxCurrent2->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxCurrent2, 3, 1, 1, 1);

        cBoxAngleX_2 = new QComboBox(groupBox_3);
        cBoxAngleX_2->setObjectName(QString::fromUtf8("cBoxAngleX_2"));
        sizePolicy14.setHeightForWidth(cBoxAngleX_2->sizePolicy().hasHeightForWidth());
        cBoxAngleX_2->setSizePolicy(sizePolicy14);
        cBoxAngleX_2->setMaximumSize(QSize(250, 16777215));
        cBoxAngleX_2->setEditable(true);
        cBoxAngleX_2->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxAngleX_2, 1, 1, 1, 1);

        cBoxAngleY_2 = new QComboBox(groupBox_3);
        cBoxAngleY_2->setObjectName(QString::fromUtf8("cBoxAngleY_2"));
        sizePolicy14.setHeightForWidth(cBoxAngleY_2->sizePolicy().hasHeightForWidth());
        cBoxAngleY_2->setSizePolicy(sizePolicy14);
        cBoxAngleY_2->setMaximumSize(QSize(250, 16777215));
        cBoxAngleY_2->setEditable(true);
        cBoxAngleY_2->setMinimumContentsLength(0);

        gridLayout_42->addWidget(cBoxAngleY_2, 1, 3, 1, 1);

        label_64 = new QLabel(groupBox_3);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        sizePolicy10.setHeightForWidth(label_64->sizePolicy().hasHeightForWidth());
        label_64->setSizePolicy(sizePolicy10);
        label_64->setMaximumSize(QSize(120, 16777215));

        gridLayout_42->addWidget(label_64, 1, 0, 1, 1);

        label_65 = new QLabel(groupBox_3);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        sizePolicy10.setHeightForWidth(label_65->sizePolicy().hasHeightForWidth());
        label_65->setSizePolicy(sizePolicy10);
        label_65->setMaximumSize(QSize(120, 16777215));

        gridLayout_42->addWidget(label_65, 1, 2, 1, 1);


        gridLayout_53->addLayout(gridLayout_42, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout_57 = new QGridLayout(groupBox_4);
        gridLayout_57->setSpacing(6);
        gridLayout_57->setContentsMargins(11, 11, 11, 11);
        gridLayout_57->setObjectName(QString::fromUtf8("gridLayout_57"));
        gridLayout_56 = new QGridLayout();
        gridLayout_56->setSpacing(6);
        gridLayout_56->setObjectName(QString::fromUtf8("gridLayout_56"));
        gridLayout_56->setHorizontalSpacing(30);
        gridLayout_56->setVerticalSpacing(20);
        cBoxTorqueX = new QComboBox(groupBox_4);
        cBoxTorqueX->setObjectName(QString::fromUtf8("cBoxTorqueX"));
        sizePolicy14.setHeightForWidth(cBoxTorqueX->sizePolicy().hasHeightForWidth());
        cBoxTorqueX->setSizePolicy(sizePolicy14);
        cBoxTorqueX->setMaximumSize(QSize(250, 16777215));
        cBoxTorqueX->setEditable(true);
        cBoxTorqueX->setMinimumContentsLength(0);

        gridLayout_56->addWidget(cBoxTorqueX, 0, 3, 1, 1);

        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        sizePolicy10.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy10);
        label_31->setMaximumSize(QSize(120, 16777215));

        gridLayout_56->addWidget(label_31, 1, 0, 1, 1);

        cBoxForceX = new QComboBox(groupBox_4);
        cBoxForceX->setObjectName(QString::fromUtf8("cBoxForceX"));
        sizePolicy14.setHeightForWidth(cBoxForceX->sizePolicy().hasHeightForWidth());
        cBoxForceX->setSizePolicy(sizePolicy14);
        cBoxForceX->setMaximumSize(QSize(250, 16777215));
        cBoxForceX->setEditable(true);
        cBoxForceX->setMinimumContentsLength(0);

        gridLayout_56->addWidget(cBoxForceX, 0, 1, 1, 1);

        label_37 = new QLabel(groupBox_4);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        sizePolicy10.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy10);
        label_37->setMaximumSize(QSize(120, 16777215));

        gridLayout_56->addWidget(label_37, 2, 0, 1, 1);

        label_39 = new QLabel(groupBox_4);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        sizePolicy10.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy10);
        label_39->setMaximumSize(QSize(120, 16777215));

        gridLayout_56->addWidget(label_39, 1, 2, 1, 1);

        cBoxForceY = new QComboBox(groupBox_4);
        cBoxForceY->setObjectName(QString::fromUtf8("cBoxForceY"));
        sizePolicy14.setHeightForWidth(cBoxForceY->sizePolicy().hasHeightForWidth());
        cBoxForceY->setSizePolicy(sizePolicy14);
        cBoxForceY->setMaximumSize(QSize(250, 16777215));
        cBoxForceY->setEditable(true);
        cBoxForceY->setMinimumContentsLength(0);

        gridLayout_56->addWidget(cBoxForceY, 1, 1, 1, 1);

        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy10.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy10);
        label_30->setMaximumSize(QSize(120, 16777215));

        gridLayout_56->addWidget(label_30, 0, 0, 1, 1);

        label_40 = new QLabel(groupBox_4);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        sizePolicy10.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy10);
        label_40->setMaximumSize(QSize(120, 16777215));

        gridLayout_56->addWidget(label_40, 0, 2, 1, 1);

        cBoxTorqueY = new QComboBox(groupBox_4);
        cBoxTorqueY->setObjectName(QString::fromUtf8("cBoxTorqueY"));
        sizePolicy14.setHeightForWidth(cBoxTorqueY->sizePolicy().hasHeightForWidth());
        cBoxTorqueY->setSizePolicy(sizePolicy14);
        cBoxTorqueY->setMaximumSize(QSize(250, 16777215));
        cBoxTorqueY->setEditable(true);
        cBoxTorqueY->setMinimumContentsLength(0);

        gridLayout_56->addWidget(cBoxTorqueY, 1, 3, 1, 1);

        cBoxForceZ = new QComboBox(groupBox_4);
        cBoxForceZ->setObjectName(QString::fromUtf8("cBoxForceZ"));
        sizePolicy14.setHeightForWidth(cBoxForceZ->sizePolicy().hasHeightForWidth());
        cBoxForceZ->setSizePolicy(sizePolicy14);
        cBoxForceZ->setMaximumSize(QSize(250, 16777215));
        cBoxForceZ->setEditable(true);
        cBoxForceZ->setMinimumContentsLength(0);

        gridLayout_56->addWidget(cBoxForceZ, 2, 1, 1, 1);

        label_38 = new QLabel(groupBox_4);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        sizePolicy10.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy10);
        label_38->setMaximumSize(QSize(120, 16777215));

        gridLayout_56->addWidget(label_38, 2, 2, 1, 1);

        cBoxTorqueZ = new QComboBox(groupBox_4);
        cBoxTorqueZ->setObjectName(QString::fromUtf8("cBoxTorqueZ"));
        sizePolicy14.setHeightForWidth(cBoxTorqueZ->sizePolicy().hasHeightForWidth());
        cBoxTorqueZ->setSizePolicy(sizePolicy14);
        cBoxTorqueZ->setMaximumSize(QSize(250, 16777215));
        cBoxTorqueZ->setEditable(true);
        cBoxTorqueZ->setMinimumContentsLength(0);

        gridLayout_56->addWidget(cBoxTorqueZ, 2, 3, 1, 1);


        gridLayout_57->addLayout(gridLayout_56, 0, 0, 1, 1);

        btnSixForceSave = new QPushButton(groupBox_4);
        btnSixForceSave->setObjectName(QString::fromUtf8("btnSixForceSave"));

        gridLayout_57->addWidget(btnSixForceSave, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 2, 0, 1, 1);


        gridLayout_46->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_10 = new QGroupBox(tab_6);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        QSizePolicy sizePolicy19(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy19.setHorizontalStretch(0);
        sizePolicy19.setVerticalStretch(2);
        sizePolicy19.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy19);
        groupBox_10->setMinimumSize(QSize(600, 0));
        groupBox_10->setMaximumSize(QSize(1500, 200));
        groupBox_10->setFont(font);
        groupBox_10->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_40 = new QGridLayout(groupBox_10);
        gridLayout_40->setSpacing(6);
        gridLayout_40->setContentsMargins(11, 11, 11, 11);
        gridLayout_40->setObjectName(QString::fromUtf8("gridLayout_40"));
        gridLayout_41 = new QGridLayout();
        gridLayout_41->setSpacing(6);
        gridLayout_41->setObjectName(QString::fromUtf8("gridLayout_41"));
        label_120 = new QLabel(groupBox_10);
        label_120->setObjectName(QString::fromUtf8("label_120"));

        gridLayout_41->addWidget(label_120, 2, 4, 1, 1);

        cBoxAxisDecel = new QComboBox(groupBox_10);
        cBoxAxisDecel->setObjectName(QString::fromUtf8("cBoxAxisDecel"));
        cBoxAxisDecel->setEditable(true);
        cBoxAxisDecel->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisDecel, 2, 3, 1, 1);

        cBoxAxisNum = new QComboBox(groupBox_10);
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->addItem(QString());
        cBoxAxisNum->setObjectName(QString::fromUtf8("cBoxAxisNum"));
        cBoxAxisNum->setEditable(true);
        cBoxAxisNum->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisNum, 0, 1, 1, 1);

        cBoxAxisAccel = new QComboBox(groupBox_10);
        cBoxAxisAccel->setObjectName(QString::fromUtf8("cBoxAxisAccel"));
        cBoxAxisAccel->setEditable(true);
        cBoxAxisAccel->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisAccel, 1, 3, 1, 1);

        label_32 = new QLabel(groupBox_10);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_41->addWidget(label_32, 0, 4, 1, 1);

        label_14 = new QLabel(groupBox_10);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_41->addWidget(label_14, 1, 4, 1, 1);

        cBoxAxisSpeed = new QComboBox(groupBox_10);
        cBoxAxisSpeed->setObjectName(QString::fromUtf8("cBoxAxisSpeed"));
        cBoxAxisSpeed->setEditable(true);
        cBoxAxisSpeed->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisSpeed, 0, 3, 1, 1);

        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_41->addWidget(label_15, 2, 2, 1, 1);

        cBoxAxisRSLimit = new QComboBox(groupBox_10);
        cBoxAxisRSLimit->setObjectName(QString::fromUtf8("cBoxAxisRSLimit"));
        cBoxAxisRSLimit->setEditable(true);
        cBoxAxisRSLimit->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisRSLimit, 1, 5, 1, 1);

        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_41->addWidget(label_21, 0, 0, 1, 1);

        label_22 = new QLabel(groupBox_10);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_41->addWidget(label_22, 1, 2, 1, 1);

        cBoxAxisInit = new QComboBox(groupBox_10);
        cBoxAxisInit->setObjectName(QString::fromUtf8("cBoxAxisInit"));
        cBoxAxisInit->setEditable(true);
        cBoxAxisInit->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisInit, 0, 5, 1, 1);

        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_41->addWidget(label_19, 0, 2, 1, 1);

        label_23 = new QLabel(groupBox_10);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_41->addWidget(label_23, 2, 0, 1, 1);

        lbl_HeartBeatInfo_2 = new QLabel(groupBox_10);
        lbl_HeartBeatInfo_2->setObjectName(QString::fromUtf8("lbl_HeartBeatInfo_2"));

        gridLayout_41->addWidget(lbl_HeartBeatInfo_2, 1, 0, 1, 1);

        cBoxAxisFSLimit = new QComboBox(groupBox_10);
        cBoxAxisFSLimit->setObjectName(QString::fromUtf8("cBoxAxisFSLimit"));
        cBoxAxisFSLimit->setEditable(true);
        cBoxAxisFSLimit->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisFSLimit, 2, 5, 1, 1);

        cBoxAxisUnits = new QComboBox(groupBox_10);
        cBoxAxisUnits->setObjectName(QString::fromUtf8("cBoxAxisUnits"));
        cBoxAxisUnits->setEditable(true);
        cBoxAxisUnits->setMinimumContentsLength(0);

        gridLayout_41->addWidget(cBoxAxisUnits, 2, 1, 1, 1);


        gridLayout_40->addLayout(gridLayout_41, 0, 0, 1, 1);

        btnAxisSave = new QPushButton(groupBox_10);
        btnAxisSave->setObjectName(QString::fromUtf8("btnAxisSave"));

        gridLayout_40->addWidget(btnAxisSave, 1, 0, 1, 1);


        gridLayout_46->addWidget(groupBox_10, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        gridLayout_61 = new QGridLayout(tab_8);
        gridLayout_61->setSpacing(6);
        gridLayout_61->setContentsMargins(11, 11, 11, 11);
        gridLayout_61->setObjectName(QString::fromUtf8("gridLayout_61"));
        groupBox_12 = new QGroupBox(tab_8);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        gridLayout_55 = new QGridLayout(groupBox_12);
        gridLayout_55->setSpacing(6);
        gridLayout_55->setContentsMargins(11, 11, 11, 11);
        gridLayout_55->setObjectName(QString::fromUtf8("gridLayout_55"));
        gridLayout_54 = new QGridLayout();
        gridLayout_54->setSpacing(6);
        gridLayout_54->setObjectName(QString::fromUtf8("gridLayout_54"));
        label_18 = new QLabel(groupBox_12);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy10.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy10);

        gridLayout_54->addWidget(label_18, 1, 0, 1, 1);

        leDbName = new QLineEdit(groupBox_12);
        leDbName->setObjectName(QString::fromUtf8("leDbName"));

        gridLayout_54->addWidget(leDbName, 1, 1, 1, 2);

        label_42 = new QLabel(groupBox_12);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        sizePolicy10.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy10);

        gridLayout_54->addWidget(label_42, 2, 0, 1, 1);

        leDbUser = new QLineEdit(groupBox_12);
        leDbUser->setObjectName(QString::fromUtf8("leDbUser"));

        gridLayout_54->addWidget(leDbUser, 2, 1, 1, 2);

        label_43 = new QLabel(groupBox_12);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        sizePolicy10.setHeightForWidth(label_43->sizePolicy().hasHeightForWidth());
        label_43->setSizePolicy(sizePolicy10);

        gridLayout_54->addWidget(label_43, 3, 0, 1, 1);

        leDbPassword = new QLineEdit(groupBox_12);
        leDbPassword->setObjectName(QString::fromUtf8("leDbPassword"));
        leDbPassword->setEchoMode(QLineEdit::Normal);

        gridLayout_54->addWidget(leDbPassword, 3, 1, 1, 2);

        leDbHost = new QLineEdit(groupBox_12);
        leDbHost->setObjectName(QString::fromUtf8("leDbHost"));
        sizePolicy9.setHeightForWidth(leDbHost->sizePolicy().hasHeightForWidth());
        leDbHost->setSizePolicy(sizePolicy9);

        gridLayout_54->addWidget(leDbHost, 0, 1, 1, 2);

        label_45 = new QLabel(groupBox_12);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        sizePolicy10.setHeightForWidth(label_45->sizePolicy().hasHeightForWidth());
        label_45->setSizePolicy(sizePolicy10);

        gridLayout_54->addWidget(label_45, 0, 0, 1, 1);


        gridLayout_55->addLayout(gridLayout_54, 0, 0, 1, 3);

        btnDbConnect = new QPushButton(groupBox_12);
        btnDbConnect->setObjectName(QString::fromUtf8("btnDbConnect"));

        gridLayout_55->addWidget(btnDbConnect, 1, 0, 1, 1);

        btnDbDisconnect = new QPushButton(groupBox_12);
        btnDbDisconnect->setObjectName(QString::fromUtf8("btnDbDisconnect"));

        gridLayout_55->addWidget(btnDbDisconnect, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_46 = new QLabel(groupBox_12);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        sizePolicy10.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy10);

        horizontalLayout_2->addWidget(label_46);

        lbl_database = new QLabel(groupBox_12);
        lbl_database->setObjectName(QString::fromUtf8("lbl_database"));
        sizePolicy13.setHeightForWidth(lbl_database->sizePolicy().hasHeightForWidth());
        lbl_database->setSizePolicy(sizePolicy13);
        lbl_database->setMinimumSize(QSize(30, 30));
        lbl_database->setMaximumSize(QSize(30, 30));
        lbl_database->setStyleSheet(QString::fromUtf8("\n"
"border: 2px solid black; "));

        horizontalLayout_2->addWidget(lbl_database);


        gridLayout_55->addLayout(horizontalLayout_2, 1, 2, 1, 1);


        gridLayout_61->addWidget(groupBox_12, 0, 0, 1, 1);

        groupBox_16 = new QGroupBox(tab_8);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        gridLayout_59 = new QGridLayout(groupBox_16);
        gridLayout_59->setSpacing(6);
        gridLayout_59->setContentsMargins(11, 11, 11, 11);
        gridLayout_59->setObjectName(QString::fromUtf8("gridLayout_59"));
        gridLayout_58 = new QGridLayout();
        gridLayout_58->setSpacing(6);
        gridLayout_58->setObjectName(QString::fromUtf8("gridLayout_58"));
        btnDbAdd = new QPushButton(groupBox_16);
        btnDbAdd->setObjectName(QString::fromUtf8("btnDbAdd"));

        gridLayout_58->addWidget(btnDbAdd, 1, 1, 1, 1);

        btnDbDelete = new QPushButton(groupBox_16);
        btnDbDelete->setObjectName(QString::fromUtf8("btnDbDelete"));

        gridLayout_58->addWidget(btnDbDelete, 1, 2, 1, 1);

        btnDbQuery = new QPushButton(groupBox_16);
        btnDbQuery->setObjectName(QString::fromUtf8("btnDbQuery"));

        gridLayout_58->addWidget(btnDbQuery, 1, 0, 1, 1);

        cbxDbTables = new QComboBox(groupBox_16);
        cbxDbTables->addItem(QString());
        cbxDbTables->addItem(QString());
        cbxDbTables->addItem(QString());
        cbxDbTables->setObjectName(QString::fromUtf8("cbxDbTables"));

        gridLayout_58->addWidget(cbxDbTables, 0, 0, 1, 2);

        btnDbShow = new QPushButton(groupBox_16);
        btnDbShow->setObjectName(QString::fromUtf8("btnDbShow"));

        gridLayout_58->addWidget(btnDbShow, 1, 3, 1, 1);

        btnDbSave = new QPushButton(groupBox_16);
        btnDbSave->setObjectName(QString::fromUtf8("btnDbSave"));

        gridLayout_58->addWidget(btnDbSave, 1, 4, 1, 1);

        leQueryCondition = new QLineEdit(groupBox_16);
        leQueryCondition->setObjectName(QString::fromUtf8("leQueryCondition"));

        gridLayout_58->addWidget(leQueryCondition, 0, 2, 1, 3);


        gridLayout_59->addLayout(gridLayout_58, 0, 0, 1, 1);


        gridLayout_61->addWidget(groupBox_16, 1, 0, 1, 1);

        groupBox_26 = new QGroupBox(tab_8);
        groupBox_26->setObjectName(QString::fromUtf8("groupBox_26"));
        sizePolicy7.setHeightForWidth(groupBox_26->sizePolicy().hasHeightForWidth());
        groupBox_26->setSizePolicy(sizePolicy7);
        groupBox_26->setMinimumSize(QSize(0, 300));
        gridLayout_60 = new QGridLayout(groupBox_26);
        gridLayout_60->setSpacing(6);
        gridLayout_60->setContentsMargins(11, 11, 11, 11);
        gridLayout_60->setObjectName(QString::fromUtf8("gridLayout_60"));
        tvDbData = new QTableView(groupBox_26);
        tvDbData->setObjectName(QString::fromUtf8("tvDbData"));
        tvDbData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvDbData->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvDbData->verticalHeader()->setVisible(true);

        gridLayout_60->addWidget(tvDbData, 0, 0, 1, 1);


        gridLayout_61->addWidget(groupBox_26, 2, 0, 1, 1);

        tabWidget->addTab(tab_8, QString());

        gridLayout_26->addWidget(tabWidget, 0, 0, 3, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        StartVision_2 = new QMenuBar(MainWindow);
        StartVision_2->setObjectName(QString::fromUtf8("StartVision_2"));
        StartVision_2->setGeometry(QRect(0, 0, 1694, 21));
        LRUMonitor = new QMenu(StartVision_2);
        LRUMonitor->setObjectName(QString::fromUtf8("LRUMonitor"));
        AGVMonitor = new QMenu(StartVision_2);
        AGVMonitor->setObjectName(QString::fromUtf8("AGVMonitor"));
        LevelMonitor = new QMenu(StartVision_2);
        LevelMonitor->setObjectName(QString::fromUtf8("LevelMonitor"));
        LiftMonitor = new QMenu(StartVision_2);
        LiftMonitor->setObjectName(QString::fromUtf8("LiftMonitor"));
        CoverPlateMonitor = new QMenu(StartVision_2);
        CoverPlateMonitor->setObjectName(QString::fromUtf8("CoverPlateMonitor"));
        PinMonitor = new QMenu(StartVision_2);
        PinMonitor->setObjectName(QString::fromUtf8("PinMonitor"));
        Camera_2 = new QMenu(StartVision_2);
        Camera_2->setObjectName(QString::fromUtf8("Camera_2"));
        CoverPlate3D = new QMenu(StartVision_2);
        CoverPlate3D->setObjectName(QString::fromUtf8("CoverPlate3D"));
        MainWindow->setMenuBar(StartVision_2);

        StartVision_2->addAction(AGVMonitor->menuAction());
        StartVision_2->addAction(LevelMonitor->menuAction());
        StartVision_2->addAction(LiftMonitor->menuAction());
        StartVision_2->addAction(CoverPlateMonitor->menuAction());
        StartVision_2->addAction(PinMonitor->menuAction());
        StartVision_2->addAction(LRUMonitor->menuAction());
        StartVision_2->addAction(CoverPlate3D->menuAction());
        StartVision_2->addAction(Camera_2->menuAction());
        LRUMonitor->addAction(StartMonitor);
        AGVMonitor->addAction(StartAGVMonitor);
        LevelMonitor->addAction(StartLevelMonitor);
        LiftMonitor->addAction(StartLiftMonitor);
        CoverPlateMonitor->addAction(StartCoverPlateMonitor);
        PinMonitor->addAction(StartPinMonitor);
        Camera_2->addAction(StartCamera);
        CoverPlate3D->addAction(StartCoverPlate3D);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LRU\347\263\273\347\273\237", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        StartMonitor->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartAGVMonitor->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartLevelMonitor->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartLiftMonitor->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartCoverPlateMonitor->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartPinMonitor->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        Camera->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartVision->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartSee->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartCamera->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        StartCoverPlate3D->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\346\217\220\347\244\272\344\277\241\346\201\257", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\250\241\345\274\217", nullptr));
        lbl_Auto->setText(QString());
        label_50->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", nullptr));
        lbl_Manual->setText(QString());
        groupBox_37->setTitle(QCoreApplication::translate("MainWindow", "\345\205\255\347\273\264\345\212\233\344\277\241\346\201\257", nullptr));
        cbxShowType->setItemText(0, QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        cbxShowType->setItemText(1, QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\277\220\350\241\214\346\227\266\351\227\264\347\273\237\350\256\241", nullptr));

        btnGenerateChart->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\217\257\350\247\206\345\214\226", nullptr));
        cbxSensorType->setItemText(0, QCoreApplication::translate("MainWindow", "AGV\347\263\273\347\273\237", nullptr));
        cbxSensorType->setItemText(1, QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\347\263\273\347\273\237", nullptr));
        cbxSensorType->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\345\215\207\351\231\215\347\263\273\347\273\237", nullptr));
        cbxSensorType->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277\347\263\273\347\273\237", nullptr));
        cbxSensorType->setItemText(4, QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\345\215\207\351\231\215\347\263\273\347\273\237", nullptr));
        cbxSensorType->setItemText(5, QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200\347\263\273\347\273\237", nullptr));

        groupBox_TaskMgr->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\260\203\345\272\246\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_231->setText(QCoreApplication::translate("MainWindow", "AGV \345\255\220\347\263\273\347\273\237", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\345\211\215\345\276\200\345\256\211\350\243\205", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\345\216\237\347\202\271", nullptr));
        label_248->setText(QCoreApplication::translate("MainWindow", "\345\276\205\346\234\272", nullptr));
        label_249->setText(QCoreApplication::translate("MainWindow", "\345\212\250\344\275\234\344\270\255", nullptr));
        label_252->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220", nullptr));
        label_260->setText(QCoreApplication::translate("MainWindow", "\351\224\231\350\257\257", nullptr));
        lbl_AGV->setText(QString());
        lbl_VehTaskForward->setText(QString());
        lbl_VehTaskBackward->setText(QString());
        lbl_AGV_Ready->setText(QString());
        lbl_AGV_Running->setText(QString());
        lbl_AGV_Complete->setText(QString());
        lbl_AGV_Error->setText(QString());
        label_232->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\345\255\220\347\263\273\347\273\237", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\350\260\203\345\271\263", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\350\247\246\345\234\260", nullptr));
        lbl_Level->setText(QString());
        lbl_LevelTaskForward->setText(QString());
        lbl_LevelTaskBackward->setText(QString());
        lbl_Level_Ready->setText(QString());
        lbl_Level_Running->setText(QString());
        lbl_Level_Complete->setText(QString());
        lbl_Level_Error->setText(QString());
        label_233->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\345\215\207\351\231\215\345\255\220\347\263\273\347\273\237", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\346\212\254\345\215\207", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\344\270\213\351\231\215", nullptr));
        lbl_MainLift->setText(QString());
        lbl_MainLiftTaskForward->setText(QString());
        lbl_MainLiftTaskBackward->setText(QString());
        lbl_MainLift_Ready->setText(QString());
        lbl_MainLift_Running->setText(QString());
        lbl_MainLift_Complete->setText(QString());
        lbl_MainLift_Error->setText(QString());
        label_234->setText(QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277\345\255\220\347\263\273\347\273\237", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\233\226\347\233\226\346\235\277", nullptr));
        lbl_CoverPlate->setText(QString());
        lbl_CoverPlateTaskForward->setText(QString());
        lbl_LiftTaskBackward->setText(QString());
        lbl_CoverPlate_Ready->setText(QString());
        lbl_CoverPlate_Running->setText(QString());
        lbl_CoverPlate_Complete->setText(QString());
        lbl_CoverPlate_Error->setText(QString());
        label_239->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\345\215\207\351\231\215\345\255\220\347\263\273\347\273\237", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\346\212\254\345\215\207", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\344\270\213\351\231\215", nullptr));
        lbl_Lift->setText(QString());
        lbl_LiftTaskForward->setText(QString());
        lbl_CoverPlateTaskBackward->setText(QString());
        lbl_Lift_Ready->setText(QString());
        lbl_Lift_Running->setText(QString());
        lbl_Lift_Complete->setText(QString());
        lbl_Lift_Error->setText(QString());
        label_236->setText(QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200\345\255\220\347\263\273\347\273\237", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200\345\212\250\344\275\234", nullptr));
        lbl_Pin->setText(QString());
        lbl_PinTask->setText(QString());
        lbl_Pin_Ready->setText(QString());
        lbl_Pin_Running->setText(QString());
        lbl_Pin_Complete->setText(QString());
        lbl_Pin_Error->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "AGV\351\200\232\350\256\257", nullptr));
        label_119->setText(QCoreApplication::translate("MainWindow", "\345\257\274\350\210\252\346\234\215\345\212\241\345\231\250\357\274\232", nullptr));
        lineEdit_NaviSvr->setText(QCoreApplication::translate("MainWindow", "192.168.192.5", nullptr));
        label_153->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        comBox_NavigatePort->setCurrentText(QCoreApplication::translate("MainWindow", "19206", nullptr));
        btn_CnntNavigateSvr->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_117->setText(QCoreApplication::translate("MainWindow", "\346\216\250\351\200\201\346\234\215\345\212\241\345\231\250\357\274\232", nullptr));
        lineEdit_PushSvr->setText(QCoreApplication::translate("MainWindow", "192.168.192.5", nullptr));
        label_118->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        comBox_PushPort->setCurrentText(QCoreApplication::translate("MainWindow", "19301", nullptr));
        btn_CnntPushSvr->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_170->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276\346\226\207\344\273\266\357\274\232", nullptr));
        label_172->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        btn_MapLoad->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275\345\234\260\345\233\276", nullptr));
        label_162->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\234\215\345\212\241\345\231\250\357\274\232", nullptr));
        lineEdit_StatusSvr->setText(QCoreApplication::translate("MainWindow", "192.168.192.5", nullptr));
        label_169->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        comBox_StatusPort->setCurrentText(QCoreApplication::translate("MainWindow", "19204", nullptr));
        btn_CnntStatusSvr->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_167->setText(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\346\234\215\345\212\241\345\231\250\357\274\232", nullptr));
        lineEdit_ContSvr->setText(QCoreApplication::translate("MainWindow", "192.168.192.5", nullptr));
        label_168->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243:", nullptr));
        comBox_ControlPort->setCurrentText(QCoreApplication::translate("MainWindow", "19205", nullptr));
        btn_CnntControlSvr->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\346\216\247\345\210\266", nullptr));
        groupBox_ManualMode->setTitle(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", nullptr));
        btn_MainLiftManual->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\345\215\207\351\231\215\346\234\272\346\236\204", nullptr));
        btn_PinManual->setText(QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200\346\234\272\346\236\204", nullptr));
        btn_AGVManual->setText(QCoreApplication::translate("MainWindow", "AGV\345\260\217\350\275\246", nullptr));
        btn_LiftManual->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\345\215\207\351\231\215\346\234\272\346\236\204", nullptr));
        btn_LevelManual->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\346\234\272\346\236\204", nullptr));
        btn_CoverPlateManual->setText(QCoreApplication::translate("MainWindow", "\347\233\226\346\235\277\346\234\272\346\236\204", nullptr));
        radioButton_ManualMode->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250\346\211\213\345\212\250", nullptr));
        groupBox_AutoMode->setTitle(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\250\241\345\274\217", nullptr));
        radioButton_AutoMode->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250\350\207\252\345\212\250", nullptr));
        radioButton_leftPlate->setText(QCoreApplication::translate("MainWindow", "\345\267\246\347\201\257\347\256\261\347\233\226\346\235\277", nullptr));
        radioButton_middlePlate->setText(QCoreApplication::translate("MainWindow", "\344\270\255\347\201\257\347\256\261\347\233\226\346\235\277", nullptr));
        radioButton_rightPlate->setText(QCoreApplication::translate("MainWindow", "\345\217\263\347\201\257\347\256\261\347\233\226\346\235\277", nullptr));
        btn_StartTask->setText(QCoreApplication::translate("MainWindow", "\345\205\250\350\207\252\345\212\250\345\256\211\350\243\205", nullptr));
        btn_PauseTask->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        btn_ContinueTask->setText(QCoreApplication::translate("MainWindow", "\347\273\247\347\273\255", nullptr));
        label_238->setText(QCoreApplication::translate("MainWindow", "LRU\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox_LRU->setItemText(0, QString());
        comboBox_LRU->setItemText(1, QCoreApplication::translate("MainWindow", "\345\201\217\346\214\257\346\250\241\345\235\227", nullptr));
        comboBox_LRU->setItemText(2, QCoreApplication::translate("MainWindow", "AO\350\260\203\346\225\264\346\236\266", nullptr));
        comboBox_LRU->setItemText(3, QCoreApplication::translate("MainWindow", "TM1\351\230\265\345\210\227", nullptr));
        comboBox_LRU->setItemText(4, QCoreApplication::translate("MainWindow", "\344\270\255\347\201\257\347\256\261", nullptr));
        comboBox_LRU->setItemText(5, QCoreApplication::translate("MainWindow", "\344\276\247\347\201\257\347\256\261", nullptr));
        comboBox_LRU->setItemText(6, QCoreApplication::translate("MainWindow", "\345\215\241\350\256\241", nullptr));
        comboBox_LRU->setItemText(7, QCoreApplication::translate("MainWindow", "\345\217\226\346\240\267\351\225\234", nullptr));
        comboBox_LRU->setItemText(8, QCoreApplication::translate("MainWindow", "\345\267\246\347\211\207\346\236\266", nullptr));
        comboBox_LRU->setItemText(9, QCoreApplication::translate("MainWindow", "\347\211\207\347\252\227", nullptr));
        comboBox_LRU->setItemText(10, QCoreApplication::translate("MainWindow", "\350\205\224\345\217\215\345\260\204\351\225\234", nullptr));

        label_255->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207\347\253\231\347\202\271\357\274\232", nullptr));
        comboBox_Station->setItemText(0, QString());
        comboBox_Station->setItemText(1, QCoreApplication::translate("MainWindow", "LM0", nullptr));
        comboBox_Station->setItemText(2, QCoreApplication::translate("MainWindow", "LM1", nullptr));
        comboBox_Station->setItemText(3, QCoreApplication::translate("MainWindow", "LM2", nullptr));
        comboBox_Station->setItemText(4, QCoreApplication::translate("MainWindow", "LM3", nullptr));
        comboBox_Station->setItemText(5, QCoreApplication::translate("MainWindow", "LM4", nullptr));
        comboBox_Station->setItemText(6, QCoreApplication::translate("MainWindow", "LM5", nullptr));
        comboBox_Station->setItemText(7, QCoreApplication::translate("MainWindow", "LM6", nullptr));
        comboBox_Station->setItemText(8, QCoreApplication::translate("MainWindow", "LM7", nullptr));

        btn_InitialAll->setText(QString());
        btn_AllRapidStop->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\350\277\233\345\272\246\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\346\216\247\345\210\266\345\231\250\351\200\232\350\256\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        lbl_isConnect->setText(QString());
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        btnConnectSimulation->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\344\273\277\347\234\237\345\231\250", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\226\271\345\274\217\357\274\232", nullptr));
        ledMotion->setText(QString());
        cBoxConnectType->setItemText(0, QCoreApplication::translate("MainWindow", "COM", nullptr));
        cBoxConnectType->setItemText(1, QCoreApplication::translate("MainWindow", "ETH", nullptr));
        cBoxConnectType->setItemText(2, QCoreApplication::translate("MainWindow", "USB", nullptr));
        cBoxConnectType->setItemText(3, QCoreApplication::translate("MainWindow", "PCI", nullptr));
        cBoxConnectType->setItemText(4, QCoreApplication::translate("MainWindow", "LOCAL", nullptr));

        btnInitBus->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\346\200\273\347\272\277", nullptr));
        btnInitAxis->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\350\275\264", nullptr));
        btnEnableAxis->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275\350\275\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\345\255\227\347\254\246\344\270\262\357\274\232", nullptr));
        btnDisableAxis->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\344\275\277\350\203\275", nullptr));
        btnType0->setText(QCoreApplication::translate("MainWindow", "\350\231\232\346\213\237\350\275\264", nullptr));
        btnType65->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\350\275\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\346\200\273\346\216\247\347\263\273\347\273\237", nullptr));
        groupBox_33->setTitle(QCoreApplication::translate("MainWindow", "AGV\346\211\213\345\212\250\346\223\215\344\275\234", nullptr));
        btn_AGVOpen->setText(QCoreApplication::translate("MainWindow", "AGV\345\274\200\346\234\272", nullptr));
        btn_AGVClose->setText(QCoreApplication::translate("MainWindow", "AGV\345\205\263\346\234\272", nullptr));
        btn_AGVRapidStop->setText(QString());
        btn_AGVToAuto->setText(QString());
        btn_AGVPauseNavigate->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\345\275\223\345\211\215\345\257\274\350\210\252", nullptr));
        btn_AGVContinueNavigate->setText(QCoreApplication::translate("MainWindow", "\347\273\247\347\273\255\345\275\223\345\211\215\345\257\274\350\210\252", nullptr));
        btn_AGVCancelNavigate->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\345\275\223\345\211\215\345\257\274\350\210\252", nullptr));
        btn_AGV_Translate->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\212\250", nullptr));
        btn_AGVToTarget->setText(QCoreApplication::translate("MainWindow", "\345\211\215\345\276\200\347\233\256\346\240\207\347\253\231\347\202\271", nullptr));
        btn_AGVToOrigin->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\345\210\235\345\247\213\347\253\231\347\202\271", nullptr));
        btn_AGV_Turn->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        btn_AGV_Transverse->setText(QCoreApplication::translate("MainWindow", "\346\250\252\347\247\273", nullptr));
        label_134->setText(QCoreApplication::translate("MainWindow", "Timeout:", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "Number:", nullptr));
        label_131->setText(QCoreApplication::translate("MainWindow", "Byte15:", nullptr));
        label_130->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        groupBox_34->setTitle(QCoreApplication::translate("MainWindow", "Json\346\225\260\346\215\256\344\277\241\346\201\257", nullptr));
        btn_Send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        btn_CancleTask->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\344\273\273\345\212\241", nullptr));
        groupBox_36->setTitle(QCoreApplication::translate("MainWindow", "\346\277\200\345\205\211\346\265\213\350\267\235\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_343->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\211\215\350\267\235\347\246\273\357\274\232", nullptr));
        btn_ShowDistance->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\267\235\347\246\273\344\277\241\346\201\257", nullptr));
        btnOpenDistanceCOM->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\267\235\347\246\273\344\270\262\345\217\243", nullptr));
        label_341->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\211\215\350\267\235\347\246\273\357\274\232", nullptr));
        label_342->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\220\216\350\267\235\347\246\273\357\274\232", nullptr));
        label_344->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\220\216\350\267\235\347\246\273\357\274\232", nullptr));
        groupBox_35->setTitle(QCoreApplication::translate("MainWindow", "AGV\347\212\266\346\200\201\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_155->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\267\256\350\247\222\345\272\246\357\274\232", nullptr));
        lbl_handle->setText(QString());
        label_148->setText(QCoreApplication::translate("MainWindow", "\345\211\251\344\275\231\350\267\257\345\276\204\351\225\277\345\272\246\357\274\232", nullptr));
        label_140->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\347\212\266\346\200\201\357\274\232", nullptr));
        label_149->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\351\251\261\345\212\250\346\200\245\345\201\234\357\274\232", nullptr));
        label_166->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\256\232\344\275\215\347\212\266\346\200\201\357\274\232", nullptr));
        label_165->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276\350\275\275\345\205\245\347\212\266\346\200\201\357\274\232", nullptr));
        label_144->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\234\200\350\277\221\347\253\231\347\202\271\357\274\232", nullptr));
        label_164->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\267\256Y\357\274\232", nullptr));
        label_137->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\2402\347\224\265\351\207\217\357\274\232", nullptr));
        label_141->setText(QCoreApplication::translate("MainWindow", "\346\200\245\345\201\234\357\274\232", nullptr));
        label_138->setText(QCoreApplication::translate("MainWindow", "\346\277\200\345\205\211\351\201\256\346\214\241\357\274\232", nullptr));
        label_145->setText(QCoreApplication::translate("MainWindow", "\346\212\261\351\227\270\357\274\232", nullptr));
        label_154->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\2402\347\224\265\345\216\213\357\274\232", nullptr));
        label_160->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\267\256X\357\274\232", nullptr));
        label_139->setText(QCoreApplication::translate("MainWindow", "\351\201\256\346\214\241\345\216\237\345\233\240\357\274\232", nullptr));
        label_152->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\237\204\346\230\257\345\220\246\346\277\200\346\264\273", nullptr));
        label_147->setText(QCoreApplication::translate("MainWindow", "\345\257\274\350\210\252\347\261\273\345\236\213\357\274\232", nullptr));
        label_136->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\2401\347\224\265\351\207\217\357\274\232", nullptr));
        label_142->setText(QCoreApplication::translate("MainWindow", "\350\275\257\346\200\245\345\201\234\357\274\232", nullptr));
        label_151->setText(QCoreApplication::translate("MainWindow", "\347\273\247\347\224\265\345\231\250\357\274\232", nullptr));
        label_143->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\2402\347\224\265\346\265\201\357\274\232", nullptr));
        btn_AGVPositionAdjust->setText(QCoreApplication::translate("MainWindow", "AGV\344\275\215\347\275\256\347\273\206\350\260\203\350\212\202", nullptr));
        btn_Battery2->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\224\265\346\261\240\344\272\214\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "AGV\345\255\220\347\263\273\347\273\237", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", "\345\200\276\350\247\222\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_163->setText(QCoreApplication::translate("MainWindow", "X\346\226\271\345\220\221\345\200\276\350\247\222\357\274\232", nullptr));
        btnOpenAngleCOM->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\247\222\345\272\246\344\270\262\345\217\243", nullptr));
        label_340->setText(QCoreApplication::translate("MainWindow", "Y\346\226\271\345\220\221\345\200\276\350\247\222\357\274\232", nullptr));
        label_330->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\346\240\207\345\277\227\357\274\232", nullptr));
        lbl_SymbolAll->setText(QString());
        btn_ShowAngle->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\247\222\345\272\246\344\277\241\346\201\257", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", "\351\230\262\350\231\232\350\204\232\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_157->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2470\350\247\246\345\234\260", nullptr));
        label_240->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol0->setText(QString());
        label_333->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2470\345\216\213\345\212\233\357\274\232", nullptr));
        label_337->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2720\347\224\265\346\265\201\357\274\232", nullptr));
        btnOpenForceCOM->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\216\213\345\212\233\344\270\262\345\217\243", nullptr));
        label_156->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2471\350\247\246\345\234\260", nullptr));
        label_244->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol1->setText(QString());
        label_336->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2471\345\216\213\345\212\233\357\274\232", nullptr));
        label_326->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2721\347\224\265\346\265\201\357\274\232", nullptr));
        label_158->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2472\350\247\246\345\234\260", nullptr));
        label_242->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol2->setText(QString());
        label_334->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2472\345\216\213\345\212\233\357\274\232", nullptr));
        label_332->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2722\347\224\265\346\265\201\357\274\232", nullptr));
        btn_ShowForce->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\216\213\345\212\233\344\277\241\346\201\257", nullptr));
        label_159->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2473\350\247\246\345\234\260", nullptr));
        label_246->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol3->setText(QString());
        label_338->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\2473\345\216\213\345\212\233\357\274\232", nullptr));
        label_335->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2723\347\224\265\346\265\201\357\274\232", nullptr));
        btn_ShowCurrent->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\224\265\346\265\201\344\277\241\346\201\257", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\350\260\203\345\271\263", nullptr));
        lbl_LevelPosi1->setText(QString());
        lblAxisStatusColor3->setText(QString());
        label_266->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        btnZero0_4->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\345\233\236\351\233\266", nullptr));
        lbl_LevelPosi3->setText(QString());
        label_150->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\220\216\347\224\265\346\234\2723", nullptr));
        label_265->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        lblAxisStatusColor1->setText(QString());
        label_243->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        label_146->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\211\215\347\224\265\346\234\2720", nullptr));
        label_245->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        btnInit0_4->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\345\210\235\345\247\213", nullptr));
        label_267->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        lbl_LevelPosi2->setText(QString());
        lblAxisStatusColor2->setText(QString());
        label_161->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\211\215\347\224\265\346\234\2721", nullptr));
        label_113->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\220\216\347\224\265\346\234\2722", nullptr));
        label_241->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        lblAxisStatusColor0->setText(QString());
        label_247->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        label_264->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        lbl_LevelPosi0->setText(QString());
        btnForward0->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\211\215\350\247\222\344\270\213\351\231\215", nullptr));
        btnBackward1->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\211\215\350\247\222\344\270\213\351\231\215", nullptr));
        btnBackward2->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\220\216\350\247\222\344\270\213\351\231\215", nullptr));
        btnForward3->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\220\216\350\247\222\344\270\213\351\231\215", nullptr));
        btnBackward0->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\211\215\350\247\222\346\212\254\345\215\207", nullptr));
        btnForward1->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\211\215\350\247\222\346\212\254\345\215\207", nullptr));
        btnForward2->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\220\216\350\247\222\346\212\254\345\215\207", nullptr));
        btnBackward3->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\220\216\350\247\222\346\212\254\345\215\207", nullptr));
        btnDisAbsMove0_4->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\347\273\235\345\257\271\350\277\220\345\212\250", nullptr));
        btnDisMove0_4->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\347\233\270\345\257\271\350\277\220\345\212\250", nullptr));
        groupBox_22->setTitle(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\260\203\345\271\263", nullptr));
        btn_FeetToGround->setText(QCoreApplication::translate("MainWindow", "\350\204\232\345\272\247\350\247\246\345\234\260", nullptr));
        btn_BalanceBody->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\350\275\246\350\272\253", nullptr));
        btn_BodyToGround->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215\350\247\246\345\234\260", nullptr));
        btn_LevelRapidStop->setText(QString());
        btn_LevelToAuto->setText(QString());
        groupBox_23->setTitle(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\346\250\241\345\274\217", nullptr));
        btn_SpeedBodyUp->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\272\253\346\212\254\345\215\207", nullptr));
        btn_SpeedBodyDown->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\272\253\344\270\213\351\231\215", nullptr));
        groupBox_24->setTitle(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\344\275\215\347\275\256\346\250\241\345\274\217", nullptr));
        btn_PosBodyUp->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\272\253\346\212\254\345\215\207", nullptr));
        btn_PosBodyDown->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\272\253\344\270\213\351\231\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\350\267\235\347\246\273\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\345\255\220\347\263\273\347\273\237", nullptr));
        groupBox_25->setTitle(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250/\350\207\252\345\212\250\344\270\200\347\272\247\345\215\207\351\231\215", nullptr));
        btn_MainLiftToAuto->setText(QString());
        btnInit4->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213", nullptr));
        label_122->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        label_219->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        btnForward4->setText(QCoreApplication::translate("MainWindow", "\344\270\212\345\215\207", nullptr));
        lblAxisStatusColor4->setText(QString());
        btn_MainLiftRapidStop->setText(QString());
        btnBackward4->setText(QCoreApplication::translate("MainWindow", "\344\270\213\351\231\215", nullptr));
        btnDisMove4->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\350\277\220\345\212\250", nullptr));
        label_114->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\350\267\235\347\246\273\357\274\232", nullptr));
        left_laser->setText(QString());
        btnDisableMainLiftAxis->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\346\226\255\345\274\200", nullptr));
        btnEnableMainLiftAxis->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\344\275\277\350\203\275", nullptr));
        lbl_MainLiftPosi4->setText(QString());
        btn_MainLiftBackward->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\344\270\213\351\231\215", nullptr));
        label_105->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\347\224\265\346\234\2724", nullptr));
        btnZero4->setText(QCoreApplication::translate("MainWindow", "\345\233\236\351\233\266", nullptr));
        label_121->setText(QCoreApplication::translate("MainWindow", "\347\273\235\345\257\271\345\235\220\346\240\207\357\274\232", nullptr));
        right_laser->setText(QString());
        btnDisAbsMove4->setText(QCoreApplication::translate("MainWindow", "\347\273\235\345\257\271\350\277\220\345\212\250", nullptr));
        btn_MainLiftForward->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\212\254\345\215\207", nullptr));
        groupBox_29->setTitle(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\345\217\226\350\243\205\347\233\226\346\235\277", nullptr));
        btnForward9_10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\346\234\272\346\236\204\350\277\234\347\246\273", nullptr));
        btnBackward5_6->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\345\217\215\345\220\221\347\272\265\347\247\273", nullptr));
        btnForward7->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\346\250\252\347\247\273+", nullptr));
        label_179->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        btnDisAbsMove9_10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\347\273\235\345\257\271\350\277\220\345\212\250", nullptr));
        btnZero9_10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\345\233\236\351\233\266", nullptr));
        btnZero7_8->setText(QCoreApplication::translate("MainWindow", "\346\250\252\347\247\273\345\233\236\351\233\266", nullptr));
        lbl_CoverPlatePosi5->setText(QString());
        lblAxisStatusColor6->setText(QString());
        lblAxisStatusColor9->setText(QString());
        btnDisAbsMove11->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\273\235\345\257\271\345\215\207\351\231\215", nullptr));
        lblAxisStatusColor5->setText(QString());
        label_104->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273\347\224\265\346\234\2725", nullptr));
        btnBackward7->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\346\250\252\347\247\273-", nullptr));
        btnForward10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\350\277\234\347\246\273", nullptr));
        lblAxisStatusColor7->setText(QString());
        btnBackward6->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\347\272\265\347\247\273-", nullptr));
        btnBackward10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\351\235\240\346\213\242", nullptr));
        label_213->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        lblAxisStatusColor8->setText(QString());
        btnForward9->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\350\277\234\347\246\273", nullptr));
        lbl_CoverPlatePosi6->setText(QString());
        label_227->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        label_181->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        lbl_CoverPlatePosi7->setText(QString());
        btnDisMove7_8->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\233\270\345\257\271\346\250\252\347\247\273", nullptr));
        label_225->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        btnInit7_8->setText(QCoreApplication::translate("MainWindow", "\346\250\252\347\247\273\345\210\235\345\247\213", nullptr));
        lblAxisStatusColor10->setText(QString());
        btnForward6->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\347\272\265\347\247\273+", nullptr));
        btnBackward5->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\347\272\265\347\247\273-", nullptr));
        label_89->setText(QCoreApplication::translate("MainWindow", "\346\250\252\347\247\273\347\224\265\346\234\2728", nullptr));
        btnDisAbsMove5_6->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\273\235\345\257\271\347\272\265\347\247\273", nullptr));
        label_102->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\347\224\265\346\234\2729", nullptr));
        btnForward8->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\346\250\252\347\247\273+", nullptr));
        btnZero11->setText(QCoreApplication::translate("MainWindow", "\345\233\236\351\233\266", nullptr));
        btnForward11->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\344\270\213\351\231\215", nullptr));
        btnInit11->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213", nullptr));
        btnForward5->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\347\272\265\347\247\273+", nullptr));
        label_183->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        btnDisMove11->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\233\270\345\257\271\345\215\207\351\231\215", nullptr));
        label_178->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        label_224->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        label_214->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        btnBackward9->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\351\235\240\346\213\242", nullptr));
        btnBackward9_10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\346\234\272\346\236\204\351\235\240\350\277\221", nullptr));
        lbl_CoverPlatePosi11->setText(QString());
        btnDisAbsMove7_8->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\273\235\345\257\271\346\250\252\347\247\273", nullptr));
        lblAxisStatusColor11->setText(QString());
        lbl_CoverPlatePosi8->setText(QString());
        label_83->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273\347\224\265\346\234\2726", nullptr));
        label_215->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        lbl_CoverPlatePosi9->setText(QString());
        btnZero5_6->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273\345\233\236\351\233\266", nullptr));
        btnForward5_6->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\346\255\243\345\220\221\347\272\265\347\247\273", nullptr));
        btnBackward7_8->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\345\217\215\345\220\221\346\250\252\347\247\273", nullptr));
        lbl_CoverPlatePosi10->setText(QString());
        label_184->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        btnBackward11->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\346\212\254\345\215\207", nullptr));
        btnInit5_6->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273\345\210\235\345\247\213", nullptr));
        label_180->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        label_103->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\347\224\265\346\234\27210", nullptr));
        label_88->setText(QCoreApplication::translate("MainWindow", "\346\250\252\347\247\273\347\224\265\346\234\2727", nullptr));
        btnDisMove9_10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\347\233\270\345\257\271\350\277\220\345\212\250", nullptr));
        label_107->setText(QCoreApplication::translate("MainWindow", "\346\211\230\344\270\276\347\224\265\346\234\27211", nullptr));
        btnInit9_10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\207\345\210\235\345\247\213", nullptr));
        label_182->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        label_223->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        btnForward7_8->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\346\255\243\345\220\221\346\250\252\347\247\273", nullptr));
        btnDisMove5_6->setText(QCoreApplication::translate("MainWindow", "\346\234\272\346\236\204\347\233\270\345\257\271\347\272\265\347\247\273", nullptr));
        btnBackward8->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272\346\250\252\347\247\273-", nullptr));
        groupBox_30->setTitle(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\217\226\350\243\205\347\233\226\346\235\277", nullptr));
        btn_CloseDoor->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\345\260\201\351\227\250", nullptr));
        btn_TakePlate->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\226\346\235\277", nullptr));
        btn_CoverPlateToAuto->setText(QString());
        btn_OpenDoor->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\260\201\351\227\250", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\346\265\201\347\250\213\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_253->setText(QCoreApplication::translate("MainWindow", "\345\217\226\345\260\201\351\227\250\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_TakeDoor->setText(QString());
        label_250->setText(QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_TakePlate->setText(QString());
        label_251->setText(QCoreApplication::translate("MainWindow", "\347\233\226\347\233\226\346\235\277\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_FixPlate->setText(QString());
        label_322->setText(QCoreApplication::translate("MainWindow", "\347\233\226\345\260\201\351\227\250\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_FixDoor->setText(QString());
        btn_AutoTakePlate->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\211\223\345\274\200", nullptr));
        btn_CoverPlateRapidStop->setText(QString());
        label_53->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\2079\347\224\265\346\265\201", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\214\20710\347\224\265\346\265\201", nullptr));
        lbl_current9->setText(QString());
        lbl_current10->setText(QString());
        btn_CoverPlate->setText(QCoreApplication::translate("MainWindow", "\345\256\211\350\243\205\347\233\226\346\235\277", nullptr));
        btn_AutoCoverPlate->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\205\263\351\227\255", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273\350\247\222\345\272\246", nullptr));
        label_angle->setText(QString());
        label_49->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273Y", nullptr));
        label_y->setText(QString());
        label_47->setText(QCoreApplication::translate("MainWindow", "\347\272\265\347\247\273X", nullptr));
        label_x->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\345\215\207\351\231\215+\345\217\226\347\233\226\346\235\277\345\255\220\347\263\273\347\273\237", nullptr));
        groupBox_28->setTitle(QCoreApplication::translate("MainWindow", "\345\205\255\350\207\252\347\224\261\345\272\246\345\271\263\345\217\260", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X\357\274\232", nullptr));
        label_96->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\217\260\344\275\277\350\203\275\357\274\232", nullptr));
        lbl_PlatformIsTarget->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        lbl_PlatformInfoRy->setText(QCoreApplication::translate("MainWindow", "0.001", nullptr));
        lbl_PlatformInfoZ->setText(QCoreApplication::translate("MainWindow", "0.001", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "RY\357\274\232", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "RZ\357\274\232", nullptr));
        lbl_PlatformStatus->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\350\277\220\345\212\250", nullptr));
        label_95->setText(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\347\212\266\346\200\201: ", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "RX\357\274\232", nullptr));
        label_100->setText(QCoreApplication::translate("MainWindow", "\345\247\277\346\200\201\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_PlatformInfoRx->setText(QCoreApplication::translate("MainWindow", "0.0001", nullptr));
        lbl_PlatformEnable->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "Z\357\274\232", nullptr));
        lbl_PlatformInfoY->setText(QCoreApplication::translate("MainWindow", "0.001", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Y\357\274\232", nullptr));
        label_94->setText(QCoreApplication::translate("MainWindow", "\350\255\246\345\221\212\344\277\241\346\201\257\357\274\232", nullptr));
        lbl_PlatformInfoX->setText(QCoreApplication::translate("MainWindow", "0.0001", nullptr));
        lbl_PlatformWarning->setText(QCoreApplication::translate("MainWindow", "NoError", nullptr));
        lbl_PlatformInfoRz->setText(QCoreApplication::translate("MainWindow", "0.001", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\345\247\277\346\200\201\350\256\276\347\275\256", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "X(mm):", nullptr));
        label_93->setText(QCoreApplication::translate("MainWindow", "Z(mm):", nullptr));
        label_85->setText(QCoreApplication::translate("MainWindow", "RX(deg):", nullptr));
        label_86->setText(QCoreApplication::translate("MainWindow", "RY(deg):", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "RZ(deg):", nullptr));
        label_80->setText(QCoreApplication::translate("MainWindow", "Y(mm):", nullptr));
        btn_PlatformGo->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        btn_PlatformStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        btn_PlatformOpen->setText(QCoreApplication::translate("MainWindow", "\345\274\200\346\234\272", nullptr));
        btn_PlatformClose->setText(QCoreApplication::translate("MainWindow", "\345\205\263\346\234\272", nullptr));
        btn_PlatformInitial->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213", nullptr));
        btn_PlatformGoZero->setText(QCoreApplication::translate("MainWindow", "\345\233\236\351\233\266", nullptr));
        btn_PlatformLeveling->setText(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263", nullptr));
        btn_PlatformReset->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\217\260RX:", nullptr));
        groypitch->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\217\260RY\357\274\232", nullptr));
        groyroll->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "\346\234\200\347\273\210X:", nullptr));
        final_x->setText(QString());
        label_66->setText(QCoreApplication::translate("MainWindow", "\346\234\200\347\273\210Y:", nullptr));
        final_y->setText(QString());
        groupBox_18->setTitle(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\344\272\214\347\272\247\345\215\207\351\231\215", nullptr));
        label_111->setText(QCoreApplication::translate("MainWindow", "\347\273\235\345\257\271\345\235\220\346\240\207\357\274\232", nullptr));
        label_97->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        lblAxisStatusColor12->setText(QString());
        btn_LiftRapidStop->setText(QString());
        label_112->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\350\267\235\347\246\273\357\274\232", nullptr));
        label_99->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\347\224\265\346\234\27212", nullptr));
        lbl_LiftPosi12->setText(QString());
        btn_LiftToAuto->setText(QString());
        btnForward12->setText(QCoreApplication::translate("MainWindow", "\344\270\212\345\215\207", nullptr));
        btnZero12->setText(QCoreApplication::translate("MainWindow", "\345\233\236\351\233\266", nullptr));
        label_218->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\357\274\232", nullptr));
        btnBackward12->setText(QCoreApplication::translate("MainWindow", "\344\270\213\351\231\215", nullptr));
        btnInit12->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213", nullptr));
        btnDisAbsMove12->setText(QCoreApplication::translate("MainWindow", "\347\273\235\345\257\271\350\277\220\345\212\250", nullptr));
        btnDisMove12->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\350\277\220\345\212\250", nullptr));
        groupBox_21->setTitle(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\344\272\214\347\272\247\345\215\207\351\231\215(\345\237\272\344\272\216\350\247\206\350\247\211)", nullptr));
        label_132->setText(QCoreApplication::translate("MainWindow", "X\345\256\275\345\272\246(mm)\357\274\232", nullptr));
        lbl_GapWidth_y->setText(QCoreApplication::translate("MainWindow", "2.0", nullptr));
        btn_auto_descent->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\344\270\213\351\231\215", nullptr));
        btn_CheckStatus->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\345\247\277\346\200\201", nullptr));
        lbl_GapWidth_x->setText(QCoreApplication::translate("MainWindow", "2.0", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "x\345\201\217\347\275\256", nullptr));
        btn_stop_secondry->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\216\245\347\256\241", nullptr));
        label2222->setText(QCoreApplication::translate("MainWindow", "rz\345\201\217\347\275\256", nullptr));
        label_129->setText(QCoreApplication::translate("MainWindow", "\347\274\235\351\232\231\350\247\222\345\272\246(deg)\357\274\232", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "\345\205\211\346\272\2202\344\272\256\345\272\246", nullptr));
        btn_StatusModifyLatter->setText(QCoreApplication::translate("MainWindow", "\345\247\277\346\200\201\350\260\203\346\225\264", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "\345\205\211\346\272\2201\344\272\256\345\272\246", nullptr));
        btn_secondary_lift->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\212\254\345\215\207", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "y\345\201\217\347\275\256", nullptr));
        distance1->setText(QString());
        lbl_GapAngle->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label_133->setText(QCoreApplication::translate("MainWindow", "Y\345\256\275\345\272\246(mm)\357\274\232", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\347\242\260\346\222\236\346\243\200\346\265\213", nullptr));
        groupBox_27->setTitle(QCoreApplication::translate("MainWindow", "\345\212\233\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "FX:", nullptr));
        lbl_FX->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Fy:", nullptr));
        lbl_FY->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "Fz:", nullptr));
        lbl_FZ->setText(QString());
        label_108->setText(QCoreApplication::translate("MainWindow", "Mx:", nullptr));
        lbl_MX->setText(QString());
        label_115->setText(QCoreApplication::translate("MainWindow", "My: ", nullptr));
        lbl_MY->setText(QString());
        label_116->setText(QCoreApplication::translate("MainWindow", "Mz:", nullptr));
        lbl_MZ->setText(QString());
        groupBox_32->setTitle(QCoreApplication::translate("MainWindow", "\347\242\260\346\222\236\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        lbl_CrashInfo->setText(QString());
        lbl_isCrash->setText(QString());
        btn_ShowForceInfo->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\212\233\344\277\241\346\201\257", nullptr));
        btn_GoZero->setText(QCoreApplication::translate("MainWindow", "\344\274\240\346\204\237\345\231\250\350\260\203\351\233\266", nullptr));
        btn_CheckCollision->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\347\242\260\346\222\236", nullptr));
        btn_FindCamera->setText(QCoreApplication::translate("MainWindow", "\346\243\200\347\264\242\347\233\270\346\234\272", nullptr));
        btn_CameraMonitor->setText(QCoreApplication::translate("MainWindow", "\351\232\224\346\235\277\347\216\273\347\222\203\350\247\206\350\247\211\347\233\221\346\265\213", nullptr));
        btn_IOForward->setText(QCoreApplication::translate("MainWindow", "\351\207\212\346\224\276\347\211\207\346\236\266\351\224\200\345\255\220", nullptr));
        btn_IOBackward->setText(QCoreApplication::translate("MainWindow", "\346\224\266\347\274\251\347\211\207\346\236\266\351\224\200\345\255\220", nullptr));
        btn_PMCConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\347\201\257\347\256\261\347\224\265\346\234\272", nullptr));
        btn_PMCSpeedBackward->setText(QCoreApplication::translate("MainWindow", "\346\224\266\347\274\251\347\201\257\347\256\261\351\224\200\345\255\220", nullptr));
        btn_PMCSpeedForward->setText(QCoreApplication::translate("MainWindow", "\351\207\212\346\224\276\347\201\257\347\256\261\351\224\200\345\255\220", nullptr));
        btn_LightSongKai->setText(QCoreApplication::translate("MainWindow", "\346\235\276\345\274\200\347\201\257\347\256\261", nullptr));
        btn_LightGuDing->setText(QCoreApplication::translate("MainWindow", "\345\233\272\345\256\232\347\201\257\347\256\261", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\345\215\207\351\231\215\345\255\220\347\263\273\347\273\237", nullptr));
        btn_ExeVehTaskBackward->setText(QCoreApplication::translate("MainWindow", "AGV\346\201\242\345\244\215\345\210\235\345\247\213\344\275\215", nullptr));
        btn_Motor78Backward->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2727\343\200\2018\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_ExeMainLiftTaskBackward->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\344\270\213\351\231\215", nullptr));
        btn_Motor78Forward_16->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2726\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_XYSame->setText(QCoreApplication::translate("MainWindow", "\345\235\220\346\240\207\345\257\271\351\275\220", nullptr));
        btn_Motor78Forward_6->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2720\343\200\2011\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_ExeMainLiftTaskForward->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\346\212\254\345\215\207", nullptr));
        btn_Motor78Forward_9->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2724\343\200\2015\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward_10->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2724\343\200\2015\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward_15->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2726\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_ExeLevelTaskBackward->setText(QCoreApplication::translate("MainWindow", "AGV\350\247\246\345\234\260", nullptr));
        btn_AngleSame->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\272\246\345\257\271\351\275\220", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "LRU\344\275\215\345\247\277\350\260\203\346\225\264", nullptr));
        btn_ExeLiftTaskBackward->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\344\270\213\351\231\215", nullptr));
        btn_ExeLiftTaskForward->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\346\212\254\345\215\207", nullptr));
        btn_Motor78Forward_13->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2722\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward_4->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\224\265\346\261\240\346\225\260\346\215\256", nullptr));
        btn_ExeCoverPlateTaskForward->setText(QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277", nullptr));
        btn_Motor78Forward_12->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2720\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2727\343\200\2018\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_ExePinTaskForward->setText(QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200", nullptr));
        btn_ExeLevelTaskForward->setText(QCoreApplication::translate("MainWindow", "AGV \350\260\203\345\271\263", nullptr));
        btn_Motor78Forward_17->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272IO\344\277\241\346\201\257", nullptr));
        btn_Motor78Forward_5->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2720\343\200\2011\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward_2->setText(QCoreApplication::translate("MainWindow", "144OUTIO\345\206\2311", nullptr));
        btn_Motor78Forward_14->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2722\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward_8->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2722\343\200\2013\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_ExeVehTaskForward->setText(QCoreApplication::translate("MainWindow", "AGV\350\241\214\351\251\266\350\207\263\345\256\211\350\243\205\344\275\215", nullptr));
        btn_Motor78Forward_3->setText(QCoreApplication::translate("MainWindow", "144OUTIO\345\206\2310", nullptr));
        btn_Motor78Forward_7->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2722\343\200\2013\346\255\243\345\220\221\347\247\273\345\212\250", nullptr));
        btn_Motor78Forward_11->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\2720\345\217\215\345\220\221\347\247\273\345\212\250", nullptr));
        btn_ExeCoverPlateTaskBackward->setText(QCoreApplication::translate("MainWindow", "\347\233\226\347\233\226\346\235\277", nullptr));
        btn_PMCSpeedBackward_2->setText(QCoreApplication::translate("MainWindow", "\346\224\266\347\274\251\347\201\257\347\256\261\351\224\200\345\255\220", nullptr));
        btn_CheckDetach->setText(QCoreApplication::translate("MainWindow", "\350\204\261\347\246\273\346\243\200\346\265\213", nullptr));
        btn_LightRelease->setText(QCoreApplication::translate("MainWindow", "\351\207\212\346\224\276\347\201\257\347\256\261\351\224\200\345\255\220", nullptr));
        btn_LightClamp->setText(QCoreApplication::translate("MainWindow", "\346\224\266\347\274\251\347\201\257\347\256\261\351\224\200\345\255\220", nullptr));
        btn_CheckDetach_2->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200\345\255\220\347\263\273\347\273\237", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\351\230\210\345\200\274\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\347\263\273\347\273\237\351\230\210\345\200\274", nullptr));
        btnLevelSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Y\346\226\271\345\220\221\345\200\276\350\247\222\351\230\210\345\200\274\357\274\232", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\220\216\347\224\265\346\234\2722\347\224\265\346\265\201\351\230\210\345\200\274\357\274\232", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\220\216\347\224\265\346\234\2723\347\224\265\346\265\201\351\230\210\345\200\274\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\211\215\347\224\265\346\234\2721\347\224\265\346\265\201\351\230\210\345\200\274\357\274\232", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "X\346\226\271\345\220\221\345\200\276\350\247\222\351\230\210\345\200\274\357\274\232", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\211\215\347\224\265\346\234\2722\347\224\265\346\265\201\351\230\210\345\200\274\357\274\232", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "\346\264\201\345\207\200\347\256\261X\346\226\271\345\220\221\345\200\276\350\247\222\357\274\232", nullptr));
        label_65->setText(QCoreApplication::translate("MainWindow", "\346\264\201\345\207\200\347\256\261Y\346\226\271\345\220\221\345\200\276\350\247\222\357\274\232", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\347\242\260\346\222\236\346\243\200\346\265\213\351\230\210\345\200\274", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Y\346\226\271\345\220\221\345\212\233\351\230\210\345\200\274\357\274\232", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Z\346\226\271\345\220\221\345\212\233\351\230\210\345\200\274\357\274\232", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Y\346\226\271\345\220\221\345\212\233\347\237\251\351\230\210\345\200\274\357\274\232", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "X\346\226\271\345\220\221\345\212\233\351\230\210\345\200\274\357\274\232", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "X\346\226\271\345\220\221\345\212\233\347\237\251\351\230\210\345\200\274\357\274\232", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Z\346\226\271\345\220\221\345\212\233\347\237\251\351\230\210\345\200\274\357\274\232", nullptr));
        btnSixForceSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\350\275\264\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_120->setText(QCoreApplication::translate("MainWindow", "\346\255\243\351\231\220\357\274\232", nullptr));
        cBoxAxisNum->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        cBoxAxisNum->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        cBoxAxisNum->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        cBoxAxisNum->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        cBoxAxisNum->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        cBoxAxisNum->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        cBoxAxisNum->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        cBoxAxisNum->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        cBoxAxisNum->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        cBoxAxisNum->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        cBoxAxisNum->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));
        cBoxAxisNum->setItemText(11, QCoreApplication::translate("MainWindow", "11", nullptr));
        cBoxAxisNum->setItemText(12, QCoreApplication::translate("MainWindow", "12", nullptr));

        label_32->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\350\264\237\351\231\220\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\345\207\217\351\200\237\345\272\246\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\351\200\211\345\256\232\347\224\265\346\234\272\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\350\204\211\345\206\262\345\275\223\351\207\217\357\274\232", nullptr));
        lbl_HeartBeatInfo_2->setText(QString());
        btnAxisSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        leDbName->setText(QCoreApplication::translate("MainWindow", "lru_database", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        leDbUser->setText(QCoreApplication::translate("MainWindow", "root", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        leDbPassword->setText(QCoreApplication::translate("MainWindow", "SHU123456", nullptr));
        leDbHost->setText(QCoreApplication::translate("MainWindow", "localhost", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        btnDbConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        btnDbDisconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\350\277\236\346\216\245\357\274\232", nullptr));
        lbl_database->setText(QString());
        groupBox_16->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\223\215\344\275\234", nullptr));
        btnDbAdd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        btnDbDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        btnDbQuery->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
        cbxDbTables->setItemText(0, QCoreApplication::translate("MainWindow", "sensor_data", nullptr));
        cbxDbTables->setItemText(1, QCoreApplication::translate("MainWindow", "task_status", nullptr));
        cbxDbTables->setItemText(2, QCoreApplication::translate("MainWindow", "error_log", nullptr));

        btnDbShow->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        btnDbSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        leQueryCondition->setText(QString());
        leQueryCondition->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        groupBox_26->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\261\225\347\244\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\347\256\241\347\220\206", nullptr));
        LRUMonitor->setTitle(QCoreApplication::translate("MainWindow", "LRU\346\225\260\345\255\227\345\255\252\347\224\237", nullptr));
        AGVMonitor->setTitle(QCoreApplication::translate("MainWindow", "AGV\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        LevelMonitor->setTitle(QCoreApplication::translate("MainWindow", "\350\260\203\345\271\263\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        LiftMonitor->setTitle(QCoreApplication::translate("MainWindow", "\345\215\207\351\231\215\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        CoverPlateMonitor->setTitle(QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        PinMonitor->setTitle(QCoreApplication::translate("MainWindow", "\346\213\224\351\224\200\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        Camera_2->setTitle(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\350\247\206\350\247\211\347\224\273\351\235\242", nullptr));
        CoverPlate3D->setTitle(QCoreApplication::translate("MainWindow", "\345\217\226\347\233\226\346\235\277\346\225\260\345\255\227\345\255\252\347\224\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
