//
// UCSD p-System cross compiler
// Copyright (C) 2010, 2012 Peter Miller
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

#ifndef UCSDPSYS_ASSEMBLE_EXPRESSION_SUBTRACTION_SEGREL_H
#define UCSDPSYS_ASSEMBLE_EXPRESSION_SUBTRACTION_SEGREL_H

#include <lib/expression/subtraction.h>

/**
  * The expression_subtraction_segrel class is used to represent
  * a subtraction expression that results in a segment relative value.
  */
class expression_subtraction_segrel:
    public expression_subtraction
{
public:
    typedef boost::shared_ptr<expression_subtraction_segrel> pointer;

    /**
      * The destructor.
      */
    virtual ~expression_subtraction_segrel();

    /**
      * The create class method is used to create new dynamically
      * allocated instances of this class.
      *
      * @param lhs
      *     The left hand side of the subtraction.
      * @param rhs
      *     The right hand side of the subtraction.
      */
    static pointer create(const expression::pointer &lhs,
        const expression::pointer &rhs);

protected:
    // See base class for documentation.
    expression::pointer optimize(void) const;

    // See base class for documentation.
    expression::pointer clone(const location &locn) const;

    // See base class for documentation.
    type::pointer get_type(void) const;

private:
    /**
      * The constructor.
      * It is private on purpose, use a #create class method instead.
      *
      * @param lhs
      *     The left hand side of the subtraction.
      * @param rhs
      *     The right hand side of the subtraction.
      */
    expression_subtraction_segrel(const expression::pointer &lhs,
        const expression::pointer &rhs);

    /**
      * The default constructor.  Do not use.
      */
    expression_subtraction_segrel();

    /**
      * The copy constructor.  Do not use.
      *
      * @param rhs
      *     The right hand side of the initialisation.
      */
    expression_subtraction_segrel(const expression_subtraction_segrel &rhs);

    /**
      * The assignment operator.  Do not use.
      *
      * @param rhs
      *     The right hand side of the assignment.
      */
    expression_subtraction_segrel &operator=(
        const expression_subtraction_segrel &rhs);
};

#endif // UCSDPSYS_ASSEMBLE_EXPRESSION_SUBTRACTION_SEGREL_H
// vim: set ts=8 sw=4 et :
