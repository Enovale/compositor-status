#include "settings.h"
#include "CompositorNotifier.h"

CompositorPrefs::CompositorPrefs() {
    config = KSharedConfig::openConfig(APPID);
    group = config->group(GENERAL_GROUP);
    setEnabledIcon(group.readEntry(ENABLEDICON_KEY, "tvconnected"));
    setDisabledIcon(group.readEntry(DISABLEDICON_KEY, "tvdisconnected"));
    setTrayShownCondition(group.readEntry(SHOWNCONDITION_KEY, 0));
    sync();
}

QString CompositorPrefs::getEnabledIcon() {
    return enabledIcon;
}

void CompositorPrefs::setEnabledIcon(QString value) {
    enabledIcon = value;
    group.writeEntry(ENABLEDICON_KEY, value);
}

QString CompositorPrefs::getDisabledIcon() {
    return disabledIcon;
}

void CompositorPrefs::setDisabledIcon(QString value) {
    disabledIcon = value;
    group.writeEntry(DISABLEDICON_KEY, value);
}

int CompositorPrefs::getTrayShownCondition() {
    return shownCondition;
}

void CompositorPrefs::setTrayShownCondition(int value) {
    shownCondition = value;
    group.writeEntry(SHOWNCONDITION_KEY, value);
}

void CompositorPrefs::sync() {
    group.sync();
    config->sync();
}


