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

#ifndef LIB_SEGKIND_H
#define LIB_SEGKIND_H

#include <lib/rcstring.h>

enum segkind_t
{
    /**
      * PASCAL host program outer block, executable, fully linked.
      *
      * This is what PROGRAM compilations look like, when they have
      * no EXTERNAL procedures.
      *
      * The unlinked form of this is HOSTSEG.
      */
    LINKED,

    /**
      * PASCAL host program outer block, incomplete.
      *
      * This is what PROGRAM compilations look like, when they have
      * at least one EXTERNAL procedure.
      *
      * The linked form of this is LINKED.
      */
    HOSTSEG,

    /**
      * PASCAL segment procedure, not host, fully linked.
      * (Not supposed to be able to have an unlinked one of these.)
      */
    SEGPROC,

    /**
      * library unit occurance/reference
      *
      * This is what non-intrinsic units look like.  They may or may
      * not have unresolved EXTERNAL procedures.  Segments of this kind
      * always have link-info attached, even if it consists of just
      * EOFMARK.  The otherwise-empty link-info is how you can tell it's
      * fully linked.
      *
      * A UNITSEG with zero length is a reference.  The name is the name
      * of the segment to look for, the number is the segment number the
      * linked should use when it copies the segment into the program.
      * The segment in the library may well have a different segment
      * number.
      */
    UNITSEG,

    /**
      * This is a library separate procedure and function segment,
      * generated by the assembler.
      *
      * It is also generated by the compiler for SEPARATE UNIT
      * compilations (only available in the UCSD II.0 native compiler,
      * not present in I.5, not present in II.1).
      */
    SEPRTSEG,

    /**
      * unlinked intrinsic unit
      *
      * This is what an intrinsic unit looks like when it has
      * unresolved EXTERNAL procedures.
      *
      * The linked form of this is LINKED_INTRINS.
      */
    UNLINKED_INTRINS,

    /**
      * linked intrinsic unit
      *
      * This is what an intrinsic unit looks like when it has
      * no unresolved EXTERNAL procedures.
      *
      * The unlinked form of this is UNLINKED_INTRINS.
      */
    LINKED_INTRINS,

    /**
      * data segment
      */
    DATASEG
};

/**
  * The kind_name function is used to decode a segment kind code
  * into a segment kind name string.
  */
rcstring segkind_name(segkind_t kind);

#endif // LIB_SEGKIND_H
// vim: set ts=8 sw=4 et :