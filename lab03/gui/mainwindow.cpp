#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QFileDialog>
#include <QMessageBox>

#include "commands/commands.hpp"
#include "gui/drawers.hpp"
#include "exceptions/BaseException.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->frame->setFixedWidth(250);
  this->set_up_scene_view();
  ui->cameraChoiceButton->addItem(QString::number(0) + " : camera");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e) {
  ssize_t model_current_index = ui->modelChoiceButton->currentIndex() - 1;
  std::size_t camera_current_index = ui->cameraChoiceButton->currentIndex();

  try {

    if (e->key() == Qt::Key_W) {
      commands::RotateModelOX comm(ANGLE, model_current_index);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_A) {
      commands::RotateModelOY comm(ANGLE, model_current_index);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_S) {
      commands::RotateModelOX comm(-ANGLE, model_current_index);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_D) {
      commands::RotateModelOY comm(-ANGLE, model_current_index);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_Z) {
      commands::RotateModelOZ comm(-ANGLE, model_current_index);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_X) {
      commands::RotateModelOZ comm(ANGLE, model_current_index);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_I) {
      Point3D<double> point(0, OFFSET, 0);
      commands::TranslateModel comm(model_current_index, point);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_J) {
      Point3D<double> point(-OFFSET, 0, 0);
      commands::TranslateModel comm(model_current_index, point);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_K) {
      Point3D<double> point(0, -OFFSET, 0);
      commands::TranslateModel comm(model_current_index, point);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_L) {
      Point3D<double> point(OFFSET, 0, 0);
      commands::TranslateModel comm(model_current_index, point);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_M) {
      Point3D<double> point(0, 0, OFFSET);
      commands::TranslateModel comm(model_current_index, point);
      this->command_controller.executeCommand(comm);

    }  else if (e->key() == Qt::Key_N) {
      Point3D<double> point(0, 0, -OFFSET);
      commands::TranslateModel comm(model_current_index, point);
      this->command_controller.executeCommand(comm);

    }  else if (e->key() == Qt::Key_Plus) {
      commands::ScaleModel comm(model_current_index, SCALE_FACTOR);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_Minus) {
      commands::ScaleModel comm(model_current_index, 1 / SCALE_FACTOR);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_H) {
      commands::RollLook comm(camera_current_index, ANGLE);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_F) {
      commands::RollLook comm(camera_current_index, -ANGLE);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_T) {
      commands::RollUp comm(camera_current_index, -ANGLE);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_G) {
      commands::RollUp comm(camera_current_index, ANGLE);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_B) {
      commands::RollRight comm(camera_current_index, -ANGLE);
      this->command_controller.executeCommand(comm);

    } else if (e->key() == Qt::Key_V) {
      commands::RollRight comm(camera_current_index, ANGLE);
      this->command_controller.executeCommand(comm);
    }

    this->update_scene_view(camera_current_index);

  } catch (BaseException& ex) {
    QMessageBox::warning(this, "Error message", QString(ex.what()));
  }
}

void MainWindow::set_up_scene_view() {
  this->scene_view_scene = new QGraphicsScene(ui->sceneView);
  ui->sceneView->setMinimumSize(600, 600);
  ui->sceneView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->sceneView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->sceneView->installEventFilter(this);
}

void MainWindow::update_scene_view(ssize_t camera_index) {
  this->scene_view_scene->clear();
  Drawer dr(this->scene_view_scene);
  commands::Draw comm(camera_index, dr);
  this->command_controller.executeCommand(comm);
  ui->sceneView->setScene(this->scene_view_scene);
}

void MainWindow::on_actionupload_model_triggered() {
  try {
    QString filename = "../models/platonic/cube";// QFileDialog::getOpenFileName(this, QObject::tr("Specify file with model"), QDir::currentPath(), QObject::tr("Any file (*)"));
    if (filename.isEmpty())
      return;
    commands::UploadView comm(filename.toStdString());
    this->command_controller.executeCommand(comm);
    ui->listWidget->addItem(filename.section("/", -1, -1).section(".", 0, 0));

  } catch (BaseException& ex) {
    QMessageBox::warning(this, "Error message", QString(ex.what()));
  }
}

void MainWindow::on_addSceneObjectButton_clicked() {
  try {

    if (ui->modelButton->isChecked() && ui->listWidget->count() > 0) {
      commands::AddModel comm(ui->listWidget->currentIndex().row());
      this->command_controller.executeCommand(comm);
      ui->modelChoiceButton->addItem(QString::number(ui->modelChoiceButton->count() - 1) + " : model");

    } else if (ui->cameraButton->isChecked()) {
      commands::AddCamera comm;
      this->command_controller.executeCommand(comm);
      ui->cameraChoiceButton->addItem(QString::number(ui->cameraChoiceButton->count()) + " : camera");
    }

    this->update_scene_view(ui->cameraChoiceButton->currentIndex());

  } catch (BaseException& ex) {
    QMessageBox::warning(this, "Error message", QString(ex.what()));
  }
}

void MainWindow::on_removeSceneObjectButton_clicked() {
  try {

    if (ui->modelButton->isChecked() && ui->modelChoiceButton->currentIndex() > 0) {
      commands::DeleteModel comm(ui->modelChoiceButton->currentIndex() - 1);
      this->command_controller.executeCommand(comm);
      std::size_t i = static_cast<std::size_t>(ui->modelChoiceButton->currentIndex());
      ui->modelChoiceButton->removeItem(ui->modelChoiceButton->currentIndex());

      for (; i < static_cast<std::size_t>(ui->modelChoiceButton->count()); ++i) {
        ui->modelChoiceButton->setItemText(i, QString::number(i - 1) + " : model");
      }

    } else if (ui->cameraButton->isChecked() && ui->cameraChoiceButton->currentIndex() > 0) {
      commands::DeleteCamera comm(ui->cameraChoiceButton->currentIndex());
      this->command_controller.executeCommand(comm);
      std::size_t i = static_cast<std::size_t>(ui->cameraChoiceButton->currentIndex());
      ui->cameraChoiceButton->removeItem(ui->cameraChoiceButton->currentIndex());

      for (; i < static_cast<std::size_t>(ui->cameraChoiceButton->count()); ++i) {
        ui->cameraChoiceButton->setItemText(i, QString::number(i) + " : camera");
      }
    }

    this->update_scene_view(ui->cameraChoiceButton->currentIndex());

  } catch (BaseException& ex) {
    QMessageBox::warning(this, "Error message", QString(ex.what()));
  }
}

void MainWindow::on_deleteViewButton_clicked() {
  try {
    commands::DeleteView comm(ui->listWidget->currentIndex().row());
    this->command_controller.executeCommand(comm);

  } catch (BaseException& ex) {
    QMessageBox::warning(this, "Error message", QString(ex.what()));
  }

  delete ui->listWidget->item(ui->listWidget->currentIndex().row());
}
