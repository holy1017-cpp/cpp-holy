#include "guidEx.h"

// For UUID
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")

namespace guidEx {

    void CGUID::print()
    {
        wcout << s << " : ";
    }

    void CGUID::printn()
    {
        wcout << s << endl;
    }

    void test()
    {
        // Create a new uuid
        UUID uuid;
        RPC_STATUS ret_val = ::UuidCreate(&uuid);

        if (ret_val == RPC_S_OK)
        {
            // convert UUID to LPWSTR
            WCHAR* wszUuid = NULL;
            ::UuidToStringW(&uuid, (RPC_WSTR*)&wszUuid);
            if (wszUuid != NULL)
            {
                //TODO: do something with wszUuid
                wstring s = wszUuid;
                wcout << s << endl;

                // free up the allocated string
                ::RpcStringFreeW((RPC_WSTR*)&wszUuid);
                wszUuid = NULL;
            }
            else
            {
                //TODO: uh oh, couldn't convert the GUID to string (a result of not enough free memory)
            }
        }
        else
        {
            //TODO: uh oh, couldn't create the GUID, handle this however you need to
        }

    }

    CGUID::CGUID()
    {
        // Create a new uuid
        ret_val = ::UuidCreate(&uuid);

        if (ret_val == RPC_S_OK)
        {
            // convert UUID to LPWSTR
            WCHAR* wszUuid = NULL;
            ::UuidToStringW(&uuid, (RPC_WSTR*)&wszUuid);
            if (wszUuid != NULL)
            {
                //TODO: do something with wszUuid
                s = wszUuid;
                //wcout << s << endl;

                // free up the allocated string
                ::RpcStringFreeW((RPC_WSTR*)&wszUuid);
                wszUuid = NULL;
            }
            else
            {
                //TODO: uh oh, couldn't convert the GUID to string (a result of not enough free memory)
            }
        }
        else
        {
            //TODO: uh oh, couldn't create the GUID, handle this however you need to
        }
    }


}

