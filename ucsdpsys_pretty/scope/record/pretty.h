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

#ifndef UCSDPSYS_PRETTY_SCOPE_RECORD_PRETTY_H
#define UCSDPSYS_PRETTY_SCOPE_RECORD_PRETTY_H

#include <lib/scope/record.h>

class translator_pretty; // forward

/**
  * The scope_record_pretty class is used to represent
  * a record scope, for the pretty printer.
  */
class scope_record_pretty:
    public scope_record
{
public:
    typedef boost::shared_ptr<scope_record_pretty> pointer;

    /**
      * The destructor.
      */
    virtual ~scope_record_pretty();

    /**
      * The create class method is used to create new dynamically
      * allocated instances of this class.
      *
      * @param is_packed
      *     Whether or not this record is to have its fields packed.
      * @param context
      *     The translation context we are working within.
      */
    static pointer create(bool is_packed, translator_pretty *context);

protected:
    // See base class for documentation.
    symbol_variable::pointer variable_factory(const variable_name &name,
        const type::pointer &tp, int lex_level);

private:
    /**
      * The constructor.
      * It is private on purpose, use a #create class method instead.
      *
      * @param is_packed
      *     Whether or not this record is to have its fields packed.
      * @param context
      *     The translation context we are working within.
      */
    scope_record_pretty(bool is_packed, translator_pretty *context);

    /**
      * The context instance variable i sused to remember
      * the translation context we are working within.
      */
    translator_pretty *context;

    /**
      * The default constructor.  Do not use.
      */
    scope_record_pretty();

    /**
      * The copy constructor.  Do not use.
      *
      * @param rhs
      *     The right hand side of the initialisation.
      */
    scope_record_pretty(const scope_record_pretty &rhs);

    /**
      * The assignment operator.  Do not use.
      *
      * @param rhs
      *     The right hand side of the assignment.
      */
    scope_record_pretty &operator=(const scope_record_pretty &rhs);
};

#endif // UCSDPSYS_PRETTY_SCOPE_RECORD_PRETTY_H
// vim: set ts=8 sw=4 et :
