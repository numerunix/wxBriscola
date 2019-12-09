/**********************************************************************************
 *   Copyright (C) 2015 by Giulio Sorrentino                                      *
 *   gsorre84@gmail.com                                                           *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the GNU Lesser General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or            *
 *   (at your option) any later version.                                          *
 *                                                                                *
 *   This program is distributed in the hope that it will be useful,              *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
 *   GNU General Public License for more details.                                 *
 *                                                                                *
 *   You should have received a copy of the GNU General Public License            *
 *   along with this program; if not, write to the                                *
 *   Free Software Foundation, Inc.,                                              *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                    *
 **********************************************************************************/

#ifndef _GIOCATORE_HELPER_H_
#define _GIOCATORE_HELPER_H_

#include "carta.h"
#include <stdexcept>
#include <vector>
#include <wx/dcbuffer.h>

/* Identifica una classe per personalizzare i comportamenti della classe giocatore*/

class giocatoreHelper {
	public:
		giocatoreHelper() {;}
		virtual size_t gioca(const vector<carta *> &v, size_t i)=0; //il giocatore gioca da primo di mano
		virtual size_t gioca(const vector<carta *> &v, carta *c, size_t iCarta)=0; //il giocatore gioca da secondo di mano
		virtual size_t getPunteggio(carta *c, carta *c1)=0; //deve restituire i punteggi delle due carte
		virtual wxPoint paint(wxPaintDC &dc, const wxString nome, const vector<carta *> mano, const size_t iCartaGiocata)=0; //disegna il giocatore sullo schermo
		virtual ~giocatoreHelper() {};
};

#endif
