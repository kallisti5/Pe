/*	$Id$
	
	Copyright 1996, 1997, 1998, 2002
	        Hekkelman Programmatuur B.V.  All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	1. Redistributions of source code must retain the above copyright notice,
	   this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.
	3. All advertising materials mentioning features or use of this software
	   must display the following acknowledgement:
	   
	    This product includes software developed by Hekkelman Programmatuur B.V.
	
	4. The name of Hekkelman Programmatuur B.V. may not be used to endorse or
	   promote products derived from this software without specific prior
	   written permission.
	
	THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
	AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
	OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
	OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 	

	Created: 10/15/97 11:08:27
*/

#include "pe.h"
#include "HBox.h"
#include "HDefines.h"

void HBox::Draw(BRect update)
{
	BRect R(Bounds());
	float l = R.left, t = R.top, r = R.right, b = R.bottom;
	
	if (Label())
	{
		font_height fh;
		be_plain_font->GetHeight(&fh);
		float lh = fh.ascent + fh.descent, w = StringWidth(Label()) + 4;
		
		DrawString(Label(), BPoint(6, lh));
		
		BeginLineArray(10);
		AddLine(BPoint(l, t + lh / 2), BPoint(l + 4, t + lh / 2), kShadow);
		AddLine(BPoint(l + 1, t + lh / 2 + 1), BPoint(l + 5, t + lh / 2 + 1), kWhite);
		
		AddLine(BPoint(l + w + 4, t + lh / 2), BPoint(r, t + lh / 2), kShadow);
		AddLine(BPoint(l + w + 4, t + lh / 2 + 1), BPoint(r - 1, t + lh / 2 + 1), kWhite);
		
		AddLine(BPoint(l, t + lh / 2), BPoint(l, b), kShadow);
		AddLine(BPoint(l + 1, t + lh / 2 + 1), BPoint(l + 1, b - 2), kWhite);
		
		AddLine(BPoint(l, b - 1), BPoint(r - 1, b - 1), kShadow);
		AddLine(BPoint(l, b), BPoint(r, b), kWhite);
				
		AddLine(BPoint(r - 1, b - 1), BPoint(r - 1, t + lh / 2), kShadow);
		AddLine(BPoint(r, b), BPoint(r, t + lh / 2), kWhite);
		
		EndLineArray();
	}
	else
	{
		BeginLineArray(8);
		AddLine(BPoint(l, t), BPoint(r - 1, t), kShadow);
		AddLine(BPoint(l + 1, t + 1), BPoint(r - 2, t + 1), kWhite);
		
		AddLine(BPoint(l, t), BPoint(l, b - 1), kShadow);
		AddLine(BPoint(l + 1, t + 1), BPoint(l + 1, b - 2), kWhite);
		
		AddLine(BPoint(l, b - 1), BPoint(r - 1, b - 1), kShadow);
		AddLine(BPoint(l, b), BPoint(r, b), kWhite);
				
		AddLine(BPoint(r - 1, b - 1), BPoint(r - 1, t), kShadow);
		AddLine(BPoint(r, b), BPoint(r, t), kWhite);
		
		EndLineArray();
	}
} /* HBox::Draw */
