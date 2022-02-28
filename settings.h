#pragma once
#include <QDialog>
#include "CompositorPrefs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsDiag; }
QT_END_NAMESPACE

class SettingsDiag : public QDialog {
Q_OBJECT

public:
    explicit SettingsDiag(QWidget *parent, CompositorPrefs *cfg);

    ~SettingsDiag() override;

private:
    Ui::SettingsDiag *ui;
    CompositorPrefs *prefs;
    Q_SLOT void enabledIconChanged(QString);
    Q_SLOT void disabledIconChanged(QString);
    Q_SLOT void trayConditionChanged(int);
    Q_SLOT void accepted();
};