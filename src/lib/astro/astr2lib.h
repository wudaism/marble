//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2014 Gerhard Holtkamp
//

#if !defined(__astr2lib_h)
#define __astr2lib_h

#include "attlib.h"

/***********************************************************************
	Definitions of Astr2lib Functions


  Author: Gerhard HOLTKAMP                   25-MAR-2014
 ***********************************************************************/

class Plan200      // Calculating the Planets in epoch J2000.0 coordinates
 {
  public:
    Plan200();
    Vec3 velocity();   // return last calculated planet velocity
    void state (Vec3& rs, Vec3& vs);  // return last state vector
    Vec3 Mercury (double t);   // position of Mercury at time t
    Vec3 Venus (double t);   // position of Venus at time t
    Vec3 Mars (double t);   // position of Mars at time t
    Vec3 Jupiter (double t);   // position of Jupiter at time t
    Vec3 Saturn (double t);   // position of Saturn at time t
    Vec3 Uranus (double t);   // position of Uranus at time t
	  Vec3 Neptune (double t);   // position of Neptune at time t
	  Vec3 Pluto (double t);   // position of Pluto at time t

  private:
	 double	c3[19], s3[19];
	 double	c[11], s[11];
	 double	m1, m2, m3, m4, m5, m6, m7, m8;
	 double	d, a, uu, tt;
	 double	u, v, dl, dr, db, l, b, r;
	 Vec3   	rp, vp;   // state vector of planet

    void addthe (double c1, double s1, double c2, double s2,
					double& cc, double& ss);
    void term (int i1, int i, int it, double dlc, double dls, double drc,
			  double drs, double dbc, double dbs);
    void posvel ();  
 };

  void MarPhobos (double t, Vec3& rs, Vec3& vs); // State vector of Phobos
  void MarDeimos (double t, Vec3& rs, Vec3& vs); // State vector of Deimos
  Vec3 PosJIo (double t);      // Position of Io
  Vec3 PosEuropa (double t);   // Position of Europa
  Vec3 PosGanymede (double t); // Position of Ganymede
  Vec3 PosCallisto (double t); // Position of Callisto
  Vec3 PosSMimas (double t); // Position of Mimas
  Vec3 PosSEnceladus (double t); // Position of Enceladus
  Vec3 PosSDione (double t); // Position of Dione
  void JupIo (double t, Vec3& rs, Vec3& vs);       // state vector of Io
  void JupEuropa (double t, Vec3& rs, Vec3& vs);   // state vector of Europa
  void JupGanymede (double t, Vec3& rs, Vec3& vs); // state vector of Ganymede
  void JupCallisto (double t, Vec3& rs, Vec3& vs); // state vector of Callisto
  void SatRhea (double t, Vec3& rs, Vec3& vs);   // state vector of Rhea
  void SatTitan (double t, Vec3& rs, Vec3& vs);  // state vector of Titan
  void NepTriton (double t, Vec3& rs, Vec3& vs); // state vector of Triton
  void PluCharon (double t, Vec3& rs, Vec3& vs); // state vector of Charon

#endif         // __astr2lib_h sentry.

