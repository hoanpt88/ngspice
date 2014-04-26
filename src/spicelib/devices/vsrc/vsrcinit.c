#include "ngspice/config.h"

#include "ngspice/devdefs.h"

#include "vsrcitf.h"
#include "vsrcext.h"
#include "vsrcinit.h"

#ifdef USE_CUSPICE
#include "ngspice/CUSPICE/CUSPICE.h"
#endif


SPICEdev VSRCinfo = {
    .DEVpublic = {
        .name = "Vsource",
        .description = "Independent voltage source",
        .terms = &VSRCnSize,
        .numNames = &VSRCnSize,
        .termNames = VSRCnames,
        .numInstanceParms = &VSRCpTSize,
        .instanceParms = VSRCpTable,
        .numModelParms = NULL,
        .modelParms = NULL,
        .flags = DEV_DEFAULT,

#ifdef XSPICE
        .cm_func = NULL,
        .num_conn = 0,
        .conn = NULL,
        .num_param = 0,
        .param = NULL,
        .num_inst_var = 0,
        .inst_var = NULL,
#endif
    },

    .DEVparam = VSRCparam,
    .DEVmodParam = NULL,
#ifdef USE_CUSPICE
    .DEVload = cuVSRCload,
#else
    .DEVload = VSRCload,
#endif
    .DEVsetup = VSRCsetup,
    .DEVunsetup = VSRCunsetup,
    .DEVpzSetup = VSRCpzSetup,
    .DEVtemperature = VSRCtemp,
    .DEVtrunc = NULL,
    .DEVfindBranch = VSRCfindBr,
    .DEVacLoad = VSRCacLoad,
    .DEVaccept = VSRCaccept,
    .DEVdestroy = VSRCdestroy,
    .DEVmodDelete = VSRCmDelete,
    .DEVdelete = VSRCdelete,
    .DEVsetic = NULL,
    .DEVask = VSRCask,
    .DEVmodAsk = NULL,
    .DEVpzLoad = VSRCpzLoad,
    .DEVconvTest = NULL,
    .DEVsenSetup = NULL,
    .DEVsenLoad = NULL,
    .DEVsenUpdate = NULL,
    .DEVsenAcLoad = NULL,
    .DEVsenPrint = NULL,
    .DEVsenTrunc = NULL,
    .DEVdisto = NULL,
    .DEVnoise = NULL,
    .DEVsoaCheck = NULL,
    .DEVinstSize = &VSRCiSize,
    .DEVmodSize = &VSRCmSize,

#ifdef CIDER
    .DEVdump = NULL,
    .DEVacct = NULL,
#endif
#ifdef KLU
    .DEVbindCSC = VSRCbindCSC,
    .DEVbindCSCComplex = VSRCbindCSCComplex,
    .DEVbindCSCComplexToReal = VSRCbindCSCComplexToReal,
#endif
#ifdef USE_CUSPICE
    .cuDEVdestroy = cuVSRCdestroy,
    .DEVtopology = VSRCtopology,
#endif
};


SPICEdev *
get_vsrc_info(void)
{
    return &VSRCinfo;
}
