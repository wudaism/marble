//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2013      Sanjiban Bairagya <sanjiban22393@gmail.com>
//

#include "KmlOrientationTagHandler.h"

#include "MarbleDebug.h"

#include "KmlElementDictionary.h"
#include "GeoDataOrientation.h"
#include "GeoDataGeometry.h"
#include "GeoDataModel.h"
#include "GeoDataParser.h"

namespace Marble
{
namespace kml
{
KML_DEFINE_TAG_HANDLER( Orientation )

GeoNode* KmlOrientationTagHandler::parse( GeoParser& parser ) const
{
    Q_ASSERT( parser.isStartElement() && parser.isValidElement( kmlTag_Orientation ) );

    GeoDataOrientation orientation;
    GeoStackItem parentItem = parser.parentElement();
#ifdef DEBUG_TAGS
    mDebug() << "Parsed <" << kmlTag_Orientation << ">"
             << " parent item name: " << parentItem.qualifiedName().first;
#endif

    if( parentItem.represents( kmlTag_Model ) ) {
        parentItem.nodeAs<GeoDataModel>()->setOrientation(orientation);
	return &parentItem.nodeAs<GeoDataModel>()->orientation();
    }
    else{
        return 0;
    }
}

}
}
