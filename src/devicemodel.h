#ifndef DEVICEMODEL_H
#define DEVICEMODEL_H

#include <QAbstractListModel>
#include <QPointer>

#include "device.h"

class QSettings;

class DeviceModel final : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int activeDevices READ activeDevices NOTIFY changed)

public:
    enum ServerCountryRoles {
        NameRole = Qt::UserRole + 1,
        CurrentOneRole,
    };

    DeviceModel() = default;

    void fromJson(QJsonObject &userObj);

    bool fromSettings(QSettings &settings);

    void writeSettings(QSettings &settings);

    bool hasDevice(const QString &deviceName) const;

    bool hasPrivateKeyDevice(const QString &currentDeviceName) const;

    void addDevice(const Device &device);

    void removeDevice(const QString &deviceName);

    const Device *device(const QString &deviceName) const;

    int activeDevices() const { return m_devices.count(); }

    // QAbstractListModel methods

    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &) const override;

    QVariant data(const QModelIndex &index, int role) const override;

signals:
    void changed();

private:
    QList<Device> m_devices;
};

#endif // DEVICEMODEL_H
