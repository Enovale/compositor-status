#pragma once
#include <KConfigSkeleton>
#include <KConfigGroup>

#define GENERAL_GROUP "General"
#define ENABLEDICON_KEY "EnabledIcon"
#define DISABLEDICON_KEY "DisabledIcon"
#define SHOWNCONDITION_KEY "TrayShownCondition"

class CompositorPrefs {
public:
    explicit CompositorPrefs();
    QString getEnabledIcon();
    void setEnabledIcon(QString value);
    QString getDisabledIcon();
    void setDisabledIcon(QString value);
    int getTrayShownCondition();
    void setTrayShownCondition(int value);
    void sync();
private:
    QString enabledIcon;
    QString disabledIcon;
    int shownCondition;
    KSharedConfigPtr config;
    KConfigGroup group;
};