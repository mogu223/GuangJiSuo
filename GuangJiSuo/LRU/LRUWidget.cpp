#include "LRUWidget.h"

LRUWidget::LRUWidget(QWidget *parent)
    : QWidget(parent)
{
    QWidget *container = QWidget::createWindowContainer(new Qt3DExtras::Qt3DWindow());
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(container);
    layout->setContentsMargins(0, 0, 0, 0);

    m_view = qobject_cast<Qt3DExtras::Qt3DWindow *>(container->window());
    m_rootEntity = new Qt3DCore::QEntity;

    // 设置摄像机
    Qt3DRender::QCamera *camera = m_view->camera();
    camera->setPosition(QVector3D(5, 5, 5));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // 添加坐标系
    createCoordinateSystem();

    // 初始化模型实体
    m_modelEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_modelTransform = new Qt3DCore::QTransform;
    m_stlMesh = new Qt3DRender::QMesh;

    m_modelEntity->addComponent(m_stlMesh);
    m_modelEntity->addComponent(m_modelTransform);
    m_modelEntity->addComponent(new Qt3DExtras::QPhongMaterial());

    m_view->setRootEntity(m_rootEntity);
}

void LRUWidget::createCoordinateSystem()
{
    // 创建网格
    Qt3DCore::QEntity *gridEntity = new Qt3DCore::QEntity(m_rootEntity);
    Qt3DExtras::QGridMesh *gridMesh = new Qt3DExtras::QGridMesh;
    gridMesh->setLines(20);
    gridMesh->setMinorLines(4);
    gridMesh->setXYPlane(true);
    gridEntity->addComponent(gridMesh);
    gridEntity->addComponent(new Qt3DExtras::QPhongMaterial());

    // 创建坐标轴
    auto createAxis = [&](QVector3D start, QVector3D end, QColor color) {
        Qt3DCore::QEntity *axis = new Qt3DCore::QEntity(m_rootEntity);
        Qt3DExtras::QCylinderMesh *cylinder = new Qt3DExtras::QCylinderMesh;
        cylinder->setRadius(0.02f);
        cylinder->setLength(end.distanceToPoint(start));

        Qt3DCore::QTransform *transform = new Qt3DCore::QTransform;
        transform->setTranslation((start + end) * 0.5f);
        transform->setRotation(QQuaternion::fromDirection(end - start, QVector3D(0, 1, 0)));

        axis->addComponent(cylinder);
        axis->addComponent(transform);
        axis->addComponent(new Qt3DExtras::QPhongMaterial(color));
    };

    createAxis(QVector3D(0,0,0), QVector3D(5,0,0), Qt::red);   // X轴
    createAxis(QVector3D(0,0,0), QVector3D(0,5,0), Qt::green); // Y轴
    createAxis(QVector3D(0,0,0), QVector3D(0,0,5), Qt::blue);  // Z轴
}

void LRUWidget::loadSTLModel(const QString &filePath)
{
    m_stlMesh->setSource(QUrl::fromLocalFile(filePath));
}

void LRUWidget::updateModelPosition(float x, float y, float z)
{
    m_modelTransform->setTranslation(QVector3D(x, y, z));
}
