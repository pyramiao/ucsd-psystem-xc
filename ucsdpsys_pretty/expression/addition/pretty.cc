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

#include <ucsdpsys_pretty/expression/addition/pretty.h>
#include <ucsdpsys_pretty/translator/pretty.h>


expression_addition_pretty::~expression_addition_pretty()
{
}


expression_addition_pretty::expression_addition_pretty(
    const expression::pointer &a_lhs,
    const expression::pointer &a_rhs,
    translator_pretty *cntxt
) :
    expression_addition(a_lhs, a_rhs),
    pretty(*cntxt)
{
}


expression_addition_pretty::pointer
expression_addition_pretty::create(const expression::pointer &a_lhs,
    const expression::pointer &a_rhs, translator_pretty *cntxt)
{
    return pointer(new expression_addition_pretty(a_lhs, a_rhs, cntxt));
}


void
expression_addition_pretty::pre_order_traversal(int pprec)
    const
{
    if (need_parens(pprec))
        pretty.print_token("(");
}


void
expression_addition_pretty::infix_order_traversal(int)
    const
{
    pretty.print_space();
    pretty.print_token("+");
    pretty.print_space();
}


void
expression_addition_pretty::post_order_traversal(int pprec)
    const
{
    if (need_parens(pprec))
        pretty.print_token(")");
}


void
expression_addition_pretty::logical_traversal(int pprec, label::pointer &,
    label::pointer &, bool) const
{
    traversal(pprec);
}


expression::pointer
expression_addition_pretty::optimize(void)
    const
{
    return create(get_lhs(), get_rhs(), &pretty);
}


expression::pointer
expression_addition_pretty::clone(const location &locn)
    const
{
    return create(get_lhs()->clone(locn), get_rhs()->clone(locn), &pretty);
}


// vim: set ts=8 sw=4 et :