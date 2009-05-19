/*
# This file is Copyright 2009 Dean Hall.
#
# This file is part of the Python-on-a-Chip program.
# Python-on-a-Chip is free software: you can redistribute it and/or modify
# it under the terms of the GNU LESSER GENERAL PUBLIC LICENSE Version 2.1.
# 
# Python-on-a-Chip is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# A copy of the GNU LESSER GENERAL PUBLIC LICENSE Version 2.1
# is seen in the file COPYING up one directory from this.
*/


/**
 * VM feature configuration
 *
 * Compile time switches to include features or save space.
 *
 * IMPORTANT: All of the HAVE_* items in this file should also exist in the
 * PM_FEATURES dict in src/tools/pmImgCreator.py.  If the item is defined here,
 * the corresponding dict value should be True; False otherwise.
 */


#ifndef FEATURES_H_
#define FEATURES_H_


/** Defines the size of the static heap */
#define PM_HEAP_SIZE 0x3000


/**
 * When defined, bytecodes PRINT_ITEM and PRINT_NEWLINE are supported. Along
 * with these, helper routines in the object type are compiled in that allow
 * printing of the object.
 */
#define HAVE_PRINT


/**
 * When defined, the code to perform mark-sweep garbage collection is included
 * in the build and automatic GC is enabled.  When undefined the allocator
 * will distribute memory until none is left, after which a memory exception
 * will occur.
 */
#define HAVE_GC


/* #148 Create configurable float datatype */
/**
 * When defined, the code to support floating point objects is included
 * in the build.
 */
/*#define HAVE_FLOAT*/
/*#define PM_FLOAT_BIG_ENDIAN*/

/**
 * When defined, the code to support the keyword del is included in the build.
 * This involves the bytecodes: DELETE_SUBSCR, DELETE_NAME, DELETE_ATTR,
 * DELETE_GLOBAL and DELETE_FAST.
 */
#define HAVE_DEL

/**
 * When defined, the code to support the IMPORT_FROM and IMPORT_STAR styles
 * is included in the build.
 */
#define HAVE_IMPORTS

/**
 * When defined, the code to support the assert statement is included
 * in the build.
 */
#define HAVE_ASSERT

/* #157 Support default args */
/**
 * When defined, the code to support default arguments to functions is included
 * in the build.
 */
#define HAVE_DEFAULTARGS

/* #160 Add support for string and tuple replication */
/**
 * When defined, the code to support sequence (list, tuple, string) replcation
 * is included in the build.
 * This feature is required by the builtin function __bi.map().
 */
#define HAVE_REPLICATION

/* #202 Implement classes in the vm */
/**
 * When defined, the code to support classes, instances, methods, etc.
 * is included in the build.
 */
#define HAVE_CLASSES

/* #207 Add support for the yield keyword */
/**
 * When defined, the code to support the yield keyword's use for 
 * generator-iterators is included in the build.
 */
#define HAVE_GENERATORS
#if defined(HAVE_GENERATORS) && !defined(HAVE_CLASSES)
#error HAVE_GENERATORS requires HAVE_CLASSES
#endif


#endif /* FEATURES_H_ */