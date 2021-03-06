//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2013      Mohammed Nafees <nafees.technocool@gmail.com>
//

#ifndef GEODATANETWORKLINKCONTROL_H
#define GEODATANETWORKLINKCONTROL_H

#include "GeoDataContainer.h"
#include "GeoDataUpdate.h"
#include "GeoDataAbstractView.h"
#include "marble_export.h"

class QDateTime;

namespace Marble
{

class GeoDataNetworkLinkControlPrivate;

class MARBLE_EXPORT GeoDataNetworkLinkControl : public GeoDataContainer
{
public:
    GeoDataNetworkLinkControl();

    GeoDataNetworkLinkControl( const GeoDataNetworkLinkControl &other );

    GeoDataNetworkLinkControl& operator=( const GeoDataNetworkLinkControl &other );

    bool operator==( const GeoDataNetworkLinkControl &other ) const;
    bool operator!=( const GeoDataNetworkLinkControl &other ) const;

    ~GeoDataNetworkLinkControl();

    /** Provides type information for downcasting a GeoNode */
    virtual const char* nodeType() const;

    qreal minRefreshPeriod() const;
    void setMinRefreshPeriod( const qreal &minRefreshPeriod );

    qreal maxSessionLength() const;
    void setMaxSessionLength( const qreal &maxSessionLength );

    QString cookie() const;
    void setCookie( const QString &cookie );

    QString message() const;
    void setMessage( const QString &message );

    QString linkName() const;
    void setLinkName( const QString &linkName );

    QString linkDescription() const;
    void setLinkDescription( const QString &linkDescription );

    QString linkSnippet() const;
    void setLinkSnippet( const QString &linkSnippet );
    int maxLines() const;
    void setMaxLines( const int &maxLines );

    QDateTime expires() const;
    void setExpires( const QDateTime &expires );

    GeoDataUpdate& update();
    const GeoDataUpdate& update() const;
    void setUpdate( const GeoDataUpdate &update );

    GeoDataAbstractView* abstractView() const;
    /**
     * Sets the abstract view and takes control of this pointer.
     */
    void setAbstractView( GeoDataAbstractView *abstractView );

private:
    GeoDataNetworkLinkControlPrivate* const d;
};

}

#endif
