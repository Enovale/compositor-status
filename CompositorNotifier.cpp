#include <KStatusNotifierItem>
#include <QDBusInterface>
#include <QDebug>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include "CompositorNotifier.h"
#include "settings.h"

CompositorNotifier::CompositorNotifier(QObject *parent) : QObject(parent) {
    prefs = new CompositorPrefs();
    settings = new SettingsDiag(nullptr, prefs);

    tray = new KStatusNotifierItem(APPID, this);
    auto* settingsAction = new QAction(QIcon::fromTheme("settings-configure"), "Configure", tray);
    tray->contextMenu()->addAction(settingsAction);
    tray->setTitle("Compositor Status");
    tray->setCategory(KStatusNotifierItem::Hardware);
    updateTrayIcon();

    auto *interface = new QDBusInterface("org.kde.KWin", "/Compositor");

    connect(settings, SIGNAL(accepted()), SLOT(updateTrayIcon()));
    connect(interface, SIGNAL(compositingToggled(bool)), this, SLOT(updateTrayIcon(bool)));
    connect(tray, SIGNAL(activateRequested(bool,QPoint)), this, SLOT(trayClicked(bool,QPoint)));
    connect(settingsAction, SIGNAL(triggered(bool)), this, SLOT(peepSettings()));
}

bool CompositorNotifier::getCompositorEnabled() {
    QDBusInterface interface("org.kde.KWin",
                             "/Compositor");
    QVariant result = interface.property("active");
    return result.value<bool>();
}

void CompositorNotifier::toggleCompositorEnabled() {
    setCompositorEnabled(!getCompositorEnabled());
}

void CompositorNotifier::setCompositorEnabled(bool active) {
    QDBusInterface interface("org.kde.KWin",
                             "/Compositor");
    interface.call(active ? "resume" : "suspend");
}

Q_SLOT void CompositorNotifier::trayClicked(bool active, QPoint pos) {
    toggleCompositorEnabled();
}

Q_SLOT void CompositorNotifier::updateTrayIcon(bool active) {
    QString icon = active ? prefs->getEnabledIcon() : prefs->getDisabledIcon();
    tray->setIconByName(icon);
    tray->setToolTip(QIcon::fromTheme(icon), "Compositor is " + QString(active ? "Enabled" : "Disabled"), "");
    switch(prefs->getTrayShownCondition()) {
        default:
        case 0:
            tray->setStatus(KStatusNotifierItem::Active);
            break;
        case 1:
            tray->setStatus(active ? KStatusNotifierItem::Active : KStatusNotifierItem::Passive);
            break;
        case 2:
            tray->setStatus(active ? KStatusNotifierItem::Passive : KStatusNotifierItem::Active);
            break;
    }
}

Q_SLOT void CompositorNotifier::updateTrayIcon() {
    updateTrayIcon(getCompositorEnabled());
}

Q_SLOT void CompositorNotifier::peepSettings() {
    settings->show();
}
