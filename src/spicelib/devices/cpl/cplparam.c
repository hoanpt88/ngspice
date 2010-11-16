/**********
Copyright 1992 Regents of the University of California.  All rights
reserved.
Author: 1992 Charles Hough
**********/


#include "ngspice.h"
#include "const.h"
#include "ifsim.h"
#include "cpldefs.h"
#include "sperror.h"
#include "suffix.h"


/* ARGSUSED */
int
CPLparam(int param, IFvalue *value, GENinstance *inst, IFvalue *select)
{

    CPLinstance *here = (CPLinstance *)inst;

    IGNORE(select);

    switch(param) {
        case CPL_POS_NODE:
            here->in_node_names = value->v.vec.sVec;
            break;
        case CPL_NEG_NODE:
            here->out_node_names = value->v.vec.sVec;
            break;
        case CPL_DIM:
            here->dimension = value->iValue;
            break;
	case CPL_LENGTH:
	    here->CPLlength = value->rValue;
	    here->CPLlengthGiven = TRUE;
	    break;
        default:
            return(E_BADPARM);
    }
    return(OK);
}
