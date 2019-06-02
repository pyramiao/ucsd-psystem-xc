//
// UCSD p-System cross compiler
// Copyright (C) 2006, 2007, 2010, 2012 Peter Miller
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or (at
// you option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program. If not, see <http://www.gnu.org/licenses/>
//

#include <ucsdpsys_littoral/statement/compound/littoral.h>
#include <ucsdpsys_littoral/translator/littoral.h>


statement_compound_littoral::~statement_compound_littoral()
{
}


statement_compound_littoral::statement_compound_littoral(
    const statement_list &sl,
    translator_littoral *cntxt
) :
    statement_compound(sl),
    littoral(*cntxt)
{
}


statement_compound_littoral::pointer
statement_compound_littoral::create(const statement_list &sl,
    translator_littoral *cntxt)
{
    return pointer(new statement_compound_littoral(sl, cntxt));
}


void
statement_compound_littoral::traversal_begin()
    const
{
    littoral.print_token("{");
    littoral.print_eoln();
    littoral.indent_more();
}


void
statement_compound_littoral::traversal_semicolon()
    const
{
}


void
statement_compound_littoral::traversal_end()
    const
{
    littoral.indent_less();
    littoral.print_token("}");
    littoral.print_eoln();
}


// vim: set ts=8 sw=4 et :
