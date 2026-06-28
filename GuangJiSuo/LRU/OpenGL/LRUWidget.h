#ifndef LRUWIDGET_H
#define LRUWIDGET_H


#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QGridMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QText2DEntity>

class LRUWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LRUWidget(QWidget *parent = nullptr);
    void loadSTLModel(const QString &filePath);
    void updateModelPosition(float x, float y, float z);

private:
    void createCoordinateSystem();

    Qt3DExtras::Qt3DWindow *m_view;
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_modelEntity;
    Qt3DRender::QMesh *m_stlMesh;
    Qt3DCore::QTransform *m_modelTransform;
};


#endif // LRUWIDGET_H
