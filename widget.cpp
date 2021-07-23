#include "widget.h"

#include <QFile>
#include <QFileDialog>
#include <QPainter>
#include <QPushButton>

#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::Widget)
{
  ui->setupUi(this);
  //  connect(ui->pushButton, &QPushButton::clicked, [=]() {
  //    posX += 20;
  //    update();
  //  });

  connect(ui->pushButton, &QPushButton::clicked, [=]() {
    //获取文件路径
    QString path = QFileDialog::getOpenFileName(
        this, "打开文件", "C://Users//oujiacheng//Desktop//123.txt");
    ui->lineEdit->setText(path);

    //读取文件内容
    QFile file(path);
    file.open(QIODevice::ReadOnly);

    QByteArray array = file.readAll();

    ui->textEdit->setText(array);

    file.close();
  });
}

// void Widget::paintEvent(QPaintEvent *event) {
//  //  QPainter painter(this);
//  //  painter.setRenderHint(QPainter::Antialiasing);
//  //  painter.drawEllipse(QPoint(100, 50), 50, 50);

//  QPainter painter(this);
//  if (posX > this->width()) {
//    posX = 0;
//  }
//  painter.drawPixmap(posX, 0,
//                     QPixmap("C://Users//oujiacheng//Desktop//image//1.png"));
//}

Widget::~Widget() { delete ui; }
