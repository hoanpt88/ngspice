/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Thomas L. Quarles
**********/

    /*
     *CKTaskNodQst
     *
     *   ask about a parameter on a node.
     */

#include "ngspice.h"
#include <stdio.h>
#include "ifsim.h"
#include "iferrmsg.h"
#include "cktdefs.h"



/* ARGSUSED */
int
CKTaskNodQst(CKTcircuit *ckt, CKTnode *node, int parm, IFvalue *value, IFvalue *selector)
{
    IGNORE(ckt);
    IGNORE(selector);

    if(!node) return(E_BADPARM);
    switch(parm) {

    case PARM_NS:
        value->rValue = node->nodeset;
        break;

    case PARM_IC:
        value->rValue = node->ic;
        break;

    case PARM_NODETYPE:
        value->iValue = node->type;
        break;

    default:
        return(E_BADPARM);
    }
    return(OK);
}
