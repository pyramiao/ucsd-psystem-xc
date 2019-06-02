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

#ifndef LIB_EXPRESSION_LE_H
#define LIB_EXPRESSION_LE_H

#include <lib/expression.h>

/**
  * The expression_le class is used to represent an abstract
  * less than or equal expression node.
  */
class expression_le:
    public expression
{
public:
    /**
      * The destructor.
      */
    virtual ~expression_le();

protected:
    /**
      * The constructor.
      * For the use of derived classes only.
      *
      * @param lhs
      *     The left hand side of the comparison.
      * @param rhs
      *     The right hand side of the comparison.
      */
    expression_le(const expression::pointer &lhs,
        const expression::pointer &rhs);

    // See base class for documentation.
    int get_precedence() const;

    // See base class for documentation.
    void traversal(int pprec) const;

    // See base class for documentation.
    type::pointer get_type() const;

    // See base class for documentation.
    bool is_lvalue() const;

    // See base class for documentation.
    side_effect_t has_side_effect() const;

    // See base class for documentation.
    bool is_constant() const;

    // See base class for documentation.
    rcstring lisp_representation(void) const;

    /**
      * The pre_order_traversal method is used to perform actions
      * required before the left hand expression is traversed.
      *
      * @param pprec
      *     The parent expressions precedence.  Not much use to code
      *     generators, but essential for pretty printers to get the
      *     parentheses correct.
      */
    virtual void pre_order_traversal(int pprec) const;

    /**
      * The infix_order_traversal method is used to perform actions
      * required between the left and right hand expression traversals.
      *
      * @param pprec
      *     The parent expressions precedence.
      */
    virtual void infix_order_traversal(int pprec) const;

    /**
      * The post_order_traversal method is used to perform actions
      * required after the right hand expression has been traversed.
      *
      * @param pprec
      *     The parent expressions precedence.  Not much use to code
      *     generators, but essential for pretty printers to get the
      *     parentheses correct.
      */
    virtual void post_order_traversal(int pprec) const;

    /**
      * The get_lhs method may be used to obtain the left hand side of
      * the comparison.
      */
    expression::pointer get_lhs() const { return lhs; }

    /**
      * The get_rhs method may be used to obtain the right hand side of
      * the comparison.
      */
    expression::pointer get_rhs() const { return rhs; }

private:
    /**
      * The lhs instance variable is used to remember the left hand side
      * of the comparison.
      */
    expression::pointer lhs;

    /**
      * The rhs instance variable is used to remember the right hand
      * side of the comparison.
      */
    expression::pointer rhs;

    /**
      * The default constructor.  Do not use.
      */
    expression_le();

    /**
      * The copy constructor.  Do not use.
      */
    expression_le(const expression_le &);

    /**
      * The assignment operator.  Do not use.
      */
    expression_le &operator=(const expression_le &);
};

#endif // LIB_EXPRESSION_LE_H
// vim: set ts=8 sw=4 et :
