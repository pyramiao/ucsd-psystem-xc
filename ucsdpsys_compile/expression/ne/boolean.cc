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

#include <lib/ac/assert.h>

#include <lib/label.h>
#include <lib/pcode.h>
#include <lib/type.h>
#include <ucsdpsys_compile/expression/boolean/compile.h>
#include <ucsdpsys_compile/expression/logical_not/compile.h>
#include <ucsdpsys_compile/expression/ne/boolean.h>
#include <ucsdpsys_compile/translator/compile.h>


expression_ne_boolean::~expression_ne_boolean()
{
}


expression_ne_boolean::expression_ne_boolean(
    const expression::pointer &a_lhs,
    const expression::pointer &a_rhs,
    translator_compile *cntxt
) :
    expression_ne(a_lhs, a_rhs),
    code(*cntxt)
{
}


expression_ne_boolean::pointer
expression_ne_boolean::create(const expression::pointer &a_lhs,
    const expression::pointer &a_rhs, translator_compile *cntxt)
{
    return pointer(new expression_ne_boolean(a_lhs, a_rhs, cntxt));
}


void
expression_ne_boolean::post_order_traversal(int)
    const
{
    code.breakpoint(get_location());
    code.emit_byte(NEQ);
    code.emit_byte(OP_CMP_BOOLEAN);
}


expression::pointer
expression_ne_boolean::optimize(void)
    const
{
    expression::pointer c1 = get_lhs();
    expression::pointer c2 = get_rhs();
    expression::pointer e1 = c1->optimize();
    expression::pointer e2 = c2->optimize();

    assert(e1->get_type() == e2->get_type());
    if (e1->is_constant() && e2->is_constant())
    {
        return
            expression_boolean_compile::create
            (
                get_location(),
                e1->get_boolean_value() != e2->get_boolean_value(),
                &code
            );
    }
    if (e1->is_constant())
    {
        bool e1v = e1->get_boolean_value();
        if (e1v)
        {
            // (true != e2) => (false == e2) => !e2
            return expression_logical_not_compile::create(e2, &code);
        }
        else
        {
            // (false != e2) => (true == e2) => e2
            return e2;
        }
    }
    if (e2->is_constant())
    {
        bool e2v = e2->get_boolean_value();
        if (e2v)
        {
            // (e1 != true) => (e1 == false) => !e1
            return expression_logical_not_compile::create(e1, &code);
        }
        else
        {
            // (e1 != false) => (r1 == true) => e1
            return e1;
        }
    }

    return expression_ne_boolean::create(e1, e2, &code);
}


expression::pointer
expression_ne_boolean::clone(const location &locn)
    const
{
    return create(get_lhs()->clone(locn), get_rhs()->clone(locn), &code);
}


void
expression_ne_boolean::logical_traversal(int pprec,
    label::pointer &true_branch, label::pointer &false_branch,
    bool fall_through_preference) const
{
    if (fall_through_preference)
    {
        // code gen positive, FJP to false_branch
        traversal(pprec);
        false_branch->branch_from_here_if_false();
    }
    else
    {
        // code gen negative, FJP to true_branch
        expression::pointer nep = code.eq_expression(get_lhs(), get_rhs());
        nep->traversal(pprec);
        true_branch->branch_from_here_if_false();
    }
}


// vim: set ts=8 sw=4 et :
