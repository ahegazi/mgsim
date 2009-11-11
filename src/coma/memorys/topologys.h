#ifndef _TOPOLOGY_S_H
#define _TOPOLOGY_S_H
//////////////////////////////////////////////////////////////////////////
// single level topology

#include "predef.h"

#include "memoryst.h"
#include "busst.h"

#include "processortok.h"
#define PROCESSOR_DEF   ProcessorTOK

#include "cachel2tokim.h"
#include "directoryrttokim.h"
#define CACHEL2IM_DEF   CacheL2TOKIM
#define DIRRTIM_DEF     DirectoryRTTOKIM

#include "directorytokim.h"

#include "vmemorydatacontainer.h"
//#include "rangememorydatacontainer.h"
//#include "simplememorydatacontainer.h"

#include "network.h"

#include "ddrmemorysys.h"

namespace MemSim{
//{ memory simulator namespace
//////////////////////////////


class TopologyS
{
public:
    TopologyS();
    ~TopologyS();

    void PreFill();
private:
    // clocks
    sc_clock*                   m_pclk;
    sc_clock*                   m_pclkmem;

    // real data container
    VMemoryDataContainer*  m_pmemDataSim;
    //RangeMemoryDataContainer*  m_pmemDataSim;
    //SimpleMemoryDataContainer*  m_pmemDataSim;

    //////////////////////////////////////////////////////////////////////////
    // systemc modules

    // processor array
    PROCESSOR_DEF**             m_ppProcessors;

    // proc-cache bus array
    BusST**                     m_ppBus;

    // cache L2 array
    CACHEL2IM_DEF**             m_ppCacheL2;

    // network
    Network*                    m_pNet;

    // network level 0  : for multi-level configuration only
    Network**                   m_ppNetL0;

    // memoy bus
    BusST**                     m_ppBusMem;
    //BusST*                      m_pBusMem;

    // root direcotyr
    DIRRTIM_DEF**               m_ppDirectoryRoot;

    // directories
    DirectoryTOKIM**            m_ppDirectoryL0;

    // memory
    DDRMemorySys**              m_ppMem;
    //DDRMemorySys*                 m_pMem;
    //MemoryST*                   m_pMem;
};

//////////////////////////////
//} memory simulator namespace
}

#endif // define topology

