#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>

#include "Facade/Facade.hpp"
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
 Q_OBJECT

  const double ANGLE = 1 * M_PI / 180;
  const double OFFSET = 5;
  const double SCALE_FACTOR = 1.25;

 public:
  explicit MainWindow(QWidget* parent = 0);
  virtual ~MainWindow();

 protected:
  virtual void keyPressEvent(QKeyEvent*) override;

  void set_up_scene_view();
  void update_scene_view(ssize_t camera_index);

 private slots:
  void on_actionupload_model_triggered();

  void on_addSceneObjectButton_clicked();

  void on_removeSceneObjectButton_clicked();

  void on_deleteViewButton_clicked();

 private:
  Ui::MainWindow* ui;
  QGraphicsScene* scene_view_scene;

  Facade command_controller;
};

#endif 
