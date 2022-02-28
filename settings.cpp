#include "settings.h"

#include <utility>
#include "ui_settings.h"

SettingsDiag::SettingsDiag(QWidget *parent, CompositorPrefs *cfg) :
        QDialog(parent), ui(new Ui::SettingsDiag) {
    ui->setupUi(this);
    prefs = cfg;
    ui->enabledIcon->setIcon(prefs->getEnabledIcon());
    ui->disabledIcon->setIcon(prefs->getDisabledIcon());
    ui->trayIconComboBox->setCurrentIndex(prefs->getTrayShownCondition());
    connect(this, SIGNAL(accepted()), SLOT(accepted()));
}

SettingsDiag::~SettingsDiag() {
    delete ui;
}

void SettingsDiag::enabledIconChanged(QString value) {
    prefs->setEnabledIcon(std::move(value));
}

void SettingsDiag::disabledIconChanged(QString value) {
    prefs->setDisabledIcon(std::move(value));
}

void SettingsDiag::trayConditionChanged(int value) {
    prefs->setTrayShownCondition(value);
}

void SettingsDiag::accepted() {
    prefs->sync();
}

