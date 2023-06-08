/**********************************************************************************
 *   Copyright (C) 2022 by Giulio Sorrentino                                      *
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

 #ifndef _DOUBLE_VALIDATOR_H_
#define _DOUBLE_VALIDATOR_H_

#include <wx/wx.h>
#include <stdexcept>
#include <wx/validate.h>
#include <wx/textctrl.h>
#include <wx/wxchar.h>
using namespace std;

// Questa classe rappresenta un validatore che accetta solo numeri interi in un range ben determinati

class IntValidator : public wxValidator {
    private:
        long min, max; //minimo e masimo valore accettabile
        wxString* valore; //valore attualmente contenuto
        void OnChar(wxKeyEvent& event); //valida il valore alla pressione del tasto
        /* Verifica che il valore sia accettabile
            PARAMETRI:
                INPUT: v: nuovo valore da validare
                       valida: true se si sta effettuando la validazione non in real time
                restituisce true se il valore Ë accettabile, false altrimenti
        */
        virtual bool controllaValore(const wxString& v, bool valida);
        DECLARE_EVENT_TABLE()
    public:
        /*Parameri:
           INPUT v: stringa che conterra' il valore dopo la validazione
                 min: minimo valore accettabile
                 max: massimo valore accettabile
            Lancia un range error se min>max
            Lancia un invalid argument se v e' null
        */
        IntValidator(wxString* v, long min, long max);
        IntValidator(const IntValidator& val);
        virtual IntValidator* Clone(void) const {return (new IntValidator(*this));};
        virtual bool TransferToWindow(void);
        virtual bool TransferFromWindow(void);
        virtual bool Validate(wxWindow *parent);
};

#endif
