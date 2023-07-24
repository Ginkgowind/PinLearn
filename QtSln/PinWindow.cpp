#include "PinWindow.h"
#include <QMouseEvent>
#include <assert.h>

PinWindow::PinWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PinWindowClass())
{
    ui->setupUi(this);

    resize(600, 400);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    // 切换Pin状态按钮
    toggleBtn = new QPushButton("toggle",this);
    toggleBtn->resize(60, 40);
    toggleBtn->move(270, 180);
    connect(toggleBtn, &QPushButton::clicked, this, [this]() {
        bPin = !bPin;
    });

    // 关闭按钮
    closeBtn = new QPushButton("close", this);
    closeBtn->resize(60, 40);
    closeBtn->move(540, 0);
    connect(closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

PinWindow::~PinWindow()
{
    delete ui;
}

void PinWindow::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        bDraging = true;
        // 获得鼠标的初始位置
        mouseStartPoint = ev->globalPos();
        // mouseStartPoint = event->pos();
        // 获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void PinWindow::mouseReleaseEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        bDraging = false;
    }
}

void PinWindow::mouseMoveEvent(QMouseEvent* ev)
{
    if (!bPin && bDraging) {
        // 获得鼠标移动的距离
        QPoint distance = ev->globalPos() - mouseStartPoint;
        // QPoint distance = ev->pos() - mouseStartPoint;
        // 改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}
