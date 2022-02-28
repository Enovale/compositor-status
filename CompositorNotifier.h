#include <QObject>
#include <QAbstractItemModel>
#include <KStatusNotifierItem>
#include <KConfigCore/kconfig.h>
#include <KConfigGroup>
#include "settings.h"

#define APPID "compositorstatus"

class CompositorNotifier : public QObject {
    Q_OBJECT
public:
    explicit CompositorNotifier(QObject *parent = nullptr);
    static bool getCompositorEnabled();
    static void toggleCompositorEnabled();
    static void setCompositorEnabled(bool active);
public Q_SLOTS:
    Q_SLOT void updateTrayIcon(bool active);
    Q_SLOT void updateTrayIcon();
    Q_SLOT void trayClicked(bool active, QPoint pos);
private:
    Q_SLOT void peepSettings();
    KStatusNotifierItem *tray;
    KSharedConfigPtr config;
    CompositorPrefs *prefs;
    SettingsDiag *settings;
};