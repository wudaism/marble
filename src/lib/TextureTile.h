//
// This file is part of the Marble Desktop Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2007-2009  Torsten Rahn <tackat@kde.org>"
// Copyright 2007       Inge Wallin  <ingwa@kde.org>"
//

//
// Description: TextureTile contains a single image quadtile 
// and jumptables for faster access to the pixel data
//


#ifndef __MARBLE__TEXTURETILE_H
#define __MARBLE__TEXTURETILE_H


#include <QtCore/QCache>
#include <QtCore/QObject>

#include "AbstractTile.h"

class QImage;
class QString;
class QUrl;

namespace Marble
{

class TextureTilePrivate;
class GeoSceneTexture;

class TextureTile : public AbstractTile {
    Q_OBJECT

 public:

    explicit TextureTile( TileId const& tid, QObject * parent = 0 );

    virtual ~TextureTile();
    
    // TODO: Move into DatasetProvider:
    void loadDataset( Marble::GeoSceneTexture *textureLayer, int level, int x,
                      int y, QCache<TileId, TextureTile> *tileCache = 0 );

    int depth() const;

    int numBytes() const;

    QImage rawtile();
    QImage *tile();

    // Here we retrieve the color value of the requested pixel on the tile.
    // This needs to be done differently for grayscale ( uchar, 1 byte ).
    // and color ( uint, 4 bytes ) images.

    uint pixel( int x, int y ) const;

 Q_SIGNALS:
    void tileUpdateDone();
    void downloadTile(const QUrl& sourceUrl, const QString& destinationFileName,
                      const QString& id);

 public Q_SLOTS:
    void   loadTile( bool requestTileUpdate = true );

 protected:
    TextureTile( TextureTilePrivate &dd, QObject *parent );

 private:
    Q_DECLARE_PRIVATE( TextureTile )
    Q_DISABLE_COPY( TextureTile )
};

}

#endif // __MARBLE__TEXTURETILE_H
